#include "Input.h"
#include "LogWriter.h"

bool Input::InitInput(HINSTANCE hInstance) {
	if (input == NULL) {

		// DirectInputオブジェクトの作成
		if (FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&input, NULL))) {

			return false;
		}
	}

	return true;
}

void Input::UninitInput() {
	if (input != NULL) {

		// DirectInputオブジェクトの開放
		input->Release();
		input = NULL;
	}
}

bool Input::InitKeyboard(HINSTANCE hInstance, HWND hWnd) {
	// 入力処理の初期化
	if (!InitInput(hInstance)) {
		MessageBox(hWnd, "DirectInputオブジェクトが作れませんでした", "警告！", MB_ICONWARNING);
		LogWriter::GetInstance().LogError("DirectInputオブジェクトが作れませんでした");
		return false;
	}

	// デバイスの作成
	if (FAILED(input->CreateDevice(GUID_SysKeyboard, &DevKeyboard, NULL))) {
		MessageBox(hWnd, "キーボードがありません", "警告！", MB_ICONWARNING);
		LogWriter::GetInstance().LogError("キーボードが見つかりませんでした");
		return false;
	}

	// データフォーマットを設定
	if (FAILED(DevKeyboard->SetDataFormat(&c_dfDIKeyboard))) {
		MessageBox(hWnd, "キーボードのデータフォーマットを設定できませんでした。", "警告！", MB_ICONWARNING);
		LogWriter::GetInstance().LogError("キーボードのデータフォーマットを設定できませんでした");
		return false;
	}

	// 協調モードを設定（フォアグラウンド＆非排他モード）
	if (FAILED(DevKeyboard->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))) {
		MessageBox(hWnd, "キーボードの協調モードを設定できませんでした。", "警告！", MB_ICONWARNING);
		LogWriter::GetInstance().LogError("キーボードの協調モードを設定できませんでした");
		return false;
	}

	// キーボードへのアクセス権を獲得(入力制御開始)
	DevKeyboard->Acquire();

	return true;
}

void Input::UninitKeyboard() {
	if (DevKeyboard != NULL) {// 入力デバイス(キーボード)の開放
		// キーボードへのアクセス権を開放(入力制御終了)
		DevKeyboard->Unacquire();

		DevKeyboard->Release();
		DevKeyboard = NULL;
	}

	// 入力処理の終了処理
	UninitInput();
}

void Input::Init(HINSTANCE hInstance, HWND hWnd) {
	InitKeyboard(hInstance, hWnd);

	//ゲームパッドなどの初期化も追加予定
}

void Input::Uninit() {
	if (input != NULL) {

		// DirectInputオブジェクトの開放
		input->Release();
		input = NULL;
	}
}

void Input::Update() {
	BYTE aKeyState[NUM_KEY_MAX];

	// デバイスからデータを取得
	if (SUCCEEDED(DevKeyboard->GetDeviceState(sizeof(aKeyState), aKeyState))) {
		// aKeyState[DIK_SPACE] & 0x80

		for (int nCnKey = 0; nCnKey < NUM_KEY_MAX; nCnKey++) {
			// キートリガー・リリース情報を生成
			KeyStateDown[nCnKey] = (KeyState[nCnKey] ^ aKeyState[nCnKey]) & aKeyState[nCnKey];
			KeyStateUp[nCnKey] = (KeyState[nCnKey] ^ aKeyState[nCnKey]) & KeyState[nCnKey];


			// キープレス情報を保存
			KeyState[nCnKey] = aKeyState[nCnKey];
		}
	} else {
		// キーボードへのアクセス権を取得
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
