#pragma once
#include "ScriptBase.h"
#include "Texture.h"
#include "Sprite.h"
class ChargeGaugeRun :	public ScriptBase {
public:
	ChargeGaugeRun();
	~ChargeGaugeRun();

	void SetSprite(Sprite* sprite);

private:
	Sprite* sprite;
};