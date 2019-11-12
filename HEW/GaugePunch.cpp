#include "GaugePunch.h"
#include "Time.h"


GaugePunch::GaugePunch() {
}


GaugePunch::~GaugePunch() {
}

void GaugePunch::Update() {
	if (isUp == true) {
		value += VALUE_MAX / 2 * Time::GetInstance().GetDeltaTime();
	} else {
		value -= VALUE_MAX / 2 * Time::GetInstance().GetDeltaTime();
	}
	if (value >= VALUE_MAX) {
		value = 1000;
		isUp = false;
	}
	if (value <= 0) {
		value = 0;
		isUp = true;
	}

	sprite->SetScale(new Vector2(SCREEN_WIDTH / 21, SCREEN_HEIGHT / 5 * 2 * value / VALUE_MAX * 0.95f));
	if (value != 0) {
		sprite->SetColor(new Color(value / VALUE_MAX * 255, 255 - value / VALUE_MAX * 255, 255 - value / VALUE_MAX * 255, 255));
	}
	if (value >= 970) {
		sprite->SetColor(new Color(255, 255, 255, 255));
	}
}

void GaugePunch::SetSprite(Sprite * _sprite) {
	sprite = _sprite;
}
