#include "ObjectManager.h"
#include "GameObject.h"

ObjectManager::ObjectManager()
{
}

ObjectManager::~ObjectManager()
{
}

void ObjectManager::AddObject(GameObject* obj, OBJTYPE type)
{
	objects[(UINT)type].emplace_back(obj);
}

void ObjectManager::Update()
{
	for (UINT i = 0; i < (UINT)OBJTYPE::END; ++i)
	{
		for (auto& Obj : objects[i])
			Obj->Update();
	}
}


void ObjectManager::Render(HDC hdc)
{
	for (UINT i = 0; i < (UINT)OBJTYPE::END; ++i)
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
	for (UINT i = 0; i < (UINT)OBJTYPE::END; ++i)
	{
		for (auto& Obj : objects[i])
			objects[i].clear();
	}
}
