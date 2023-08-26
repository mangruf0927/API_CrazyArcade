#pragma once
#include "object.h"

//struct BOXINFO
//{
//	int Width, Height; // 박스 크기
//	int Xbox, Ybox; // 박스 좌표
//	bool isPush; // 밀수 있는지
//	bool isBroken; // 사라지는지
//	bool isExist; // 존재하는지
//};


class Box : public Object
{
private :
	//BOXINFO* map[13][15]; // 맵 한 칸당 40 X 40
	const TCHAR* boxName;
	bool isPush; // 밀수 있는지
	bool isBroken; // 사라지는지
	bool isExist; // 존재하는지
	
public :
	Box();
	~Box();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


};

