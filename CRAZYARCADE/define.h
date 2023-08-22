#pragma once

#define SINGLETONE(type) public : static type* GetInstance() { static type mgr; return &mgr; }

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