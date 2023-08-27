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

}

void Tile::Update()
{
}

void Tile::Render(HDC hdc)
{
	HDC memDC;
	switch (drawKey)
	{
	case 1:
		memDC = BmpManager::GetInstance()->FindImage(L"Tile1");
		GdiTransparentBlt(hdc, info.posX - 20, info.posY - 20, 40, 40, memDC, 0, 0, 40, 40, RGB(255, 0, 255));		
		break;
	case 2:
		memDC = BmpManager::GetInstance()->FindImage(L"Box1");
		GdiTransparentBlt(hdc, info.posX - 20, info.posY - 27, 40, 47, memDC, 0, 0, 40, 47, RGB(255, 0, 255));
		break;
	case 3:
		memDC = BmpManager::GetInstance()->FindImage(L"Box2");
		GdiTransparentBlt(hdc, info.posX - 20, info.posY - 27, 40, 47, memDC, 0, 0, 40, 47, RGB(255, 0, 255));
		break;
	case 4:
		memDC = BmpManager::GetInstance()->FindImage(L"Obj1");
		GdiTransparentBlt(hdc, info.posX - 20, info.posY - 40, 40, 60, memDC, 0, 0, 40, 60, RGB(255, 0, 255));
		break;
	case 5:
		memDC = BmpManager::GetInstance()->FindImage(L"Obj2");
		GdiTransparentBlt(hdc, info.posX - 20, info.posY - 40, 40, 60, memDC, 0, 0, 40, 60, RGB(255, 0, 255));
		break;
	case 6:
		memDC = BmpManager::GetInstance()->FindImage(L"Obj3");
		GdiTransparentBlt(hdc, info.posX - 20, info.posY - 40, 40, 60, memDC, 0, 0, 40, 60, RGB(255, 0, 255));
		break;
	case 7:
		memDC = BmpManager::GetInstance()->FindImage(L"Obj4");
		GdiTransparentBlt(hdc, info.posX - 20, info.posY - 40, 40, 60, memDC, 0, 0, 40, 60, RGB(255, 0, 255));
		break;

	default:
		break;
	}
}

void Tile::Release()
{
}



//void Tile::SetTileType()
//{
//	switch (drawKey)
//	{
//	case 1:
//		isPass = true;
//		isPush = false;
//		isBroken = false;
//		tileKey = L"tile1";
//		info.sizeY = 40;
//
//	case 2:
//		isPass = false;
//		isPush = true;
//		isBroken = true;
//		tileKey = L"Box1";
//		info.posY -= 7;
//		info.sizeY = 47;
//
//	case 3:
//		isPass = false;
//		isPush = true;
//		isBroken = true;
//		tileKey = L"Box2";
//		info.posY -= 7;
//		info.sizeY = 47;
//
//	case 4:
//		isPass = false;
//		isPush = false;
//		isBroken = false;
//		tileKey = L"Obj1";
//		info.posY -= 20;
//		info.sizeY = 60;
//
//	case 5:
//		isPass = false;
//		isPush = false;
//		isBroken = false;
//		tileKey = L"Obj2";
//		info.posY -= 20;
//		info.sizeY = 60;
//
//	case 6:
//		isPass = false;
//		isPush = false;
//		isBroken = false;
//		tileKey = L"Obj3";
//		info.posY -= 20;
//		info.sizeY = 60;
//
//	case 7:
//		isPass = false;
//		isPush = false;
//		isBroken = false;
//		tileKey = L"Obj4";
//		info.posY -= 20;
//		info.sizeY = 60;
//
//	default:
//		break;
//	}
//}

