#include "Rule.h"
#include "VariableManager.h"
#include "Input.h"
#include "SceneManager.h"

Rule::Rule(string name) : Scene(name) {
}


Rule::~Rule() {
}

void Rule::Start() {
	ObjectManager::GetInstance().Instantiate(manualObject);
	ObjectManager::GetInstance().Instantiate(ruleObject);

	for (int i = 0; i < playerCount; i++) {
		isReady.emplace_back(false);
	}
}

void Rule::Load() {
	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	//Background
	manualObject = new GameObject();
	manualSprite = new Sprite();
	manualObject->AddComponent(manualSprite);

	manualSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));
	manualSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));
	manualSprite->SetColor(new Color(0, 0, 0, 0));


	//Rule
	ruleObject = new GameObject();
	ruleSprite = new Sprite();
	ruleObject->AddComponent(ruleSprite);

	ruleSprite->SetScale(new Vector2(SD_WIDTH * 10.0f, SD_HEIGHT * 7.0f));
	ruleSprite->SetPosition(new Vector3(SD_WIDTH * 5.0f, SD_HEIGHT * 3.5f, 0));
	ruleSprite->SetColor(new Color(100, 100, 100, 200));


	for (int i = 0; i < playerCount; i++) {
		string path = "assets/textures/All/UI/";
		path += to_string(i + 1) + "P.png";
		Texture* playerTexture = new Texture(path, to_string(i) + "P");

		Sprite* player = new Sprite(playerTexture);
		player->SetScale(new Vector2(SD_HEIGHT * 1.3f, SD_HEIGHT * 1.3f));
		player->SetPosition(new Vector3(SCREEN_WIDTH * (i * 0.25f + 0.125f), SCREEN_HEIGHT * 0.775f, 0));
		players.emplace_back(player);
		manualObject->AddComponent(player);
	}

}

void Rule::Update() {

}

void Rule::UnLoad() {
	ObjectManager::GetInstance().Destroy(manualObject);
}