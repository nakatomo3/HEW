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
	// ゲームの初期化関数
		// Direct3Dインターフェースの取得
	D3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (D3D == NULL) {
		// Direct3Dインターフェースの取得に失敗
		MessageBox(hwnd, "Direct3Dインターフェースの作成に失敗しました", "エラー", MB_OK);
		return false;
	}

	// デバイスの生成に利用する情報構造体の作成
	D3DPRESENT_PARAMETERS d3dpp = {};

	d3dpp.BackBufferWidth = SCREEN_WIDTH;            // バックバッファの横幅				
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;           // バックバッファの縦幅
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;          // バックバッファのフォーマット指定
	d3dpp.BackBufferCount = 1;                       // バックバッファの数
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;   // スワップエフェクト（スワップ方法）の設定		
	d3dpp.Windowed = TRUE;                    // ウィンドウモード or フルスクリーン
	d3dpp.EnableAutoDepthStencil = TRUE;                    // 深度バッファ・ステンシルバッファの使用				
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;              // 深度バッファ・ステンシルバッファのフォーマット指定
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT; // フルスクリーン時のリフレッシュレートの指定
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE; // リフレッシュレートとPresent処理の関係

														  // Direct3Dデバイスの取得
	if (FAILED(D3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &D3DDevice))) {
		// デバイスの作成に失敗
		MessageBox(hwnd, "Direct3Dデバイスの作成に失敗しました", "エラー", MB_OK);
		return false;
	}

	return true;
}

void MyDirect3D::Uninit() {
	// Direct3Dデバイスの解放
	if (D3DDevice) {
		D3DDevice->Release();
		D3DDevice = NULL;
	}

	// Direct3Dインターフェースの解放
	if (D3D != NULL) {
		D3D->Release();
		D3D = NULL;
	}
}

MyDirect3D::MyDirect3D() {
}


MyDirect3D::~MyDirect3D() {
}
