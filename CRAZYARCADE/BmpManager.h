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


	static BmpManager* GetInstance()
	{
		if (nullptr == Instance)
			Instance = new BmpManager;

		return Instance;
	}

	void DestroyInstance()
	{
		if (Instance)
		{
			delete Instance;
			Instance = nullptr;
		}
	}
};


