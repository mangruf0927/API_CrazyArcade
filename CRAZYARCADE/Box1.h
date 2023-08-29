#pragma once
#include "Object.h"

class Box1 : public Object
{
private:

public :
	Box1();
	~Box1();

	virtual void Init() override;
	virtual int Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

