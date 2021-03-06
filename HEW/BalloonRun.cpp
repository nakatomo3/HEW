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

	if (run->timer >= 11) {       // ドンッ 1秒後
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetTexture(textures[5]);

	} else if (run->timer >= 10) { // よーい 2秒後
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetTexture(textures[4]);

	} else if (run->timer >= 8) { //２回目のアップ
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));

	} else if (run->timer >= 6) { //１回目のアップ
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.6f, SCREEN_WIDTH*0.6f * 9 / 16.0f));
	
	} else if (run->timer >= 4) { //小さい振っての表示
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
	
	} else if (run->timer >= 3) { //大き振っての表示
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[3]);
	
	} else if (run->timer >= 2) { //残り1秒の表示
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[2]);
	
	} else if (run->timer >= 1) { //残り2秒の表示
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[1]);
	
	} else if (run->timer >= 0) { //残り3秒の表示
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
