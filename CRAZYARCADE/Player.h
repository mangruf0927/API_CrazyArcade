#pragma once
#include "Object.h"

// 64 X 76
class Player :public Object
{
private:
	float Speed;  
	const TCHAR* curState;
	void KeyUpdate();
	DWORD dwTime;

public:
	Player();
	~Player();

	virtual void Init() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void CreateBalloon();
	
	
	void SetCenter() { centerPos.x = info.posX + info.sizeX * 0.5f, centerPos.y = info.posY + info.sizeY * 0.5f + 9 ; }
	void SetRect() { rect.left = centerPos.x - 16, rect.right = centerPos.x + 16, rect.top = centerPos.y - 16, rect.bottom = centerPos.y + 16; }
	void SetBubbleState() { curState = L"Trap"; }
	
	//enum state {IDLE, UP, RIGHT, LEFT, DOWN, BUBBLE, DEAD, ALIVE};
};

