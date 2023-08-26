#include "Monster.h"
#include "BmpManager.h"

void Monster::Init()
{
	BmpManager::GetInstance()->InsertBmp(L"moster1_IDLE", L"Image/Monster/moster1_IDLE");
	BmpManager::GetInstance()->InsertBmp(L"moster1_RIGHT", L"Image/Monster/moster1_LEFT");
	BmpManager::GetInstance()->InsertBmp(L"moster1_LEFT", L"Image/Monster/moster1_RIGHT");
	BmpManager::GetInstance()->InsertBmp(L"moster1_UP", L"Image/Monster/moster1_UP");
	BmpManager::GetInstance()->InsertBmp(L"moster1_DOWN", L"Image/Monster/moster1_DOWN");
}

void Monster::Update()
{
}

void Monster::Render(HDC hdc)
{
}

void Monster::Release()
{
}
