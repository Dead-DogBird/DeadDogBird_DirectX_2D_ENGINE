#pragma once
#include "GameObject.h"
class Map :
	public GameObject
{
public:
	Map();
	~Map();
	LPDIRECT3DTEXTURE9 subTexture,oriTexture;
	void Awake();
	void Update();
	void LateUpdate();
};

