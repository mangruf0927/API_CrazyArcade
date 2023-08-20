#pragma once
#include "Bmp.h"
#include "framework.h"

class Bmp;
class BmpManager
{
private:
	static BmpManager* Instance;
	map<const TCHAR*, Bmp*> MapBmp;

public:
	BmpManager();
	~BmpManager();

	HDC FindImage(const TCHAR* ImgName);
	void InsertBmp(const TCHAR* ImgName, const TCHAR* File);
	void Release();

	static BmpManager* getInstance();
	void DestroyInstance();
};

