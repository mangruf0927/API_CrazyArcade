#pragma once
#include "Object.h"
#include "enum.h"


class BoxObject : public Object
{
private:
	BLOCKTYPE blockType;

public :
	BoxObject();
	~BoxObject();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;
};

