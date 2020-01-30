#include "Rule.h"
#include "Time.h"
#include "VariableManager.h"
#include "Input.h"
#include "SceneManager.h"

Rule::Rule(string name) : Scene(name) {
}


Rule::~Rule() {
}

void Rule::Start() {
	ObjectManager::GetInstance().Instantiate(backgroundObject);
	ObjectManager::GetInstance().Instantiate(ruleObject);

	for (int i = 0; i < playerCount; i++) {
		isReady.emplace_back(false);
	}
}

void Rule::Load() {
	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	//Background
	backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);

	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));
	backgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.001));
	backgroundSprite->SetColor(new Color(0, 0, 0, 0));


	//Rule
	ruleObject = new GameObject();
	ruleSprite = new Sprite();
	ruleObject->AddComponent(ruleSprite);

	ruleSprite->SetScale(new Vector2(SD_WIDTH * 10.0f, SD_HEIGHT * 7.0f));
	ruleSprite->SetPosition(new Vector3(SD_WIDTH * 5.0f, SD_HEIGHT * 3.5f, -0.001));
	ruleSprite->SetColor(new Color(100, 100, 100, 200));

	okTexture = new Texture("assets/textures/All/UI/OK.png");

	for (int i = 0; i < playerCount; i++) {
		string path = "assets/textures/All/UI/";
		path += to_string(i + 1) + "P.png";
		Texture* playerTexture = new Texture(path, to_string(i) + "P");

		Sprite* player = new Sprite(playerTexture);
		player->SetScale(new Vector2(SD_HEIGHT * 1.3f, SD_HEIGHT * 1.3f));
		player->SetPosition(new Vector3(SCREEN_WIDTH * (i * 0.25f + 0.125f), SCREEN_HEIGHT * 0.775f, 0));
		players.emplace_back(player);
		backgroundObject->AddComponent(player);

		Sprite* ok = new Sprite(okTexture);
		ok->SetScale(new Vector2(SCREEN_HEIGHT * 0.17f, SCREEN_HEIGHT * 0.17f));
		ok->SetPosition(new Vector3(SCREEN_WIDTH * (i * 0.25f + 0.125f), SCREEN_HEIGHT * 0.92f, 0));
		ok->SetColor(new Color(128, 128, 128, 255));
		oks.emplace_back(ok);
		backgroundObject->AddComponent(ok);
	}

}

void Rule::Update() {

	if (playerCount >= 1) {
		if (Input::GetInstance().GetKeyDown(DIK_A) == true || ((Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_Y))) {// A‚ð‰Ÿ‚µ‚½‚çtrue
			isReady[0] = true;
		}
	}
	if (playerCount >= 2) {
		if (Input::GetInstance().GetKeyDown(DIK_S) == true || (Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_Y)) {// S‚ð‰Ÿ‚µ‚½‚çtrue
			isReady[1] = true;
		}
	}
	if (playerCount >= 3) {
		if (Input::GetInstance().GetKeyDown(DIK_D) == true || (Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_Y)) {// D‚ð‰Ÿ‚µ‚½‚çtrue
			isReady[2] = true;
		}
	}
	if (playerCount >= 4) {
		if (Input::GetInstance().GetKeyDown(DIK_F) == true || (Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_Y)) {// F‚ð‰Ÿ‚µ‚½‚çtrue
			isReady[3] = true;
		}
	}

	for (int i = 0; i < playerCount; i++) {

		if (isReady[i] == false) {
			oks[i]->SetColor(new Color(128, 128, 128, 255));
		} else {
			oks[i]->SetColor(new Color(255, 255, 255, 255));
		}
	}

	bool isAllReady = true;
	for (int i = 0; i < playerCount; i++) {
		if (isReady[i] == false) {
			isAllReady = false;
			break;
		}
	}

	if (isAllReady == true) {
		SceneManager::GetInstance().LoadScene("characterSelect");
	}

}

void Rule::UnLoad() {
	ObjectManager::GetInstance().Destroy(backgroundObject);
	ObjectManager::GetInstance().Destroy(ruleObject);
}