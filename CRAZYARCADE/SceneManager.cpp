#include "SceneManager.h"
#include "define.h"
#include "SceneTool.h"
#include "Stage1.h"

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
	//Scene 전부 삭제
	for (UINT i = 0; i < (UINT)SCENETYPE::END; i++)
	{
		if (Scenes[i] != nullptr)
			delete Scenes[i];
	}
}

void SceneManager::Init()
{
	//Scene 생성
	/*Scenes[(UINT)SCENETYPE::START] = new Start;
	Scenes[(UINT)SCENETYPE::START2] = new Stage2;
	Scenes[(UINT)SCENETYPE::START3] = new Stage3;*/

	Scenes[(UINT)SCENETYPE::STAGE1] = new Stage1;
	Scenes[(UINT)SCENETYPE::STAGE1]->SetName(L"STAGE1");

	Scenes[(UINT)SCENETYPE::TOOL] = new SceneTool;
	Scenes[(UINT)SCENETYPE::TOOL]->SetName(L"TOOL");


	//현재 씬 지정
	curScene = Scenes[(UINT)SCENETYPE::STAGE1];
	curScene->Init();
}

void SceneManager::Update()
{
	curScene->Update();
	curScene->LateUpdate();
}

void SceneManager::Render(HDC hdc)
{
	curScene->Render(hdc);
}

void SceneManager::Release()
{
	SafeDelete(curScene);
}

void SceneManager::ChangeScene(SCENETYPE type)
{
	//curScene = Scenes[(UINT)type];
}
