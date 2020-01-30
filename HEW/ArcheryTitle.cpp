#include "ArcheryTitle.h"
#include "Time.h"
#include "VariableManager.h"
#include "Input.h"
#include "SceneManager.h"



ArcheryTitle::ArcheryTitle(string name) : Scene(name) {

}

ArcheryTitle::~ArcheryTitle() {
}


void ArcheryTitle::Start() {
	ObjectManager::GetInstance().Instantiate(backgroundObject);
	ObjectManager::GetInstance().Instantiate(archeryObject);
	for (int i = 0; i < playerCount; i++) {
		isReady.emplace_back(false);
	}
}

void ArcheryTitle::Load() {
	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);
	backgroundObject->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.001));
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	backgroundSprite->SetColor(new Color(0, 0, 0, 0));

	archeryObject = new GameObject();
	archerySprite = new Sprite();
	archeryObject->AddComponent(archerySprite);

	archeryTexture1 = new Texture("assets/textures/Archery/Title/Title1.png", "Title1");// 軌道
	archeryLogo1 = new Sprite(archeryTexture1);
	archeryObject->AddComponent(archeryLogo1);
	archeryLogo1->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT*2));
	archeryLogo1->SetPosition(new Vector3(SCREEN_WIDTH, SCREEN_HEIGHT, 0));

	archeryTexture2 = new Texture("assets/textures/Archery/Title/Title2.png", "Title2");// 弓なしプレイヤー
	archeryLogo2 = new Sprite(archeryTexture2);
	archeryObject->AddComponent(archeryLogo2);
	archeryLogo2->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT*2));

	archeryTexture3 = new Texture("assets/textures/Archery/Title/Title3.png", "Title3");// 弓ありプレイヤー
	archeryLogo3 = new Sprite(archeryTexture3);
	archeryObject->AddComponent(archeryLogo3);
	archeryLogo3->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT*2));
	archeryLogo3->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT /10, 0));

	archeryTexture4 = new Texture("assets/textures/Archery/Title/Title4.png", "Title4");// 的
	archeryLogo4 = new Sprite(archeryTexture4);
	archeryObject->AddComponent(archeryLogo4);
	archeryLogo4->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT*2));
	archeryLogo4->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 10, 0));

	archeryTexture5 = new Texture("assets/textures/Archery/Title/Title5.png", "Title5");// 台座
	archeryLogo5 = new Sprite(archeryTexture5);
	archeryObject->AddComponent(archeryLogo5);
	archeryLogo5->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT*2));
	archeryLogo5->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 10, 0));

	archeryTexture6 = new Texture("assets/textures/Archery/Title/Title6.png", "Title6");// クソデカロゴ
	archeryLogo6 = new Sprite(archeryTexture6);
	archeryObject->AddComponent(archeryLogo6);
	archeryLogo6->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT*2));
	archeryLogo6->SetPosition(new Vector3(SCREEN_WIDTH, SCREEN_HEIGHT, 0));


	manualObject = new GameObject();
	manualSprite = new Sprite();
	manualObject->AddComponent(manualSprite);

	manualSprite->SetScale(new Vector2(SD_WIDTH * 10.0f, SD_HEIGHT * 7.0f));
	manualSprite->SetPosition(new Vector3(SD_WIDTH * 5.0f, SD_HEIGHT * 3.5f, -0.001));
	manualSprite->SetColor(new Color(100, 100, 100, 200));

	okTexture = new Texture("assets/textures/All/UI/OK.png");

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

void ArcheryTitle::Update() {

	timer += Time::GetInstance().GetDeltaTime();

	if (timer > 2.0) {
		archeryLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 10, 0));// 軌道
		
	}
	if (timer > 2.8) {
		archeryLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 10, 0));// 弓なしプレイヤー
		archeryLogo3->SetActive(false);// 弓ありプレイヤーを消してる
		archeryLogo1->SetActive(false);// 軌道を消している
	}
	if (timer > 3.0) {//+0.2
		archeryLogo4->SetActive(false);// 的を消してる
	}
	if (timer > 3.0) {//+0.2
		archeryLogo6->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 10, 0));// クソデカロゴ//左から右
	}
	if (timer > 10.0) {
		archeryLogo2->SetActive(false);// 弓なしプレイヤー
		archeryLogo5->SetActive(false);// 台座
		archeryLogo6->SetActive(false);// クソデカロゴ
	}

	if (timer > 10.0) {

		if (isManual == false) {

			if (playerCount >= 1) {
				if (timer >= 5) {// 5経ったらtrueにする
					isReady[0] = true;
				}
			}
			if (playerCount >= 2) {
				if (timer >= 5) {// 5経ったらtrueにする
					isReady[1] = true;
				}
			}
			if (playerCount >= 3) {
				if (timer >= 5) {// 5経ったらtrueにする
					isReady[2] = true;
				}
			}
			if (playerCount >= 4) {
				if (timer >= 5) {// 5経ったらtrueにする
					isReady[3] = true;
				}
			}

			//-----↓キー入力でもできる奴はとりあえず残してます。------
			/*if (playerCount >= 1) {
				if (Input::GetInstance().GetKeyDown(DIK_A) == true) {
					isReady[0] = true;
				}
			}
			if (playerCount >= 2) {
				if (Input::GetInstance().GetKeyDown(DIK_S) == true) {
					isReady[1] = true;
				}
			}
			if (playerCount >= 3) {
				if (Input::GetInstance().GetKeyDown(DIK_D) == true) {
					isReady[2] = true;
				}
			}
			if (playerCount >= 4) {
				if (Input::GetInstance().GetKeyDown(DIK_F) == true) {
					isReady[3] = true;
				}
			}*/
			//-----------------------------------------------------------

			bool isAllReady = true;
			for (int i = 0; i < playerCount; i++) {
				if (isReady[i] == false) {
					isAllReady = false;
					break;
				}
			}

			if (isAllReady == true) {
				isManual = true;
				ObjectManager::GetInstance().Instantiate(manualObject);
				archeryObject->SetActive(false);
				for (int i = 0; i < 4; i++) {
					isReady[i] = false;
				}
			}
		} else {

			if (playerCount >= 1) {
				if (Input::GetInstance().GetKeyDown(DIK_A) == true) {// Aを押したらtrue
					isReady[0] = true;
				}
			}

			if (playerCount >= 2) {
				if (Input::GetInstance().GetKeyDown(DIK_S) == true) {// Sを押したらtrue
					isReady[1] = true;
				}
			}
			if (playerCount >= 3) {
				if (Input::GetInstance().GetKeyDown(DIK_D) == true) {// Dを押したらtrue
					isReady[2] = true;
				}
			}
			if (playerCount >= 4) {
				if (Input::GetInstance().GetKeyDown(DIK_F) == true) {// Fを押したらtrue
					isReady[3] = true;
				}
			}

			for (int i = 0; i < playerCount; i++) {

				if (isReady[i] == false) {
					oks[i]->SetColor(new Color(128, 128, 128, 255));
				}
				else {
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
				SceneManager::GetInstance().LoadScene("archery");
			}
		}
	}
}

void ArcheryTitle::UnLoad() {
	ObjectManager::GetInstance().Destroy(backgroundObject);
	ObjectManager::GetInstance().Destroy(manualObject);
	ObjectManager::GetInstance().Destroy(archeryObject);
	LogWriter::GetInstance().Log("a");
}