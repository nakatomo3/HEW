//#pragma once
//
//#include "Component.h"
//#include "AudioClip.h"
//
////�����o���R���|�[�l���g
////CD�v���C���[�̖����BCD�ɓ�����AudioClip�������Ɖ���点�Ȃ�
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
//	IXAudio2 *XAudio2;						// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
//	IXAudio2MasteringVoice *masteringVoice;	// �}�X�^�[�{�C�X
//	IXAudio2SourceVoice *voiceSource;		// �\�[�X�{�C�X
//	BYTE* audioData;							// �I�[�f�B�I�f�[�^
//	DWORD audioDataSize;						// �I�[�f�B�I�f�[�^�T�C�Y
//
//	static HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD *pChunkSize, DWORD *pChunkDataPosition);
//	static HRESULT ReadChunkData(HANDLE hFile, void *pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);
//};