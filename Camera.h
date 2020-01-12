#pragma once
#include "stdafx.h"
class Camera
{
public:
	Camera();
	~Camera();
	D3DXMATRIX CarmeraMatrix;

	static float shake_x;
	static float shake_y;
	static float shake_dire;
	static float size;
	static float length;

	static D3DXVECTOR2 position;
	static float scale;
	static float rotation;
	static D3DXMATRIX GetMatrix();
	static void Update();
	static void Shake(float x = 0, float y = 0, float dire = 0, float size = 1, float length = 10);
	static float RangeRandom(float min, float max);

};

