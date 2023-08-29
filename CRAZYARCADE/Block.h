#pragma once
#include "object.h"
#include "enum.h"

class Block : public Object
{
private :
	const TCHAR* boxName;
	BLOCKTYPE blockType;
	bool isExist;
	bool isPush; 
	bool isBroken; 
	
public :
	Block();
	~Block();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


};

