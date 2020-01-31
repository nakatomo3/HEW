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

	//ランキングのテクスチャ
	Texture* rankingTexture;

	//ランキング背景のオブジェクト
	GameObject* background;

	//ランキング背景のスプライト
	Sprite* backgroundSprite;

	//順位のオブジェクト
	vector<GameObject*> rankingTime{};

	//順位のテキスト
	vector<Text*> rankingTimeText{};

	//順位ポイントのオブジェクト
	vector<GameObject*> rankingPoint{};

	//順位ポイントのテキスト
	vector<Text*> rankingPointText{};

	//メダルのオブジェクト
	vector <GameObject*> medal{};

	//メダルのスプライト
	vector <Sprite*> medalSprite{};

	//メダルのテクスチャ
	vector <Texture*> medalTexture{};

	RunResult* runResult;

	float timer = 0;

	bool isRanking = false;

	vector<float> times;
	vector<int> ranks;
	vector<int> point;
};