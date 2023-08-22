#pragma once
#include "framework.h"
#include "define.h"

class GameObject
{
protected:
	FRAME frame;
	_POINTFLOAT Pos;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Init() = 0; // 초기화할 함수
	virtual void Update() = 0; // 물체들의 변경점 체크할 함수 
	virtual void Render(HDC hdc) = 0; // 그림 그릴 함수. 
	virtual void Release() = 0; // 해제 할 함수. 

	void UpdateFrame(HWND hWnd);
	void SetPos(_POINTFLOAT objPos) { objPos = Pos; }
	void SetPos(int x, int y) { Pos.x = x, Pos.y = y; }
	_POINTFLOAT GetPos() { return Pos; }

};

