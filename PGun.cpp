#include "stdafx.h"
#include "PGun.h"
PGun::PGun()
{
}
PGun::~PGun()
{
}

void PGun::Awake()
{
	SetTexture("Resource/gun2.png", D3DXVECTOR2(180, 124));
}

void PGun::Update()
{
	if (GetAsyncKeyState(VK_LBUTTON)&&time>delay)
	{
		Instantiate<Bullet>(position);
		time = 0;
	}
	time++;
	//transform.rotation=
}
