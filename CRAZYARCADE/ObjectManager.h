#pragma once
#include "framework.h"
#include "enum.h"
#include "define.h"

class GameObject;
class ObjectManager
{
	SINGLETONE(ObjectManager)
private:
	vector<GameObject*> objects[(UINT)OBJTYPE::END];

public:
	ObjectManager();
	~ObjectManager();

	void Update();
	void Render(HDC hDC);
	void Release();
	
	void AddObject(GameObject* obj, OBJTYPE type);
};