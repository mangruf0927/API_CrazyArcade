#include "Stage1.h"
#include "Object.h"
#include "Player.h"
#include "BmpManager.h"
#include "ObjectManager.h"
#include "TileManager.h"
#include "Box1.h"

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

	BmpManager::GetInstance()->InsertBmp(L"Box1", L"Image/stage/Box1.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Box2", L"Image/stage/Box2.bmp");

	BmpManager::GetInstance()->InsertBmp(L"Obj1", L"Image/stage/Obj1.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj2", L"Image/stage/Obj2.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj3", L"Image/stage/Obj3.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Obj4", L"Image/stage/Obj4.bmp");
	
	//TileManager::GetInstance()->LoadMap(L"Data/stage1.dat");

	// 플레이어
	{
		Object* obj = new Player;
		obj->Init();
		obj->SetPos(297, 250);
		ObjectManager::GetInstance()->AddObject(obj, OBJTYPE::PLAYER);
	}

	// 박스
	for(int i = 1; i < 15; i += 2)
		for (int j = 1; j < 4; j += 2)
		{
			Object* box = new Box1;
			box->Init();
			box->SetPos(20 + 40 * i, 80 + 40 * j);
			ObjectManager::GetInstance()->AddObject(box, OBJTYPE::BLOCK);
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
	ObjectManager::GetInstance()->LateUpdate();
}

void Stage1::Render(HDC hdc)
{
	HDC memDC = BmpManager::GetInstance()->FindImage(L"Background");
	BitBlt(hdc, 0, 0, 800, 598, memDC, 0, 0, SRCCOPY);

	memDC = BmpManager::GetInstance()->FindImage(L"Bazzi_");
	GdiTransparentBlt(hdc, 661, 104, 42, 33, memDC, 0, 0, 91, 73, RGB(255, 0, 255));


	//TileManager::GetInstance()->Render(hdc);

	ObjectManager::GetInstance()->Render(hdc);
}

void Stage1::Release()
{
	ObjectManager::GetInstance()->Release();
}
