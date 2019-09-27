#pragma once
#include <memory>
#include <d3d9.h>

bool Init();
void Update();
void Uninit();
void Draw();

// ウィンドウプロシージャ(コールバック関数)
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);