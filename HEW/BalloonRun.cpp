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


	//ƒhƒ“ƒb 1•bŒã
	if (run->GetTimer() >= 11) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetColor(D3DCOLOR_RGBA(250, 0, 0, 230));
	}

	//‚æ[‚¢ 2•bŒã
	else if (run->GetTimer() >= 10) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetColor(D3DCOLOR_RGBA(0, 250, 0, 230));
	}

	//‚Q‰ñ–Ú‚ÌƒAƒbƒv
	else if (run->GetTimer() >= 8) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
	}

	//‚P‰ñ–Ú‚ÌƒAƒbƒv
	else if (run->GetTimer() >= 6) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.6f, SCREEN_WIDTH*0.6f * 9 / 16.0f));
	}

	//¬‚³‚¢U‚Á‚Ä‚Ì•\Ž¦
	else if (run->GetTimer() >= 4) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
	}

	//‘å‚«U‚Á‚Ä‚Ì•\Ž¦
	else if (run->GetTimer() >= 3) {
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetColor(D3DCOLOR_RGBA(0, 0, 0, 230));
	}

	//Žc‚è1•b‚Ì•\Ž¦
	else if (run->GetTimer() >= 2) {
		oneSprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		oneSprite->SetColor(D3DCOLOR_RGBA(0, 0, 100, 230));
	}

	//Žc‚è2•b‚Ì•\Ž¦
	else if (run->GetTimer() >= 1) {
		twoSprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		twoSprite->SetColor(D3DCOLOR_RGBA(0, 100, 0, 230));
	}

	//Žc‚è3•b‚Ì•\Ž¦
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
