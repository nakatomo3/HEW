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
	void UnLoad();

private:

	//ランキングのオブジェクト
	GameObject* ranking;

	//ランキングのスプライト
	Sprite* rankingSprite;

	//ランキング背景のオブジェクト
	GameObject* rankingBackground;

	//ランキング背景のスプライト
	Sprite* rankingBackgroundSprite;
};

