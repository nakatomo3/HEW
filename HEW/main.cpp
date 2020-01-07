#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"dxguid.lib")
#pragma comment(lib,"dinput8.lib")
#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

#include <stdio.h>
#include "HeroEngine.h"

#include "Title.h"
#include "Rule.h"
#include "SelectCharacter.h"
#include "SelectPlayerCount.h"
#include "Run.h"
#include "RunTitle.h"
#include "RunResult.h"
#include "MegatonPunch.h"
#include "MegatonPunchTitle.h"
#include "SelectCharacter.h"
#include "Archery.h"
#include "ArcheryTitle.h"
#include "MegatonPunchResult.h"
#include "ArcheryResult.h"
/*------------------------------------------------------------------------------
グローバル変数宣言
------------------------------------------------------------------------------*/
static HWND hWnd;                           // ウィンドウハンドル
static LPDIRECT3D9 g_pD3D = NULL;             // Direct3Dインターフェース
// Direct3Dデバイス
static LPDIRECT3DTEXTURE9 g_pTexture = NULL;  // テクスチャインターフェース

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// 使用しない一時変数を明示。ログ回避
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// ウィンドウクラス構造体の設定
	WNDCLASS wc = {};
	wc.lpfnWndProc = WndProc;                          // ウィンドウプロシージャの指定
	wc.lpszClassName = CLASS_NAME;                     // クラス名の設定
	wc.hInstance = hInstance;                          // インスタンスハンドルの指定
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);          // マウスカーソルを指定
	wc.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1); // ウインドウのクライアント領域の背景色を設定

													   // クラス登録
	RegisterClass(&wc);


	// ウィンドウスタイル
	DWORD window_style = WS_OVERLAPPEDWINDOW & ~(WS_MAXIMIZEBOX | WS_THICKFRAME);

	// 基本矩形座標
	RECT window_rect = { 0, 0, (UINT)SCREEN_WIDTH, (UINT)SCREEN_HEIGHT };

	// 指定したクライアント領域を確保するために新たな矩形座標を計算
	AdjustWindowRect(&window_rect, window_style, FALSE);

	// 新たなWindowの矩形座標から幅と高さを算出
	int window_width = window_rect.right - window_rect.left;
	int window_height = window_rect.bottom - window_rect.top;

	// プライマリモニターの画面解像度取得
	int desktop_width = GetSystemMetrics(SM_CXSCREEN);
	int desktop_height = GetSystemMetrics(SM_CYSCREEN);

	// デスクトップの真ん中にウィンドウが生成されるように座標を計算
	// ※ただし万が一、デスクトップよりウィンドウが大きい場合は左上に表示
	int window_x = max((desktop_width - window_width) / 2, 0);
	int window_y = max((desktop_height - window_height) / 2, 0);

	// ウィンドウの生成
	hWnd = CreateWindow
	(
		CLASS_NAME,     // ウィンドウクラス
		WINDOW_CAPTION, // ウィンドウテキスト
		window_style,   // ウィンドウスタイル
		window_x,       // ウィンドウ座標x
		window_y,       // ウィンドウ座標y
		window_width,   // ウィンドウの幅
		window_height,  // ウィンドウの高さ
		NULL,           // 親ウィンドウハンドル
		NULL,           // メニューハンドル
		hInstance,      // インスタンスハンドル
		NULL            // 追加のアプリケーションデータ
	);

	if (hWnd == NULL) {
		// ウィンドウハンドルが何らかの理由で生成出来なかった
		return -1;
	}


	Input::GetInstance().Init(hInstance, hWnd);

	if (IS_VIEW_CAPTION != true) {
		SetWindowLong(hWnd, GWL_STYLE, WS_POPUP);
	}

	// 指定のウィンドウハンドルのウィンドウを指定の方法で表示
	ShowWindow(hWnd, nCmdShow);

	// ゲームの初期化(Direct3Dの初期化)
	if (!Init()) {
		// ゲームの初期化に失敗した
		return -1;
	}

	// Windowsゲーム用メインループ
	MSG msg = {}; // msg.message == WM_NULL

	while (WM_QUIT != msg.message) {

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			// メッセージがある場合はメッセージ処理を優先
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {
			if (Time::GetInstance().IsUpdate()) {
				// ゲームの更新
				Update();
				//キーボードの入力状態の確認
				Input::GetInstance().Update();
				// ゲームの描画
				Draw();
			}
		}
	}

	// ゲームの終了処理(Direct3Dの終了処理)
	Input::GetInstance().Uninit();
	Uninit();

	return (int)msg.wParam;
}

