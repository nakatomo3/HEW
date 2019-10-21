#include "Texture.h"
#include "LogWriter.h"
#include <d3d.h>
#include <d3dx9.h>

Texture::Texture(string _path, int _width, int _height, string _name) {
	path = _path;
	name = _name;
	width = _width;
	height = _height;
	LoadTexture(_path, _name);
}


Texture::~Texture() {
}

bool Texture::LoadTexture(string _path, string _name) {
	if (path.size() == 0) {
		return false;
	}
	if (FAILED(D3DXCreateTextureFromFile(MyDirect3D::GetInstance().GetDevice(), path.c_str(), &texture))) {
		LogWriter::GetInstance().LogWorning("テクスチャの生成に失敗しました。パス：%s", path.c_str());
		return false;
	}
	LogWriter::GetInstance().Log("テクスチャの生成に成功しました。パス：%s", path.c_str());
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
