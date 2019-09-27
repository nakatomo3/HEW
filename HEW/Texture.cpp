#include "Texture.h"
#include "LogWriter.h"
#include <d3d.h>
#include <d3dx9.h>

Texture::Texture() {
}


Texture::~Texture() {
}

bool Texture::LoadTexture(string _path, string _name) {
	if (path.size() == 0) {
		return false;
	}
	if (FAILED(D3DXCreateTextureFromFile(MyDirect3D::GetInstance().GetDevice(), path.c_str(), &texture))) {
		LogWriter::GetInstance().LogWorning("�e�N�X�`���̐����Ɏ��s���܂����B�p�X�F%s", path.c_str());
		return false;
	}
	LogWriter::GetInstance().Log("�e�N�X�`���̐����ɐ������܂����B�p�X�F%s", path.c_str());
	return true;
}

void Texture::Release(void) {
	delete this;
}

LPDIRECT3DTEXTURE9 Texture::GetTexture() {
	return texture;
}

void Texture::SetTexture(LPDIRECT3DTEXTURE9 _texture) {
	texture = _texture;
}

void Texture::SetWidth(int _width) {
	width = _width;
}

void Texture::SetHeight(int _height) {
	height = _height;
}

int Texture::GetWidth() {
	return width;
}

int Texture::GetHeight() {
	return height;
}

string Texture::GetName() {
	return name;
}

string Texture::GetPath() {
	return path;
}