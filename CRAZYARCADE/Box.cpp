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
	info.sizeX = 40;
	info.sizeY = 40;
}

void Box::Update()
{
	// ��ǳ���̶� �浹�ϸ� �������
	// �и��� ���� : �÷��̾�� �浹�ϸ� �и��� 
}

void Box::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(boxName);
	GdiTransparentBlt(hdc, info.posX, info.posY, info.sizeX, info.sizeY, memDC, 0, 0, 40, 40, RGB(255, 0, 255));
}

void Box::Release()
{
}
