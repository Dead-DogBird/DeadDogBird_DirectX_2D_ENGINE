#include "stdafx.h"
#include "GrapicManager.h"

HWND GrapicManager::window=nullptr;
LPDIRECT3D9 GrapicManager::direct = nullptr;
LPDIRECT3DDEVICE9 GrapicManager::device = nullptr;
LPD3DXSPRITE GrapicManager::sprite = nullptr;
ID3DXFont* GrapicManager::font;

GrapicManager::GrapicManager()
{
}


GrapicManager::~GrapicManager()
{
}

void GrapicManager::Render()
{
	device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(255, 255, 255), 1.0f, 0);

	// Begin the scene
	if (SUCCEEDED(device->BeginScene()))
	{
		if (!SUCCEEDED(sprite->Begin(D3DXSPRITE_ALPHABLEND)))
			printf("스프라이트 에러! code:begin\n");

		ObjectManager::Render();

		// End the scene
		sprite->End();
		device->EndScene();
	}

	// Present the backbuffer contents to the display
	device->Present(NULL, NULL, NULL, NULL);

	return;

}

HRESULT GrapicManager::Init()
{
	if (NULL == (direct = Direct3DCreate9(D3D_SDK_VERSION)))
		return E_FAIL;

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = !FULLSCREEN;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;

	if (FAILED(direct->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &device)))
	{
		return E_FAIL;
	}


	//스프라이트 생성
	D3DXCreateSprite(device, &sprite);

	//폰트생성
	//if (FAILED(D3DXCreateFont(device, 70, 0, FW_BOLD, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, "경기천년제목V Bold", &font)))
		//exit(0);

	return E_NOTIMPL;
}

HRESULT GrapicManager::TextureRender(Transform info, D3DXVECTOR2 position)
{
	D3DXMATRIX mat, center, pos, scale, rotation;

	D3DXMatrixTranslation(&center, -info.center.x, -info.center.y, 0);
	D3DXMatrixTranslation(&pos, (int)position.x, (int)position.y, 0);
	D3DXMatrixScaling(&scale, info.scale.x, info.scale.y, 1);
	D3DXMatrixRotationZ(&rotation, D3DXToRadian(info.rotation));

	mat = center * scale * rotation * pos;

	if (info.camera_on == true)
		mat *= Camera::GetMatrix();
	if (!SUCCEEDED(sprite->SetTransform(&mat)))
		printf("트랜스폼 세팅 에러\n");

	//도트겜일경우 사용
	device->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_POINT);
	device->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
	device->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);
	
	RECT rect = RECT{ (LONG)(int)info.index * (LONG)info.size.x,0,(LONG)((int)info.index + 1) * (LONG)info.size.x,(LONG)info.size.y };
	return sprite->Draw(info.texture,&rect,NULL,NULL,info.color);
}

void GrapicManager::gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
