#include "stdafx.h"
#include "GameObject.h"


GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::SetTexture(string path, D3DXVECTOR2 size)
{
	transform.texture = TextureManager::LoadTexture(path);
	transform.size = size;
	transform.center = size / 2;
}
