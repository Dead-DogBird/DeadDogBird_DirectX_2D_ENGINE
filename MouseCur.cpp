#include "stdafx.h"
#include "MouseCur.h"



MouseCur::MouseCur()
{
}


MouseCur::~MouseCur()
{
}

void MouseCur::Awake()
{
	SetTexture("Resource/mouse.png", D3DXVECTOR2(64,64));
	transform.camera_on = false;
	ShowCursor(false);
}

void MouseCur::Update()
{
	position =D3DXVECTOR2(InputManager::GetMousePosition().x, InputManager::GetMousePosition().y);
}
