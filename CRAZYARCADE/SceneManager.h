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
	
	SCENETYPE nextscene;
	SCENETYPE curscene;

public:
	SceneManager();
	~SceneManager();

	void Init();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);
	void Release();

	void ChangeScene(SCENETYPE type);
	Scene* GetCurScene() { return curScene; }
};

