#pragma once
#include "framework.h"

class MainGame
{
private:

public:
	MainGame();
	~MainGame();

	void Init();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);
	void Release();
};

