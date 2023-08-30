#include "ObjectManager.h"
#include "Object.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::AddObject(Object* obj, OBJTYPE type)
{
	objects[(UINT)type].emplace_back(obj);
}

void ObjectManager::AddBlock(Object* block, BLOCKTYPE type)
{
	blocks[(UINT)type].emplace_back(block);
}

void ObjectManager::Update()
{
	for (int i = 0; i < (UINT)OBJTYPE::END; ++i)
	{
		for (auto iter = objects[i].begin(); iter != objects[i].end();)
		{
			int iEvent = (*iter)->Update();
			if (iEvent == DEAD)
			{
				SafeDelete(*iter);
				iter = objects[i].erase(iter);
			}
			else
				++iter;
		}
	}
}

void ObjectManager::LateUpdate()
{
	for (int i = 0; i < (UINT)OBJTYPE::END; ++i)
	{
		for (auto& Obj : objects[i])
			Obj->LateUpdate();
	}
}


void ObjectManager::Render(HDC hdc)
{
	for (int i = 0; i < (UINT)OBJTYPE::END; ++i)
	{
		for (auto& Obj : objects[i])
		{
			if (!Obj) continue;
			Obj->Render(hdc);
		}
	}
}

void ObjectManager::Release()
{
	for (int i = 0; i < (UINT)OBJTYPE::END; ++i)
	{
		for (auto& Obj : objects[i])
			objects[i].clear();
	}
}
