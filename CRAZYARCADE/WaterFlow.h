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
	
	void SetCenter() { centerPos.x = info.posX + info.sizeX * 0.5f, centerPos.y = info.posY + info.sizeY * 0.5f; }
	void SetRect() { rect.left = centerPos.x - 20, rect.right = centerPos.x + 20, rect.top = centerPos.y - 20, rect.bottom = centerPos.y + 20; }
};
