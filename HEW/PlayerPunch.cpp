#include "PlayerPunch.h"
#include "Input.h"
#include "LogWriter.h"
#include "ObjectManager.h"
#include "MegatonPunch.h"
#include "SceneManager.h"
#include "Time.h"

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

	string path = "";

	int characterID = VariableManager::GetInstance().GetInt("character" + to_string(playerNumber));

	switch (characterID) {
	case 0://ウルフ
		path = "assets/textures/MegatonPunch/Player/masukudourufu/"; //ここを画像名に変える　　各ファイルまでぶち込み
		break;
	case 1://かしこま
		path = "assets/textures/MegatonPunch/Player/kasikomk2/"; //ここを画像名に変える
		break;
	case 2://せん
		path = "assets/textures/MegatonPunch/Player/senntyann/"; //ここを画像名に変える
		break;
	case 3://宇宙
		path = "assets/textures/MegatonPunch/Player/utyuujinn/"; //ここを画像名に変える
		break;
	}

	readyTexture = new Texture(path + "ready.png"/*+個別画像名*/);//画像の名前は統一しそれをぶち込む
	sprite->SetTexture(readyTexture);
	punchTexture = new Texture(path + "punch.png"/*+個別画像名*/);

	megatonPunch = (MegatonPunch*)SceneManager::GetInstance().GetNowScene();
}

void PlayerPunch::Update() {
	switch (nowMode) {
		default:
			break;
		case GAUGE:
			if (Input::GetInstance().GetKeyDown(KEY) || (Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_Y) == true) {
				gaugeValue = gauge->GetValue();
				ObjectManager::GetInstance().Destroy(gauge->GetGameObject());
				ObjectManager::GetInstance().Instantiate(aiming->GetGameObject());
				nowMode = AIMING;
			}
			break;
		case AIMING:
			if (Input::GetInstance().GetKeyDown(KEY) || (Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_Y) == true) {
				aimingValue = aiming->GetValue();
				ObjectManager::GetInstance().Destroy(aiming->GetGameObject());
				ObjectManager::GetInstance().Instantiate(pendulum->GetGameObject());
				nowMode = PENDULUM;
			}
			break;
		case PENDULUM:
			if (Input::GetInstance().GetKeyDown(KEY) || (Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(playerNumber).Gamepad.wButtons & XINPUT_GAMEPAD_Y) == true) {
				pendulumValue = pendulum->GetValue();
				ObjectManager::GetInstance().Destroy(pendulum->GetGameObject());
				nowMode = WAIT;
				isBreaking = true;//trueにする
				if (isBreaking == true) {//trueになった時
					switch (characterID) {
					default:
						break;
					case 0://ウルフ
						sprite->SetTexture(punchTexture);
						break;
					case 1://かしこま
						sprite->SetTexture(punchTexture);
						break;
					case 2://せんちゃん
						sprite->SetTexture(punchTexture);
						break;
					case 3://宇宙
						sprite->SetTexture(punchTexture);
						break;
					}
				}
			}
			break;
		case WAIT:
			megatonPunch->SetWaiting(playerNumber);
			value = gaugeValue / 10 + (1 - aimingValue) * 100 + (1 - pendulumValue) * 100;
			break;
		case BREAKING:
			sprite->SetActive(false);
			waitTimer += Time::GetInstance().GetDeltaTime();
			if (waitTimer < value / 1800) {
				breaking->SetScale(new Vector2(SCREEN_WIDTH * 0.05, SCREEN_HEIGHT * waitTimer * 3));
				breaking->SetTextureScale(1, waitTimer * value / 60);
			}
		case VIEWSCORE:
			text->SetActive(true);
			int intValue = floor(value);
			text->text = to_string(intValue) + "km";
			VariableManager::GetInstance().SetInt("megatonScore" + to_string(playerNumber), value);
			break;
	}
	
}

void PlayerPunch::SetBreakingFlag() {
	nowMode = BREAKING;
}

void PlayerPunch::SetText(Text * _text) {
	text = _text;
}

void PlayerPunch::SetBreaking(Sprite * sprite) {
	breaking = sprite;
}
