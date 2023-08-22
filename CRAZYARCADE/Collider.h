#pragma once
#include "framework.h"

class Object;
class Collider
{
private :
	Object* owner; // collider를 소유하고 있는 오브젝트
	_POINTFLOAT offsetPos; //오브젝트로부터 상대적인 위치
	_POINTFLOAT finalPos; //최종 위치

public:
	friend class Object;

	Collider();
	~Collider();
	void LateUpdate();
};

