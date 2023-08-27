#include "TileManager.h"
#include "ObjectManager.h"

TileManager::TileManager()
{
}

TileManager::~TileManager()
{
	Release();
}

void TileManager::Init()
{
	for (int i = 0; i < 13; ++i)
	{
		for (int j = 0; j < 15; ++j)
		{
			float x = 40 + 40 * j;
			float y = 20 + 40 + 40 * i;

			Object* tile = new Tile;
			tile->Init();
			tile->SetPos(x, y);
			ObjectManager::GetInstance()->AddObject(tile, TILE);
			
			Tiles.emplace_back(tile);
		}
	}
}

void TileManager::Update()
{
	for (auto& tile : Tiles)
		tile->Update();
}

void TileManager::Render(HDC hdc)
{
	for (auto& tile : Tiles)
		tile->Render(hdc);
}

void TileManager::Release()
{
	for (auto& tile : Tiles)
	{
		if (tile) delete tile;
	}
		Tiles.clear();
}


void TileManager::PickTile(int tileName)
{

}

void TileManager::SaveMap()
{
	HANDLE file = CreateFile(L"Data/map.dat", GENERIC_WRITE, 0, 0, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

	if (INVALID_HANDLE_VALUE == file)
	{
		MessageBox(g_hWnd, L"저장 실패", L"error", MB_OK);
		return;
	}

	DWORD dwByte = 0;

	for (auto& tile : Tiles)
	{
		WriteFile(file, &tile->GetInfo(), sizeof(OBJINFO), &dwByte, NULL);
		WriteFile(file, &dynamic_cast<Tile*>(tile)->GetTileKey());
	}
}
                                                                              
void TileManager::LoadMap(TCHAR* filePath)
{

}
