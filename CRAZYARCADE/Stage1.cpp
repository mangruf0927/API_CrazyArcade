#include "Stage1.h"
#include "GameObject.h"
#include "Player.h"

Stage1::Stage1()
{
}

Stage1::~Stage1()
{
}

void Stage1::Enter()
{
	// Object Ãß°¡ 
	GameObject* obj = new Player;
	obj->GetPos();
	addObject(obj, OBJTYPE::PLAYER);
}

void Stage1::Exit()
{
}

void Stage1::Init()
{
}

void Stage1::Update()
{
}

void Stage1::LateUpdate()
{
}

void Stage1::Render(HDC hdc)
{
}

void Stage1::Release()
{
}
