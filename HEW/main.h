#pragma once
#include <memory>
#include <d3d9.h>

bool Init();
void Update();
void Uninit();
void Draw();

// �E�B���h�E�v���V�[�W��(�R�[���o�b�N�֐�)
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);