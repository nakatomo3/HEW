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
	case 0://�E���t
		path = "assets/textures/Run/Player/masukudourufu/"; //�������摜���ɕς���@�@�e�t�@�C���܂łԂ�����
		break;
	case 1://��������
		path = "assets/textures/Run/Player/kasikomk2/"; //�������摜���ɕς���
		break;
	case 2://����
		path = "assets/textures/Run/Player/senntyann/"; //�������摜���ɕς���
		break;
	case 3://�F��
		path = "assets/textures/Run/Player/utyuujinn/"; //�������摜���ɕς���
		break;
	}

	playerTexture = new Texture(path + "waiting1.png"/*+�ʉ摜��*/);//�摜�̖��O�͓��ꂵ������Ԃ�����  �N���E�`���O
	sprite->SetTexture(playerTexture);
	playerTexture2 = new Texture(path + "waiting2.png"/*+�ʉ摜��*/);
	playerTexture3 = new Texture(path + "waiting3.png"/*+�ʉ摜��*/);

	runTextureA = new Texture(path + "runA.png"/*+ run.png�Ƃ��摜��*/);//�����Ă�
	runTextureB = new Texture(path + "runB.png"/*+ run.png�Ƃ��摜��*/);
	runTextureC = new Texture(path + "runC.png");

	ZeroMemory(&state, sizeof(XINPUT_STATE));
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

	DWORD dwResult = XInputGetState(playerID, &state);

	switch (playerID) {
	case 0:
		if (run->timer >= 4 && run->timer <= 10) {
			if (Input::GetInstance().GetKey(DIK_A)) { // ����Q�[�W �������U���Ă��\�������Ɠ�����A�L�[�Ń`���[�W�\
				charge += 10.0f; // �l�͒���                                                                         ��[�����\�������ƃ`���[�W�͕s�\
			}
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
	if (run->timer >= 4 && run->timer <= 10) {
		charge += abs(state.Gamepad.bRightTrigger - 128) * 0.03f;
	}

	if (charge >= 600.0f) {
		sprite->SetTexture(playerTexture3);
	}

	else if (charge >= 300.0f) {
		sprite->SetTexture(playerTexture2);
	}

	if (run->timer > 12.0f) {
		isReady = true;
	} else if(run->timer>17.0f) {
		isReady = false;
	}

	if (isReady == true) {
		switch (characterID) {
		default:
			break;
		case 0://�E���t
			float animationTimer = run->timer;
			float animationInterval = 0.2f;//�A�j���[�V�������x
			while (animationTimer > animationInterval) {
				animationTimer -= animationInterval;
			}
			if (animationTimer <= 0.1f) {
				sprite->SetTexture(runTextureA);
			}
			if (animationTimer >= 0.1f) {
				sprite->SetTexture(runTextureB);
			}
			break;
		case 1://��������
			//�A�j���[�V�����Ȃ�
			break;
		case 2://���񂿂��
			//�A�j���[�V�����Ȃ�
			break;
		case 3://�F��
			if (charge <= 300) {//�Q�[�W�̃`���[�W�i�K�ŕύX
				sprite->SetTexture(runTextureA);
			}
			if (charge >= 600) {
				sprite->SetTexture(runTextureB);
			}
			if (charge >= 900) {
				sprite->SetTexture(runTextureC);
			}
		}
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
