#include "Run.h"



Run::Run(string name) : Scene(name){
}


Run::~Run() {
}

void Run::Start() {
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Instantiate(playerObjects[i]);
		ObjectManager::GetInstance().Instantiate(gaugeObjects[i]);
	}
}

void Run::Load() {
	for (int i = 0; i < playerCount; i++) {
		gauges.emplace_back(new ChargeGaugeRun());
		gaugeSprites.emplace_back(new Sprite());
		gaugeObjects.emplace_back(new GameObject());
		gaugeObjects[i]->AddComponent(gauges[i]);
		gaugeObjects[i]->AddComponent(gaugeSprites[i]);

		players.emplace_back(new PlayerRun());
		players[i]->SetplayerID(i);
		playerSprite.emplace_back(new Sprite());
		playerObjects.emplace_back(new GameObject());
		playerObjects[i]->AddComponent(players[i]);
		playerObjects[i]->AddComponent(playerSprite[i]);

	}

	//このコメントの下にゲージ関連の処理を追加

	if (playerCount >= 1) {
		//左上仮ゲージ
		gaugeSprites[0]->SetScale(new Vector2(25, 200));//横,縦 の大きさ
		gaugeObjects[0]->SetPosition(new Vector3(50, 150, 0));//x,y,z座標
		gaugeObjects[0]->AddComponent(gaugeSprites[0]);
	}

	if (playerCount >= 2) {
		//右上仮ゲージ
		gaugeSprites[1]->SetScale(new Vector2(25, 200));//横,縦 の大きさ
		gaugeObjects[1]->SetPosition(new Vector3(550, 150, 0));//x,y,z座標
		gaugeObjects[1]->AddComponent(gaugeSprites[1]);
	}

	if (playerCount >= 3) {
		//左下仮ゲージ
		gaugeSprites[2]->SetScale(new Vector2(25, 200));//横,縦 の大きさ
		gaugeObjects[2]->SetPosition(new Vector3(50, 450, 0));//x,y,z座標
		gaugeObjects[2]->AddComponent(gaugeSprites[2]);
	}

	if (playerCount >= 4) {
		//右下仮ゲージ
		gaugeSprites[3]->SetScale(new Vector2(25, 200));//横,縦 の大きさ
		gaugeObjects[3]->SetPosition(new Vector3(550, 450, 0));//x,y,z座標
		gaugeObjects[3]->AddComponent(gaugeSprites[3]);
	}

	//このコメントの下にプレイヤー関連の処理を追加

	

}

void Run::Update() {
	//これ以外何も書かないでください！
	timer += Time::GetInstance().GetDeltaTime();
}

float Run::GetTimer() {
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
