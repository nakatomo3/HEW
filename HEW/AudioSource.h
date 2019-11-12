//#pragma once
//
//#include "Component.h"
//#include "AudioClip.h"
//
////音を出すコンポーネント
////CDプレイヤーの役割。CDに当たるAudioClipが無いと音を鳴らせない
//class AudioSource : public Component {
//public:
//
//	AudioSource(HWND hWnd);
//	~AudioSource();
//
//	void Play();
//	void PlayLoop();
//
//private:
//	AudioClip* audioClip;
//
//	bool isPlay = false;
//	bool isLooping = false;
//
//	unsigned int loopCount;
//
//	IXAudio2 *XAudio2;						// XAudio2オブジェクトへのインターフェイス
//	IXAudio2MasteringVoice *masteringVoice;	// マスターボイス
//	IXAudio2SourceVoice *voiceSource;		// ソースボイス
//	BYTE* audioData;							// オーディオデータ
//	DWORD audioDataSize;						// オーディオデータサイズ
//
//	static HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
//	static HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);
//};