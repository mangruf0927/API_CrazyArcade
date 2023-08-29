#pragma once
#include "Object.h"

class Monster : public Object
{
private :
	float Speed;
	const TCHAR* curState;

public :
	virtual void Init() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

