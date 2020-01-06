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

	int playerCount = 0;

	float timer = 0;
};

