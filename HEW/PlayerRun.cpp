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

float PlayerRun::GetCharge() {
	return charge;
}

int PlayerRun::SetplayerID(int id) {
	return playerID = id;

}

void PlayerRun::Update() {
	switch (playerID) {
	case 0:
		if (Input::GetInstance().GetKey(DIK_A)) {//����Q�[�W
			charge += 10.0f; //�l�͒���
			LogWriter::GetInstance().Log("A");
			LogWriter::GetInstance().Log("%d:%f", playerID, charge);
		}
		break;
	case 1:
		if (Input::GetInstance().GetKey(DIK_S)) {//�E��Q�[�W
			charge += 10.0f; //�l�͒���
			LogWriter::GetInstance().Log("S");
			LogWriter::GetInstance().Log("%d:%f", playerID, charge);
		}
		break;
	case 2:
		if (Input::GetInstance().GetKey(DIK_D)) {//�����Q�[�W
			charge += 10.0f; //�l�͒���
			LogWriter::GetInstance().Log("D");
			LogWriter::GetInstance().Log("%d:%f", playerID, charge);
		}
		break;
	case 3:
		if (Input::GetInstance().GetKey(DIK_F)) {//�E���Q�[�W
			charge += 10.0f; //�l�͒���
			LogWriter::GetInstance().Log("F");
			LogWriter::GetInstance().Log("%d:%f", playerID, charge);
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
	if (run->GetTimer() >= 1) {
		gameObject->Move(Vector3(charge * 0.05f * SCREEN_WIDTH/1024, charge * -0.00f  * SCREEN_HEIGHT/576, 0));
	}
}

void PlayerRun::SetSprite(Sprite * _sprite){
	sprite = _sprite;
}

void PlayerRun::SetScene(Run * _run){
	run = _run;
}