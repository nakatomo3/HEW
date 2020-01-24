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
	string path = "";

	switch (characterID) {
	case 0:
		path = ""; //�������摜���ɕς���
		break;
	case 1:
		path = ""; //�������摜���ɕς���
		break;
	case 2:
		path = ""; //�������摜���ɕς���
		break;
	case 3:
		path = ""; //�������摜���ɕς���
		break;
	}

	playerTexture = new Texture(path /*+�ʉ摜��*/);
	sprite->SetTexture(playerTexture);
	playerTexture2 = new Texture(path /*+�ʉ摜��*/);
	playerTexture3 = new Texture(path /*+�ʉ摜��*/);

	runTextureA = new Texture(path /*+ run.png�Ƃ��摜��*/);
	runTextureB = new Texture(path /*+ run.png�Ƃ��摜��*/);
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
		}
		break;
	case 1:
		if (Input::GetInstance().GetKey(DIK_S) && run->timer >= 4 && run->timer <= 10) { // �E��Q�[�W �������U���Ă��\�������Ɠ�����S�L�[�Ń`���[�W�\
			charge += 10.0f; // �l�͒���                                                                         ��[�����\�������ƃ`���[�W�͕s�\
		}
		break;
	case 2:
		if (Input::GetInstance().GetKey(DIK_D) && run->timer >= 4 && run->timer <= 10) { // �����Q�[�W �������U���Ă��\�������Ɠ�����D�L�[�Ń`���[�W�\
			charge += 10.0f; // �l�͒���                                                                         ��[�����\�������ƃ`���[�W�͕s�\
		}
		break;
	case 3:
		if (Input::GetInstance().GetKey(DIK_F) && run->timer >= 4 && run->timer <= 10) { // �E���Q�[�W �������U���Ă��\�������Ɠ�����F�L�[�Ń`���[�W�\
			charge += 10.0f; // �l�͒���                                                                         ��[�����\�������ƃ`���[�W�͕s�\
		}
		break;
	}

	if (charge >= 600.0f) {
		sprite->SetTexture(playerTexture3); 
	}

	else if (charge >= 300.0f) {
		sprite->SetTexture(playerTexture2);
	}

	//�p�x8�x���炢��0.1�b�ňړ�
	if (run->timer >= 12 && isReplay == false) {
		gameObject->Move(Vector3(charge * 0.03f * SCREEN_WIDTH/1024, charge * -0.00f  * SCREEN_HEIGHT/576, 0));
		run->SetTime(playerID, 500 / charge);
	}

	if (run->timer >= 16.5f) {
		isReplay = true;
		
	}

	//���v���C���x�̈ړ�
	if (isReplay == true) {
		if (run->timer <= 22.5f) {
			gameObject->Move(Vector3(charge * 0.003f * SCREEN_WIDTH / 1024.0, charge * -0.00f  * SCREEN_HEIGHT / 576, 0));
		} else {
			gameObject->Move(Vector3(charge * 0.002f * SCREEN_WIDTH / 1024.0, charge * -0.00f  * SCREEN_HEIGHT / 576, 0));
		}
	}
}

void PlayerRun::SetSprite(Sprite * _sprite){
	sprite = _sprite;
}

void PlayerRun::SetScene(Run * _run){
	run = _run;
}

void PlayerRun::SetCharacterID(int id) {
	characterID = id;
}
