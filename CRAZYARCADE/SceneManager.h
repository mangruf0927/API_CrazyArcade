#pragma once
#include "framework.h"
#include "enum.h"
#include "define.h"


class Scene;
class SceneManager
{
	SINGLETONE(SceneManager)
private:
	Scene* Scenes[(UINT)SCENETYPE::END]; // ��� �� ���
	Scene* curScene; // ���� ��
	static SceneManager* Instance;

public:
	SceneManager();
	~SceneManager();

	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	Scene* GetCurScene() { return curScene; }
};

