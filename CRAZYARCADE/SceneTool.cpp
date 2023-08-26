#include "SceneTool.h"
#include "Tile.h"

SceneTool::SceneTool()
{
}

SceneTool::~SceneTool()
{
}

void SceneTool::Init()
{
	//타일 생성
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 13; ++j)
		{
			Tile* tile = new Tile;
			tile->Init();
			tile->SetPos(20 + i * 40, 40 + 40 * j);
			ObjectManager::GetInstance()->AddObject(tile, OBJTYPE::TILE);
		}
	}
}

void SceneTool::Update()
{
	ObjectManager::GetInstance()->Update();
}

void SceneTool::LateUpdate()
{
}

void SceneTool::Render(HDC hdc)
{
	ObjectManager::GetInstance()->Render(hdc);
}

void SceneTool::Release()
{
}
