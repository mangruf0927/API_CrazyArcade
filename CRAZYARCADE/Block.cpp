#include "Block.h"
#include "BmpManager.h"

// �ڽ� 1, �ڽ� 2, ������Ʈ 

Block::Block()
{
	//BOXINFO{};
}

Block::~Block()
{
}

void Block::Init()
{
	info.sizeX = 40;
	info.sizeY = 40;
}

void Block::Update()
{
	// ��ǳ���̶� �浹�ϸ� �������
	// �и��� ���� : �÷��̾�� �浹�ϸ� �и��� 
}

void Block::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(boxName);
	GdiTransparentBlt(hdc, info.posX, info.posY, info.sizeX, info.sizeY, memDC, 0, 0, 40, 40, RGB(255, 0, 255));
}

void Block::Release()
{
}
