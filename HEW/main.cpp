#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dinput8.lib")
#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

#include <stdio.h>
#include"Vector3.h"
#include"Vector2.h"
#include"ObjectManager.h"
#include"SceneManager.h"
#include"Singleton.h"
#include"SaveManager.h"
#include"LogWriter.h"
#include"Time.h"
#include"Color.h"
#include"Object.h"
#include"Component.h"
#include"ScriptBase.h"
#include"GameObject.h"
#include"MyDirect3D.h"
#include"Setting.h"
#include"Input.h"
#include"Sprite.h"
#include"Text.h"

#include "Run.h"
/*------------------------------------------------------------------------------
�O���[�o���ϐ��錾
------------------------------------------------------------------------------*/
static HWND hWnd;                           // �E�B���h�E�n���h��
static LPDIRECT3D9 g_pD3D = NULL;             // Direct3D�C���^�[�t�F�[�X
// Direct3D�f�o�C�X
static LPDIRECT3DTEXTURE9 g_pTexture = NULL;  // �e�N�X�`���C���^�[�t�F�[�X

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// �g�p���Ȃ��ꎞ�ϐ��𖾎��B���O���
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// �E�B���h�E�N���X�\���̂̐ݒ�
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;                          // �E�B���h�E�v���V�[�W���̎w��
	wc.lpszClassName = CLASS_NAME;                     // �N���X���̐ݒ�
	wc.hInstance = hInstance;                          // �C���X�^���X�n���h���̎w��
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);          // �}�E�X�J�[�\�����w��
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1); // �E�C���h�E�̃N���C�A���g�̈�̔w�i�F��ݒ�

													   // �N���X�o�^
	RegisterClass(&wc);


	// �E�B���h�E�X�^�C��
	DWORD window_style = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);

	// ��{��`���W
	RECT window_rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };

	// �w�肵���N���C�A���g�̈���m�ۂ��邽�߂ɐV���ȋ�`���W���v�Z
	AdjustWindowRect(&window_rect, window_style, FALSE);

	// �V����Window�̋�`���W���畝�ƍ������Z�o
	int window_width = window_rect.right - window_rect.left;
	int window_height = window_rect.bottom - window_rect.top;

	// �v���C�}�����j�^�[�̉�ʉ𑜓x�擾
	int desktop_width = GetSystemMetrics(SM_CXSCREEN);
	int desktop_height = GetSystemMetrics(SM_CYSCREEN);

	// �f�X�N�g�b�v�̐^�񒆂ɃE�B���h�E�����������悤�ɍ��W���v�Z
	// ��������������A�f�X�N�g�b�v���E�B���h�E���傫���ꍇ�͍���ɕ\��
	int window_x = max((desktop_width - window_width) / 2, 0);
	int window_y = max((desktop_height - window_height) / 2, 0);

	// �E�B���h�E�̐���
	hWnd = CreateWindow
	(
		CLASS_NAME,     // �E�B���h�E�N���X
		WINDOW_CAPTION, // �E�B���h�E�e�L�X�g
		window_style,   // �E�B���h�E�X�^�C��
		window_x,       // �E�B���h�E���Wx
		window_y,       // �E�B���h�E���Wy
		window_width,   // �E�B���h�E�̕�
		window_height,  // �E�B���h�E�̍���
		NULL,           // �e�E�B���h�E�n���h��
		NULL,           // ���j���[�n���h��
		hInstance,      // �C���X�^���X�n���h��
		NULL            // �ǉ��̃A�v���P�[�V�����f�[�^
	);

	if (hWnd == NULL) {
		// �E�B���h�E�n���h�������炩�̗��R�Ő����o���Ȃ�����
		return -1;
	}


	Input::GetInstance().Init(hInstance, hWnd);

	// �w��̃E�B���h�E�n���h���̃E�B���h�E���w��̕��@�ŕ\��
	ShowWindow(hWnd, nCmdShow);


	// �Q�[���̏�����(Direct3D�̏�����)
	if (!Init()) {
		// �Q�[���̏������Ɏ��s����
		return -1;
	}

	// Windows�Q�[���p���C�����[�v
	MSG msg = {}; // msg.message == WM_NULL

	while (WM_QUIT != msg.message) {

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			// ���b�Z�[�W������ꍇ�̓��b�Z�[�W������D��
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {
			if (Time::GetInstance().IsUpdate()) {
				// �Q�[���̍X�V
				Update();
				//�L�[�{�[�h�̓��͏�Ԃ̊m�F
				Input::GetInstance().Update();
				// �Q�[���̕`��
				Draw();
			}
		}
	}

	// �Q�[���̏I������(Direct3D�̏I������)
	Input::GetInstance().Uninit();
	Uninit();

	return (int)msg.wParam;
}

