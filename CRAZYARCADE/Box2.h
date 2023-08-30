#pragma once
#include "Object.h"

class Box2 : public Object
{
private:

public:
	Box2();
	~Box2();

	virtual void Init() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void SetRect() { rect.left = centerPos.x - 20, rect.right = centerPos.x + 20, rect.top = info.posY + info.sizeY - 47, rect.bottom = info.posY + info.sizeY - 7; }
};

