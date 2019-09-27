#pragma once
#include "Singleton.h"
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>
#include <Windows.h>

#define	NUM_KEY_MAX	(256)	// キーの最大数

class Input : public Singleton<Input> {
public:

	friend class Singleton<Input>;

	void Init(HINSTANCE hInstance, HWND hWnd);
	void Uninit();

	void Update();

	bool GetKey(int key);
	bool GetKeyDown(int key);
	bool GetKeyUp(int key);

private:
	LPDIRECTINPUT8			input = NULL;					// DirectInputオブジェクトへのポインタ
	LPDIRECTINPUTDEVICE8	DevKeyboard = NULL;				// 入力デバイス(キーボード)へのポインタ
	BYTE					KeyState[NUM_KEY_MAX];			// キーボードの入力情報ワーク
	BYTE					KeyStateDown[NUM_KEY_MAX];	// キーボードのトリガー情報ワーク
	BYTE					KeyStateUp[NUM_KEY_MAX];	// キーボードのリリース情報ワーク

	bool InitInput(HINSTANCE hInstance);
	void UninitInput();

	bool InitKeyboard(HINSTANCE hInstance, HWND hWnd);
	void UninitKeyboard();

	Input();
	~Input();
};

