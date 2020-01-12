#include "stdafx.h"
#include "Camera.h"
D3DXVECTOR2 Camera::position = D3DXVECTOR2(0, 0);
float Camera::scale = 1;
float Camera::rotation = 0;

float Camera::shake_x=0;
float Camera::shake_y=0;
float Camera::shake_dire=0;
float Camera::size=1;
float Camera::length=15;
Camera::Camera()
{
}


Camera::~Camera()
{
}

D3DXMATRIX Camera::GetMatrix()
{
	D3DXMATRIX mat, mat_rotation, mat_scale, mat_position, screen;

	D3DXMatrixTranslation(&mat_position, -(int)position.x, -(int)position.y, 0);
	D3DXMatrixRotationZ(&mat_rotation, D3DXToRadian(rotation));
	D3DXMatrixScaling(&mat_scale, 1 / scale, 1 / scale, 0);
	D3DXMatrixTranslation(&screen, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);

	mat = mat_position * mat_scale * mat_rotation * screen;

	return mat;
}

void Camera::Update()
{
	position = D3DXVECTOR2(RangeRandom(-shake_x, shake_x), RangeRandom(-shake_y, shake_y));
	rotation = RangeRandom(-shake_dire, shake_dire);
	scale =size;

	shake_x -= shake_x / length;
	shake_y -= shake_y / length;
	shake_dire -= shake_dire / length;
	size += (1 - size) / length;
}

void Camera::Shake(float x, float y, float dire, float Size, float Length)
{
	shake_x = x;
	shake_y = y;
	shake_dire = dire;
	size = Size;
	length = Length;
}

float Camera::RangeRandom(float min, float max)
{
	return (min + (rand()%(int)(max - min + 1)));
}
