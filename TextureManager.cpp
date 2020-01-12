#include "stdafx.h"
#include "TextureManager.h"

map<string, LPDIRECT3DTEXTURE9> TextureManager::texture_map=map<string, LPDIRECT3DTEXTURE9>();
TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
}

LPDIRECT3DTEXTURE9 TextureManager::LoadTexture(string path)
{
	LPDIRECT3DTEXTURE9 texture;
	if (texture_map.count(path))
	{

		printf("%s 재활용.\n", path.c_str());
		texture = texture_map.find(path)->second;
	}
	else
	{
		D3DXCreateTextureFromFileEx(GrapicManager::device,
			path.c_str(),
			D3DX_DEFAULT_NONPOW2,
			D3DX_DEFAULT_NONPOW2,
			1,
			0,
			D3DFMT_A8R8G8B8,
			D3DPOOL_MANAGED,
			D3DX_FILTER_NONE,
			D3DX_DEFAULT,
			0,
			NULL,
			NULL,
			&texture);

		texture_map[path] = texture;

		printf("%s 불러오기 성공\n", path.c_str());
	}
	if(texture==NULL)
		printf("불러오기 실패\n");
	return texture;
}
