#include "BmpManager.h"
#include "define.h"

BmpManager* BmpManager::Instance = nullptr;
BmpManager::BmpManager()
{
}

BmpManager::~BmpManager()
{
	Release();
}

HDC BmpManager::FindImage(const TCHAR* ImgName)
{
	if (MapBmp.empty())
		return nullptr;

	auto iter = find_if(MapBmp.begin(), MapBmp.end(), [&ImgName](auto& MyPair)
		{
			return !lstrcmp(ImgName, MyPair.first);
		});

	if (MapBmp.end() == iter)
		return nullptr;

	return iter->second->GetMemDC(); //second = key°ª
}

void BmpManager::InsertBmp(const TCHAR* ImgName, const TCHAR* File)
{
	if (true == MapBmp.insert({ ImgName,nullptr }).second)
	{
		MapBmp[ImgName] = new Bmp;
		MapBmp[ImgName]->LoadBmp(File);
	}
}

void BmpManager::Release()
{
	for (auto& iter : MapBmp)
	{
		if (nullptr != iter.second)
		{
			SafeDelete(iter.second);
		}
	}
	MapBmp.clear();
}

