#pragma once
#include "object.h"

//struct BOXINFO
//{
//	int Width, Height; // �ڽ� ũ��
//	int Xbox, Ybox; // �ڽ� ��ǥ
//	bool isPush; // �м� �ִ���
//	bool isBroken; // ���������
//	bool isExist; // �����ϴ���
//};


class Box : public Object
{
private :
	//BOXINFO* map[13][15]; // �� �� ĭ�� 40 X 40
	const TCHAR* boxName;
	bool isPush; // �м� �ִ���
	bool isBroken; // ���������
	bool isExist; // �����ϴ���
	
public :
	Box();
	~Box();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;


};