//����������
bool Init(){
	if (!MyDirect3D::GetInstance().Init(hWnd)) {
		return false;
	}

	LogWriter::GetInstance();
	SaveManager::GetInstance();
	ObjectManager::GetInstance();
	SceneManager::GetInstance();
	Time::GetInstance();

	Sprite::Init();
	Text::Init();
	
	//�[�[�[�[�[�[�������͂�������[�[�[�[�[�[�[�[�[�[�[�[

	Scene* run = new Run("run");
	SceneManager::GetInstance().AddScene(run);

	SceneManager::GetInstance().LoadScene("run");

	//��B����Ȋ����ŏ���������B�V�[���ɂ܂Ƃ߂�̂𐄏�
	/*GameObject* obj = new GameObject();
	ObjectManager::GetInstance().Instantiate(obj);

	sampleComponent* samp = new sampleComponent();
	obj->AddComponent(samp);*/
	
	//�[�[�[�[�[�[�������͂����܂łɓ��́[�[�[�[�[�[�[�[�[

	ObjectManager::GetInstance().Awake();
	ObjectManager::GetInstance().Start();

	return true;
}

//�I������
void Uninit() {

}

//�����֌W
void Update() {
	ObjectManager::GetInstance().FirstUpdate();
	ObjectManager::GetInstance().Update();
	if (SceneManager::GetInstance().GetNowScene() != nullptr) {
		SceneManager::GetInstance().GetNowScene()->Update();
	}
	ObjectManager::GetInstance().LateUpdate();
}

//�`��֌W
void Draw() {

	static LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();

	// ��ʂ̃N���A
	pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(80, 80, 80, 255), 1.0f, 0);

	// �`��o�b�`���߂̊J�n
	pDevice->BeginScene();

	pDevice->SetFVF(FVF_VERTEX2D);

	//�u�����h�ݒ�
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);			// ���u�����h���s��
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		// ���\�[�X�J���[�̎w��
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);	// ���f�X�e�B�l�[�V�����J���[�̎w��
	// �T���v���[�X�e�[�g�p�����[�^�̐ݒ�
	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);// �e�N�X�`���A�h���b�V���O���@(U�l)��ݒ�
	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);// �e�N�X�`���A�h���b�V���O���@(V�l)��ݒ�
	pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);	// �e�N�X�`���k���t�B���^���[�h��ݒ�
	pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);	// �e�N�X�`���g��t�B���^���[�h��ݒ�

	ObjectManager::GetInstance().Draw();
	ObjectManager::GetInstance().LateDraw();

	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);

	// �`��o�b�`���߂̏I��
	pDevice->EndScene();

	// �o�b�N�o�b�t�@���t���b�v�i�^�C�~���O��D3DPRESENT_PARAMETERS�̐ݒ�ɂ��j
	pDevice->Present(NULL, NULL, NULL, NULL);
}

//�[�[�[�[�[��������K�{�֐��B���g��������Ȃ����Ɓ[�[�[�[�[

// �E�B���h�E�v���V�[�W��(�R�[���o�b�N�֐�)
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_KEYDOWN:
			if (wParam == VK_ESCAPE) {
				SendMessage(hWnd, WM_CLOSE, 0, 0); // WM_CLOSE���b�Z�[�W�̑��M
			}
			break;

		case WM_CLOSE:
			if (MessageBox(hWnd, END_CONFIRMATION, END_WINDOW_CAPTION, MB_OKCANCEL | MB_DEFBUTTON2) == IDOK) {
				DestroyWindow(hWnd); // �w��̃E�B���h�E��WM_DESTROY���b�Z�[�W�𑗂�
			}
			return 0; // DefWindowProc�֐��Ƀ��b�Z�[�W�𗬂����I�����邱�Ƃɂ���ĉ����Ȃ��������Ƃɂ���

		case WM_DESTROY: // �E�B���h�E�̔j�����b�Z�[�W
			PostQuitMessage(0); // WM_QUIT���b�Z�[�W�̑��M
			return 0;
	};

	// �ʏ탁�b�Z�[�W�����͂��̊֐��ɔC����
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}