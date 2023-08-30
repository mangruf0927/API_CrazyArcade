#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

void Object::LateUpdate()
{

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



