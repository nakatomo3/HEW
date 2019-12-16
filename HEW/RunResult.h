#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "HeroEngine.h"
#include <vector>

using namespace std;
class RunResult : public Scene {
public:
	RunResult(string name);
	~RunResult();

	void Start();
	void Load();
	void UnLoad();
	void Update();

private:

	int playerCount;

	///ランキングのオブジェクト
	GameObject* ranking;

	//ランキングのスプライト
	Sprite* rankingSprite;

	//ランキング背景のオブジェクト
	GameObject* background;

	//ランキング背景のスプライト
	Sprite* backgroundSprite;

	//順位のオブジェクト
	vector<GameObject*> rankingTime{};

	//順位のテキスト
	vector<Text*> rankingTimeText{};

	RunResult* runResult;

	float timer = 0;

	bool isRanking = false;

	vector<float> times;
	vector<int> ranks;
};