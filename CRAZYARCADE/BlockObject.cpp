#include "BlockObject.h"
#include "BmpManager.h"

BlockObject::BlockObject()
{
}

BlockObject::~BlockObject()
{
}

void BlockObject::Init()
{
	BmpManager::GetInstance()->InsertBmp(L"OBJ1", L"Image/stage/Obj1.bmp");
	BmpManager::GetInstance()->InsertBmp(L"OBJ2", L"Image/stage/Obj2.bmp");
	BmpManager::GetInstance()->InsertBmp(L"OBJ3", L"Image/stage/Obj3.bmp");
	BmpManager::GetInstance()->InsertBmp(L"OBJ4", L"Image/stage/Obj4.bmp");
	//BmpManager::GetInstance()->InsertBmp(L"OBJ5", L"Image/stage/Obj5.bmp");

	blockType = BLOCKTYPE::OBJECT;

	info.sizeX = 40;
	info.sizeY = 60;	  
}

int BlockObject::Update()
{
	SetCenter();
	SetRect();
    return LIVE;
}

void BlockObject::LateUpdate()
{
}

void BlockObject::Render(HDC hdc)
{
	HDC memDC;

	if (objName == L"OBJ1")
	{
		memDC = BmpManager::GetInstance()->FindImage(L"OBJ1"); // 파
		GdiTransparentBlt(hdc, info.posX, info.posY - 20, 40, 60, memDC, 0, 0, 40, 60, RGB(255, 0, 255));
	}
	if (objName == L"OBJ2")
	{
		memDC = BmpManager::GetInstance()->FindImage(L"OBJ2"); // 주
		GdiTransparentBlt(hdc, info.posX, info.posY - 20, 40, 60, memDC, 0, 0, 40, 60, RGB(255, 0, 255));
	}
	if (objName == L"OBJ3")
	{
		memDC = BmpManager::GetInstance()->FindImage(L"OBJ3"); // 노
		GdiTransparentBlt(hdc, info.posX, info.posY - 20, 40, 60, memDC, 0, 0, 40, 60, RGB(255, 0, 255));
		//Rectangle(hdc, centerPos.x - 20, centerPos.y - 20, centerPos.x + 20, centerPos.y + 20);
		Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
	}
	if (objName == L"OBJ4")
	{
		memDC = BmpManager::GetInstance()->FindImage(L"OBJ4"); // 초
		GdiTransparentBlt(hdc, info.posX, info.posY - 20, 40, 60, memDC, 0, 0, 40, 60, RGB(255, 0, 255));
	}
	/*if (objName == L"OBJ5")
	{
		memDC = BmpManager::GetInstance()->FindImage(L"OBJ5");
		GdiTransparentBlt(hdc, info.posX, info.posY - 24, 40, 64, memDC, 0, 0, 40, 64, RGB(255, 0, 255));
	}*/
}

void BlockObject::Release()
{
}
