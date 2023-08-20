#include "SceneManager.h"
#include "Stage1.h"

SceneManager* SceneManager::Instance = nullptr;
SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	//Scene ���� ����
	for (UINT i = 0; i < (UINT)SCENETYPE::END; i++)
	{
		if (Scenes[i] != nullptr)
			delete Scenes[i];
	}
}

void SceneManager::Init()
{
	//Scene ����
	/*Scenes[(UINT)SCENETYPE::START] = new Start;
	Scenes[(UINT)SCENETYPE::START2] = new Stage2;
	Scenes[(UINT)SCENETYPE::START3] = new Stage3;*/

	Scenes[(UINT)SCENETYPE::STAGE1] = new Stage1;
	Scenes[(UINT)SCENETYPE::STAGE1]->SetName(L"STAGE1");


	//���� �� ����
	curScene = Scenes[(UINT)SCENETYPE::STAGE1];
	curScene->Enter();
}

void SceneManager::Update()
{
	curScene->Update();
}

void SceneManager::LateUpdate()
{
	curScene->LateUpdate();
}

void SceneManager::Render(HDC hdc)
{
	curScene->Render(hdc);
}

void SceneManager::Release()
{
	curScene->Release();
}

SceneManager* SceneManager::GetInstance()
{
	if (!Instance)
		Instance = new SceneManager;
	return Instance;
}

void SceneManager::DestroyInstance()
{
	if (Instance)
	{
		delete Instance;
		Instance = nullptr;
	}
}
