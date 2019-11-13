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
		scaler->SetScale(new Vector2(SCREEN_WIDTH / 30, SCREEN_HEIGHT / 3 * 1.0f));
		scaler->SetCriterion(DOWN);

		PlayerRun* player = new PlayerRun();
		players.emplace_back(player);
		players[i]->SetplayerID(i);
		playerSprite.emplace_back(new Sprite());
		playerObjects.emplace_back(new GameObject());
		playerObjects[i]->AddComponent(players[i]);
		playerObjects[i]->AddComponent(playerSprite[i]);

		LogWriter::GetInstance().Log("%d", player);
		gauge->SetPlayer(player);
		gauge->SetBrokenTexture(brokenGaugeTexture);
	}

	//このコメントの下にゲージ関連の処理を追加
	float sdWidth = SCREEN_WIDTH / 10;
	float sdHeight = SCREEN_HEIGHT / 10;

	float gaugeWidth = SCREEN_WIDTH / 30;	//ゲージの横の大きさ
	float gaugeHeight = SCREEN_HEIGHT / 3;	//ゲージの縦の大きさ

	float playerWidth = gaugeHeight / 5;
	float playerHeight = gaugeHeight / 5 * 4;

	float sideBuffer = SCREEN_WIDTH / 18;	//画面の上下左右からの距離


	if (playerCount >= 1) {
		//左上仮ゲージ
		gaugeSprites[0]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//横,縦 の大きさ
		gaugeObjects[0]->SetPosition(new Vector3(sideBuffer, sideBuffer + gaugeHeight, 0));//x,y,z座標
		gaugeSprites[0]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}

	if (playerCount >= 2) {
		//右上仮ゲージ
		gaugeSprites[1]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//横,縦 の大きさ
		gaugeObjects[1]->SetPosition(new Vector3(SCREEN_WIDTH - sideBuffer, sideBuffer + gaugeHeight - 0.0f, 0));//x,y,z座標
		gaugeSprites[1]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}

	if (playerCount >= 3) {
		//左下仮ゲージ
		gaugeSprites[2]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//横,縦 の大きさ
		gaugeObjects[2]->SetPosition(new Vector3(sideBuffer, SCREEN_HEIGHT - sideBuffer, 0));//x,y,z座標
		gaugeSprites[2]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}

	if (playerCount >= 4) {
		//右下仮ゲージ
		gaugeSprites[3]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//横,縦 の大きさ
		gaugeObjects[3]->SetPosition(new Vector3(SCREEN_WIDTH - sideBuffer, SCREEN_HEIGHT - sideBuffer, 0));//x,y,z座標
		gaugeSprites[3]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}


	//このコメントの下にプレイヤー関連の処理を追加
	if (playerCount >= 1) {
		//一番目のプレイヤー
		playerSprite[0]->SetScale(new Vector2(50, 50));
		playerObjects[0]->SetPosition(new Vector3(99, 155, 0));
		players[0]->SetSprite(playerSprite[0]);
		players[0]->SetScene(this);
	}
	
	if (playerCount >= 2) {
		//二番目のプレイヤー
		playerSprite[1]->SetScale(new Vector2(50, 50));
		playerObjects[1]->SetPosition(new Vector3(925, 155, 0));
		players[1]->SetSprite(playerSprite[1]);
		players[1]->SetScene(this);
	}

	if (playerCount >= 3) {
		//三番目のプレイヤー
		playerSprite[2]->SetScale(new Vector2(50, 50));
		playerObjects[2]->SetPosition(new Vector3(99,425, 0));
		players[2]->SetSprite(playerSprite[2]);
		players[2]->SetScene(this);
	}

	if (playerCount >= 4) {
		//四番目のプレイヤー
		playerSprite[3]->SetScale(new Vector2(50, 50));
		playerObjects[3]->SetPosition(new Vector3(925, 425, 0));
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
}

void Run::Update() {
	//これ以外何も書かないでください！
	timer += Time::GetInstance().GetDeltaTime();
}

double Run::GetTimer() {
	return timer;
}

void Run::ChangePlayerCount(unsigned int num) {
	if (num > 4) {
		LogWriter::GetInstance().LogError("プレイヤーの数は最大4です");
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
