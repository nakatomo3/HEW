#pragma once
#include <vector>
#include "Scene.h"
#include "Time.h"
#include "ChargeGaugeRun.h"
#include "PlayerRun.h"
#include "BalloonRun.h"

using namespace std;

class Run :	public Scene {
public:
	Run(string name);
	~Run();

	void Start();
	void Load();

	void Update();

	float GetTimer();

	void ChangePlayerCount(unsigned int num);
	int GetPlayerCount();

	Sprite* GetPlayerSprite(int playerID);


private:

	const float COUNT_DOWN_MAX = 3;

	float timer = -COUNT_DOWN_MAX;

	int playerCount = 4;

	//吹き出しのオブジェクト
	GameObject* balloon;

	//吹き出しのスプライト
	Sprite* balloonSprite;

	//吹き出しのテキスチャー
	Texture* balloonTexture;

	BalloonRun* balloonRun;


	//プレイヤースクリプト
	vector<PlayerRun*> players{};

	//プレイヤーのスプライト
	vector<Sprite*> playerSprite{};

	//プレイヤーのオブジェクト
	vector<GameObject*> playerObjects{};


	//ゲージスクリプト
	vector<ChargeGaugeRun*> gauges{};

	//ゲージのスプライト
	vector<Sprite*> gaugeSprites{};

	//ゲージのオブジェクト
	vector<GameObject*> gaugeObjects;
};