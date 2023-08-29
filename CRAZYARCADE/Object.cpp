#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
	/*if (nullptr != collider)
	{
		delete collider;
	}*/
}

void Object::LateUpdate()
{
	/*if (collider)
		collider->LateUpdate();*/
}

void Object::UpdateFrame(HWND hWnd)
{
	if (frame.Timer + frame.Speed < GetTickCount())
	{
		frame.Cur++;
		if (frame.Cur > frame.End)
		{
			frame.Cur = frame.Start;
		}
		frame.Timer = GetTickCount();

		InvalidateRect(hWnd, NULL, false);
	}
}

//void Object::CreateCollider()
//{
//	collider = new Collider;
//	collider->owner = this;
//}
