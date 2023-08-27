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
	LPARAM lParam;
	POINT ptMouse = {};

	ptMouse.x = LOWORD(lParam);
	ptMouse.y = HIWORD(lParam);


	/*GetCursorPos(&ptMouse);
	ScreenToClient(g_hWnd, &ptMouse);*/

	int x = (ptMouse.x - 20) / 40;
	int y = (ptMouse.y - 40) / 40;
	int idx = 15 * y + x;

	if (0 > idx || Tiles.size() <= (size_t)idx) return;

	dynamic_cast<Tile*>(Tiles[idx])->SetTileKey(tileName);
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
		int drawID = dynamic_cast<Tile*>(tile)->GetDrawID();

		WriteFile(file, &tile->GetInfo(), sizeof(OBJINFO), &dwByte, NULL);
		WriteFile(file, &drawID, sizeof(int), &dwByte, 0);
	}

	CloseHandle(file);
	MessageBox(g_hWnd, L"저장 성공", L"success", MB_OK);
}
              


void TileManager::LoadMap(TCHAR* filePath)
{
	HANDLE file = CreateFile(L"Data/map.dat", GENERIC_READ, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	if (INVALID_HANDLE_VALUE == file)
	{
		MessageBox(g_hWnd, L"불러오기 실패", L"error", MB_OK);
		return;
	}

	Release();

	OBJINFO tempinfo = {};
	int drawID = 0;
	DWORD dwByte = 0;

	while (1)
	{
		ReadFile(file, &tempinfo, sizeof(OBJINFO), &dwByte, NULL);
		ReadFile(file, &drawID, sizeof(int), &dwByte, NULL);

		if (dwByte == 0) break;

		Object* tile = new Tile;
		tile->Init();
		tile->SetPos(tempinfo.posX, tempinfo.posY);

		dynamic_cast<Tile*>(tile)->SetDrawID(drawID);
		Tiles.push_back(tile);
	}

	CloseHandle(file);
}
