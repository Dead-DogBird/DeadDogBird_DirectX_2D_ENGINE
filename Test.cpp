#include "stdafx.h"
#include "Test.h"
#include "GameObject.h"
#include <conio.h>
D3DXVECTOR2 Test::playerPosition = D3DXVECTOR2(0,0);
float Test::playerScale = 0;
float Test::playerSpeed = 0;
Test::Test()
{
}


Test::~Test()
{
}

void Test::Awake()
{
	SetTexture("Resource/player.png", D3DXVECTOR2(129, 128));
	collid.GetComponent(this,D3DXVECTOR2(100, 100));
	gun = Instantiate<PGun>(D3DXVECTOR2(position.x, position.y));
	gun->texture_layer = -1;
	texture_layer = 1;
	system("cls");
}

void Test::Update()
{
	//if (GetAsyncKeyState('W'))
	//	Camera::scale -= Camera::scale * 0.02;
	//if (GetAsyncKeyState('S'))
	//	Camera::scale += Camera::scale * 0.02;
	move();
	transform.index += 0.1 + playerSpeed/100;
	if (transform.index > 3)
		transform.index = 0;
	playerPosition = position;
	playerScale = transform.scale.x;
	playerSpeed = fabs(hspeed);
	gun->position = D3DXVECTOR2(position.x+10, position.y+50);
	gun->transform.rotation = gun->PointDirection(gun->position, D3DXVECTOR2(InputManager::GetMousePosition().x, InputManager::GetMousePosition().y));
	GrapicManager::gotoxy(0, 10);
	printf("속도 : %.2f\n", playerSpeed);
	printf("x: %.2f  y: %.2f\n", position.x, position.y);
	printf("현재 총 각도 : %.2f", gun->transform.rotation);
}

void Test::move()
{
	if (GetAsyncKeyState('A'))
	{
		//if (hspeed > -50)
			hspeed +=(-30-hspeed)/5;
		//	transform.scale.x = -1;
	}

	if (GetAsyncKeyState('D'))
	{
		hspeed += (30 - hspeed) / 5;

		//transform.scale.x = 1;
	}

	if (GetAsyncKeyState('T'))
	{
		hspeed += (600 - hspeed) / 30;
	}
	if (GetAsyncKeyState('W'))
	{
		//if (vspeed > -50)
		//	vspeed -= 0.5f;
		vspeed += (-40 - vspeed) / 10;
	}

	if (GetAsyncKeyState('S'))
	{
		vspeed += (40 - vspeed) / 10;
	}

	if (GetAsyncKeyState(VK_ESCAPE))
		SceneManager::LoadScene(SceneManager::Menu);
	if (_kbhit() == 0)
	{
		vspeed -= vspeed / 5;
		hspeed -= hspeed / 5;
		transform.rotation = 0;
	}
	if (GetAsyncKeyState('Q'))
	{
		position = D3DXVECTOR2(0, 0);
	}
	if (position.y < -100)
		position.y = -100;
	if (position.y >438)
		position.y = 438;
	if (position.x < -863)
		position.x = -863;
	if (position.x > 933)
		position.x = 933;

	if (collid.PlaceMeeting(D3DXVECTOR2(hspeed, 0), position) != nullptr)
		hspeed = 0;
	if (collid.PlaceMeeting(D3DXVECTOR2(0, vspeed), position) != nullptr)
		vspeed = 0;

	position += D3DXVECTOR2(hspeed, vspeed);
	//Camera::position.x += ((playerPosition.x+400) - Camera::position.x) / 4;
}