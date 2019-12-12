#include "Archery.h"
#include "VariableManager.h"
#include "Input.h"
#include "SceneManager.h"



Archery::Archery(string name) : Scene(name) {
}


Archery::~Archery() {
}

void Archery::Start() {
	ObjectManager::GetInstance().Instantiate(backgroundObject);
}

void Archery::Load() {
	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	//Background
	backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);

	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));
	backgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.001));
	backgroundSprite->SetColor(new Color(0, 0, 0, 0));

	Texture* playerTexture = new Texture("assets/textures/rumia.png");
	Texture* targetTexture = new Texture("assets/textures/warmup.png");

	for (int i = 0; i < playerCount; i++) {
		string path = "assets/textures/All/UI/";
		path += to_string(i + 1) + "P.png";
		Texture* numberTexture = new Texture(path, to_string(i) + "P");

		Sprite* player = new Sprite(playerTexture);
		player->SetScale(new Vector2(SD_HEIGHT * 2.5f, SD_HEIGHT * 2.5f));
		player->SetPosition(new Vector3(SD_WIDTH * 1.5 + SD_HEIGHT * 2.5, SD_HEIGHT * ( i * 2.5 + 1.25), 0));
		players.emplace_back(player);
		backgroundObject->AddComponent(player);

		Sprite* number = new Sprite(numberTexture);
		number->SetScale(new Vector2(SD_HEIGHT * 0.5f, SD_HEIGHT * 0.5f));
		number->SetPosition(new Vector3(SD_WIDTH * 4.75, SD_HEIGHT * ( i * 2.5f + 0.25f), -0.001));
		numbers.emplace_back(number);
		backgroundObject->AddComponent(number);

		Sprite* target = new Sprite(targetTexture);
		target->SetScale(new Vector2(SD_HEIGHT * 1.5f, SD_HEIGHT * 1.5f));
		target->SetPosition(new Vector3(SD_WIDTH * 9 - SD_HEIGHT * 0.75, SD_HEIGHT * (i * 2.5 + 1.25), 0));
		targets.emplace_back(target);
		backgroundObject->AddComponent(target);

	}

}

void Archery::Update() {
}

void Archery::UnLoad() {
	ObjectManager::GetInstance().Destroy(backgroundObject);
}