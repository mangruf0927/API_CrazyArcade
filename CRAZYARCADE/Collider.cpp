#include "Collider.h"
#include "Object.h"


Collider::Collider()
{
}

Collider::~Collider()
{
}

bool Collider::CheckCollision(vector<Object*> _obj1, vector<Object*> _obj2)
{
	RECT rect;
	for (auto& obj1 : _obj1)
	{
		for (auto& obj2 : _obj2)
		{
			if (IntersectRect(&rect, &obj1->GetRect(), &obj2->GetRect()) != 0)
			{
				return true;
			}
		}
	}
	return false;

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
	//float moveX = 0.1f, moveY = 0.1f;

	//RECT rect;
	//for (auto& obj1 : _obj1)
	//{
	//	for (auto& obj2 : _obj2)
	//	{
	//		if (IntersectRect(&rect, &obj1->GetRect(), &obj2->GetRect()))
	//		{
	//			if (obj1->GetInfo().posY < obj2->GetInfo().posY)
	//			{
	//				obj1->SetPos(obj1->GetPos(), obj1->GetInfo().posY - moveY);
	//			}
	//			else
	//			{
	//				obj1->SetPos(obj1->GetInfo().posX, obj1->GetInfo().posY + moveY);
	//			}


	//			if (obj1->GetInfo().posX < obj2->GetInfo().posX)
	//			{
	//				obj1->SetPos(obj1->GetInfo().posX - moveX, obj1->GetInfo().posY);
	//			}
	//			else
	//			{
	//				obj1->SetPos(obj1->GetInfo().posX + moveX, obj1->GetInfo().posY);
	//			}

	//		}
	//	}


	float moveX, moveY;


	for (auto& obj : _obj1)
	{
		if (CheckRect(obj, player, &moveX, &moveY))
		{
			cout << "충돌했다" << endl;

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




//bool Collider::CheckCollision(vector<Object*> _obj1, vector<Object*> _obj2)
//{
//	RECT rt = {};
//
//	for (auto& obj1 : _obj1)
//	{
//		for (auto& obj2 : _obj2)
//		{
//			if (IntersectRect(&rt, &obj1->GetRect(), &obj2->GetRect()) != 0)
//			{
//				return true;
//			}
//			else
//			{
//				return false;
//			}
//		}
//	}
//}