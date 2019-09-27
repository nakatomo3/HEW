#pragma once
#include "Singleton.h"
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>
#include <Windows.h>

#define	NUM_KEY_MAX	(256)	// �L�[�̍ő吔

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
	LPDIRECTINPUT8			input = NULL;					// DirectInput�I�u�W�F�N�g�ւ̃|�C���^
	LPDIRECTINPUTDEVICE8	DevKeyboard = NULL;				// ���̓f�o�C�X(�L�[�{�[�h)�ւ̃|�C���^
	BYTE					KeyState[NUM_KEY_MAX];			// �L�[�{�[�h�̓��͏�񃏁[�N
	BYTE					KeyStateDown[NUM_KEY_MAX];	// �L�[�{�[�h�̃g���K�[��񃏁[�N
	BYTE					KeyStateUp[NUM_KEY_MAX];	// �L�[�{�[�h�̃����[�X��񃏁[�N

	bool InitInput(HINSTANCE hInstance);
	void UninitInput();

	bool InitKeyboard(HINSTANCE hInstance, HWND hWnd);
	void UninitKeyboard();

	Input();
	~Input();
};

