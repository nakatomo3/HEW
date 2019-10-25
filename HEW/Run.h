#pragma once
#include "Scene.h"
#include "Time.h"
#include "ChargeGaugeRun.h"
#include "PlayerRun.h"

class Run :	public Scene {
public:
	Run(string name);
	~Run();

	void Start();
	void Load();

	void Update();

	float GetTimer();

	void ChangePlayerCount(unsigned int num);

private:

	const float COUNT_DOWN_MAX = 3;

	float timer = -COUNT_DOWN_MAX;

	int playerCount = 0;

	//吹き出しのオブジェクト
	GameObject* balloon;

	//吹き出しのスプライト
	Sprite* balloonSprite;

	//プレイヤースクリプト
	PlayerRun* players[4];

	//プレイヤーのオブジェクト
	GameObject* playerObjects[4];

	//プレイヤーのスプライト
	Sprite* playerSprite[4];

	//ゲージスクリプト
	ChargeGaugeRun* gauge[4];

	//ゲージのスプライト
	Sprite* gaugeSprite[4];
};