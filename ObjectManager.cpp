#include "stdafx.h"
#include "ObjectManager.h"
#include "GameObject.h"
list<GameObject *>ObjectManager::object_list=list<GameObject *>();
ObjectManager::ObjectManager()
{
}
ObjectManager::~ObjectManager()
{
}

bool ObjectManager::SortObject(const GameObject * a, const GameObject * b)
{
	return a->texture_layer > b->texture_layer;
}

void ObjectManager::sort()
{
	object_list.sort(SortObject);
}

void ObjectManager::Update()
{
	Camera::Update();
	list<GameObject *>::iterator it = object_list.begin();
	while (it != object_list.end()
		)
	{
		GameObject* inst = it._Ptr->_Myval;
		if (inst->destroy)
		{
			object_list.erase(it++);
			delete(inst);
			continue;
		}
		inst->Update();
		it++;
	}
}

void ObjectManager::LateUpdate()
{
	for (auto inst : object_list)
	{
		inst->LateUpdate();
	}
}

void ObjectManager::Render()
{
	for (auto inst : object_list)
	{
		inst->Draw();
	}
}

void ObjectManager::Clear()
{
	for (GameObject * inst: object_list)
	{
		inst->destroy = true;
	}
}
