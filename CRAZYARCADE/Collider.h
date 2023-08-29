#pragma once
#include "framework.h"

class Object;
class Collider
{
private :

public:
	Collider();
	~Collider();


	static bool CheckRect(Object* obj1, Object* obj2, float* x, float* y);
	static void CollisionRect(Object* player, vector<Object*> vecBlock);

};

