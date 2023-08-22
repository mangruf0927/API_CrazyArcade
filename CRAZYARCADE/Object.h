#pragma once
#include "framework.h"
#include "define.h"
//#include "Collider.h"

class Object
{
protected:
	FRAME frame;
	_POINTFLOAT Pos;

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
	void SetPos(_POINTFLOAT objPos) { objPos = Pos; }
	void SetPos(int x, int y) { Pos.x = x, Pos.y = y; }
	_POINTFLOAT GetPos() { return Pos; }

	//void CreateCollider();

};

