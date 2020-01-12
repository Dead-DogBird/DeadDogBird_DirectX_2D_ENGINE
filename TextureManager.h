#pragma once
#include "stdafx.h"
class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	static map<string, LPDIRECT3DTEXTURE9> texture_map;
	static LPDIRECT3DTEXTURE9 LoadTexture(string path);
};

