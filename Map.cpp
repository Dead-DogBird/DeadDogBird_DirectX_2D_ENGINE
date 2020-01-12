#include "stdafx.h"
#include "Map.h"



Map::Map()
{
}


Map::~Map()
{
}

void Map::Awake()
{
	SetTexture("Resource/Road.png", D3DXVECTOR2(1922,1080));
	oriTexture = transform.texture;
	subTexture = TextureManager::LoadTexture("Resource/Road2.png");

	texture_layer = 10;
	transform.texture = subTexture;
	//transform.center = D3DXVECTOR2(0,0);
}

void Map::Update()
{
	//if (Test::playerSpeed > 80)
		//transform.texture = subTexture;
	//else
		//transform.texture = oriTexture;
	position.x -= 60;
	if (position.x < -1920)
		position.x = 1910;

}

void Map::LateUpdate()
{
}
