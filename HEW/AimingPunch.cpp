#include "AimingPunch.h"



AimingPunch::AimingPunch() {
}


AimingPunch::~AimingPunch() {
}

void AimingPunch::Start() {
}

void AimingPunch::Update() {
	rad += 0.1f;

	aimingA->SetPosition(new Vector3(cos(rad) * 50, sin(rad) * 10 + 10, 0));
	aimingB->SetPosition(new Vector3(cos(rad + PI) * 50, sin(rad + PI) * 10 - 10, 0));
}

void AimingPunch::SetSprite(bool isA, Sprite* sprite) {
	if (isA) {
		aimingA = sprite;
	} else {
		aimingB = sprite;
	}
}

float AimingPunch::GetValue() {
	float value = rad;
	while (value >= PI) {
		value -= PI;
	}
	return abs(value - PI / 2 * 3);
}
