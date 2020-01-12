#pragma once
#include "BoxCollider.h"
class GameObject
{
public:
	GameObject();
	~GameObject();
	Transform transform;
	D3DXVECTOR2 position = D3DXVECTOR2(0, 0);
	BoxCollider collid;
	bool destroy = false;
	int texture_layer = 0;
	virtual void Awake()
	{
		return;
	}
	virtual void Update()
	{
		return;
	}
	virtual void LateUpdate()
	{
		return;
	}
	virtual void Draw()
	{
		return DrawSelf();
	}
	void DrawSelf()
	{
		if (!SUCCEEDED(GrapicManager::TextureRender(transform, position)))
			printf("드로우 에러!\n");
	}
	void SetTexture(string path, D3DXVECTOR2 size);

	template<class T>
	static T* Instantiate(D3DXVECTOR2 position)
	{
		return ObjectManager::Instantiate<T>(position);
	}
};

