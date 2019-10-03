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

	//�e�N�X�`���̃��[�h
	bool LoadTexture(string _path, string _name);

	//�e�N�X�`���̃����[�X
	void Release(void);

	//�e�N�X�`���C���^�[�t�F�[�X�̏K��
	LPDIRECT3DTEXTURE9 GetTexture();
	void SetTexture(LPDIRECT3DTEXTURE9 _texture);

	void SetWidth(int _width);
	void SetHeight(int _height);

	int GetWidth();
	int GetHeight();//�摜�T�C�Y�̏K��

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

