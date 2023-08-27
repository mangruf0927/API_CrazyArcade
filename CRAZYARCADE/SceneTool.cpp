#include "SceneTool.h"
#include "Tile.h"
#include "BmpManager.h"

SceneTool::SceneTool()
{
}

SceneTool::~SceneTool()
{
}

void SceneTool::Init()
{
	// 배경
	BmpManager::GetInstance()->InsertBmp(L"background", L"image/stage/Background.bmp");
	
	// 타일
	BmpManager::GetInstance()->InsertBmp(L"background", L"image/stage/Background.bmp");
	
	// 블록
	BmpManager::GetInstance()->InsertBmp(L"background", L"image/stage/Background.bmp");
	BmpManager::GetInstance()->InsertBmp(L"background", L"image/stage/Background.bmp");

}

void SceneTool::Update()
{
	ObjectManager::GetInstance()->Update();
}

void SceneTool::LateUpdate()
{
}

void SceneTool::Render(HDC hdc)
{
	ObjectManager::GetInstance()->Render(hdc);
}

void SceneTool::Release()
{
}
