#pragma once
#include "Scene.h"

class SceneTool : public Scene
{
private:

public :
	SceneTool();
	~SceneTool();

	virtual void Init(); 
	virtual void Update();
	virtual void LateUpdate();
	virtual void Render(HDC hdc);
	virtual void Release(); 
};

