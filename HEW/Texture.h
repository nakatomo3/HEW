#pragma once
#include <d3d9.h>
#include <string>
#include "MyDirect3D.h"
#include "Setting.h"
using namespace std;

class Texture {
public:
	Texture();
	Texture(string _path, int width, int height, string _name = "newTexture");

	//テクスチャのロード
	bool LoadTexture(string _path, string _name);

	//テクスチャのリリース
	void Release(void);

	//テクスチャインターフェースの習得
	LPDIRECT3DTEXTURE9 GetTexture();
	void SetTexture(LPDIRECT3DTEXTURE9 _texture);

	void SetWidth(int _width);
	void SetHeight(int _height);

	int GetWidth();
	int GetHeight();//画像サイズの習得

	string GetName();
	string GetPath();

	void Destroy() {
		Release();
		delete this;
	}

private :
	LPDIRECT3DTEXTURE9 texture;

	int width, height;

	string path;
	string name;

	~Texture();
};

