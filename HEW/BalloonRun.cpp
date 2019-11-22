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

	if (run->GetTimer() >= 11) {       // �h���b 1�b��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetTexture(textures[5]);

	} else if (run->GetTimer() >= 10) { // ��[�� 2�b��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetTexture(textures[4]);

	} else if (run->GetTimer() >= 8) { //�Q��ڂ̃A�b�v
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));

	} else if (run->GetTimer() >= 6) { //�P��ڂ̃A�b�v
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.6f, SCREEN_WIDTH*0.6f * 9 / 16.0f));
	
	} else if (run->GetTimer() >= 4) { //�������U���Ă̕\��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
	
	} else if (run->GetTimer() >= 3) { //�傫�U���Ă̕\��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[3]);
	
	} else if (run->GetTimer() >= 2) { //�c��1�b�̕\��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[2]);
	
	} else if (run->GetTimer() >= 1) { //�c��2�b�̕\��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[1]);
	
	} else if (run->GetTimer() >= 0) { //�c��3�b�̕\��
		sprite->SetTexture(textures[0]);
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));

	}
}

void BalloonRun::SetSprite(Sprite * _sprite){
	sprite = _sprite;
}

void BalloonRun::SetTexture(Texture * texture) {
	textures.emplace_back(texture);
}
