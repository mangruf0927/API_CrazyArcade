#pragma once
#include "framework.h"
#include "enum.h"
#include "define.h"

class Object;
class ObjectManager
{
	SINGLETONE(ObjectManager)
private:
	vector<Object*> objects[(UINT)OBJTYPE::END];

public:
	ObjectManager();
	~ObjectManager();

	void Update();
	void LateUpdate();
	void Render(HDC hDC);
	void Release();
	
	void AddObject(Object* obj, OBJTYPE type);
};