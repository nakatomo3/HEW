#include "Run.h"
#include "Input.h"
#include "Sprite.h"
#include "Texture.h"
#include "PlayerRun.h"

Run::Run(string name) : Scene(name){
}


Run::~Run() {
}


void Run::Start() {
	//背景のインスタンス
	ObjectManager::GetInstance().Instantiate(background);
	//ハイライト背景のインスタンス
	ObjectManager::GetInstance().Instantiate(highlightBackground);
	//レーンのインスタンス
	ObjectManager::GetInstance().Instantiate(lane);
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Instantiate(playerObjects[i]);
		ObjectManager::GetInstance().Instantiate(gaugeObjects[i]);
	}
	//吹き出しのインスタンス
	ObjectManager::GetInstance().Instantiate(balloon);
	//リプレイロゴのインスタンス
	ObjectManager::GetInstance().Instantiate(replayRogo);
	//タイム表示のインスタンス
	ObjectManager::GetInstance().Instantiate(runTime);
	//リプレイロゴ背景のインスタンス
	ObjectManager::GetInstance().Instantiate(replayRogoBackground);
}

void Run::Load() {
	Texture* normalGaugeTexture = new Texture("assets/textures/Run/UI/gauge.png");
	Texture* brokenGaugeTexture = new Texture("assets/textures/Run/UI/gauge2.png");
	
	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	for (int i = 0; i < playerCount; i++) {//プレイヤーのカウント(playerCount)の数によってゲージの表示
		ChargeGaugeRun* gauge = new ChargeGaugeRun();
		gauges.emplace_back(gauge);
		gaugeSprites.emplace_back(new Sprite());
		gaugeObjects.emplace_back(new GameObject());
		gaugeObjects[i]->AddComponent(gauges[i]);
		gaugeSprites[i]->SetCriterion(DOWN);
		gauges[i]->SetSprite(gaugeSprites[i]);

		Sprite* scaler = new Sprite(normalGaugeTexture);
		gauge->SetScalerSprite(scaler);
		gaugeObjects[i]->AddComponent(gaugeSprites[i]);
		gaugeObjects[i]->AddComponent(scaler);
		scaler->SetScale(new Vector2(SCREEN_WIDTH * 0.05f , SCREEN_HEIGHT * 0.25f));
		scaler->SetCriterion(DOWN);

		PlayerRun* player = new PlayerRun();
		players.emplace_back(player);
		players[i]->SetplayerID(i);
		playerSprite.emplace_back(new Sprite());
		playerObjects.emplace_back(new GameObject());
		playerObjects[i]->AddComponent(player);
		playerObjects[i]->AddComponent(playerSprite[i]);
		charges.emplace_back(0);

		gauge->SetPlayer(player);
		gauge->SetBrokenTexture(brokenGaugeTexture);
	}

	//このコメントの下にゲージ関連の処理を追加
	float gaugeWidth = SD_WIDTH * 0.5f;		//ゲージの横の大きさ
	float gaugeHeight = SD_HEIGHT * 2.5f;	//ゲージの縦の大きさ

	float sideBuffer = SCREEN_WIDTH / 18;	//画面の上下左右からの距離


	if (playerCount >= 1) {
		//左上仮ゲージ
		gaugeObjects[0]->SetPosition(new Vector3(SD_WIDTH * 0.95f ,SD_HEIGHT * 3.6f, 0));//x,y,z座標
		gaugeSprites[0]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}

	if (playerCount >= 2) {
		//右上仮ゲージ
		gaugeObjects[1]->SetPosition(new Vector3(SD_WIDTH * 9.3f, SD_HEIGHT * 3.6f, 0));//x,y,z座標
		gaugeSprites[1]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}

	if (playerCount >= 3) {
		//左下仮ゲージ
		gaugeObjects[2]->SetPosition(new Vector3(SD_WIDTH * 0.95f, SD_HEIGHT * 8.6f, 0));//x,y,z座標
		gaugeSprites[2]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}

	if (playerCount >= 4) {
		//右下仮ゲージ
		gaugeObjects[3]->SetPosition(new Vector3(SD_WIDTH * 9.3f, SD_HEIGHT * 8.6f, 0));//x,y,z座標
		gaugeSprites[3]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}


	//このコメントの下にプレイヤー関連の処理を追加
	if (playerCount >= 1) {
		//一番目のプレイヤー
		playerSprite[0]->SetScale(new Vector2(SD_HEIGHT * 4.0f, SD_HEIGHT * 4.0f));
		playerObjects[0]->SetPosition(new Vector3(SD_WIDTH * 2.5f, SD_HEIGHT * 2.3f, 0));
		players[0]->SetSprite(playerSprite[0]);
		players[0]->SetScene(this);
		
	}

	if (playerCount >= 2) {
		//二番目のプレイヤー
		playerSprite[1]->SetScale(new Vector2(SD_HEIGHT * 4.0f, SD_HEIGHT * 4.0f));
		playerObjects[1]->SetPosition(new Vector3(SD_WIDTH * 7.5f, SD_HEIGHT * 2.3f, 0));
		players[1]->SetSprite(playerSprite[1]);
		players[1]->SetScene(this);
	}

	if (playerCount >= 3) {
		//三番目のプレイヤー
		playerSprite[2]->SetScale(new Vector2(SD_HEIGHT * 4.0f, SD_HEIGHT * 4.0f));
		playerObjects[2]->SetPosition(new Vector3(SD_WIDTH * 2.5f, SD_HEIGHT * 7.3f, 0));
		players[2]->SetSprite(playerSprite[2]);
		players[2]->SetScene(this);
	}

	if (playerCount >= 4) {
		//四番目のプレイヤー
		playerSprite[3]->SetScale(new Vector2(SD_HEIGHT * 4.0f, SD_HEIGHT * 4.0f));
		playerObjects[3]->SetPosition(new Vector3(SD_WIDTH * 7.5f, SD_HEIGHT * 7.3f, 0));
		players[3]->SetSprite(playerSprite[3]);
		players[3]->SetScene(this);
	}

	//吹き出しの処理
	balloonSprite = new Sprite();
	balloonSprite->SetScale(new Vector2(0, 0)); //最初は非表示
	balloon = new GameObject();
	balloon->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	balloon->AddComponent(balloonSprite);
	balloonRun = new BalloonRun();
	balloon->AddComponent(balloonRun);
	balloonRun->SetSprite(balloonSprite);

	balloonRun->SetTexture(new Texture("assets/textures/Run/UI/3.png", "3"));
	balloonRun->SetTexture(new Texture("assets/textures/Run/UI/2.png", "2"));
	balloonRun->SetTexture(new Texture("assets/textures/Run/UI/1.png", "1"));
	balloonRun->SetTexture(new Texture("assets/textures/Run/UI/Shake.png", "shake"));
	balloonRun->SetTexture(new Texture("assets/textures/Run/UI/Ready.png", "ready"));
	balloonRun->SetTexture(new Texture("assets/textures/Run/UI/Start.png", "start"));

	//レーンの処理
	laneTexture = new Texture("assets/textures/Run/UI/lane.png", "lane");
	laneSprite = new Sprite(laneTexture);
	laneSprite->SetScale(new Vector2(SCREEN_WIDTH*2, SCREEN_HEIGHT*0.7f));
	lane = new GameObject();
	lane->SetPosition(new Vector3(SCREEN_WIDTH - SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT*0.65f, 0));
	lane->AddComponent(laneSprite);
	lane->SetActive(false);

	//背景の処理
	backgroundTexture = new Texture("assets/textures/Run/UI/background.png", "background");
	backgroundSprite = new Sprite(backgroundTexture);
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH*2, SCREEN_HEIGHT*0.3f));
	background = new GameObject();
	background->SetPosition(new Vector3(SCREEN_WIDTH - SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT*0.15f, 0));
	background->AddComponent(backgroundSprite);
	background->SetActive(false);

	//リプレイロゴの処理
	replayRogo = new GameObject();

	replayRogoTexture = new Texture("assets/textures/Run/UI/ReplayBar.png", "ReplayBar");// 右から左 ↑棒
	replayRogoSprite = new Sprite(replayRogoTexture);
	replayRogo->AddComponent(replayRogoSprite);
	replayRogoSprite->SetScale(new Vector2(SCREEN_WIDTH*0.6, SCREEN_HEIGHT*0.2));// 画像の横、横の大きさ　縦の大きさ
	replayRogoSprite->SetPosition(new Vector3(SCREEN_WIDTH * 2, SCREEN_HEIGHT/10, 0));// 開始位置 x,y,z
	replayRogo->SetActive(false);

	replayRogoSprite2 = new Sprite(replayRogoTexture);// 左から右 ↓棒
	replayRogo->AddComponent(replayRogoSprite2);
	replayRogoSprite2->SetScale(new Vector2(SCREEN_WIDTH*0.6, SCREEN_HEIGHT*0.2));// 画像の横、横の大きさ　縦の大きさ
	replayRogoSprite2->SetPosition(new Vector3(-SCREEN_WIDTH /1, SCREEN_HEIGHT /1.1, 0));// 開始位置 x,y,z
	replayRogo->SetActive(false);

	replayRogoTexture2 = new Texture("assets/textures/Run/UI/Replay.png", "Replay");// 左から右 文字
	replayRogoSprite3 = new Sprite(replayRogoTexture2);
	replayRogo->AddComponent(replayRogoSprite3);
	replayRogoSprite3->SetScale(new Vector2(SCREEN_WIDTH*0.8, SCREEN_HEIGHT*0.8));// 画像の横、横の大きさ　縦の大きさ
	replayRogoSprite3->SetPosition(new Vector3(-SCREEN_WIDTH / 1, SCREEN_HEIGHT / 2, 0));// 開始位置 x,y,z
	replayRogo->SetActive(false);

	//リプレイロゴ背景の処理
	replayRogoBackgroundSprite = new Sprite();
	replayRogoBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	replayRogoBackgroundSprite->SetColor(D3DCOLOR_RGBA(104, 158, 205, 0));
	replayRogoBackground = new GameObject();
	replayRogoBackground->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	replayRogoBackground->AddComponent(replayRogoBackgroundSprite);
	replayRogoBackground->SetActive(false);

	//ハイライト背景の処理
	highlightBackgroundTexture = new Texture("assets/textures/Run/UI/Hilight.png");
	highlightBackgroundSprite = new Sprite(highlightBackgroundTexture);
	highlightBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	highlightBackground = new GameObject();
	highlightBackground->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.01f));
	highlightBackground->AddComponent(highlightBackgroundSprite);
	highlightBackground->SetActive(false);

	//タイム系の処理
	runTimeText = new Text();
	runTime = new GameObject();
	runTimeText->SetPosition(new Vector3(SD_WIDTH*0.5, SD_HEIGHT*0.5));
	runTime->AddComponent(runTimeText);
	runTime->SetActive(false);

	for (int i = 0; i < 4; i++) {
		times.emplace_back(-1);
	}

}

