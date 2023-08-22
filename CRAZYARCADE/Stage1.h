#pragma once
#include "Scene.h"

class Stage1 : public Scene
{
private:
	unsigned long startTime;
	bool gameStart;
	bool gameEnd;

public:
	Stage1();
	~Stage1();

	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

