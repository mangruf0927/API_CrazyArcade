#pragma once
#include "framework.h"
#include "define.h"
#include "enum.h"
#include "Tile.h"

class TileManager
{
	SINGLETONE(TileManager);
private:
	vector<Object*> Tiles;
	TCHAR* FrameKey;

public :
	TileManager();
	~TileManager();

	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void PickTile(int tileName);
	void SaveMap();
	void LoadMap(const TCHAR *filePath);
};