//初期化処理
bool Init(){
	if (!MyDirect3D::GetInstance().Init(hWnd)) {
		return false;
	}

	LogWriter::GetInstance();
	SaveManager::GetInstance();
	ObjectManager::GetInstance();
	SceneManager::GetInstance();
	Time::GetInstance();
	VariableManager::GetInstance();

	Sprite::Init();
	Text::Init();
	
	//ーーーーーー初期化はここからーーーーーーーーーーーー
	VariableManager::GetInstance().SetInt("playerCount",4);

	Scene* title = new Title("Title");
	Scene* rule = new Rule("Rule");
	Scene* selectCharacter = new SelectCharacter("selectCharacter");
	Scene* selectPlayerCount = new SelectPlayerCount("selectPlayerCount");
	Scene* run = new Run("run");
	Scene* runTitle = new RunTitle("runTitle");
	Scene* runResult = new RunResult("runResult");
	
	Scene* megatonPunch = new MegatonPunch("megatonPunch");
	Scene* megatonPunchTitle = new MegatonPunchTitle("megatonPunchTitle");
	Scene* megatonPunchResult = new MegatonPunchResult("megatonPunchResult");

	Scene* archery = new Archery("archery");
	Scene* archeryTitle = new ArcheryTitle("archeryTitle");
	Scene* archeryResult = new ArcheryResult("ArcheryResult");

	SceneManager::GetInstance().LoadScene("run");//仮のScene遷移機能
	

	//例。こんな感じで初期化する。シーンにまとめるのを推奨
	/*GameObject* obj = new GameObject();
	ObjectManager::GetInstance().Instantiate(obj);

	sampleComponent* samp = new sampleComponent();
	obj->AddComponent(samp);*/
	
	//ーーーーーー初期化はここまでに入力ーーーーーーーーー

	return true;
}

//終了処理
void Uninit() {

}

//処理関係
void Update() {
	ObjectManager::GetInstance().FirstUpdate();
	ObjectManager::GetInstance().Update();
	if (SceneManager::GetInstance().GetNowScene() != nullptr) {
		SceneManager::GetInstance().GetNowScene()->Update();
	}
	ObjectManager::GetInstance().LateUpdate();

}

//描画関係
void Draw() {

	static LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();

	// 画面のクリア
	pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(80, 80, 80, 255), 1.0f, 0);

	// 描画バッチ命令の開始
	pDevice->BeginScene();

	pDevice->SetFVF(FVF_VERTEX2D);

	//ブレンド設定
	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);			// αブレンドを行う
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);		// αソースカラーの指定
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);	// αデスティネーションカラーの指定
	// サンプラーステートパラメータの設定
	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSU, D3DTADDRESS_WRAP);// テクスチャアドレッシング方法(U値)を設定
	pDevice->SetSamplerState(0, D3DSAMP_ADDRESSV, D3DTADDRESS_WRAP);// テクスチャアドレッシング方法(V値)を設定
	pDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);	// テクスチャ縮小フィルタモードを設定
	pDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);	// テクスチャ拡大フィルタモードを設定

	ObjectManager::GetInstance().Draw();
	ObjectManager::GetInstance().LateDraw();

	pDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);

	// 描画バッチ命令の終了
	pDevice->EndScene();

	// バックバッファをフリップ（タイミングはD3DPRESENT_PARAMETERSの設定による）
	pDevice->Present(NULL, NULL, NULL, NULL);
}

//ーーーーーここから必須関数。中身をいじらないことーーーーー

// ウィンドウプロシージャ(コールバック関数)
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch (uMsg) {
		case WM_KEYDOWN:
			if (wParam == VK_ESCAPE) {
				SendMessage(hWnd, WM_CLOSE, 0, 0); // WM_CLOSEメッセージの送信
			}
			break;

		case WM_CLOSE:
			if (MessageBox(hWnd, END_CONFIRMATION, END_WINDOW_CAPTION, MB_OKCANCEL | MB_DEFBUTTON2) == IDOK) {
				DestroyWindow(hWnd); // 指定のウィンドウにWM_DESTROYメッセージを送る
			}
			return 0; // DefWindowProc関数にメッセージを流さず終了することによって何もなかったことにする

		case WM_DESTROY: // ウィンドウの破棄メッセージ
			PostQuitMessage(0); // WM_QUITメッセージの送信
			return 0;
	};

	// 通常メッセージ処理はこの関数に任せる
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
