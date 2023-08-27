#include "Tile.h"
#include "BmpManager.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::Init()
{
	info.sizeX = 40;
	info.sizeY = 40;

	BmpManager::GetInstance()->InsertBmp(L"Tile1", L"Image/stage/Tile.bmp");

	BmpManager::GetInstance()->InsertBmp(L"Box1", L"Image/stage/Box1.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Box2", L"Image/stage/Box2.bmp");
	
	BmpManager::GetInstance()->InsertBmp(L"Obj1", L"Image/stage/Obj1.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj2", L"Image/stage/Obj2.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj3", L"Image/stage/Obj3.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj4", L"Image/stage/Obj4.bmp");

}

void Tile::Update()
{
}

void Tile::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(tileKey);
	GdiTransparentBlt(hdc, info.posX, info.posY, 40, 40, memDC, 0, 0, 40, 40, RGB(255, 0, 255));
}

void Tile::Release()
{
}
