#include "stdafx.h"
#include "BoxCollider.h"
list<GameObject *> BoxCollider::ColliderList = list<GameObject*>();
BoxCollider::BoxCollider()
{
}
BoxCollider::~BoxCollider()
{
}

GameObject * BoxCollider::CollidCheck(D3DXVECTOR2 collid, D3DXVECTOR2 position)
{
	for (GameObject* inst : BoxCollider::ColliderList)
	{
		if (inst->collid.enable == false)
			continue;

		if (position.x < inst->position.x + inst->collid.size.x / 2)
			if (position.x + collid.x > inst->position.x - inst->collid.size.x / 2)
				if (position.y < inst->position.y + inst->collid.size.y / 2)
					if (position.y + collid.y > inst->position.y - inst->collid.size.y / 2)
					{
						return inst;
					}
	}
	return nullptr;
}

GameObject * BoxCollider::PlaceMeeting(D3DXVECTOR2 vector,D3DXVECTOR2 position)
{	
	enable = false;
	GameObject* inst=CollidCheck(size, position + vector - size / 2);
	enable = true;

	return inst;
}

void BoxCollider::GetComponent(GameObject *inst, D3DXVECTOR2 SIZE, D3DXVECTOR2 CENTER)
{
	BoxCollider::ColliderList.push_back(inst);
	size = SIZE;
	center = CENTER;
}

