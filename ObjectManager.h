#pragma once
#include <iostream>
#include <list>
#include "Layer.h"
class GameObject;

class ObjectManager
{
public:
	static std::list<GameObject*> objectList;
	static std::list<GameObject*> colliderList;

	template<typename T>
	static T* Instantiate(D3DXVECTOR2 position = { 0,0 });

	static void Update();
	static void LateUpdate();
	static void Render();
	static void Release();
	static void Clear();

	static GameObject* ColliderCheck(RECT* objRect, int layer = Layer::DEFAULT);
};

bool Sort(const GameObject* a, const GameObject* b);

template<typename T>
inline T* ObjectManager::Instantiate(D3DXVECTOR2 position)
{
	T* inst = new T;

	objectList.push_back(inst);
	inst->Init();
	inst->position = position;
	objectList.sort(Sort);

	return inst;
}
