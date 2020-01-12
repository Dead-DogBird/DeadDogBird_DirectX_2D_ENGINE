#include "stdafx.h"
#include "Test2.h"

Test2::Test2()
{
}


Test2::~Test2()
{
}

void Test2::Awake()
{
	SetTexture("Resource/car1.png", D3DXVECTOR2(256, 128));
	shadow = ObjectManager::Instantiate<Shadow>(D3DXVECTOR2(position.x, position.y));
	shadow->transform.scale.x = 1.5;
	//collid.GetComponent(this, D3DXVECTOR2(100, 10));
}

void Test2::Update()
{
	transform.index +=0.05+Test::playerSpeed / 100;
	if (transform.index > 5)
		transform.index = 0;

	position = Test::playerPosition +D3DXVECTOR2((Test::playerScale==1)?-20:20,50);
	transform.scale.x = Test::playerScale;
	shadow->position = D3DXVECTOR2(position.x, position.y + 50);

	if (GetAsyncKeyState(VK_SPACE))
	{
		Camera::Shake(30, 30, 0, 0.8, 10);
	}
}

void Test2::LateUpdate()
{
}
