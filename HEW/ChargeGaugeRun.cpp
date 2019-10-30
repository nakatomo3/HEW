#include "ChargeGaugeRun.h"



ChargeGaugeRun::ChargeGaugeRun() {
}


ChargeGaugeRun::~ChargeGaugeRun() {
}

void ChargeGaugeRun::SetSprite(Sprite* _sprite) {
	sprite = _sprite;
}

void ChargeGaugeRun::SetPlayer(PlayerRun * _player){
	player = _player;
}

void ChargeGaugeRun::Update(){
	if (player->GetCharge() <= 1000) {//1000以下
		sprite->SetScale(new Vector2(SCREEN_WIDTH / 30, player->GetCharge() /1000*  SCREEN_HEIGHT / 3 ));
	}
	else {//1000以上になろうとしたらゲージをとどめる
		sprite->SetScale(new Vector2(SCREEN_WIDTH / 30, SCREEN_HEIGHT / 3));
	}
}
