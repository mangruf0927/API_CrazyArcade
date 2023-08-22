#pragma once
#include "framework.h"
#include "define.h"

enum class KEYSTATE
{
	NONE, // ������ �ʾҰ�, �������� ������ ���� ����
	TAP, // �� ���� ����
	HOLD, // ������ �ִ�
	AWAY // �� �� ����
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
	KEYSTATE state; // Ű�� ���°�
	bool prevPush; // ���� �����ӿ��� ���ȴ��� ����
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

