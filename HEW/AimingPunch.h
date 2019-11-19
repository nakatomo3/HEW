#pragma once
#include "ScriptBase.h"
#include "Sprite.h"

class AimingPunch : public ScriptBase {
public:
	AimingPunch();
	~AimingPunch();

	void Start();
	void Update();

	void SetSprite(bool isA, Sprite* sprite);

	float GetValue();

private:
	Sprite* aimingA;
	Sprite* aimingB;

	float rad;

	const float PI = 3.1415926f;
};

