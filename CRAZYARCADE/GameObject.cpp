#include "GameObject.h"

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::Init()
{
}

void GameObject::Update()
{
}

void GameObject::LateUpdate()
{
}

void GameObject::Render(HDC hdc)
{
}

void GameObject::Release()
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
