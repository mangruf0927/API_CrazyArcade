#pragma once
#include "GameObject.h"

// 56 X 54
class WaterBalloon : public GameObject
{
private:
	const TCHAR* frameKey; // ��ǳ�� ���� 
	unsigned long BoomTime;

public:
	WaterBalloon();
	~WaterBalloon();

	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

};
