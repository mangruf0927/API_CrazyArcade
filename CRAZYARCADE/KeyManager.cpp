#include "KeyManager.h"

int arrVK[(int)KEY::LAST] = { VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, VK_SPACE, VK_RETURN, VK_ESCAPE, VK_LBUTTON };


void KeyManager::Init()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		vecKey.push_back(KeyInfo{ KEYSTATE::NONE, false });
	}
}

void KeyManager::Update()
{
	for (int i = 0; i < (int)KEY::LAST; ++i)
	{
		if (GetAsyncKeyState(arrVK[i]) & 0x8000)
		{
			if (vecKey[i].prevPush)
				vecKey[i].state = KEYSTATE::HOLD;
			else
				vecKey[i].state = KEYSTATE::TAP;

			vecKey[i].prevPush = true;
		}
		else
		{
			if (vecKey[i].prevPush)
				vecKey[i].state = KEYSTATE::AWAY;
			else
				vecKey[i].state = KEYSTATE::NONE;

			vecKey[i].prevPush = false;
		}
	}
}
