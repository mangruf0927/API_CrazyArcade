#pragma once
#include "framework.h"
#include "enum.h"
#include "define.h"

class Object;
class ObjectManager
{
	SINGLETONE(ObjectManager)
private:
	vector<Object*> objects[OBJTYPE::END];

public:
	ObjectManager();
	~ObjectManager();

	void Update();
	void LateUpdate();
	void Render(HDC hDC);
	void Release();
	
	void AddObject(Object* obj, OBJTYPE type);

	/*void PickBlock(Object* obj, BLOCKTYPE blockType);
	void SaveBlock();
	void LoadBlock();*/
};