#pragma once
#include "framework.h"
#include "enum.h"

class GameObject; 
class Scene
{
private:
	wstring sceneName;

public:
	Scene();
	virtual ~Scene();

	virtual void Init() = 0; // 해당 Scene에 진입 시 호출
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0; // 해당 Scene을 탈출할 시 호출

	void SetName(const wstring& _strName) { sceneName = _strName; }
	const wstring& GetName() { return sceneName; }
};

