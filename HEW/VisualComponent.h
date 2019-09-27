#pragma once
#include "Component.h"

//�|�W�V�����̊�l�B��{�͐^�񒆂����ύX�\
typedef enum Criterion {
	CENTER,
	LEFT_UP,
	UP,
	RIGHT_UP,
	RIGHT,
	RIGHT_DOWN,
	DOWN,
	DOWN_LEFT,
	LEFT
};

class VisualComponent :	public Component {
public:
	VisualComponent();
	~VisualComponent();

	//�`��Ɋ�����R���|�[�l���g�ł��鎞������I�[�o�[���C�h���Ďg�p�B
	virtual void Draw();

	//�Ō�ɕ`�悷��p�̊֐��BUI�Ȃǂ�z��
	virtual void LateDraw();

};

