#include "SceneTool.h"
#include "Tile.h"
#include "TileManager.h"
#include "BmpManager.h"
#include "KeyManager.h"

SceneTool::SceneTool()
{
}

SceneTool::~SceneTool()
{
}

void SceneTool::Init()
{
	BmpManager::GetInstance()->InsertBmp(L"background", L"Image/stage/background.bmp");

	BmpManager::GetInstance()->InsertBmp(L"Tile1", L"Image/stage/Tile.bmp");

	BmpManager::GetInstance()->InsertBmp(L"Box1", L"Image/stage/Box1.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Box2", L"Image/stage/Box2.bmp");

	BmpManager::GetInstance()->InsertBmp(L"Obj1", L"Image/stage/Obj1.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj2", L"Image/stage/Obj2.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj3", L"Image/stage/Obj3.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj4", L"Image/stage/Obj4.bmp");
	TileManager::GetInstance()->Init();
}

void SceneTool::Update()
{
	KeyUpdate();

	TileManager::GetInstance()->Update();
	ObjectManager::GetInstance()->Update();
}

void SceneTool::LateUpdate()
{
}

void SceneTool::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(L"background");
	BitBlt(hdc, 0, 0, 800, 598, memDC, 0, 0, SRCCOPY);

	RenderLine(hdc);

	TileManager::GetInstance()->Render(hdc);
	ObjectManager::GetInstance()->Render(hdc);
}

void SceneTool::Release()
{
}

void SceneTool::KeyUpdate()
{
	if (KeyManager::GetInstance()->GetKeyState(KEY::LMOUSE) == KEYSTATE::TAP && (GetKeyState('Q') & 0x8000))
		TileManager::GetInstance()->PickTile(1);
	if (KeyManager::GetInstance()->GetKeyState(KEY::LMOUSE) == KEYSTATE::TAP && (GetKeyState('W') & 0x8000))
		TileManager::GetInstance()->PickTile(2);
	if (KeyManager::GetInstance()->GetKeyState(KEY::LMOUSE) == KEYSTATE::TAP && (GetKeyState('E') & 0x8000))
		TileManager::GetInstance()->PickTile(3);
	if (KeyManager::GetInstance()->GetKeyState(KEY::LMOUSE) == KEYSTATE::TAP && (GetKeyState('R') & 0x8000))
		TileManager::GetInstance()->PickTile(4);
	if (KeyManager::GetInstance()->GetKeyState(KEY::LMOUSE) == KEYSTATE::TAP && (GetKeyState('T') & 0x8000))
		TileManager::GetInstance()->PickTile(5);
	if (KeyManager::GetInstance()->GetKeyState(KEY::LMOUSE) == KEYSTATE::TAP && (GetKeyState('Y') & 0x8000))
		TileManager::GetInstance()->PickTile(6);
	if (KeyManager::GetInstance()->GetKeyState(KEY::LMOUSE) == KEYSTATE::TAP && (GetKeyState('U') & 0x8000))
		TileManager::GetInstance()->PickTile(7);

	if (GetKeyState('S') && 0x8000) TileManager::GetInstance()->SaveMap();
}

void SceneTool::RenderLine(HDC hdc)
{
	float x = 20;
	float y = 40;

	for (int i = 0; i <= 15; i++)
	{
		x = i * 40 + 20;
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, x, y + 520);
	}

	for (int i = 0; i <= 13; i++) 
	{
		x = 20;
		y = i * 40 + 40;
		MoveToEx(hdc, x, y, NULL);
		LineTo(hdc, x + 600, y);
	}
}

