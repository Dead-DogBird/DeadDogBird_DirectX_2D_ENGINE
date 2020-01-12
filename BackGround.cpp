#include "stdafx.h"
#include "BackGround.h"



BackGround::BackGround()
{
}


BackGround::~BackGround()
{
}

void BackGround::Awake()
{
	SetTexture("Resource/Background.png",D3DXVECTOR2(1920,1080));
	texture_layer = 20;
}

void BackGround::Update()
{
	position.x--;
	if (position.x < -1920)
		position.x =0;
}

void BackGround::LateUpdate()
{
}
