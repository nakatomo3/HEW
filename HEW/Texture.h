#pragma once
#include <d3d9.h>
#include <string>
#include "MyDirect3D.h"
#include "Setting.h"
using namespace std;

class Texture {
public:
	Texture(string _path, string _name = "newTexture");

	//�e�N�X�`���̃��[�h
	bool LoadTexture(string _path, string _name);

	//�e�N�X�`���̃����[�X
	void Release();

	//�e�N�X�`���C���^�[�t�F�[�X�̏K��
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

