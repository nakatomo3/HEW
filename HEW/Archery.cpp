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
	ObjectManager::GetInstance().Instantiate(balloon);
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

	balloonSprite = new Sprite();
	balloonSprite->SetScale(new Vector2(0, 0));
	balloon = new GameObject();
	balloon->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	balloon->AddComponent(balloonSprite);
	balloonArchery = new BalloonArchery();
	balloon->AddComponent(balloonArchery);
	balloonArchery->SetSprite(balloonSprite);

	balloonArchery->SetTexture(new Texture("assets/textures/Archery/UI/Ready.png", "ready"));
	balloonArchery->SetTexture(new Texture("assets/textures/Archery/UI/Go.png", "go"));
	balloonArchery->SetTexture(new Texture("assets/textures/Archery/UI/button1.png", "hit1"));
	balloonArchery->SetTexture(new Texture("assets/textures/Archery/UI/button2.png", "hit2"));
	balloonArchery->SetTexture(new Texture("assets/textures/Archery/UI/CountDown3.png", "3"));
	balloonArchery->SetTexture(new Texture("assets/textures/Archery/UI/CountDown2.png", "2"));
	balloonArchery->SetTexture(new Texture("assets/textures/Archery/UI/CountDown1.png", "1"));
	balloonArchery->SetTexture(new Texture("assets/textures/Archery/UI/Finish.png", "finish"));

	for (int i = 0; i < playerCount; i++) {
		Sprite* player = new Sprite(/*playerTexture*/);
		player->SetScale(new Vector2(SD_HEIGHT * 2.5f, SD_HEIGHT * 2.5f));
		player->SetPosition(new Vector3(SD_HEIGHT * 2.5 + SD_WIDTH * 0.5 , SD_HEIGHT * (i * 2.5 + 1.25), -0.001));
		players.emplace_back(player);
		playerObject->AddComponent(player);

		Sprite* number = new Sprite(/*numberTexture*/);
		number->SetScale(new Vector2(SD_HEIGHT * 0.5f, SD_HEIGHT * 0.5f));
		number->SetPosition(new Vector3(SD_WIDTH + SD_HEIGHT * 2.5 + SD_WIDTH * 0.35, SD_HEIGHT * (i * 2.5f + 0.25f), -0.001));
		numbers.emplace_back(number);
		numberObject->AddComponent(number);

		Sprite* target = new Sprite(/*targetTexture*/);
		target->SetScale(new Vector2(SD_HEIGHT * 2, SD_HEIGHT * 2));
		target->SetPosition(new Vector3(SD_WIDTH * 9 , SD_HEIGHT * (i * 2.5 + 1.25), -0.001));
		targets.emplace_back(target);
		targetObject->AddComponent(target);

		Sprite* scoretitle = new Sprite(/*scoretitleTexture*/);
		scoretitle->SetScale(new Vector2(SD_WIDTH * 1, SD_HEIGHT * 0.9));
		scoretitle->SetPosition(new Vector3(SD_WIDTH * 0.5, SD_HEIGHT * (i * 2.5 + 0.25), -0.001));
		scoretitles.emplace_back(scoretitle);
		scoretitleObject->AddComponent(scoretitle);

		Text* mark = new Text();
		scoreObject->AddComponent(mark);
		marks.emplace_back(mark);
		mark->SetPosition(new Vector3(0, SD_HEIGHT * (i * 2.5 + 0.8), -0.002));
		mark->isOutline = true;
		mark->isBeautifulOutline = true;
		mark->SetOutlineColor(new Color(128, 128, 128, 255));
		mark->outlineDistance = SD_HEIGHT * 0.02;
		mark->SetSize(SD_HEIGHT * 0.6);
		mark->text = to_string(0);
		scoreValues.emplace_back(0);
		
		wasInput.emplace_back(false);

		string path = "";

		int characterID = VariableManager::GetInstance().GetInt("character" + to_string(i));

		switch (characterID) {
		case 0://ウルフ
			path = "assets/textures/Archery/Player/masukudourufu/"; //ここを画像名に変える　　各ファイルまでぶち込み
			break;
		case 1://かしこま
			path = "assets/textures/Archery/Player/kasikomk2/"; //ここを画像名に変える
			break;
		case 2://せん
			path = "assets/textures/Archery/Player/senntyann/"; //ここを画像名に変える
			break;
		case 3://宇宙
			path = "assets/textures/Archery/Player/utyuujinn/"; //ここを画像名に変える
			break;
		}

		waitingPlayerTexture[i] = new Texture(path + "waiting.png"/*+個別画像名*/);//画像の名前は統一しそれをぶち込む  クラウチング
		player->SetTexture(waitingPlayerTexture[i]);
		shotPlayerTexture[i] = new Texture(path + "shot.png"/*+個別画像名*/);
	}

}

