#pragma once
#include "Singleton.h"
#include<windows.h>
#include<d3dx9.h>
#include<dxerr.h>
#include<math.h>


class MyDirect3D : public Singleton<MyDirect3D> {
public:
	friend class Singleton<MyDirect3D>;

	LPDIRECT3DDEVICE9 GetDevice();

	bool Init(HWND hwnd);
	void Uninit();

private:
	LPDIRECT3D9 D3D = NULL;
	LPDIRECT3DDEVICE9 D3DDevice = NULL;

	MyDirect3D();
	~MyDirect3D();
};