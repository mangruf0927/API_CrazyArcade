#pragma once
#include "Object.h"

class Tile : public Object
{
private :
	bool isPass; // 통과 가능한가?
	bool isBroken; // 부서지나?
	bool isPush; // 밀리는가?

	TCHAR* FrameKey;

public :
	Tile();
	~Tile();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void SetIsPass(bool pass) { isPass = pass; }
	void SetIsBroken(bool broken) { isBroken = broken; }
	void SetIsPush(bool push) { isPush = push; }

	bool GetIsPass() { return isPass; }
	bool GetIsBroken() { return isBroken; }
	bool GetIsPush() { return isPush; }

	POINT GetTilePos();
};

