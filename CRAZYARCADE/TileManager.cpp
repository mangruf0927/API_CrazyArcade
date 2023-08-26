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
			
			Tiles.push_back(tile);
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
		Tiles.clear();
}


void TileManager::PickTile()
{

}

void TileManager::SaveMap()
{
	//HANDLE Maap = CreateFile("MapData/map.dat", GENERIC_WRITE, 0, CREATE_ALWAYS, NULL, )
}
                                                                              
void TileManager::LoadMap()
{

}
