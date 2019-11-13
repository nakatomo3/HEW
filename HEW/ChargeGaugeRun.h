#pragma once
#include "ScriptBase.h"
#include "Texture.h"
#include "Sprite.h"
#include "PlayerRun.h"

class ChargeGaugeRun :	public ScriptBase {
public:
	ChargeGaugeRun();
	~ChargeGaugeRun();

	void SetSprite(Sprite* sprite);
	void SetScalerSprite(Sprite* sprite);
	void SetPlayer(PlayerRun* _player);

	void SetBrokenTexture(Texture* texture);

	void Update();

private:
	Texture* broken;
	Sprite* sprite;
	Sprite* scaler;
	PlayerRun* player;
};