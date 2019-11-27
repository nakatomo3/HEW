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

	if (run->timer >= 11) {       // ƒhƒ“ƒb 1•bŒã
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetTexture(textures[5]);

	} else if (run->timer >= 10) { // ‚æ[‚¢ 2•bŒã
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
		sprite->SetTexture(textures[4]);

	} else if (run->timer >= 8) { //‚Q‰ñ–Ú‚ÌƒAƒbƒv
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));

	} else if (run->timer >= 6) { //‚P‰ñ–Ú‚ÌƒAƒbƒv
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.6f, SCREEN_WIDTH*0.6f * 9 / 16.0f));
	
	} else if (run->timer >= 4) { //¬‚³‚¢U‚Á‚Ä‚Ì•\Ž¦
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.4f, SCREEN_WIDTH*0.4f * 9 / 16.0f));
	
	} else if (run->timer >= 3) { //‘å‚«U‚Á‚Ä‚Ì•\Ž¦
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[3]);
	
	} else if (run->timer >= 2) { //Žc‚è1•b‚Ì•\Ž¦
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[2]);
	
	} else if (run->timer >= 1) { //Žc‚è2•b‚Ì•\Ž¦
		sprite->SetScale(new Vector2(SCREEN_HEIGHT*0.8f, SCREEN_WIDTH*0.8f * 9 / 16.0f));
		sprite->SetTexture(textures[1]);
	
	} else if (run->timer >= 0) { //Žc‚è3•b‚Ì•\Ž¦
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
