#include "Box.h"
#include "BmpManager.h"

Box::Box()
{
	//BOXINFO{};
}

Box::~Box()
{
}

void Box::Init()
{
	Scale.x = 40;
	Scale.y = 40;
}

void Box::Update()
{
	// 물풍선이랑 충돌하면 사라지기
	// 밀리는 상자 : 플레이어랑 충돌하면 밀리기 
}

void Box::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(boxName);
	GdiTransparentBlt(hdc, Pos.x, Pos.y, Scale.x, Scale.y, memDC, 0, 0, 40, 40, RGB(255, 255, 255));		
}

void Box::Release()
{
}
