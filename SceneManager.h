#pragma once
class SceneManager
{
public:
	static enum scene {Test_s,Menu,Ingame};
	SceneManager();
	~SceneManager();
	static void LoadScene(scene);
	static void ReleseScene();
};

