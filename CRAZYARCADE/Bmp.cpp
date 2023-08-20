#include "Bmp.h"

Bmp::Bmp()
{
}

Bmp::~Bmp()
{
	Release();
}

void Bmp::LoadBmp(const TCHAR* File)
{
	HDC hdc = GetDC(g_hWnd);
	m_MemDC = CreateCompatibleDC(hdc);

	m_hBitmap = (HBITMAP)LoadImage(NULL, File, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(m_hBitmap, sizeof(BITMAP), &bit);

	if (!m_hBitmap)
	{
		MessageBox(g_hWnd, File, L"이미지 로드 실패", NULL);
		return;
	}
	m_hOldBitmap = (HBITMAP)SelectObject(m_MemDC, m_hBitmap);
	ReleaseDC(g_hWnd, hdc);
}

void Bmp::Release()
{
	SelectObject(m_MemDC, m_hOldBitmap);
	DeleteObject(m_hBitmap);
	DeleteDC(m_MemDC);
}
