#pragma once
#include "Object.h"

class WaterFlow :public Object
{
private:
	const TCHAR* waveDir;
	int wavePower;
	//enum DIR { up, down, left, right, upEdge, downEdge, leftEdge, rightEdge };
 	unsigned long waveTime;

public:
	WaterFlow();
	~WaterFlow();

	virtual void Init() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void SetWavePower(int power) { wavePower = power; }
};
