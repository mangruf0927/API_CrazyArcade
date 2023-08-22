#pragma once
#include "Object.h"

class Tile : public Object
{
private :
	bool isPass; // ��� �����Ѱ�?
	bool isBroken; // �μ�����?
	bool isPush; // �и��°�?

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

