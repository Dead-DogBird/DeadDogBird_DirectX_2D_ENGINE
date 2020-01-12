#pragma once
#include "GameObject.h"
class PGun :
	public GameObject
{
public:
	PGun();
	~PGun();
	void Awake();
	void Update();
	float delay = 20;
	float time = 0;
	float rad2deg(float degree)
	{
		return degree * 180 / PI;
	}
	float PointDirection(D3DXVECTOR2 pos1, D3DXVECTOR2 pos2) {
		//점과 점사이의 각도를 알려줍니다
		D3DXVECTOR2 pos = pos2 - pos1;
		
		float angle = rad2deg(atan2(pos.y, pos.x));
	//	if (angle < 0)
		//a	angle += 360;
		return angle;
	}
};

