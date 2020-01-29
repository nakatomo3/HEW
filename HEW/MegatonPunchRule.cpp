#include "MegatonPunchRule.h"
#include "Input.h"
#include "SceneManager.h"
#include "VariableManager.h"

MegatonPunchRule::MegatonPunchRule(string name) : Scene(name){
}

MegatonPunchRule::~MegatonPunchRule() {
}

void MegatonPunchRule::Start() {
	ObjectManager::GetInstance().Instantiate(manualObject);
	for (int i = 0; i < playerCount; i++) {
		isReady.emplace_back(false);
	}
}

void MegatonPunchRule::Load() {
	manualObject = new GameObject();
	manualSprite = new Sprite();
	manualObject->AddComponent(manualSprite);

	manualSprite->SetScale(new Vector2(SD_WIDTH * 10.0f, SD_HEIGHT * 7.0f));
	manualSprite->SetPosition(new Vector3(SD_WIDTH * 5.0f, SD_HEIGHT * 3.5f, -0.001));
	manualSprite->SetColor(new Color(100, 100, 100, 200));

	okTexture = new Texture("assets/textures/All/UI/OK.png");

	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	for (int i = 0; i < playerCount; i++) {
		string path = "assets/textures/All/UI/";
		path += to_string(i + 1) + "P.png";
		Texture* playerTexture = new Texture(path, to_string(i) + "P");

		Sprite* player = new Sprite(playerTexture);
		player->SetScale(new Vector2(SCREEN_HEIGHT * 0.13f, SCREEN_HEIGHT * 0.13f));
		player->SetPosition(new Vector3(SCREEN_WIDTH * (i * 0.25f + 0.125f), SCREEN_HEIGHT * 0.775f, 0));
		players.emplace_back(player);
		manualObject->AddComponent(player);

		Sprite* ok = new Sprite(okTexture);
		ok->SetScale(new Vector2(SCREEN_HEIGHT * 0.14f, SCREEN_HEIGHT * 0.14f));
		ok->SetPosition(new Vector3(SCREEN_WIDTH * (i * 0.25f + 0.125f), SCREEN_HEIGHT * 0.92f, 0));
		ok->SetColor(new Color(127, 127, 127, 255));
		oks.emplace_back(ok);
		manualObject->AddComponent(ok);
	}
}

void MegatonPunchRule::Update() {
	if (playerCount >= 1) {
		if (Input::GetInstance().GetKeyDown(DIK_A) == true) {// A‚ð‰Ÿ‚µ‚½‚çtrue
			isReady[0] = true;
		}
	}
	if (playerCount >= 2) {
		if (Input::GetInstance().GetKeyDown(DIK_S) == true) {// S‚ð‰Ÿ‚µ‚½‚çtrue
			isReady[1] = true;
		}
	}
	if (playerCount >= 3) {
		if (Input::GetInstance().GetKeyDown(DIK_D) == true) {// D‚ð‰Ÿ‚µ‚½‚çtrue
			isReady[2] = true;
		}
	}
	if (playerCount >= 4) {
		if (Input::GetInstance().GetKeyDown(DIK_F) == true) {// F‚ð‰Ÿ‚µ‚½‚çtrue
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
		SceneManager::GetInstance().LoadScene("megatonPunch");
	}
}

void MegatonPunchRule::UnLoad() {
	ObjectManager::GetInstance().Destroy(manualObject);
}
