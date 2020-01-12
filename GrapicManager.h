#pragma once
#include "Transform.h"
class Transform;
class GrapicManager
{
public:
	GrapicManager();
	~GrapicManager();
	static HWND window;
	static LPDIRECT3D9 direct;
	static LPDIRECT3DDEVICE9 device;
	static LPD3DXSPRITE sprite;
	static ID3DXFont* font;

	static void Render();
	static HRESULT Init();
	static HRESULT TextureRender(Transform info, D3DXVECTOR2 position);
	static void gotoxy(int x, int y);
};

