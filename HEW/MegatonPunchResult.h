#pragma once
#include "Scene.h"
#include "MegatonPunch.h"
#include <string>
#include <vector>
using namespace std;
class MegatonPunchResult : public Scene {
public:
	MegatonPunchResult(string name);
	~MegatonPunchResult();

	void Start();
	void Load();
	void UnLoad();
	void Update();

private:
	//瓦割のスコア変数
	vector<int> scores;

	//ランキングのオブジェクト
	GameObject* ranking;

	//ランキングのスプライト
	Sprite* rankingSprite;

	//ランキング背景のオブジェクト
	GameObject* rankingBackground;

	//ランキング背景のスプライト
	Sprite* rankingBackgroundSprite;

	//順位のオブジェクト
	vector<GameObject*> rankingScore{};

	//順位のテキスト
	vector<Text*> rankingScoreText{};

	//順位ポイントのオブジェクト
	vector<GameObject*> rankingPoint{};

	//順位ポイントのテキスト
	vector<Text*> rankingPointText{};

	MegatonPunchResult* megatonpunchresult;

	int playerCount = 0;

	bool isRanking = false;

  float timer = 0;

  vector<int> point;
};

