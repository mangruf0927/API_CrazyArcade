#pragma once
#include "framework.h"
#include "enum.h"

class GameObject; 
class Scene // ������Ʈ �����ϴ� Ŭ����
{
private:
	vector<GameObject*> objects[(UINT)OBJTYPE::END]; 
	wstring sceneName;

public:
	Scene();
	virtual ~Scene();

	virtual void Enter() = 0; // �ش� Scene�� ���� �� ȣ��
	virtual void Exit() = 0; // �ش� Scene�� Ż���� �� ȣ��

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render(HDC hdc) = 0;
	virtual void Release() = 0;

	void addObject(GameObject* obj, OBJTYPE type);
	void SetName(const wstring& _strName) { sceneName = _strName; }
	const wstring& GetName() { return sceneName; }
};

