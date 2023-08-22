#include "Stage1.h"
#include "Object.h"
#include "Player.h"
#include "BmpManager.h"
#include "ObjectManager.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Init()
{
	BmpManager::GetInstance()->InsertBmp(L"Background", L"Image/map/Background.bmp");

	Object* obj = new Player;
	obj->Init();
	ObjectManager::GetInstance()->AddObject(obj, OBJTYPE::PLAYER);

	startTime = GetTickCount();
}

void Stage1::Update()
{
	
	ObjectManager::GetInstance()->Update();
}

void Stage1::LateUpdate()
{
}

void Stage1::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(L"Background");
	BitBlt(hdc, 0, 0, 800, 598, memDC, 0, 0, SRCCOPY);

	

	ObjectManager::GetInstance()->Render(hdc);
}

void Stage1::Release()
{
}