void Archery::Update() {
	timer += Time::GetInstance().GetDeltaTime();

	if (timer >= 4 && timer < 14) {
		if (playerCount >= 1) {
			if ((Input::GetInstance().GetKeyDown(DIK_A) || Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_Y) == true) {
				if (wasInput[0] == false) {// A,B,X,Yを押したらtrue
					scoreValues[0] += 100;
					marks[0]->text = to_string(scoreValues[0]);
				}
				wasInput[0] = true;
				players[0]->SetTexture(shotPlayerTexture[0]);
			} else {
				wasInput[0] = false;
				players[0]->SetTexture(waitingPlayerTexture[0]);
			}
		}
		if (playerCount >= 2) {
			if ((Input::GetInstance().GetKeyDown(DIK_S) || Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_Y) == true) {// A,B,X,Yを押したらtrue
				if (wasInput[1] == false) {
					scoreValues[1] += 100;
					marks[1]->text = to_string(scoreValues[1]);
				}
				wasInput[1] = true;
				players[1]->SetTexture(shotPlayerTexture[1]);
			} else {
				wasInput[1] = false;
				players[1]->SetTexture(waitingPlayerTexture[1]);
			}
		}
		if (playerCount >= 3) {
			if ((Input::GetInstance().GetKeyDown(DIK_D) || Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_Y) == true && wasInput[2] == false) {// A,B,X,Yを押したらtrue
				if (wasInput[2] == false) {
					scoreValues[2] += 100;
					marks[2]->text = to_string(scoreValues[2]);
				}
				wasInput[2] = true;
				players[2]->SetTexture(shotPlayerTexture[2]);
			} else {
				wasInput[2] = false;
				players[2]->SetTexture(waitingPlayerTexture[2]);
			}
		}
		if (playerCount >= 4) {
			if ((Input::GetInstance().GetKeyDown(DIK_F) || Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_Y) == true && wasInput[3] == false) {// A,B,X,Yを押したらtrue
				if (wasInput[3] == false) {
					scoreValues[3] += 100;
					marks[3]->text = to_string(scoreValues[3]);
				}
				wasInput[3] = true;
				players[3]->SetTexture(shotPlayerTexture[3]);
			} else {
				wasInput[3] = false;
				players[3]->SetTexture(waitingPlayerTexture[3]);
			}
		}
	}

	for (int i = 0; i < playerCount; i++){
		int intValue = floor(scoreValues[i]);
		VariableManager::GetInstance().SetInt("archeryScore" + to_string(i), scoreValues[i]);
	}
}


void Archery::UnLoad() {
	ObjectManager::GetInstance().Destroy(backgroundObject);
	ObjectManager::GetInstance().Destroy(balloon);
	ObjectManager::GetInstance().Destroy(playerObject);
	ObjectManager::GetInstance().Destroy(numberObject);
	ObjectManager::GetInstance().Destroy(targetObject);
	ObjectManager::GetInstance().Destroy(scoretitleObject);
	ObjectManager::GetInstance().Destroy(scoreObject);
}

double Archery::GetTimer() {
	return 0;
}

void Archery::ChangePlayerCount(unsigned int num) {
	if (num > 4) {
		return;
	}
	playerCount = num;
}

int Archery::GetPlayerCount() {
	return playerCount;
}

void Archery::SetTime(int playerNumber, float time) {
	times[playerNumber] = time;
}
