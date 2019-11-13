#include "BalloonRun.h"
#include "Run.h"

Run* run;
BalloonRun::BalloonRun() {
}


BalloonRun::~BalloonRun() {
}

void BalloonRun::Start(){
	 run = dynamic_cast<Run*>(SceneManager::GetInstance().GetNowScene());
}

void BalloonRun::Update(){


	//�h���b 1�b��
	if (run->GetTimer() >= 11) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetColor(D3DCOLOR_RGBA(250, 0, 0, 230));
	}

	//��[�� 2�b��
	else if (run->GetTimer() >= 10) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetColor(D3DCOLOR_RGBA(0, 250, 0, 230));
	}

	//�Q��ڂ̃A�b�v
	else if (run->GetTimer() >= 8) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
	}

	//�P��ڂ̃A�b�v
	else if (run->GetTimer() >= 6) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.6f, SCREEN_WIDTH*0.6f * 9 / 16.0f));
	}

	//�������U���Ă̕\��
	else if (run->GetTimer() >= 4) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
	}

	//�傫�U���Ă̕\��
	else if (run->GetTimer() >= 3) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetColor(D3DCOLOR_RGBA(0, 0, 0, 230));
	}

	//�c��1�b�̕\��
	else if (run->GetTimer() >= 2) {
		oneSprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		oneSprite->SetColor(D3DCOLOR_RGBA(0, 0, 100, 230));
	}

	//�c��2�b�̕\��
	else if (run->GetTimer() >= 1) {
		twoSprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		twoSprite->SetColor(D3DCOLOR_RGBA(0, 100, 0, 230));
	}

	//�c��3�b�̕\��
	else if (run->GetTimer() >= 0) {
		threeSprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		threeSprite->SetColor(D3DCOLOR_RGBA(100, 0, 0, 230));
	}
}

void BalloonRun::SetSprite(Sprite * _sprite){
	sprite = _sprite;
	oneSprite = _sprite;
	twoSprite = _sprite;
	threeSprite = _sprite;
}
