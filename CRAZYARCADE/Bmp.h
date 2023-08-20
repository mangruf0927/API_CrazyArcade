#pragma once
#include "framework.h"

class Bmp
{
private:
	BITMAP bit;
	HBITMAP m_hBitmap, m_hOldBitmap;
	HDC m_MemDC;

public:
	Bmp();
	~Bmp();

	void LoadBmp(const TCHAR* File);
	void Release();

	HDC GetMemDC() { return m_MemDC; }
};
