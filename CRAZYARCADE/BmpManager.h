#pragma once
#include "Bmp.h"
#include "framework.h"
#include "define.h"

class Bmp;
class BmpManager
{
	SINGLETONE(BmpManager);
private:
	map<const TCHAR*, Bmp*> MapBmp;

public:
	BmpManager();
	~BmpManager();

	HDC FindImage(const TCHAR* ImgName);
	void InsertBmp(const TCHAR* ImgName, const TCHAR* File);
	void Release();
};


