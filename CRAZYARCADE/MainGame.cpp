#include "MainGame.h"
#include "BmpManager.h"
#include "SceneManager.h"
#include "KeyManager.h"
//#include "TileManager.h"

MainGame::MainGame()
{
}

MainGame::~MainGame()
{
}

void MainGame::Init()
{
	KeyManager::GetInstance()->Init();
	SceneManager::GetInstance()->Init();
	//TileManager::GetInstance()->Init();
}

void MainGame::Update()
{
	KeyManager::GetInstance()->Update();
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
