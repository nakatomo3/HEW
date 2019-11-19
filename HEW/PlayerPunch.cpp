#include "PlayerPunch.h"
#include "Input.h"
#include "LogWriter.h"
#include "ObjectManager.h"

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
}

void PlayerPunch::Update() {
	switch (nowMode) {
		default:
			break;
		case GAUGE:
			if (Input::GetInstance().GetKeyDown(DIK_A)) {
				gaugeValue = gauge->GetValue();
				ObjectManager::GetInstance().Destroy(gauge->GetGameObject());
				ObjectManager::GetInstance().Instantiate(aiming->GetGameObject());
				nowMode = AIMING;
			}
			break;
		case AIMING:
			if (Input::GetInstance().GetKeyDown(DIK_A)) {
				aimingValue = aiming->GetValue();
				ObjectManager::GetInstance().Destroy(aiming->GetGameObject());
				ObjectManager::GetInstance().Instantiate(pendulum->GetGameObject());
				nowMode = PENDULUM;
			}
			break;
		case PENDULUM:
			if (Input::GetInstance().GetKeyDown(DIK_A)) {
				pendulumValue = pendulum->GetValue();
				ObjectManager::GetInstance().Destroy(pendulum->GetGameObject());
				nowMode = WAIT;
			}
			break;
		case WAIT:
			break;
		case BREAKING:
			break;
	}

}
