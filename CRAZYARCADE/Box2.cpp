#include "Box2.h"
#include "BmpManager.h"


// ±úÁü + ¹Ð¸®Áö X
Box2::Box2()
{
}

Box2::~Box2()
{
}

void Box2::Init()
{
	BmpManager::GetInstance()->InsertBmp(L"Box2", L"Image/stage/Box2.bmp");

	blockType = BLOCKTYPE::PUSHBLOCK;

	info.sizeX = 40;
	info.sizeY = 47;
}

int Box2::Update()
{
	return LIVE;
}

void Box2::LateUpdate()
{
}

void Box2::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(L"Box2");
	GdiTransparentBlt(hdc, info.posX, info.posY - 7, 40, 47, memDC, 0, 0, 40, 47, RGB(255, 0, 255));
}

void Box2::Release()
{
}
