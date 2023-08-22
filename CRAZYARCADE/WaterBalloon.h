#pragma once
#include "Object.h"

// 56 X 54
class WaterBalloon : public Object
{
private:
	const TCHAR* curState; // 물풍선 상태 
	unsigned long BoomTime;

public:
	WaterBalloon();
	~WaterBalloon();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

};
