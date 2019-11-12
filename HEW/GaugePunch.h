#pragma once
#include "ScriptBase.h"
#include "Sprite.h"
class GaugePunch : public ScriptBase {
public:
	GaugePunch();
	~GaugePunch();

	void Update();

	void SetSprite(Sprite* _sprite);

private:
	Sprite* sprite;

	bool isUp = true;
	float value = 0;
	float VALUE_MAX = 1000;
};

