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
	vector<Object*> blocks[(UINT)BLOCKTYPE::END];

public:
	ObjectManager();
	~ObjectManager();

	void Update();
	void LateUpdate();
	void Render(HDC hDC);
	void Release();
	
	void AddObject(Object* obj, OBJTYPE type);
	void AddBlock(Object* obj, BLOCKTYPE type);

	Object* GetPlayer() { return objects[(UINT)OBJTYPE::PLAYER].front(); }
	vector<Object*> GetObjects(OBJTYPE type) { return objects[(UINT)type]; }
};