#pragma once
#include "framework.h"
#include "enum.h"

class GameObject; 
class Scene // 오브젝트 관리하는 클래스
{
private:
	vector<GameObject*> objects[(UINT)OBJTYPE::END]; 
	wstring sceneName;

public:
	Scene();
	virtual ~Scene();

	virtual void Enter() = 0; // 해당 Scene에 진입 시 호출
	virtual void Exit() = 0; // 해당 Scene을 탈출할 시 호출

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;

	void addObject(GameObject* obj, OBJTYPE type);
	void SetName(const wstring& _strName) { sceneName = _strName; }
	const wstring& GetName() { return sceneName; }
};

