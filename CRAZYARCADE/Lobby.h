#pragma once
#include "Scene.h"

class Lobby : public Scene
{
private:


public:
	Lobby();
	~Lobby();

	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

};

