#include "stdafx.h"
#include "Bullet.h"



Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}

void Bullet::Awake()
{
	SetTexture("Resource/bullyat.png", D3DXVECTOR2(128, 64));
}

void Bullet::Update()
{
	position.x += 80;
}

void Bullet::LateUpdate()
{
}
