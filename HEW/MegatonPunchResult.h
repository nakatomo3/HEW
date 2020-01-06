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

	int playerCount = 0;

	bool isRanking = false;

  float timer = 0;
};

