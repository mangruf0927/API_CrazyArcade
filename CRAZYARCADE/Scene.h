#pragma once
#include "framework.h"
#include "enum.h"

class Object;
class Scene
{
private:
	wstring sceneName;

public:
	Scene();
	virtual ~Scene();

	virtual void Init() = 0; 
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0; 

	void SetName(const wstring& _strName) { sceneName = _strName; }
	const wstring& GetName() { return sceneName; }
};

