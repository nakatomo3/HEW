#include "AimingPunch.h"



AimingPunch::AimingPunch() {
}


AimingPunch::~AimingPunch() {
}

void AimingPunch::Start() {
}

void AimingPunch::Update() {
	rad += speed;

	aimingA->SetPosition(new Vector3(cos(rad) * radiusX, sin(rad) * radiusY + radiusY, 0));
	aimingB->SetPosition(new Vector3(cos(rad + PI) * radiusX, sin(rad + PI) * radiusY - radiusY, 0));

	if (abs(rad - PI * 3 / 2.0f) <= whiteRange) {
		aimingA->SetTexture(white);
		aimingB->SetTexture(white);
	} else {
		aimingA->SetTexture(normal);
		aimingB->SetTexture(normal);
	}

	if (rad >= 2 * PI) {
		rad -= PI * 2;
	}
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
	while (value >= PI * 2) {
		value -= PI * 2;
	}
	return abs(rad - PI * 3 / 2.0f);
}

void AimingPunch::SetNormalTexture(Texture* _texture) {
	normal = _texture;
}

void AimingPunch::SetWhiteTexture(Texture * _texture) {
	white = _texture;
}
