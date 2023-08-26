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
	// ��ǳ���̶� �浹�ϸ� �������
	// �и��� ���� : �÷��̾�� �浹�ϸ� �и��� 
}

void Box::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(boxName);
	GdiTransparentBlt(hdc, Pos.x, Pos.y, Scale.x, Scale.y, memDC, 0, 0, 40, 40, RGB(255, 255, 255));		
}

void Box::Release()
{
}
