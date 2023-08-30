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
	static bool CheckCollision(vector<Object*> _obj1, vector<Object*> _obj2);
	
	static void CollisionRect(vector<Object*> _obj1, Object* player);
};
 
