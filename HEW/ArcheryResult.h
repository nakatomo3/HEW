#pragma once
#include "Scene.h"
#include "Archery.h"
#include <string>
using namespace std;
class ArcheryResult : public Scene {
public :
	ArcheryResult(string name);
	~ArcheryResult();

	void Start();
	void Load();
	void Update();
	void UnLoad();

private:

	vector<int> scores;

	//ランキングのオブジェクト
	GameObject* ranking;

	//ランキングのスプライト
	Sprite* rankingSprite;

	//ランキングのテクスチャ
	Texture* rankingTexture;

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

	ArcheryResult* archeryresult;
	
	float timer;

	int playerCount = 0;

	bool isRanking = false;

	vector<int> point;
};

