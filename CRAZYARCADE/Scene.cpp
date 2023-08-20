#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::addObject(GameObject* obj, OBJTYPE type)
{	
		objects[(UINT)type].push_back(obj);
}
