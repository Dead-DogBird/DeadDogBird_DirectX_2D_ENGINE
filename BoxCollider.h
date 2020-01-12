#pragma once
class BoxCollider
{
public:
	BoxCollider();
	~BoxCollider();
	
	static list<GameObject *> ColliderList;
	
	D3DXVECTOR2 size;
	D3DXVECTOR2 center;
	
	bool enable=true;
	
	void GetComponent(GameObject *inst, D3DXVECTOR2 SIZE, D3DXVECTOR2 CENTER = D3DXVECTOR2(0, 0));
	
	GameObject* CollidCheck(D3DXVECTOR2 collider, D3DXVECTOR2 position);
	GameObject* PlaceMeeting(D3DXVECTOR2 vector, D3DXVECTOR2 position);
	
};

