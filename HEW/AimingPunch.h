#pragma once
#include "ScriptBase.h"
#include "Sprite.h"
class AimingPunch : public ScriptBase {
public:
	AimingPunch();
	~AimingPunch();

private:
	Sprite* aimingA;
	Sprite* aimingB;

};

