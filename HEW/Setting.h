#pragma once

//目指すFPS。FPSは必ずこれよりも小さくなる
#define DEFAULT_FPS (60.0)

//ログファイルを作るかどうか
#define IS_CREATE_FILE (true)

//画面の横幅
#define SCREEN_WIDTH (1024)
//画面の縦幅
#define SCREEN_HEIGHT (576)

// ウインドウクラスの名前
#define CLASS_NAME     "GameWindow"       
// ウィンドウ上部のメッセージ
#define WINDOW_CAPTION "HEW" 

//終了時のメッセージ
#define END_CONFIRMATION "本当に終了してよろしいですか？"
//終了時のウィンドウ上部のメッセージ
#define END_WINDOW_CAPTION "確認"