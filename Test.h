#pragma once
#include "GameObject.h"
class PGun;
class Test :public GameObject
{
public:
	Test();
	~Test();
	static D3DXVECTOR2 playerPosition;
	static float playerScale;
	static float playerSpeed;
	PGun* gun;
	float vspeed=0, hspeed=0;
	void Awake();
	void Update();
	void move();
};

