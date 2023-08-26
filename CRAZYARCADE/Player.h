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
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void CreateBalloon();
	//enum state {IDLE, UP, RIGHT, LEFT, DOWN, BUBBLE, DEAD, ALIVE};
};

