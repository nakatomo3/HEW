#include "PlayerPunch.h"
#include "Input.h"
#include "LogWriter.h"
#include "ObjectManager.h"
#include "MegatonPunch.h"
#include "SceneManager.h"

PlayerPunch::PlayerPunch() {
}


PlayerPunch::~PlayerPunch() {
}

void PlayerPunch::SetSprite(Sprite * _sprite) {
	sprite = _sprite;
}

void PlayerPunch::SetPlayer(Player player) {
	thisPlayer = player;
}

void PlayerPunch::SetPlayerNumber(int number) {
	playerNumber = number;
}

void PlayerPunch::SetGauge(GaugePunch* _gauge) {
	gauge = _gauge;
}

void PlayerPunch::SetAiming(AimingPunch * _aiming) {
	aiming = _aiming;
}

void PlayerPunch::SetPendulum(PendulumPunch * _pendulum) {
	pendulum = _pendulum;
}

void PlayerPunch::Start() {
	switch (playerNumber) {
	default:
		break;
	case 0:
		KEY = DIK_A;
		break;
	case 1:
		KEY = DIK_S;
		break;
	case 2:
		KEY = DIK_D;
		break;
	case 3:
		KEY = DIK_F;
		break;
	}

	megatonPunch = (MegatonPunch*)SceneManager::GetInstance().GetNowScene();
}

void PlayerPunch::Update() {
	switch (nowMode) {
		default:
			break;
		case GAUGE:
			if (Input::GetInstance().GetKeyDown(KEY)) {
				gaugeValue = gauge->GetValue();
				ObjectManager::GetInstance().Destroy(gauge->GetGameObject());
				ObjectManager::GetInstance().Instantiate(aiming->GetGameObject());
				nowMode = AIMING;
			}
			break;
		case AIMING:
			if (Input::GetInstance().GetKeyDown(KEY)) {
				aimingValue = aiming->GetValue();
				ObjectManager::GetInstance().Destroy(aiming->GetGameObject());
				ObjectManager::GetInstance().Instantiate(pendulum->GetGameObject());
				nowMode = PENDULUM;
			}
			break;
		case PENDULUM:
			if (Input::GetInstance().GetKeyDown(KEY)) {
				pendulumValue = pendulum->GetValue();
				ObjectManager::GetInstance().Destroy(pendulum->GetGameObject());
				nowMode = WAIT;
			}
			break;
		case WAIT:
			megatonPunch->SetWaiting(playerNumber);
			value = gaugeValue / 10 + (1 - aimingValue) * 100 + (1 - pendulumValue) * 100;
			break;
		case BREAKING:
			text->SetActive(true);
			int intValue = floor(value);
			text->text = to_string(intValue) + "km";
			break;
	}

}

void PlayerPunch::SetBreakingFlag() {
	nowMode = BREAKING;
}

void PlayerPunch::SetText(Text * _text) {
	text = _text;
}
