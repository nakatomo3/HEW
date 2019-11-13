#include "ChargeGaugeRun.h"



ChargeGaugeRun::ChargeGaugeRun() {
}


ChargeGaugeRun::~ChargeGaugeRun() {
}

void ChargeGaugeRun::SetSprite(Sprite* _sprite) {
	sprite = _sprite;
}

void ChargeGaugeRun::SetScalerSprite(Sprite * sprite){
	scaler = sprite;
}

void ChargeGaugeRun::SetPlayer(PlayerRun * _player){
	player = _player;
}

void ChargeGaugeRun::SetBrokenTexture(Texture * texture){
	broken = texture;
}

void ChargeGaugeRun::Update(){
	if (player->GetCharge() <= 1000) {//1000ˆÈ‰º
		sprite->SetScale(new Vector2(SD_WIDTH * 0.5f, player->GetCharge() /1000*  SD_HEIGHT * 2.5 * 0.95f));
	}
	else {//1000ˆÈã‚É‚È‚ë‚¤‚Æ‚µ‚½‚çƒQ[ƒW‚ð‚Æ‚Ç‚ß‚é
		sprite->SetScale(new Vector2(SD_WIDTH * 0.5f, SD_HEIGHT * 2.5f * 0.95f));
		scaler->SetTexture(broken);
	}
}
