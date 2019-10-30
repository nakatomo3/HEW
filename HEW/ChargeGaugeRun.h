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
	void SetPlayer(PlayerRun* _player);

	void Update();

private:
	Sprite* sprite;
	PlayerRun* player;
};