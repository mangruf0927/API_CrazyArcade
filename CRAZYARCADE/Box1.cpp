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
	return NOEVENT;
}

void Box1::LateUpdate()
{
}

void Box1::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(L"image/stage/box1");
	GdiTransparentBlt(hdc, info.posX, info.posX, 40, 70, memDC, 0, 0, 40, 47, RGB(255, 0, 255));


	Rectangle(hdc, 10, 10, 40, 40);
}

void Box1::Release()
{
}
