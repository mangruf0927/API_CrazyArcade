#include "SceneManager.h"
#include "define.h"
#include "Lobby.h"
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
	Scenes[(UINT)SCENETYPE::LOBBY] = new Lobby;
	Scenes[(UINT)SCENETYPE::LOBBY]->SetName(L"LOBBY");

	//현재 씬 지정
	curScene = Scenes[(UINT)SCENETYPE::LOBBY];
	curScene->Init();
}

void SceneManager::Update()
{
	curScene->Update();
	curScene->LateUpdate();
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
	SafeDelete(curScene);
}

void SceneManager::ChangeScene(SCENETYPE type)
{
	Scenes[(UINT)SCENETYPE::STAGE1] = new Stage1;
	Scenes[(UINT)SCENETYPE::STAGE1]->SetName(L"STAGE1");

	curScene = Scenes[(UINT)SCENETYPE::STAGE1];
	curScene->Init();
}
