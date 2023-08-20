#include "Stage1.h"
#include "GameObject.h"
#include "Player.h"
#include "BmpManager.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Init()
{
	BmpManager::GetInstance()->InsertBmp(L"Background", L"Image/map/Background.bmp");

}

void Stage1::Update()
{

}

void Stage1::LateUpdate()
{
}

void Stage1::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(L"Background");
	BitBlt(hdc, 0, 0, 800, 598, memDC, 0, 0, SRCCOPY);


}

void Stage1::Release()
{
}
