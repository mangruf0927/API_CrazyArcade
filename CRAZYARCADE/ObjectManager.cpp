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
	objects[(UINT)type].push_back(obj);
}

void ObjectManager::Update()
{
	for (UINT i = 0; i < (UINT)OBJTYPE::END; ++i)
	{
		for (size_t j = 0; j < objects[i].size(); ++j)
		{
			objects[i][j]->Update();
		}
	}
}

void ObjectManager::LateUpdate()
{
	for (UINT i = 0; i < (UINT)OBJTYPE::END; ++i)
	{
		for (size_t j = 0; j < objects[i].size(); ++j)
		{
			objects[i][j]->LateUpdate();
		}
	}
}

void ObjectManager::Render(HDC hdc)
{
	for (UINT i = 0; i < (UINT)OBJTYPE::END; ++i)
	{
		for (size_t j = 0; j < objects[i].size(); ++j)
		{
			objects[i][j]->Render(hdc);
		}
	}
}

void ObjectManager::Release()
{
	for (UINT i = 0; i < (UINT)OBJTYPE::END; ++i)
	{
		for (size_t j = 0; j < objects[i].size(); ++j)
		{
			delete objects[i][j];
		}
	}
}
