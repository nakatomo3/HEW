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


	//２回目のアップ
	if (run->GetTimer() >= 4) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
	}

	//１回目のアップ
	else if (run->GetTimer() >= 2) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.6f, SCREEN_WIDTH*0.6f * 9 / 16.0f));
	}

	//最初の表示
	else if (run->GetTimer() >= 0) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
	}
}

void BalloonRun::SetSprite(Sprite * _sprite){
	sprite = _sprite;
}
