#pragma once
#include "framework.h"
#include "define.h"
#include "enum.h"
#include "Tile.h"

class TileManager
{
	SINGLETONE(TileManager);
private:
	Tile* Map[13][15];
	vector<Object*> Tiles;
	TCHAR* FrameKey;
	//vector<Tile*> Tiles;

public :
	TileManager();
	~TileManager();

	void Init();
	void Update();
	void Render(HDC hdc);
	void Release();

	void PickTile(int tileName);
	void SaveMap();
	void LoadMap(TCHAR *filePath);
};

