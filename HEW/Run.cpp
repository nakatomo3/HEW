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
	//LogWriter::GetInstance().Log("hoge");
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

	//左上仮ゲージ
	Sprite* gaugeSprites = new Sprite();
	gaugeSprites->SetScale(new Vector2(25, 200));//横,縦 の大きさ
	GameObject* gaugeObjects = new GameObject();
	gaugeObjects->SetPosition(new Vector3(50, 150, 0));//x,y,z座標
	gaugeObjects->AddComponent(gaugeSprites);
	ObjectManager::GetInstance().Instantiate(gaugeObjects);

	//右上仮ゲージ
	Sprite* gaugeSprites2 = new Sprite();
	gaugeSprites2->SetScale(new Vector2(25, 200));//横,縦 の大きさ
	GameObject* gaugeObjects2 = new GameObject();
	gaugeObjects2->SetPosition(new Vector3(550, 150, 0));//x,y,z座標
	gaugeObjects2->AddComponent(gaugeSprites2);
	ObjectManager::GetInstance().Instantiate(gaugeObjects2);

	//左下仮ゲージ
	Sprite* gaugeSprites3 = new Sprite();
	gaugeSprites3->SetScale(new Vector2(25, 200));//横,縦 の大きさ
	GameObject* gaugeObjects3 = new GameObject();
	gaugeObjects3->SetPosition(new Vector3(50, 450, 0));//x,y,z座標
	gaugeObjects3->AddComponent(gaugeSprites3);
	ObjectManager::GetInstance().Instantiate(gaugeObjects3);

	//右下仮ゲージ
	Sprite* gaugeSprites4 = new Sprite();
	gaugeSprites4->SetScale(new Vector2(25, 200));//横,縦 の大きさ
	GameObject* gaugeObjects4 = new GameObject();
	gaugeObjects4->SetPosition(new Vector3(550, 450, 0));//x,y,z座標
	gaugeObjects4->AddComponent(gaugeSprites4);
	ObjectManager::GetInstance().Instantiate(gaugeObjects4);


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
