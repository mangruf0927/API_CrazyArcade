#include "MainGame.h"
#include "BmpManager.h"
#include "SceneManager.h"

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

void MainGame::Init()
{
	SceneManager::GetInstance()->Init();
}

void MainGame::Update()
{
	SceneManager::GetInstance()->Update();
}

void MainGame::LateUpdate()
{
	SceneManager::GetInstance()->LateUpdate();
}

void MainGame::Render(HDC hdc)
{
	SceneManager::GetInstance()->Render(hdc);
}

void MainGame::Release()
{
	SceneManager::GetInstance()->Release();
}
