#include "Block.h"
#include "BmpManager.h"

// 박스 1, 박스 2, 오브젝트 

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
	// 물풍선이랑 충돌하면 사라지기
	// 밀리는 상자 : 플레이어랑 충돌하면 밀리기 
}

void Block::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(boxName);
	GdiTransparentBlt(hdc, info.posX, info.posY, info.sizeX, info.sizeY, memDC, 0, 0, 40, 40, RGB(255, 0, 255));
}

void Block::Release()
{
}
