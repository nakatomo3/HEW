#include "PendulumPunch.h"



PendulumPunch::PendulumPunch() {
}


PendulumPunch::~PendulumPunch() {

}

void PendulumPunch::Start() {

}

void PendulumPunch::Update() {
	if (isRight == true) {
		rad += 0.1f;
	} else {
		rad -= 0.1f;
	}

	if (rad >= 0) {
		isRight = false;
	}
	if (rad <= -PI) {
		isRight = true;
	}

	sprite->SetPosition(new Vector3(cos(rad) * 80, -sin(rad) * 80 - 80, 0));
}

void PendulumPunch::SetSprite(Sprite * _sprite) {
	sprite = _sprite;
}

float PendulumPunch::GetValue() {
	return rad;
}
