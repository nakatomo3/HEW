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
//	// COM���C�u�����̏�����
//	CoInitializeEx(NULL, COINIT_MULTITHREADED);
//
//	// XAudio2�I�u�W�F�N�g�̍쐬
//	hr = XAudio2Create(&XAudio2, 0);
//	if (FAILED(hr)) {
//		MessageBox(hWnd, "XAudio2�I�u�W�F�N�g�̍쐬�Ɏ��s�I", "�x���I", MB_ICONWARNING);
//
//		// COM���C�u�����̏I������
//		CoUninitialize();
//
//		return;
//	}
//
//	// �}�X�^�[�{�C�X�̐���
//	hr = XAudio2->CreateMasteringVoice(&masteringVoice);
//	if (FAILED(hr)) {
//		MessageBox(hWnd, "�}�X�^�[�{�C�X�̐����Ɏ��s�I", "�x���I", MB_ICONWARNING);
//
//		if (XAudio2) {
//			// XAudio2�I�u�W�F�N�g�̊J��
//			XAudio2->Release();
//			XAudio2 = NULL;
//		}
//
//		// COM���C�u�����̏I������
//		CoUninitialize();
//
//		return;
//	}
//
//	// �T�E���h�f�[�^�̏�����
//	for (int nCntSound = 0; nCntSound < SOUND_LABEL_MAX; nCntSound++) {
//		HANDLE hFile;
//		DWORD dwChunkSize = 0;
//		DWORD dwChunkPosition = 0;
//		DWORD dwFiletype;
//		WAVEFORMATEXTENSIBLE wfx;
//		XAUDIO2_BUFFER buffer;
//
//		// �o�b�t�@�̃N���A
//		memset(&wfx, 0, sizeof(WAVEFORMATEXTENSIBLE));
//		memset(&buffer, 0, sizeof(XAUDIO2_BUFFER));
//
//		// �T�E���h�f�[�^�t�@�C���̐���
//		hFile = CreateFile(g_aParam[nCntSound].pFilename, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
//		if (hFile == INVALID_HANDLE_VALUE) {
//			MessageBox(hWnd, "�T�E���h�f�[�^�t�@�C���̐����Ɏ��s�I(1)", "�x���I", MB_ICONWARNING);
//			return HRESULT_FROM_WIN32(GetLastError());
//		}
//		if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER) {// �t�@�C���|�C���^��擪�Ɉړ�
//			MessageBox(hWnd, "�T�E���h�f�[�^�t�@�C���̐����Ɏ��s�I(2)", "�x���I", MB_ICONWARNING);
//			return HRESULT_FROM_WIN32(GetLastError());
//		}
//
//		// WAVE�t�@�C���̃`�F�b�N
//		hr = CheckChunk(hFile, 'FFIR', &dwChunkSize, &dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "WAVE�t�@�C���̃`�F�b�N�Ɏ��s�I(1)", "�x���I", MB_ICONWARNING);
//			return S_FALSE;
//		}
//		hr = ReadChunkData(hFile, &dwFiletype, sizeof(DWORD), dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "WAVE�t�@�C���̃`�F�b�N�Ɏ��s�I(2)", "�x���I", MB_ICONWARNING);
//			return S_FALSE;
//		}
//		if (dwFiletype != 'EVAW') {
//			MessageBox(hWnd, "WAVE�t�@�C���̃`�F�b�N�Ɏ��s�I(3)", "�x���I", MB_ICONWARNING);
//			return S_FALSE;
//		}
//
//		// �t�H�[�}�b�g�`�F�b�N
//		hr = CheckChunk(hFile, ' tmf', &dwChunkSize, &dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "�t�H�[�}�b�g�`�F�b�N�Ɏ��s�I(1)", "�x���I", MB_ICONWARNING);
//			return S_FALSE;
//		}
//		hr = ReadChunkData(hFile, &wfx, dwChunkSize, dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "�t�H�[�}�b�g�`�F�b�N�Ɏ��s�I(2)", "�x���I", MB_ICONWARNING);
//			return S_FALSE;
//		}
//
//		// �I�[�f�B�I�f�[�^�ǂݍ���
//		hr = CheckChunk(hFile, 'atad', &audioDataSize[nCntSound], &dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "�I�[�f�B�I�f�[�^�ǂݍ��݂Ɏ��s�I(1)", "�x���I", MB_ICONWARNING);
//			return S_FALSE;
//		}
//		audioData[nCntSound] = (BYTE*)malloc(audioDataSize[nCntSound]);
//		hr = ReadChunkData(hFile, audioData[nCntSound], audioDataSize[nCntSound], dwChunkPosition);
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "�I�[�f�B�I�f�[�^�ǂݍ��݂Ɏ��s�I(2)", "�x���I", MB_ICONWARNING);
//			return S_FALSE;
//		}
//
//		// �\�[�X�{�C�X�̐���
//		hr = XAudio2->CreateSourceVoice(&voiceSource[nCntSound], &(wfx.Format));
//		if (FAILED(hr)) {
//			MessageBox(hWnd, "�\�[�X�{�C�X�̐����Ɏ��s�I", "�x���I", MB_ICONWARNING);
//			return S_FALSE;
//		}
//
//		// �o�b�t�@�̒l�ݒ�
//		memset(&buffer, 0, sizeof(XAUDIO2_BUFFER));
//		buffer.AudioBytes = audioDataSize[nCntSound];
//		buffer.pAudioData = audioDataSize[nCntSound];
//		buffer.Flags = XAUDIO2_END_OF_STREAM;
//		buffer.LoopCount = g_aParam[nCntSound].nCntLoop;
//
//		// �I�[�f�B�I�o�b�t�@�̓o�^
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
//	// �o�b�t�@�̒l�ݒ�
//	memset(&buffer, 0, sizeof(XAUDIO2_BUFFER));
//	buffer.AudioBytes = audioDataSize;
//	buffer.pAudioData = audioData;
//	buffer.Flags = XAUDIO2_END_OF_STREAM;
//	buffer.LoopCount = loopCount;
//
//	// ��Ԏ擾
//	voiceSource->GetState(&xa2state);
//	if (xa2state.BuffersQueued != 0) {// �Đ���
//		// �ꎞ��~
//		voiceSource->Stop(0);
//
//		// �I�[�f�B�I�o�b�t�@�̍폜
//		voiceSource->FlushSourceBuffers();
//	}
//
//	// �I�[�f�B�I�o�b�t�@�̓o�^
//	voiceSource->SubmitSourceBuffer(&buffer);
//
//	// �Đ�
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
//	if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER) {// �t�@�C���|�C���^��擪�Ɉړ�
//		return HRESULT_FROM_WIN32(GetLastError());
//	}
//
//	while (hr == S_OK) {
//		if (ReadFile(hFile, &dwChunkType, sizeof(DWORD), &dwRead, NULL) == 0) {// �`�����N�̓ǂݍ���
//			hr = HRESULT_FROM_WIN32(GetLastError());
//		}
//
//		if (ReadFile(hFile, &dwChunkDataSize, sizeof(DWORD), &dwRead, NULL) == 0) {// �`�����N�f�[�^�̓ǂݍ���
//			hr = HRESULT_FROM_WIN32(GetLastError());
//		}
//
//		switch (dwChunkType) {
//			case 'FFIR':
//				dwRIFFDataSize = dwChunkDataSize;
//				dwChunkDataSize = 4;
//				if (ReadFile(hFile, &dwFileType, sizeof(DWORD), &dwRead, NULL) == 0) {// �t�@�C���^�C�v�̓ǂݍ���
//					hr = HRESULT_FROM_WIN32(GetLastError());
//				}
//				break;
//
//			default:
//				if (SetFilePointer(hFile, dwChunkDataSize, NULL, FILE_CURRENT) == INVALID_SET_FILE_POINTER) {// �t�@�C���|�C���^���`�����N�f�[�^���ړ�
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
//	if (SetFilePointer(hFile, dwBufferoffset, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER) {// �t�@�C���|�C���^���w��ʒu�܂ňړ�
//		return HRESULT_FROM_WIN32(GetLastError());
//	}
//
//	if (ReadFile(hFile, pBuffer, dwBuffersize, &dwRead, NULL) == 0) {// �f�[�^�̓ǂݍ���
//		return HRESULT_FROM_WIN32(GetLastError());
//	}
//
//	return S_OK;
//}