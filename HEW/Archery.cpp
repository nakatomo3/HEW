#include "Archery.h"
#include "VariableManager.h"
#include "Input.h"
#include "SceneManager.h"
#include "Setting.h"



Archery::Archery(string name) : Scene(name) {
}


Archery::~Archery() {
}

void Archery::Start() {
	ObjectManager::GetInstance().Instantiate(backgroundObject);
	ObjectManager::GetInstance().Instantiate(playerObject);
	ObjectManager::GetInstance().Instantiate(numberObject);
	ObjectManager::GetInstance().Instantiate(targetObject);
	ObjectManager::GetInstance().Instantiate(scoretitleObject);
	ObjectManager::GetInstance().Instantiate(scoreObject);
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

	playerObject = new GameObject();
	numberObject = new GameObject();
	targetObject = new GameObject();
	scoretitleObject = new GameObject();
	scoreObject = new GameObject();

	/*
	Texture* playerTexture = new Texture("assets/textures/fish.png");
	Texture* numberTexture = new Texture("assets/textures/All/UI/1P.png");
	Texture* targetTexture = new Texture("assets/textures/warmup.png");
	*/

	for (int i = 0; i < playerCount; i++) {
		Sprite* player = new Sprite(/*playerTexture*/);
		player->SetScale(new Vector2(SD_HEIGHT * 2.5f, SD_HEIGHT * 2.5f));
		player->SetPosition(new Vector3(SD_WIDTH * 1.5 + SD_HEIGHT * 2.5, SD_HEIGHT * (i * 2.5 + 1.25), -0.001));
		players.emplace_back(player);
		playerObject->AddComponent(player);

		Sprite* number = new Sprite(/*numberTexture*/);
		number->SetScale(new Vector2(SD_HEIGHT * 0.5f, SD_HEIGHT * 0.5f));
		number->SetPosition(new Vector3(SD_WIDTH * 4.75, SD_HEIGHT * (i * 2.5f + 0.25f), -0.001));
		numbers.emplace_back(number);
		numberObject->AddComponent(number);

		Sprite* target = new Sprite(/*targetTexture*/);
		target->SetScale(new Vector2(SD_HEIGHT * 1.5f, SD_HEIGHT * 1.5f));
		target->SetPosition(new Vector3(SD_WIDTH * 9 - SD_HEIGHT * 0.75, SD_HEIGHT * (i * 2.5 + 1.25), -0.001));
		targets.emplace_back(target);
		targetObject->AddComponent(target);

		Sprite* scoretitle = new Sprite(/*scoretitleTexture*/);
		scoretitle->SetScale(new Vector2(SD_WIDTH * 1, SD_HEIGHT * 0.5));
		scoretitle->SetPosition(new Vector3(SD_WIDTH * 0.5, SD_HEIGHT * (i * 2.5 + 0.25), -0.001));
		scoretitles.emplace_back(scoretitle);
		scoretitleObject->AddComponent(scoretitle);

		Sprite* score = new Sprite();
		score->SetScale(new Vector2(SD_WIDTH * 1, SD_HEIGHT * 0.5));
		score->SetPosition(new Vector3(SD_WIDTH * 0.5, SD_HEIGHT * (i * 2.5 + 0.75), -0.001));
		scores.emplace_back(score);
		scoreObject->AddComponent(score);

		Text* mark = new Text();
		scoreObject->AddComponent(mark);
		marks.emplace_back(mark);
		mark->SetPosition(new Vector3(0, SD_HEIGHT * (i * 2.5 + 0.65), -0.002));
		mark->isOutline = true;
		mark->isBeautifulOutline = true;
		mark->SetOutlineColor(new Color(128, 128, 128, 255));
		mark->outlineDistance = SD_HEIGHT * 0.02;
		mark->SetSize(SD_HEIGHT * 0.3);

		scoreValues.emplace_back(0);
		//marks[i]->text = to_string(scoreValues[i]);
	}

}

void Archery::Update() {
	if (playerCount >= 1) {
		if (Input::GetInstance().GetKeyDown(DIK_A) == true) {// A‚ð‰Ÿ‚µ‚½‚çtrue
			scoreValues[0] += 100;
			marks[0]->text = to_string(scoreValues[0]);
		}
	}
	if (playerCount >= 2) {
		if (Input::GetInstance().GetKeyDown(DIK_S) == true) {// S‚ð‰Ÿ‚µ‚½‚çtrue
			scoreValues[1] += 100;
			marks[1]->text = to_string(scoreValues[1]);
		}
	}
	if (playerCount >= 3) {
		if (Input::GetInstance().GetKeyDown(DIK_D) == true) {// D‚ð‰Ÿ‚µ‚½‚çtrue
			scoreValues[2] += 100;
			marks[2]->text = to_string(scoreValues[2]);
		}
	}
	if (playerCount >= 4) {
		if (Input::GetInstance().GetKeyDown(DIK_F) == true) {// F‚ð‰Ÿ‚µ‚½‚çtrue
			scoreValues[3] += 100;
			marks[3]->text = to_string(scoreValues[3]);
		}
	}
}


void Archery::UnLoad() {
	ObjectManager::GetInstance().Destroy(backgroundObject);
}
