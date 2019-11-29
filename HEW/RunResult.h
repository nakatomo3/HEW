#pragma once
#include "Scene.h"
#include "Sprite.h"

class RunResult : public Scene {
public:
	RunResult(string name);
	~RunResult();

	void Start();
	void Load();
	void UnLoad();
	void Update();

private:
	///ランキングのオブジェクト
	GameObject* ranking;

	//ランキングのスプライト
	Sprite* rankingSprite;

	//ランキング背景のオブジェクト
	GameObject* background;

	//ランキング背景のスプライト
	Sprite* backgroundSprite;

	RunResult* runResult;

	float timer = 0;
};