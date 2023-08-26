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
	Scale.x = 40;
	Scale.y = 40;

	BmpManager::GetInstance()->InsertBmp(L"Tile1", L"Image/stage3/Tile.bmp");
}

void Tile::Update()
{
}

void Tile::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(L"Tile1");
	BitBlt(hdc, Pos.x, Pos.y, Scale.x, Scale.y, memDC, 0, 0, SRCCOPY);

	//Rectangle(hdc, Pos.x, Pos.y, Pos.x + Scale.x, Pos.y + Scale.y);

	/*if (tileKey == L"Tile1")
	{
		HDC memDC = BmpManager::GetInstance()->FindImage(L"Tile1");
		BitBlt(hdc, Pos.x - (Scale.x / 2), Pos.y - (Scale.y / 2), Scale.x, Scale.y, memDC, 0, 0, SRCCOPY);
	}*/
}

void Tile::Release()
{
}
