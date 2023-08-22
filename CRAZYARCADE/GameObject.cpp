#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}


void GameObject::UpdateFrame(HWND hWnd)
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
