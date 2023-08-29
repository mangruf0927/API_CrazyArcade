#pragma once
#include "framework.h"

class Object;
class Collider
{
private :
	Object* owner; // collider�� �����ϰ� �ִ� ������Ʈ
	POINT offsetPos; //������Ʈ�κ��� ������� ��ġ
	POINT finalPos; //���� ��ġ

public:
	friend class Object;

	Collider();
	~Collider();
	void LateUpdate();
};

