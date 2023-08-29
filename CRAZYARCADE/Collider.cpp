#include "Collider.h"
#include "Object.h"


Collider::Collider()
{
}

Collider::~Collider()
{
}

bool Collider::CheckRect(Object* obj1, Object* obj2, float* x, float* y)
{
	float distanceX = abs(obj1->GetInfo().posX - obj2->GetInfo().posX);
	float distanceY = abs(obj1->GetInfo().posY - obj2->GetInfo().posY);

	float RadiusX = (obj1->GetInfo().sizeX * 0.5f) + (obj2->GetInfo().sizeX * 0.5f);
	float RadiusY = (obj1->GetInfo().sizeY * 0.5f) + (obj2->GetInfo().sizeY * 0.5f);

	if (distanceX <= RadiusX && distanceY <= RadiusY)
	{
		*x = RadiusX - distanceX;
		*y = RadiusY - distanceY;
		return true;
	}
	return false;
}

void Collider::CollisionRect(Object* player, vector<Object*> vecBlock)
{
}

