#pragma once

//目指すFPS。FPSは必ずこれよりも小さくなる
#define DEFAULT_FPS (60.0)

//ログファイルを作るかどうか
#define IS_CREATE_FILE (true)

//画面の比率(16:9)
#define WINDOW_ASPECT (16.0f/9.0f)

//キャプションを表示するか否か
#define IS_VIEW_CAPTION (true)

//画面の横幅
#define SCREEN_WIDTH (1024)
//画面の縦幅
#define SCREEN_HEIGHT (SCREEN_WIDTH / WINDOW_ASPECT)

//画面の横幅 (Stardard Unit)
#define SD_WIDTH (SCREEN_WIDTH / 10)
//画面の縦幅 (Stardard Unit)
#define SD_HEIGHT (SCREEN_HEIGHT / 10)

//画面の中心(横)
#define SCREEN_CENTER_X (SCREEN_WIDTH/2)
//画面の中心(縦)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT/2)

// ウインドウクラスの名前
#define CLASS_NAME     "GameWindow"       
// ウィンドウ上部のメッセージ
#define WINDOW_CAPTION "HEW" 

//終了時のメッセージ
#define END_CONFIRMATION "本当に終了してよろしいですか？"
//終了時のウィンドウ上部のメッセージ
#define END_WINDOW_CAPTION "確認"