#include "Lobby.h"
#include "BmpManager.h"
#include "SceneManager.h"
#include "KeyManager.h"

Lobby::Lobby()
{	
	// ¹è°æ
	BmpManager::GetInstance()->InsertBmp(L"Lobby", L"Image/stage/Lobby.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Start", L"Image/stage/start.bmp");
	BmpManager::GetInstance()->InsertBmp(L"Start2", L"Image/stage/start2.bmp");

}

Lobby::~Lobby()
{
}

void Lobby::Init()
{
}

void Lobby::Update()
{
}

void Lobby::LateUpdate()
{
	POINT pt = {};
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (GetKeyState(VK_LBUTTON) & 0x8000)
	{
		if (515 < pt.x && 700 > pt.x && 496 < pt.y && 547 > pt.y)
		{
			SceneManager::GetInstance()->ChangeScene(SCENETYPE::STAGE1);
		}
	}
}

void Lobby::Render(HDC hdc)
{
	HDC memDC;

	memDC = BmpManager::GetInstance()->FindImage(L"Lobby");
	BitBlt(hdc, 0, 0, 800, 598, memDC, 0, 0, SRCCOPY);

	memDC = BmpManager::GetInstance()->FindImage(L"Start2");
	GdiTransparentBlt(hdc, 513, 495, 192, 55, memDC, 0, 0, 191, 55, RGB(255, 0, 255));


	POINT pt = {};
	RECT rect = { 513, 495, 703, 550 };
	GetCursorPos(&pt);
	
	ScreenToClient(g_hWnd, &pt);
	if (PtInRect(&rect, pt))
	{
		memDC = BmpManager::GetInstance()->FindImage(L"Start");
		GdiTransparentBlt(hdc, 513, 495, 192, 55, memDC, 0, 0, 191, 55, RGB(255, 0, 255));
	}
}

void Lobby::Release()
{
}
