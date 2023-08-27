#include "SceneTool.h"
#include "Tile.h"
#include "TileManager.h"
#include "BmpManager.h"

SceneTool::SceneTool()
{
}

SceneTool::~SceneTool()
{
}

void SceneTool::Init()
{
	// ���
	BmpManager::GetInstance()->InsertBmp(L"background", L"image/stage/Background.bmp");
	
	// Ÿ��
	BmpManager::GetInstance()->InsertBmp(L"tile", L"image/stage/Tile.bmp");
	
	// ���
	BmpManager::GetInstance()->InsertBmp(L"box1", L"image/stage/Box1.bmp");
	BmpManager::GetInstance()->InsertBmp(L"box2", L"image/stage/Box2.bmp");

	// ��� ������Ʈ
	BmpManager::GetInstance()->InsertBmp(L"obj1", L"image/stage/Obj1.bmp");

}

void SceneTool::Update()
{
	TileManager::GetInstance()->Update();
	ObjectManager::GetInstance()->Update();
}

void SceneTool::LateUpdate()
{
}

void SceneTool::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(L"background");

	TileManager::GetInstance()->Render(hdc);
	ObjectManager::GetInstance()->Render(hdc);
}

void SceneTool::Release()
{
}
