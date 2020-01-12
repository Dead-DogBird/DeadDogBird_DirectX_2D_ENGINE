#include "stdafx.h"
#include "Shadow.h"

Shadow::Shadow()
{
}


Shadow::~Shadow()
{
}

void Shadow::Awake()
{
	SetTexture("Resource/shadow.png", D3DXVECTOR2(128, 64));
	texture_layer = 1;
}

void Shadow::Update()
{
}

void Shadow::LateUpdate()
{
}
