#include "RunTitle.h"
#include "Time.h"
#include "VariableManager.h"
#include "Input.h"
#include "SceneManager.h"

RunTitle::RunTitle(string name) : Scene(name){

}

RunTitle::~RunTitle() {
}

void RunTitle::Start() {
	//説明のオブジェクトは条件を満たしたときに一回だけInstantiate
	ObjectManager::GetInstance().Instantiate(titleObject);

	for (int i = 0; i < playerCount; i++) {
		isReady.emplace_back(false);
	}
}

void RunTitle::Load() {
	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	titleObject = new GameObject();
	titleSprite = new Sprite();
	runTitleAnimation = new RunTitleAnimation();
	titleObject->AddComponent(titleSprite);
	titleObject->AddComponent(runTitleAnimation);

	backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);

	backgroundObject->SetPosition(new Vector3(1, 1, 0));
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));

	/*titleObject->SetPosition(new Vector3(500, 100, 0));
	titleSprite->SetScale(new Vector2(300, 300));*/

	// 背景
	titleSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// 背景の大きさ
	titleSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 背景の位置
	titleSprite->SetColor(new Color(0, 0, 0, 0));// 黒色背景


	logoTexture1 = new Texture("assets/textures/Run/Title/RunTitle1.png", "RunTitle1");// 100m  右から左
	titleLogo1 = new Sprite(logoTexture1);
	titleObject->AddComponent(titleLogo1);
	titleLogo1->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// 画像の横、横の大きさ
	titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 0.6, SCREEN_HEIGHT / 2, 0));// 開始位置 x,y,z座標 /, /2, 0


	logoTexture2 = new Texture("assets/textures/Run/Title/RunTitle2.png", "RunTitle2");// 走　右から左
	titleLogo2 = new Sprite(logoTexture2);
	titleObject->AddComponent(titleLogo2);
	titleLogo2->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// 画像の横、横の大きさ
	titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 0.6, SCREEN_HEIGHT / 2, 0));// 開始位置 x,y,z座標 /0.8, /2, 0


	//以下説明
	manualObject = new GameObject();
	manualSprite = new Sprite();
	manualObject->AddComponent(manualSprite);
	/*manualSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	manualSprite->SetPosition(new Vector3(SCREEN_CEMTER_X, SCREEN_CEMTER_Y));*/

	okTexture = new Texture("assets/textures/All/UI/OK.png");

	for (int i = 0; i < playerCount; i++) {
		string path = "assets/textures/All/UI/";
		path += to_string(i+1) + "P.png";
		Texture* playerTexture = new Texture(path, to_string(i) + "P");

		Sprite* player = new Sprite(playerTexture);
		player->SetScale(new Vector2(SCREEN_HEIGHT * 0.13f, SCREEN_HEIGHT * 0.13f));
		player->SetPosition(new Vector3(SCREEN_WIDTH * (i * 0.25f + 0.125f), SCREEN_HEIGHT * 0.775f, 0));
		players.emplace_back(player);
		manualObject->AddComponent(player);

		Sprite* ok = new Sprite(okTexture);
		ok->SetScale(new Vector2(SCREEN_HEIGHT * 0.17f, SCREEN_HEIGHT * 0.17f));
		ok->SetPosition(new Vector3(SCREEN_WIDTH * (i * 0.25f + 0.125f), SCREEN_HEIGHT * 0.92f, 0));
		ok->SetColor(new Color(127, 127, 127, 255));
		oks.emplace_back(ok);
		manualObject->AddComponent(ok);
	}

}

void RunTitle::UnLoad() {

}

void RunTitle::Update() {
	//isManualがfalseかつ説明に行く条件を満たしたらここでtrue、Instantiate
	//isManual = true;
	//Instantiate

	timer += Time::GetInstance().GetDeltaTime();

	if (titleLogo1->GetPosition()->GetX() > SCREEN_WIDTH / 2 && timer > 1) {// 100m 右から左
		//                                                             ↑ここでタイミングの調整
		titleLogo1->SetPosition(new Vector3(titleLogo1->GetPosition()->GetX() - logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 2, 0));
		//                                                                      ↑ロゴの出る速さ
		if (titleLogo1->GetPosition()->GetX() < SCREEN_WIDTH / 2) {
			titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}


	if (titleLogo2->GetPosition()->GetX() > SCREEN_WIDTH / 2 && timer > 2) {// 走 右から左
		//                                                             ↑ここでタイミングの調整
		titleLogo2->SetPosition(new Vector3(titleLogo2->GetPosition()->GetX() - logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 2, 0));
		//                                                                      ↑ロゴの出る速さ
		if (titleLogo2->GetPosition()->GetX() < SCREEN_WIDTH / 2) {
			titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}

	if (timer > 2) {

		if (isManual == false) {
			LogWriter::GetInstance().Log("タイトルです");

			if (playerCount >= 1) {
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
			}

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
				ObjectManager::GetInstance().Destroy(titleObject);
				for (int i = 0; i < 4; i++) {
					isReady[i] = false;
				}
			}
		} else {
			LogWriter::GetInstance().Log("マニュアルです");
			if (playerCount >= 1) {
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
			}

			bool isAllReady = true;
			for (int i = 0; i < playerCount; i++) {
				if (isReady[i] == false) {
					isAllReady = false;
					break;
				}
			}

			if (isAllReady == true) {
				SceneManager::GetInstance().LoadScene("run");
			}


		}



	}
}
