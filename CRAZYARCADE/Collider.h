#pragma once
#include "framework.h"

class Object;
class Collider
{
private :
	Object* owner; // collider�� �����ϰ� �ִ� ������Ʈ
	_POINTFLOAT offsetPos; //������Ʈ�κ��� ������� ��ġ
	_POINTFLOAT finalPos; //���� ��ġ

public:
	friend class Object;

	Collider();
	~Collider();
	void LateUpdate();
};

