#pragma once
#include "framework.h"
#include "enum.h"

class Object;
class Collider
{
private :

public:
	Collider();
	~Collider();

	static bool CheckRect(Object* obj1, Object* obj2, float* x, float* y);	
	static void CollisionRect(vector<Object*> _obj1, Object* player);

	static void CollisionWave(vector<Object*> obj1, vector<Object*> obj2, OBJTYPE type1, OBJTYPE type2);
};
 
