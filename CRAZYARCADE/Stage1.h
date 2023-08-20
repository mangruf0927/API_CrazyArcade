#pragma once
#include "Scene.h"

class Stage1 : public Scene
{
public:
	Stage1();
	~Stage1();

	virtual void Enter() override;
	virtual void Exit() override;
	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

