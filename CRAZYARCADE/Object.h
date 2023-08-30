#pragma once
#include "framework.h"
#include "define.h"
#include "ObjectManager.h"

class Object
{
protected:
	const TCHAR* objName;
	bool isDead;

	FRAME frame;
	OBJINFO info;
	
	BLOCKTYPE blockType;
	RECT rect;
	POINT centerPos;


public:
	Object();
	virtual ~Object();

	virtual void Init() = 0; 
	virtual int Update() = 0;
	virtual void LateUpdate() = 0; 
	virtual void Render(HDC hdc) = 0; 
	virtual void Release() = 0; 

	void UpdateFrame(HWND hWnd);
	//void UpdateRect();

	void SetObjName(const TCHAR* name) { objName = name; }

	const OBJINFO& GetInfo() { return info; }

	void SetPos(float x, float y) { info.posX = x, info.posY = y; }
	float GetPos() { return info.posX, info.posY; }
	
	void SetSize(float x, float y) { info.sizeX = x, info.sizeY = y; }
	float GetSize() { return info.sizeX, info.sizeY; }

	POINT GetCenter() { return centerPos; }
	RECT& GetRect() { return rect; }

	void SetDead() { isDead = true; }
	//bool GetDead() { return isDead; }
};

