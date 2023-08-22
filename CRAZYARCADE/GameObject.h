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

	virtual void Init() = 0; // �ʱ�ȭ�� �Լ�
	virtual void Update() = 0; // ��ü���� ������ üũ�� �Լ� 
	virtual void Render(HDC hdc) = 0; // �׸� �׸� �Լ�. 
	virtual void Release() = 0; // ���� �� �Լ�. 

	void UpdateFrame(HWND hWnd);
	void SetPos(_POINTFLOAT objPos) { objPos = Pos; }
	void SetPos(int x, int y) { Pos.x = x, Pos.y = y; }
	_POINTFLOAT GetPos() { return Pos; }

};

