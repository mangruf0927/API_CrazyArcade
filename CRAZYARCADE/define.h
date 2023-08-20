#pragma once

struct FRAME
{
	int Start;
	int Cur;
	int End;

	unsigned long Speed;
	unsigned long Timer;
};

template<typename T>
void SafeDelete(T& obj) {
	if (obj)
	{
		delete obj;
		obj = nullptr;
	}
}