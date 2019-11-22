#include "PendulumPunch.h"



PendulumPunch::PendulumPunch() {
}


PendulumPunch::~PendulumPunch() {

}

void PendulumPunch::Start() {

}

void PendulumPunch::Update() {
	if (isRight == true) {
		rad += 0.05f;
	} else {
		rad -= 0.05f;
	}

	if (rad >= 0) {
		isRight = false;
	}
	if (rad <= -PI) {
		isRight = true;
	}

	sprite->SetPosition(new Vector3(cos(rad) * 80, -sin(rad) * 80 - 80, 0));

	if (abs(rad + PI / 2) <= 0.1f) {
		sprite->SetTexture(white);
	} else {
		sprite->SetTexture(normal);
	}
}

void PendulumPunch::SetSprite(Sprite * _sprite) {
	sprite = _sprite;
}

float PendulumPunch::GetValue() {
	return rad;
}

void PendulumPunch::SetNormalTexture(Texture * _texture) {
	normal = _texture;
}

void PendulumPunch::SetWhiteTexutre(Texture * _texture) {
	white = _texture;
}
