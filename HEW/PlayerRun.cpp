#include "PlayerRun.h"
#include "Input.h"

#include "Sprite.h"
#include "Texture.h"
#include "Run.h"
#include "SceneManager.h"



PlayerRun::PlayerRun() {

}


PlayerRun::~PlayerRun() {

}

void PlayerRun::Start() {

}

float PlayerRun::GetCharge() {
	return charge;
}

int PlayerRun::SetplayerID(int id) {
	return playerID = id;

}

void PlayerRun::Update() {

	if (run == NULL) {
		run = (Run*)(SceneManager::GetInstance().GetNowScene());
	}

	switch (playerID) {
	case 0:
		if (Input::GetInstance().GetKey(DIK_A) && run->timer >= 4 && run->timer <= 10) { // ����Q�[�W �������U���Ă��\�������Ɠ�����A�L�[�Ń`���[�W�\
			charge += 10.0f; // �l�͒���                                                                         ��[�����\�������ƃ`���[�W�͕s�\
			LogWriter::GetInstance().Log("A"); // ������Ă��邩�̊m�F���O �\���FA
			LogWriter::GetInstance().Log("%d:%f", playerID, charge); // �`���[�W����Ă��邩�̃��O
		}
		break;
	case 1:
		if (Input::GetInstance().GetKey(DIK_S) && run->timer >= 4 && run->timer <= 10) { // �E��Q�[�W �������U���Ă��\�������Ɠ�����S�L�[�Ń`���[�W�\
			charge += 10.0f; // �l�͒���                                                                         ��[�����\�������ƃ`���[�W�͕s�\
			LogWriter::GetInstance().Log("S"); // ������Ă��邩�̊m�F���O �\���FS
			LogWriter::GetInstance().Log("%d:%f", playerID, charge); // �`���[�W����Ă��邩�̃��O
		}
		break;
	case 2:
		if (Input::GetInstance().GetKey(DIK_D) && run->timer >= 4 && run->timer <= 10) { // �����Q�[�W �������U���Ă��\�������Ɠ�����D�L�[�Ń`���[�W�\
			charge += 10.0f; // �l�͒���                                                                         ��[�����\�������ƃ`���[�W�͕s�\
			LogWriter::GetInstance().Log("D"); // ������Ă��邩�̊m�F���O �\���FD
			LogWriter::GetInstance().Log("%d:%f", playerID, charge); // �`���[�W����Ă��邩�̃��O
		}
		break;
	case 3:
		if (Input::GetInstance().GetKey(DIK_F) && run->timer >= 4 && run->timer <= 10) { // �E���Q�[�W �������U���Ă��\�������Ɠ�����F�L�[�Ń`���[�W�\
			charge += 10.0f; // �l�͒���                                                                         ��[�����\�������ƃ`���[�W�͕s�\
			LogWriter::GetInstance().Log("F"); // ������Ă��邩�̊m�F���O �\���FF
			LogWriter::GetInstance().Log("%d:%f", playerID, charge); // �`���[�W����Ă��邩�̃��O
		}
		break;
	}

	if (charge >= 600.0f) {
		sprite->SetColor(D3DCOLOR_RGBA(100, 100, 0, 230));
	}

	else if (charge >= 300.0f) {
		sprite->SetColor(D3DCOLOR_RGBA(200, 0, 0, 230));
	}

	//�p�x8�x���炢��0.1�b�ňړ�
	if (run->timer >= 12 && isReplay == false) {
		gameObject->Move(Vector3(charge * 0.05f * SCREEN_WIDTH/1024, charge * -0.00f  * SCREEN_HEIGHT/576, 0));
		run->SetTime(playerID, 500 / charge);
	}

	if (run->timer >= 16.5f) {
		isReplay = true;
		
	}

	//���v���C���x�̈ړ�
	if (isReplay == true) {
		LogWriter::GetInstance().Log("charge:%f", charge);
		LogWriter::GetInstance().Log("all:%f", charge * 0.005 * SCREEN_WIDTH / 1024.0);
		gameObject->Move(Vector3(charge * 0.005 * SCREEN_WIDTH / 1024.0, charge * -0.00f  * SCREEN_HEIGHT / 576, 0));
	}
}

void PlayerRun::SetSprite(Sprite * _sprite){
	sprite = _sprite;
}

void PlayerRun::SetScene(Run * _run){
	run = _run;
}