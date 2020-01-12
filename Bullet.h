#pragma once
#include "GameObject.h"
class Bullet :
	public GameObject
{
public:
	Bullet();
	~Bullet();
	float toAngle;
	void Awake();
	void Update();
	void LateUpdate();
	D3DXVECTOR2 VectorRotation(float _angle) 
	{
		///겜메 Length_x,y
		//반전화
		_angle -= 90;
		_angle *= -1;
		if (_angle < 0)
			_angle += 360;

		return D3DXVECTOR2(sin(D3DXToRadian(_angle)), cos(D3DXToRadian(_angle)));
	}
};

