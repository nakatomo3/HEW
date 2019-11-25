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
	//リプレイロゴ背景のインスタンス
	ObjectManager::GetInstance().Instantiate(replayRogoBackground);
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
}

void Run::Load() {
	Texture* normalGaugeTexture = new Texture("assets/textures/Run/UI/gauge.png");
	Texture* brokenGaugeTexture = new Texture("assets/textures/Run/UI/gauge2.png");

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
		playerObjects[i]->AddComponent(players[i]);
		playerObjects[i]->AddComponent(playerSprite[i]);

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
		playerSprite[0]->SetScale(new Vector2(SD_HEIGHT * 2.0f, SD_HEIGHT * 2.0f));
		playerObjects[0]->SetPosition(new Vector3(SD_WIDTH * 2.5f, SD_HEIGHT * 3.3f, 0));
		players[0]->SetSprite(playerSprite[0]);
		players[0]->SetScene(this);
	}

	if (playerCount >= 2) {
		//二番目のプレイヤー
		playerSprite[1]->SetScale(new Vector2(SD_HEIGHT * 2.0f, SD_HEIGHT * 2.0f));
		playerObjects[1]->SetPosition(new Vector3(SD_WIDTH * 7.5f, SD_HEIGHT * 3.3f, 0));
		players[1]->SetSprite(playerSprite[1]);
		players[1]->SetScene(this);
	}

	if (playerCount >= 3) {
		//三番目のプレイヤー
		playerSprite[2]->SetScale(new Vector2(SD_HEIGHT * 2.0f, SD_HEIGHT * 2.0f));
		playerObjects[2]->SetPosition(new Vector3(SD_WIDTH * 2.5f, SD_HEIGHT * 8.3f, 0));
		players[2]->SetSprite(playerSprite[2]);
		players[2]->SetScene(this);
	}

	if (playerCount >= 4) {
		//四番目のプレイヤー
		playerSprite[3]->SetScale(new Vector2(SD_HEIGHT * 2.0f, SD_HEIGHT * 2.0f));
		playerObjects[3]->SetPosition(new Vector3(SD_WIDTH * 7.5f, SD_HEIGHT * 8.3f, 0));
		players[3]->SetSprite(playerSprite[3]);
		players[3]->SetScene(this);
	}

	//吹き出しの処理
	balloonSprite = new Sprite();
	balloonSprite->SetScale(new Vector2(0, 0)); //最初は非表示
	balloon = new GameObject();
	balloon->SetPosition(new Vector3(SCREEN_CEMTER_X, SCREEN_CEMTER_Y, 0));
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
	laneSprite = new Sprite();
	laneSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT*0.7f));
	laneSprite->SetColor(D3DCOLOR_RGBA(125, 200, 233, 0));
	lane = new GameObject();
	lane->SetPosition(new Vector3(SCREEN_WIDTH - SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT*0.65f, 0));
	lane->AddComponent(laneSprite);
	lane->SetActive(false);

	//背景の処理
	backgroundSprite = new Sprite();
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT*0.3f));
	backgroundSprite->SetColor(D3DCOLOR_RGBA(94, 186, 83, 0));
	background = new GameObject();
	background->SetPosition(new Vector3(SCREEN_WIDTH - SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT*0.15f, 0));
	background->AddComponent(backgroundSprite);
	background->SetActive(false);

	//リプレイロゴの処理
	replayRogoSprite = new Sprite();
	replayRogoSprite->SetScale(new Vector2(SCREEN_WIDTH*0.6f, SCREEN_HEIGHT*0.6f));
	replayRogoSprite->SetColor(D3DCOLOR_RGBA(245, 212, 47, 0));
	replayRogo = new GameObject();
	replayRogo->SetPosition(new Vector3(SCREEN_CEMTER_X, SCREEN_CEMTER_Y, 0));
	replayRogo->AddComponent(replayRogoSprite);
	replayRogo->SetActive(false);

	//リプレイロゴ背景の処理
	replayRogoBackgroundSprite = new Sprite();
	replayRogoBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	replayRogoBackgroundSprite->SetColor(D3DCOLOR_RGBA(104, 158, 205, 0));
	replayRogoBackground = new GameObject();
	replayRogoBackground->SetPosition(new Vector3(SCREEN_CEMTER_X, SCREEN_CEMTER_Y, 0));
	replayRogoBackground->AddComponent(replayRogoBackgroundSprite);
	replayRogoBackground->SetActive(false);
	
}

void Run::Update() {
	//これ以外何も書かないでください！
	timer += Time::GetInstance().GetDeltaTime();

	//走っている時の処理（前半）
	if (timer >= 12.0f) {

		//レーンの表示
		lane->SetActive(true);
		//背景の表示
		background->SetActive(true);

		//プレイヤーの走る処理
		if (isReady == false) {
			//セット
			//一番目のプレイヤーの処理（前半）
			if (playerCount >= 1) {
				playerObjects[0]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 3.75f, 0));
				ObjectManager::GetInstance().Destroy(gaugeObjects[0]);
			}

			
			//二番目のプレイヤーの処理（前半）
			if (playerCount >= 2) {
				playerObjects[1]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 5.50f, 0));
				ObjectManager::GetInstance().Destroy(gaugeObjects[1]);
			}

			
			//三番目のプレイヤーの処理（前半）
			if (playerCount >= 3) {
				playerObjects[2]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 7.25f, 0));
				ObjectManager::GetInstance().Destroy(gaugeObjects[2]);
			}

			//四番目のプレイヤーの処理（前半）
			if (playerCount >= 4) {
				playerObjects[3]->SetPosition(new Vector3(SD_WIDTH * 1.0f, SD_HEIGHT * 9.0f, 0));
				ObjectManager::GetInstance().Destroy(gaugeObjects[3]);
			}
			
			//スタートしたら吹き出し消す
			ObjectManager::GetInstance().Destroy(balloon);
			
		}
		isReady = true;
	}

	//走っている時の処理（後半）
	if (timer >= 12.5f) {

		//レーンの表示
		laneSprite->SetColor(D3DCOLOR_RGBA(126, 15, 133, 0));
		//背景の表示
		backgroundSprite->SetColor(D3DCOLOR_RGBA(76, 108, 179, 0));

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
	}

	//リプレイロゴの処理
	if (timer >= 13.5f) {
		//リプレイロゴ背景の表示
		replayRogoBackground->SetActive(true);
		//リプレイロゴの表示
		replayRogo->SetActive(true);

		//レーンと走っているときの背景を消す
		if (isReplay == false) {
			ObjectManager::GetInstance().Destroy(lane);
			ObjectManager::GetInstance().Destroy(background);
		}
		isReplay = true;
	}
}

double Run::GetTimer() {
	return timer;
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
