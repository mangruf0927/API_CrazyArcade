#include "Collider.h"
#include "Object.h"
#include "Player.h"


Collider::Collider()
{
}

Collider::~Collider()
{
}


bool Collider::CheckRect(Object* obj1, Object* obj2, float* x, float* y)
{
	float distX = abs(obj1->GetCenter().x - obj2->GetCenter().x);
	float distY = abs(obj1->GetCenter().y - obj2->GetCenter().y);
	
	float rX = (abs(obj1->GetRect().right - obj1->GetRect().left)*0.5f) + (abs(obj2->GetRect().right - obj2->GetRect().left) * 0.5f);
	float rY = (abs(obj1->GetRect().bottom - obj1->GetRect().top) * 0.5f) + (abs(obj2->GetRect().bottom - obj2->GetRect().top) * 0.5f);

	if (rX >= distX && rY >= distY)
	{
		*x = rX - distX;
		*y = rY - distY;
		return true;
	}
	return false;
}


void Collider::CollisionRect(vector<Object*> _obj1, Object* player)
{
	float moveX = 0.1f, moveY = 0.1f;

	for (auto& obj : _obj1)
	{
		if (CheckRect(obj, player, &moveX, &moveY))
		{
			float x = player->GetInfo().posX;
			float y = player->GetInfo().posY;

			if (moveX > moveY)
			{
				if (player->GetInfo().posY < obj->GetInfo().posY)
				{
					player->SetPos(x, y - moveY);
				}
				else
				{
					player->SetPos(x, y + moveY);
				}
			}
			else
			{
				if (player->GetInfo().posX < obj->GetInfo().posX)
				{
					player->SetPos(x - moveX, y);
				}
				else
				{
					player->SetPos(x + moveX, y);
				}
			}
		}
	}
}

void Collider::CollisionWave(vector<Object*> obj1, vector<Object*> obj2, OBJTYPE type1, OBJTYPE type2)
{
	RECT rc = {};

	for (auto& OBJ1 : obj1)
	{
		for (auto& OBJ2 : obj2)
		{
			if (IntersectRect(&rc, &OBJ1->GetRect(), &OBJ2->GetRect()))
			{
				if (type1 == OBJTYPE::FLOW && type2 == OBJTYPE::PLAYER)
				{
					dynamic_cast<Player*>(OBJ2)->SetBubbleState();
				}

				if (type1 == OBJTYPE::FLOW && type2 == OBJTYPE::BOX)
				{
					OBJ2->SetDead();
				}
			}

		}
	}
}


