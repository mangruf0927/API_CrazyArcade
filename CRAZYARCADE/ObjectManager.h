#pragma once
#include "framework.h"
#include "enum.h"

class GameObject;
class ObjectManager
{
private:
	static ObjectManager* Instance;
	vector<GameObject*> objects[(UINT)OBJTYPE::END];

public:
	ObjectManager();
	~ObjectManager();

	void Update();
	void LateUpdate();
	void Render(HDC hDC);
	void Release();
	
	void AddObject(GameObject* obj, OBJTYPE type);

	static ObjectManager* GetInstance()
	{
		if (nullptr == Instance)
			Instance = new ObjectManager;

		return Instance;
	}
	static void DestoryInstance()
	{
		if (Instance)
		{
			delete Instance;
			Instance = nullptr;
		}
	}

};