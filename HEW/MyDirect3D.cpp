#include "MyDirect3D.h"
#include "Setting.h"
#include<windows.h>
#include<d3d9.h>
#include<d3dx9.h>
#include<dxerr.h>
#include<math.h>

LPDIRECT3DDEVICE9 MyDirect3D::GetDevice() {
	return D3DDevice;
}

bool MyDirect3D::Init(HWND hwnd) {
	// �Q�[���̏������֐�
		// Direct3D�C���^�[�t�F�[�X�̎擾
	D3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (D3D == NULL) {
		// Direct3D�C���^�[�t�F�[�X�̎擾�Ɏ��s
		MessageBox(hwnd, "Direct3D�C���^�[�t�F�[�X�̍쐬�Ɏ��s���܂���", "�G���[", MB_OK);
		return false;
	}

	// �f�o�C�X�̐����ɗ��p������\���̂̍쐬
	D3DPRESENT_PARAMETERS d3dpp = {};

	d3dpp.BackBufferWidth = SCREEN_WIDTH;            // �o�b�N�o�b�t�@�̉���				
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;           // �o�b�N�o�b�t�@�̏c��
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;          // �o�b�N�o�b�t�@�̃t�H�[�}�b�g�w��
	d3dpp.BackBufferCount = 1;                       // �o�b�N�o�b�t�@�̐�
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;   // �X���b�v�G�t�F�N�g�i�X���b�v���@�j�̐ݒ�		
	d3dpp.Windowed = TRUE;                    // �E�B���h�E���[�h or �t���X�N���[��
	d3dpp.EnableAutoDepthStencil = TRUE;                    // �[�x�o�b�t�@�E�X�e���V���o�b�t�@�̎g�p				
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;              // �[�x�o�b�t�@�E�X�e���V���o�b�t�@�̃t�H�[�}�b�g�w��
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT; // �t���X�N���[�����̃��t���b�V�����[�g�̎w��
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE; // ���t���b�V�����[�g��Present�����̊֌W

														  // Direct3D�f�o�C�X�̎擾
	if (FAILED(D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &D3DDevice))) {
		// �f�o�C�X�̍쐬�Ɏ��s
		MessageBox(hwnd, "Direct3D�f�o�C�X�̍쐬�Ɏ��s���܂���", "�G���[", MB_OK);
		return false;
	}

	return true;
}

void MyDirect3D::Uninit() {
	// Direct3D�f�o�C�X�̉��
	if (D3DDevice) {
		D3DDevice->Release();
		D3DDevice = NULL;
	}

	// Direct3D�C���^�[�t�F�[�X�̉��
	if (D3D != NULL) {
		D3D->Release();
		D3D = NULL;
	}
}

MyDirect3D::MyDirect3D() {
}


MyDirect3D::~MyDirect3D() {
}