void Run::UnLoad() {
	ObjectManager::GetInstance().Destroy(balloon);
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Destroy(playerObjects[i]);
		ObjectManager::GetInstance().Destroy(gaugeObjects[i]);
	}
	ObjectManager::GetInstance().Destroy(lane);
	ObjectManager::GetInstance().Destroy(background);
	ObjectManager::GetInstance().Destroy(replayRogo);
	ObjectManager::GetInstance().Destroy(replayRogoBackground);
	ObjectManager::GetInstance().Destroy(runTime);
	ObjectManager::GetInstance().Destroy(highlightBackground);
}

void Run::Update() {
	//これ以外何も書かないでください！
	timer += Time::GetInstance().GetDeltaTime();

	//ランキングへの移行処理
	if (timer >= 25.0f) {
		//いらないもの消す
		background->SetActive(false);
		lane->SetActive(false);
		//ランキングをロードする
		SceneManager::GetInstance().LoadScene("runResult");
	} else/*ハイライトの処理*/ if (timer >= 23.0f) {//22.5
    if (isReady == true) {
			//いらないもの消す
			runTime->SetActive(false);
			//ハイライト背景とカメラの表示
			highlightBackground->SetActive(true);
			//ハイライト映像の処理
			laneSprite->SetScale(new Vector2(SCREEN_WIDTH*0.7f, SCREEN_HEIGHT*0.49f));
			lane->SetPosition(new Vector3(SCREEN_WIDTH , SCREEN_HEIGHT, 0));
			laneSprite->SetCriterion(DOWN_RIGHT);
			backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH*0.7f, SCREEN_HEIGHT*0.21f));
			backgroundSprite->SetCriterion(DOWN_RIGHT);
			background->SetPosition(new Vector3(SCREEN_WIDTH, SCREEN_HEIGHT*0.51f, 0));
			if (playerCount >= 1) {
				playerSprite[0]->SetScale(new Vector2(SCREEN_HEIGHT*0.14f, SCREEN_HEIGHT*0.14f));
				playerObjects[0]->SetPosition(new Vector3(playerObjects[0]->GetPosition()->GetX()*0.5f, SCREEN_HEIGHT*0.6f, 0));
				playerSprite[0]->SetCriterion(DOWN_RIGHT);
			}
			if (playerCount >= 2) {
				playerSprite[1]->SetScale(new Vector2(SCREEN_HEIGHT*0.14f, SCREEN_HEIGHT*0.14f));
				playerObjects[1]->SetPosition(new Vector3(playerObjects[1]->GetPosition()->GetX()*0.5f, SCREEN_HEIGHT*0.74f, 0));
				playerSprite[1]->SetCriterion(DOWN_RIGHT);
			}
			if (playerCount >= 3) {
				playerSprite[2]->SetScale(new Vector2(SCREEN_HEIGHT*0.14f, SCREEN_HEIGHT*0.14f));
				playerObjects[2]->SetPosition(new Vector3(playerObjects[2]->GetPosition()->GetX()*0.5f, SCREEN_HEIGHT*0.88f, 0));
				playerSprite[2]->SetCriterion(DOWN_RIGHT);
			}
			if (playerCount >= 4) {
				playerSprite[3]->SetScale(new Vector2(SCREEN_HEIGHT*0.14f, SCREEN_HEIGHT*0.14f));
				playerObjects[3]->SetPosition(new Vector3(playerObjects[3]->GetPosition()->GetX()*0.6f, SCREEN_HEIGHT, 0));
				playerSprite[3]->SetCriterion(DOWN_RIGHT);
			}
		}
		isReady = false;
	} else/*リプレイの処理*/if (timer >= 17.0f) {//16.5
		replayTimer += Time::GetInstance().GetDeltaTime() / 10;
		
		//タイムを小数点第二位まで表示させる
		int intTimer = floor(replayTimer);
		int dicimalTimer = floor(replayTimer * 100 - intTimer * 100);
		runTimeText->text = to_string(intTimer) + "." + to_string(dicimalTimer);
		if (isReady == false) {
			for (int i = 0; i < playerCount; i++) {
				charges[i] = players[i]->GetCharge();
				times[i] = 500 / charges[i];
				VariableManager::GetInstance().SetFloat("time" + to_string(i), times[i]);
			}
			//タイム表示
			runTime->SetActive(true);
			//リプレイロゴ背景を消す
			replayRogoBackground->SetActive(false);
			//リプレイロゴを消す
			replayRogo->SetActive(false);
			//レーンの表示
			lane->SetActive(true);
			lane->SetPosition(new Vector3(SCREEN_WIDTH, SCREEN_HEIGHT*0.65f, 0));
			//背景の表示
			background->SetActive(true);
			background->SetPosition(new Vector3(SCREEN_WIDTH, SCREEN_HEIGHT*0.15f, 0));

			//リプレイロゴ中はプレイヤー消す
			for (int i = 0; i < playerCount; i++) {
				playerObjects[i]->SetActive(true);
			}

			//リプレイ速度(ゆっくり）で走る
				//セット
				//一番目のプレイヤーの処理（前半）
			if (playerCount >= 1) {
				playerObjects[0]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 3.75f, 0));
			}


			//二番目のプレイヤーの処理（前半）
			if (playerCount >= 2) {
				playerObjects[1]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 5.50f, 0));
			}


			//三番目のプレイヤーの処理（前半）
			if (playerCount >= 3) {
				playerObjects[2]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 7.25f, 0));
			}

			//四番目のプレイヤーの処理（前半）
			if (playerCount >= 4) {
				playerObjects[3]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 9.0f, 0));
			}
		}
		isReady = true;
	} else /*リプレイロゴの処理*/ if (timer >= 14.5f) {// 仮背景の色は水色黄色
		//リプレイロゴ中はプレイヤー消す
		for (int i = 0; i < playerCount; i++) {
			playerObjects[i]->SetActive(false);
		}
		//リプレイロゴ背景の表示
		replayRogoBackground->SetActive(true);
		//リプレイロゴの表示
		replayRogo->SetActive(true);
		if (replayRogoSprite->GetPosition()->GetX() > SCREEN_WIDTH / 2 && timer > 4) {//  右から左
		//                                                             ↑ここでタイミングの調整
			replayRogoSprite->SetPosition(new Vector3(replayRogoSprite->GetPosition()->GetX() - logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 10, 0));
			//                                                                      ↑ロゴの出る速さ
			if (replayRogoSprite->GetPosition()->GetX() < SCREEN_WIDTH / 2) {
				replayRogoSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 10, 0));// 動かす位置
			}
		}
		if (replayRogoSprite2->GetPosition()->GetX() < SCREEN_WIDTH / 2 && timer > 4) {//  左から右
		//                                                             ↑ここでタイミングの調整
			replayRogoSprite2->SetPosition(new Vector3(replayRogoSprite2->GetPosition()->GetX() + logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 1.1, 0));
			//                                                                      ↑ロゴの出る速さ
			if (replayRogoSprite2->GetPosition()->GetX() > SCREEN_WIDTH / 2) {
				replayRogoSprite2->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 1.1, 0));// 動かす位置
			}
		}
		if (replayRogoSprite3->GetPosition()->GetX() < SCREEN_WIDTH / 2 && timer > 2) {//  左から右
		//                                                             ↑ここでタイミングの調整
			replayRogoSprite3->SetPosition(new Vector3(replayRogoSprite3->GetPosition()->GetX() + 4000 * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 2, 0));
			//                                                                      ↑ロゴの出る速さ
			if (replayRogoSprite3->GetPosition()->GetX() > SCREEN_WIDTH / 2) {
				replayRogoSprite3->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
			}
		}

		//レーンと走っているときの背景を消す
		if (isReplay == true) {
			lane->SetActive(false);
			background->SetActive(false);
		}
		isReplay = true;
		isReady = false;
	} else /*走っている時の処理（後半）*/ if (timer >= 12.5f) {

		//レーンの表示
		laneSprite->SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
		lane->SetActive(true);
		lane->SetPosition(new Vector3(SCREEN_WIDTH - SCREEN_WIDTH, SCREEN_HEIGHT*0.65f, 0));
		//背景の表示
		backgroundSprite->SetColor(D3DCOLOR_RGBA(255, 255, 255, 255));
		background->SetActive(true);
		background->SetPosition(new Vector3(SCREEN_WIDTH-SCREEN_WIDTH, SCREEN_HEIGHT*0.15f, 0));

		//プレイヤーの走る処理
		if (isGoalCamera == false) {
			//セット
			//一番目のプレイヤーの処理
			if (playerCount >= 1) {
				playerObjects[0]->Move(Vector3(-SCREEN_WIDTH, 0, 0));
			}

			//二番目のプレイヤーの処理
			if (playerCount >= 2) {
				playerObjects[1]->Move(Vector3(-SCREEN_WIDTH, 0, 0));
			}

			//三番目のプレイヤーの処理
			if (playerCount >= 3) {
				playerObjects[2]->Move(Vector3(-SCREEN_WIDTH, 0, 0));
			}

			//四番目のプレイヤーの処理
			if (playerCount >= 4) {
				playerObjects[3]->Move(Vector3(-SCREEN_WIDTH, 0, 0));
			}
		}
		isGoalCamera = true;
		//isReady = false;
	} else /*走っている時の処理（前半）*/if (timer >= 12.0f) {

		//レーンの表示
		lane->SetActive(true);
		lane->SetPosition(new Vector3(SCREEN_WIDTH, SCREEN_HEIGHT*0.65f, 0));
		//背景の表示
		background->SetActive(true);
		background->SetPosition(new Vector3(SCREEN_WIDTH, SCREEN_HEIGHT*0.15f, 0));

		//プレイヤーの走る処理
		if (isReady == false) {
			//セット
			//一番目のプレイヤーの処理（前半）
			if (playerCount >= 1) {
				playerObjects[0]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 3.75f, 0));
				gaugeObjects[0]->SetActive(false);
			}


			//二番目のプレイヤーの処理（前半）
			if (playerCount >= 2) {
				playerObjects[1]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 5.50f, 0));
				gaugeObjects[1]->SetActive(false);
			}


			//三番目のプレイヤーの処理（前半）
			if (playerCount >= 3) {
				playerObjects[2]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 7.25f, 0));
				gaugeObjects[2]->SetActive(false);
			}

			//四番目のプレイヤーの処理（前半）
			if (playerCount >= 4) {
				playerObjects[3]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 9.0f, 0));
				gaugeObjects[3]->SetActive(false);
			}

			//スタートしたら吹き出し消す
			balloon->SetActive(false);

		}
		isReady = true;
	}

}

double Run::GetTimer() {
	//LogWriter::GetInstance().Log("%f", timer);
	return 0;
}

void Run::ChangePlayerCount(unsigned int num) {
	if (num > 4) {
		//LogWriter::GetInstance().LogError("プレイヤーの最大数は４です");
		return;
	}
	playerCount = num;
}

int Run::GetPlayerCount() {
	return playerCount;
}

Sprite * Run::GetPlayerSprite(int playerID){
	return playerSprite[playerID];
}

void Run::SetTime(int playerNumber, float time) {
	times[playerNumber] = time;
}
