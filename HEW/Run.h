#pragma once
#include <vector>
#include "Scene.h"
#include "Time.h"
#include "ChargeGaugeRun.h"
#include "PlayerRun.h"
#include "BalloonRun.h"
#include "HeroEngine.h"


using namespace std;

class Run :	public Scene {
public:
	Run(string name);
	~Run();

	void Start();
	void Load();
	void UnLoad();

	void Update();

	double GetTimer();

	void ChangePlayerCount(unsigned int num);
	int GetPlayerCount();

	Sprite* GetPlayerSprite(int playerID);

	void SetSprite(Sprite* _sprite);

	void SetTime(int playerNumber, float time);

	double timer = -COUNT_DOWN_MAX;
private:

	const float COUNT_DOWN_MAX = 3;


	int playerCount = 4;//とりあえずは4人分にしている(デフォは0)

	double replayTimer = 0;

	//吹き出しのオブジェクト
	GameObject* balloon;

	//吹き出しのスプライト
	Sprite* balloonSprite;

	//吹き出しのテクスチャー
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

	//レーンのオブジェクト
	GameObject* lane;

	//レーンのスプライト
	Sprite* laneSprite;

	//レーンのテクスチャ
	Texture* laneTexture;

	//背景のオブジェクト
	GameObject* background;

	//背景のスプライト
	Sprite* backgroundSprite;

	//背景のテクスチャ
	Texture* backgroundTexture;

	//リプレイロゴのオブジェクト
	GameObject* replayRogo;

	//リプレイロゴのスプライト
	Sprite* replayRogoSprite;
	Sprite* replayRogoSprite2;
	Sprite* replayRogoSprite3;

	//リプレイロゴのテクスチャ
	Texture* replayRogoTexture;
	Texture* replayRogoTexture2;

	//リプレイロゴ背景のオブジェクト
	GameObject* replayRogoBackground;

	//リプレイロゴ背景のスプライト
	Sprite* replayRogoBackgroundSprite;

	//リプレイロゴ背景のテクスチャ
	Texture* replayRogoBackgroundTexture;

	//ハイライト背景のオブジェクト
	GameObject* highlightBackground;

	//ハイライト背景のスプライト
	Sprite*  highlightBackgroundSprite;

	//ハイライト背景のテクスチャ
	Texture* highlightBackgroundTexture;

	//タイムのオブジェクト
	GameObject* runTime;

	//タイムのテキスト
	Text* runTimeText;

	bool isReady = false;
	bool isGoalCamera = false;
	bool isReplay = false;
	int logoSpeed = 1500;

	vector<float> times;
	vector<float> charges;
};