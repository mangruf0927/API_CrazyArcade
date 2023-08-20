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

	virtual void Init(); // �ʱ�ȭ�� �Լ�
	virtual void Update(); // ��ü���� ������ üũ�� �Լ� 
	virtual void LateUpdate(); // ���� �����̳� ������ �� �ʰ� ���ư����ϴ� �͵��� �� �Լ�. 
	virtual void Render(HDC hdc); // �׸� �׸� �Լ�. 
	virtual void Release(); // ���� �� �Լ�. 

	void UpdateFrame(HWND hWnd);
	void SetPos(_POINTFLOAT objPos) { objPos = Pos; }
	void SetPos(int x, int y) { Pos.x = x, Pos.y = y; }
	_POINTFLOAT GetPos() { return Pos; }

};

