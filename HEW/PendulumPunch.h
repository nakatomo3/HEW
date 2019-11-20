#pragma once
#include "ScriptBase.h"
#include "Sprite.h"
class PendulumPunch : public ScriptBase {
public:
	PendulumPunch();
	~PendulumPunch();

	void Start();
	void Update();

	void SetSprite(Sprite* sprite);

	float GetValue();

private:
	Sprite* sprite;

	bool isRight = true;

	float rad;

	const float PI = 3.1415926f;
};

