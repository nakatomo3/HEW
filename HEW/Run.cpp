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
	ObjectManager::GetInstance().Instantiate(lane);

	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Instantiate(playerObjects[i]);
		ObjectManager::GetInstance().Instantiate(gaugeObjects[i]);
	}
	
	ObjectManager::GetInstance().Instantiate(balloon);
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
	balloon->SetPosition(new Vector3(500, 300, 0));
	balloon->AddComponent(balloonSprite);
	balloonRun = new BalloonRun();
	balloon->AddComponent(balloonRun);
	balloonRun->SetSprite(balloonSprite);

	//レーンの処理
	laneSprite = new Sprite();
	laneSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	laneSprite->SetColor(D3DCOLOR_RGBA(125, 200, 233, 0));
	lane = new GameObject();
	lane->SetPosition(new Vector3(SCREEN_WIDTH - SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT*0.8f, 0));
	lane->AddComponent(laneSprite);
	lane->SetActive(false);
}

void Run::Update() {
	//これ以外何も書かないでください！
	timer += Time::GetInstance().GetDeltaTime();

	if (timer >= 1) {
		lane->SetActive(true);
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
