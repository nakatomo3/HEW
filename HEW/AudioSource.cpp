//#include <XAudio2.h>
//#include <mmsystem.h>
//#include "AudioSource.h"
//
//#pragma comment (lib, "xaudio2.lib") 
//#pragma comment (lib, "winmm.lib") 
//
//AudioSource::AudioSource(HWND hWnd) {
//	HRESULT hr;
//
//	// COMライブラリの初期化
//	CoInitializeEx(NULL, COINIT_MULTITHREADED);
//
//	// XAudio2オブジェクトの作成
//	hr = XAudio2Create(&XAudio2, 0);
//	if (FAILED(hr)) {
//		MessageBox(hWnd, "XAudio2オブジェクトの作成に失敗！", "警告！", MB_ICONWARNING);
//
//		// COMライブラリの終了処理
//		CoUninitialize();
//
//		return;
//	}
//
//	// マスターボイスの生成
//	hr = XAudio2->CreateMasteringVoice(&masteringVoice);
//	if (FAILED(hr)) {
//		MessageBox(hWnd, "マスターボイスの生成に失敗！", "警告！", MB_ICONWARNING);
//
//		if (XAudio2) {
//			// XAudio2オブジェクトの開放
//			XAudio2->Release();
//			XAudio2 = NULL;
//		}
//
//		// COMライブラリの終了処理
//		CoUninitialize();
//
//		return;
//	}
//
//	// サウンドデータの初期化
//	for (int nCntSound = 0; nCntSound < SOUND_LABEL_MAX; nCntSound++) {
//		HANDLE hFile;
//		DWORD dwChunkSize = 0;
//		DWORD dwChunkPosition = 0;
//		DWORD dwFiletype;
//		WAVEFORMATEXTENSIBLE wfx;
//		XAUDIO2_BUFFER buffer;
//
//		// バッファのクリア
//		memset(&wfx, 0, sizeof(WAVEFORMATEXTENSIBLE));
//		memset(&buffer, 0, sizeof(XAUDIO2_BUFFER));
//
//		// サウンドデータファイルの生成
//		hFile = CreateFile(g_aParam[nCntSound].pFilename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
//		if (hFile == INVALID_HANDLE_VALUE) {
//			MessageBox(hWnd, "サウンドデータファイルの生成に失敗！(1)", "警告！", MB_ICONWARNING);
//			return HRESULT_FROM_WIN32(GetLastError());
//		}
//		if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER) {// ファイルポインタを先頭に移動
//			MessageBox(hWnd, "サウンドデータファイルの生成に失敗！(2)", "警告！", MB_ICONWARNING);
//			return HRESULT_FROM_WIN32(GetLastError());
//		}
//
//		// WAVEファイルのチェック
//		hr = CheckChunk(hFile, 'FFIR', &dwChunkSize, &dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "WAVEファイルのチェックに失敗！(1)", "警告！", MB_ICONWARNING);
//			return S_FALSE;
//		}
//		hr = ReadChunkData(hFile, &dwFiletype, sizeof(DWORD), dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "WAVEファイルのチェックに失敗！(2)", "警告！", MB_ICONWARNING);
//			return S_FALSE;
//		}
//		if (dwFiletype != 'EVAW') {
//			MessageBox(hWnd, "WAVEファイルのチェックに失敗！(3)", "警告！", MB_ICONWARNING);
//			return S_FALSE;
//		}
//
//		// フォーマットチェック
//		hr = CheckChunk(hFile, ' tmf', &dwChunkSize, &dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "フォーマットチェックに失敗！(1)", "警告！", MB_ICONWARNING);
//			return S_FALSE;
//		}
//		hr = ReadChunkData(hFile, &wfx, dwChunkSize, dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "フォーマットチェックに失敗！(2)", "警告！", MB_ICONWARNING);
//			return S_FALSE;
//		}
//
//		// オーディオデータ読み込み
//		hr = CheckChunk(hFile, 'atad', &audioDataSize[nCntSound], &dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "オーディオデータ読み込みに失敗！(1)", "警告！", MB_ICONWARNING);
//			return S_FALSE;
//		}
//		audioData[nCntSound] = (BYTE*)malloc(audioDataSize[nCntSound]);
//		hr = ReadChunkData(hFile, audioData[nCntSound], audioDataSize[nCntSound], dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "オーディオデータ読み込みに失敗！(2)", "警告！", MB_ICONWARNING);
//			return S_FALSE;
//		}
//
//		// ソースボイスの生成
//		hr = XAudio2->CreateSourceVoice(&voiceSource[nCntSound], &(wfx.Format));
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "ソースボイスの生成に失敗！", "警告！", MB_ICONWARNING);
//			return S_FALSE;
//		}
//
//		// バッファの値設定
//		memset(&buffer, 0, sizeof(XAUDIO2_BUFFER));
//		buffer.AudioBytes = audioDataSize[nCntSound];
//		buffer.pAudioData = audioDataSize[nCntSound];
//		buffer.Flags = XAUDIO2_END_OF_STREAM;
//		buffer.LoopCount = g_aParam[nCntSound].nCntLoop;
//
//		// オーディオバッファの登録
//		voiceSource[nCntSound]->SubmitSourceBuffer(&buffer);
//	}
//
//	return;
//}
//
//AudioSource::~AudioSource() {
//}
//
//void AudioSource::Play() {
//	XAUDIO2_VOICE_STATE xa2state;
//	XAUDIO2_BUFFER buffer;
//
//	// バッファの値設定
//	memset(&buffer, 0, sizeof(XAUDIO2_BUFFER));
//	buffer.AudioBytes = audioDataSize;
//	buffer.pAudioData = audioData;
//	buffer.Flags = XAUDIO2_END_OF_STREAM;
//	buffer.LoopCount = loopCount;
//
//	// 状態取得
//	voiceSource->GetState(&xa2state);
//	if (xa2state.BuffersQueued != 0) {// 再生中
//		// 一時停止
//		voiceSource->Stop(0);
//
//		// オーディオバッファの削除
//		voiceSource->FlushSourceBuffers();
//	}
//
//	// オーディオバッファの登録
//	voiceSource->SubmitSourceBuffer(&buffer);
//
//	// 再生
//	voiceSource->Start(0);
//
//	return;
//}
//
//HRESULT AudioSource::CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition) {
//	HRESULT hr = S_OK;
//	DWORD dwRead;
//	DWORD dwChunkType;
//	DWORD dwChunkDataSize;
//	DWORD dwRIFFDataSize = 0;
//	DWORD dwFileType;
//	DWORD dwBytesRead = 0;
//	DWORD dwOffset = 0;
//
//	if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER) {// ファイルポインタを先頭に移動
//		return HRESULT_FROM_WIN32(GetLastError());
//	}
//
//	while (hr == S_OK) {
//		if (ReadFile(hFile, &dwChunkType, sizeof(DWORD), &dwRead, NULL) == 0) {// チャンクの読み込み
//			hr = HRESULT_FROM_WIN32(GetLastError());
//		}
//
//		if (ReadFile(hFile, &dwChunkDataSize, sizeof(DWORD), &dwRead, NULL) == 0) {// チャンクデータの読み込み
//			hr = HRESULT_FROM_WIN32(GetLastError());
//		}
//
//		switch (dwChunkType) {
//			case 'FFIR':
//				dwRIFFDataSize = dwChunkDataSize;
//				dwChunkDataSize = 4;
//				if (ReadFile(hFile, &dwFileType, sizeof(DWORD), &dwRead, NULL) == 0) {// ファイルタイプの読み込み
//					hr = HRESULT_FROM_WIN32(GetLastError());
//				}
//				break;
//
//			default:
//				if (SetFilePointer(hFile, dwChunkDataSize, NULL, FILE_CURRENT) == INVALID_SET_FILE_POINTER) {// ファイルポインタをチャンクデータ分移動
//					return HRESULT_FROM_WIN32(GetLastError());
//				}
//		}
//
//		dwOffset += sizeof(DWORD) * 2;
//		if (dwChunkType == format) {
//			*pChunkSize = dwChunkDataSize;
//			*pChunkDataPosition = dwOffset;
//
//			return S_OK;
//		}
//
//		dwOffset += dwChunkDataSize;
//		if (dwBytesRead >= dwRIFFDataSize) {
//			return S_FALSE;
//		}
//	}
//
//	return S_OK;
//}
//
//HRESULT AudioSource::ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset) {
//	DWORD dwRead;
//
//	if (SetFilePointer(hFile, dwBufferoffset, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER) {// ファイルポインタを指定位置まで移動
//		return HRESULT_FROM_WIN32(GetLastError());
//	}
//
//	if (ReadFile(hFile, pBuffer, dwBuffersize, &dwRead, NULL) == 0) {// データの読み込み
//		return HRESULT_FROM_WIN32(GetLastError());
//	}
//
//	return S_OK;
//}