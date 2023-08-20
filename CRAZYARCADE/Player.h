#pragma once
#include "GameObject.h"

// 64 X 76
class Player :public GameObject
{
private:
	float Speed; // ¼Óµµ
	const TCHAR* frameKey;
	void KeyUpdate();

public:
	Player();
	virtual ~Player();

	virtual void Init() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render(HDC hdc) override;
	virtual void Release() override;

	void CreateBalloon();
};

