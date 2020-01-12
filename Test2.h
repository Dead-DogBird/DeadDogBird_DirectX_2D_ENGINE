#pragma once
#include "GameObject.h"
class Shadow;
class Test2 :
	public GameObject
{
public:
	Test2();
	~Test2();
	Shadow* shadow;
	void Awake();
	void Update();
	void LateUpdate();
};

