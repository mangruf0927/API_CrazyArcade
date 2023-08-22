#pragma once
#include "framework.h"
#include "define.h"

enum class KEYSTATE
{
	NONE, // 눌리지 않았고, 이전에도 눌리지 않은 상태
	TAP, // 막 누른 시점
	HOLD, // 누르고 있는
	AWAY // 막 뗀 시점
};

enum class KEY
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	SPACE,
	ENTER,
	ESC,
	LAST
};

struct KeyInfo
{
	KEYSTATE state; // 키의 상태값
	bool prevPush; // 이전 프레임에서 눌렸는지 여부
};

class KeyManager
{
	SINGLETONE(KeyManager);

private:
	vector<KeyInfo> vecKey;

public:
	void Init();
	void Update();

	KEYSTATE GetKeyState(KEY key) { return vecKey[(int)key].state; }
};

