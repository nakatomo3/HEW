#pragma once
#include <d3d9.h>
#include <string>
#include "MyDirect3D.h"
#include "Setting.h"
using namespace std;

class Texture {
public:
	Texture(string _path, string _name = "newTexture");

	//テクスチャのロード
	bool LoadTexture(string _path, string _name);

	//テクスチャのリリース
	void Release();

	//テクスチャインターフェースの習得
	LPDIRECT3DTEXTURE9 GetTexture();
	void SetTexture(LPDIRECT3DTEXTURE9 _texture);

	string GetName();
	string GetPath();

	void Destroy() {
		Release();
		delete this;
	}

private :
	LPDIRECT3DTEXTURE9 texture;

	string path;
	string name;

	~Texture();
};

