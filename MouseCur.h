#pragma once
#include "GameObject.h"
class MouseCur :
	public GameObject
{
public:
	MouseCur();
	~MouseCur();
	void Awake();
	void Update();
};

