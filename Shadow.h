#pragma once
#include "GameObject.h"
class Shadow :
	public GameObject
{
public:
	Shadow();
	~Shadow();
	void Awake();
	void Update();
	void LateUpdate();
};

