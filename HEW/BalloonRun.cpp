#include "BalloonRun.h"
#include "Run.h"

BalloonRun::BalloonRun() {
}


BalloonRun::~BalloonRun() {
}

void BalloonRun::Start(){

}

void BalloonRun::Update(){
	if (run == NULL) {
		run = dynamic_cast<Run*>(SceneManager::GetInstance().GetNowScene());
	}

	if (run->timer >= 11) {       // �h���b 1�b��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetTexture(textures[5]);

	} else if (run->timer >= 10) { // ��[�� 2�b��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetTexture(textures[4]);

	} else if (run->timer >= 8) { //�Q��ڂ̃A�b�v
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));

	} else if (run->timer >= 6) { //�P��ڂ̃A�b�v
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.6f, SCREEN_WIDTH*0.6f * 9 / 16.0f));
	
	} else if (run->timer >= 4) { //�������U���Ă̕\��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
	
	} else if (run->timer >= 3) { //�傫�U���Ă̕\��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[3]);
	
	} else if (run->timer >= 2) { //�c��1�b�̕\��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[2]);
	
	} else if (run->timer >= 1) { //�c��2�b�̕\��
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[1]);
	
	} else if (run->timer >= 0) { //�c��3�b�̕\��
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
