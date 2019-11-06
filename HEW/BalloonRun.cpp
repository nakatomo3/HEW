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


	//�Q��ڂ̃A�b�v
	if (run->GetTimer() >= 4) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
	}

	//�P��ڂ̃A�b�v
	else if (run->GetTimer() >= 2) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.6f, SCREEN_WIDTH*0.6f * 9 / 16.0f));
	}

	//�ŏ��̕\��
	else if (run->GetTimer() >= 0) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
	}
}

void BalloonRun::SetSprite(Sprite * _sprite){
	sprite = _sprite;
}
