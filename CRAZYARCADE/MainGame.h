#pragma once
#include "framework.h"
#include "SceneManager.h"

class MainGame
{
private:
	//SceneManager* Scene;

public:
	MainGame();
	~MainGame();

	void Init();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);
	void Release();
};

