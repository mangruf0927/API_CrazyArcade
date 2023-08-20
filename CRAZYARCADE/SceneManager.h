#pragma once
#include "framework.h"
#include "enum.h"

class Scene;

class SceneManager
{
private:
	Scene* Scenes[(UINT)SCENETYPE::END]; // ¸ðµç ¾À ¸ñ·Ï
	Scene* curScene; // ÇöÀç ¾À
	static SceneManager* Instance;

public:
	SceneManager();
	~SceneManager();

	void Init();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);
	void Release();

	Scene* GetCurScene() { return curScene; }
	static SceneManager* GetInstance();
	void DestroyInstance();
};

