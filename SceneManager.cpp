#include "stdafx.h"
#include "SceneManager.h"



SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

void SceneManager::LoadScene(scene Toscene)
{
	ReleseScene();
	switch (Toscene)
	{
	case SceneManager::Test_s:
		ObjectManager::Instantiate<BackGround>(D3DXVECTOR2(0, 0));
		ObjectManager::Instantiate<Map>(D3DXVECTOR2(1920, 0));
		ObjectManager::Instantiate<Map>(D3DXVECTOR2(0, 0));
		ObjectManager::Instantiate<Test>(D3DXVECTOR2(-400, 100));
		ObjectManager::Instantiate<Test2>(D3DXVECTOR2(100, 0));
		ObjectManager::Instantiate<MouseCur>(D3DXVECTOR2(100, 0));
		break;
	case SceneManager::Menu:
		break;
	case SceneManager::Ingame:
		break;
	default:
		break;
	}
}

void SceneManager::ReleseScene()
{
	for (GameObject * inst : ObjectManager::object_list)
	{
		inst->destroy = true;
	}
}
