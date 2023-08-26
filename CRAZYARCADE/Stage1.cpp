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
	// 배경
	BmpManager::GetInstance()->InsertBmp(L"Background", L"Image/stage1/Background.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Bazzi_", L"Image/UI/IngameBazzi.bmp");
	
	// 블록
	BmpManager::GetInstance()->InsertBmp(L"PushBox", L"Image/stage1/Box1.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Box", L"Image/stage1/Box2.bmp");
	
	// 오브젝트 블록
	BmpManager::GetInstance()->InsertBmp(L"Obj1", L"Image/stage1/Obj1.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj2", L"Image/stage1/Obj2.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj3", L"Image/stage1/Obj3.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj4", L"Image/stage1/Obj4.bmp");

	// 아이템
	BmpManager::GetInstance()->InsertBmp(L"Skate", L"Image/stage1/skate.bmp");
	BmpManager::GetInstance()->InsertBmp(L"balloon", L"Image/stage1/balloon.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Potion", L"Image/stage1/potion.bmp");
	BmpManager::GetInstance()->InsertBmp(L"MaxPotion", L"Image/stage1/maxpotion.bmp");

	// 플레이어
	{
		Object* obj = new Player;
		obj->Init();
		obj->SetPos(297, 260);
		ObjectManager::GetInstance()->AddObject(obj, OBJTYPE::PLAYER);
	}
	
	// 몬스터 (쫄쫄이 4 / 버럭이 2)

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

	memDC = BmpManager::GetInstance()->FindImage(L"Bazzi_");
	GdiTransparentBlt(hdc, 661, 104, 42, 33, memDC, 0, 0, 91, 73, RGB(255, 0, 255));

	/*for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			Rectangle(hdc, 20 + i * 40, 40 + j * 40, 60 + i * 40, 80 + j * 40);
		}
	}*/

	ObjectManager::GetInstance()->Render(hdc);
}

void Stage1::Release()
{
	ObjectManager::GetInstance()->Release();
}
