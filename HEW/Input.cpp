#include "Input.h"
#include "LogWriter.h"

bool Input::InitInput(HINSTANCE hInstance) {
	if (input == NULL) {

		// DirectInput�I�u�W�F�N�g�̍쐬
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&input, NULL))) {

			return false;
		}
	}

	return true;
}

void Input::UninitInput() {
	if (input != NULL) {

		// DirectInput�I�u�W�F�N�g�̊J��
		input->Release();
		input = NULL;
	}
}

bool Input::InitKeyboard(HINSTANCE hInstance, HWND hWnd) {
	// ���͏����̏�����
	if (!InitInput(hInstance)) {
		MessageBox(hWnd, "DirectInput�I�u�W�F�N�g�����܂���ł���", "�x���I", MB_ICONWARNING);
		LogWriter::GetInstance().LogError("DirectInput�I�u�W�F�N�g�����܂���ł���");
		return false;
	}

	// �f�o�C�X�̍쐬
	if (FAILED(input->CreateDevice(GUID_SysKeyboard, &DevKeyboard, NULL))) {
		MessageBox(hWnd, "�L�[�{�[�h������܂���", "�x���I", MB_ICONWARNING);
		LogWriter::GetInstance().LogError("�L�[�{�[�h��������܂���ł���");
		return false;
	}

	// �f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(DevKeyboard->SetDataFormat(&c_dfDIKeyboard))) {
		MessageBox(hWnd, "�L�[�{�[�h�̃f�[�^�t�H�[�}�b�g��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		LogWriter::GetInstance().LogError("�L�[�{�[�h�̃f�[�^�t�H�[�}�b�g��ݒ�ł��܂���ł���");
		return false;
	}

	// �������[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
	if (FAILED(DevKeyboard->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))) {
		MessageBox(hWnd, "�L�[�{�[�h�̋������[�h��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		LogWriter::GetInstance().LogError("�L�[�{�[�h�̋������[�h��ݒ�ł��܂���ł���");
		return false;
	}

	// �L�[�{�[�h�ւ̃A�N�Z�X�����l��(���͐���J�n)
	DevKeyboard->Acquire();

	return true;
}

void Input::UninitKeyboard() {
	if (DevKeyboard != NULL) {// ���̓f�o�C�X(�L�[�{�[�h)�̊J��
		// �L�[�{�[�h�ւ̃A�N�Z�X�����J��(���͐���I��)
		DevKeyboard->Unacquire();

		DevKeyboard->Release();
		DevKeyboard = NULL;
	}

	// ���͏����̏I������
	UninitInput();
}

void Input::Init(HINSTANCE hInstance, HWND hWnd) {
	InitKeyboard(hInstance, hWnd);

	//�Q�[���p�b�h�Ȃǂ̏��������ǉ��\��
}

void Input::Uninit() {
	if (input != NULL) {

		// DirectInput�I�u�W�F�N�g�̊J��
		input->Release();
		input = NULL;
	}
}

void Input::Update() {
	BYTE aKeyState[NUM_KEY_MAX];

	// �f�o�C�X����f�[�^���擾
	if (SUCCEEDED(DevKeyboard->GetDeviceState(sizeof(aKeyState), aKeyState))) {
		// aKeyState[DIK_SPACE] & 0x80

		for (int nCnKey = 0; nCnKey < NUM_KEY_MAX; nCnKey++) {
			// �L�[�g���K�[�E�����[�X���𐶐�
			KeyStateDown[nCnKey] = (KeyState[nCnKey] ^ aKeyState[nCnKey]) & aKeyState[nCnKey];
			KeyStateUp[nCnKey] = (KeyState[nCnKey] ^ aKeyState[nCnKey]) & KeyState[nCnKey];


			// �L�[�v���X����ۑ�
			KeyState[nCnKey] = aKeyState[nCnKey];
		}
	} else {
		// �L�[�{�[�h�ւ̃A�N�Z�X�����擾
		DevKeyboard->Acquire();
	}
}

bool Input::GetKey(int key) {
	return (KeyState[key] & 0x80) ? true : false;
}

bool Input::GetKeyDown(int key) {
	return (KeyStateDown[key] & 0x80) ? true : false;
}

bool Input::GetKeyUp(int key) {
	return (KeyStateUp[key] & 0x80) ? true : false;
}

Input::Input() {

}


Input::~Input() {
}
