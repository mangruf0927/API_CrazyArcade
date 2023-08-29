#include "Monster.h"
#include "BmpManager.h"

void Monster::Init()
{
	BmpManager::GetInstance()->InsertBmp(L"moster1_DOWN", L"Image/Monster/moster1_DOWN");
	BmpManager::GetInstance()->InsertBmp(L"moster1_RIGHT", L"Image/Monster/moster1_LEFT");
	BmpManager::GetInstance()->InsertBmp(L"moster1_LEFT", L"Image/Monster/moster1_RIGHT");
	BmpManager::GetInstance()->InsertBmp(L"moster1_UP", L"Image/Monster/moster1_UP");
}

int Monster::Update()
{
	return LIVE;
}

void Monster::LateUpdate()
{
}

void Monster::Render(HDC hdc)
{
	BmpManager::GetInstance()->FindImage(L"monster1_DOWN");
	BmpManager::GetInstance()->FindImage(L"monster1_RIGHT");
	BmpManager::GetInstance()->FindImage(L"monster1_LEFT");
	BmpManager::GetInstance()->FindImage(L"monster1_UP");
}

void Monster::Release()
{
}
