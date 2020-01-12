#pragma once
#include "stdafx.h"
#include <list>
using namespace std;
class GameObject;
class ObjectManager
{
public:
	ObjectManager();
	~ObjectManager();
	static list<GameObject *> object_list;

	template<class T>
	static T* Instantiate(D3DXVECTOR2 position = D3DXVECTOR2(0, 0))
	{
		T* inst = new T;

		object_list.push_back(inst);
		inst->Awake();
		inst->position = position;

		object_list.sort();
		//if (inst != NULL)
		//	printf("按眉 积己 己傍\n");
		//else
		//	printf("按眉 积己 角菩\n");

		sort();

		return inst;
	}
	static bool SortObject(const GameObject*  a, const GameObject*  b);
	static void sort();

	static void Update();
	static void LateUpdate();
	static void Render();
	static void Clear();
};

