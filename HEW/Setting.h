#pragma once

//�ڎw��FPS�BFPS�͕K����������������Ȃ�
#define DEFAULT_FPS (60.0)

//���O�t�@�C������邩�ǂ���
#define IS_CREATE_FILE (true)

//��ʂ̔䗦(16:9)
#define WINDOW_ASPECT (16.0f/9.0f)

//�L���v�V������\�����邩�ۂ�
#define IS_VIEW_CAPTION (true)

//��ʂ̉���
#define SCREEN_WIDTH (1024)
//��ʂ̏c��
#define SCREEN_HEIGHT (SCREEN_WIDTH / WINDOW_ASPECT)

//��ʂ̉��� (Stardard Unit)
#define SD_WIDTH (SCREEN_WIDTH / 10)
//��ʂ̏c�� (Stardard Unit)
#define SD_HEIGHT (SCREEN_HEIGHT / 10)

//��ʂ̒��S(��)
#define SCREEN_CENTER_X (SCREEN_WIDTH/2)
//��ʂ̒��S(�c)
#define SCREEN_CENTER_Y (SCREEN_HEIGHT/2)

// �E�C���h�E�N���X�̖��O
#define CLASS_NAME     "GameWindow"       
// �E�B���h�E�㕔�̃��b�Z�[�W
#define WINDOW_CAPTION "HEW" 

//�I�����̃��b�Z�[�W
#define END_CONFIRMATION "�{���ɏI�����Ă�낵���ł����H"
//�I�����̃E�B���h�E�㕔�̃��b�Z�[�W
#define END_WINDOW_CAPTION "�m�F"