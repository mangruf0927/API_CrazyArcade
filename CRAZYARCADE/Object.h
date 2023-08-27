#pragma once
#include "framework.h"
#include "define.h"
#include "ObjectManager.h"
//#include "Collider.h"

class Object
{
protected:
	FRAME frame;
	OBJINFO info;

	//Collider* collider;

public:
	Object();
	virtual ~Object();

	virtual void Init() = 0; 
	virtual void Update() = 0; 
	virtual void LateUpdate() final; // 최종 업데이트
	virtual void Render(HDC hdc) = 0; 
	virtual void Release() = 0; 

	void UpdateFrame(HWND hWnd);
	
	const OBJINFO& GetInfo() { return info; }
	
	void SetPos(float x, float y) { info.posX = x, info.posY = y; }
	float GetPos() { return info.posX, info.posY; }
	
	void SetSize(float x, float y) { info.sizeX = x, info.sizeY = y; }
	float GetSize() { return info.sizeX, info.sizeY; }

	//void CreateCollider();

};

