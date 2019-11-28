#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Texture.h"

#include <vector>
using namespace std;

class Rule : public Scene {
public:
	Rule(string name);
	~Rule();

	void Start();
	void Load();
	void Update();
	void UnLoad();

private:

	GameObject* manualObject;
	Sprite* manualSprite;

	GameObject* ruleObject;
	Sprite* ruleSprite;

	int playerCount = 0;

	vector<Sprite*> players;
	vector<Sprite*> oks;

	vector<bool> isReady;

};

