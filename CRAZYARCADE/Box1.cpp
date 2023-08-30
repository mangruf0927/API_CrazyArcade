#include "Box1.h"
#include "BmpManager.h"


// ±úÁü + ¹Ð¸®Áö X
Box1::Box1()
{
}

Box1::~Box1()
{
}

void Box1::Init()
{
	BmpManager::GetInstance()->InsertBmp(L"Box1", L"Image/stage/Box1.bmp");

	blockType = BLOCKTYPE::BLOCK;

	info.sizeX = 40;
	info.sizeY = 47;
}

int Box1::Update()
{
	SetCenter();
	SetRect();
	return LIVE;
}

void Box1::LateUpdate()
{
}

void Box1::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(L"Box1");
	GdiTransparentBlt(hdc, info.posX, info.posY - 7, 40, 47, memDC, 0, 0, 40, 47, RGB(255, 0, 255));
	//Rectangle(hdc, centerPos.x - 20, centerPos.y - 20, centerPos.x + 20, centerPos.y + 20);
	//Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
}

void Box1::Release()
{
}
