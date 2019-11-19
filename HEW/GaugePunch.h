#pragma once
#include "ScriptBase.h"
#include "Sprite.h"
class GaugePunch : public ScriptBase {
public:
	GaugePunch();
	~GaugePunch();

	void Update();

	void SetSprite(Sprite* _sprite);

	void SetPlayer(int value);

	float GetValue();

private:
	Sprite* sprite;

	int player;

	bool isUp = true;
	float value = 0;
	float VALUE_MAX = 1000;
};

