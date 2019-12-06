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
	bool isRule = false;

	GameObject* backgroundObject;
	Sprite* backgroundSprite;

	GameObject* ruleObject;
	Sprite* ruleSprite;

	vector<Sprite*> players;
	vector<Sprite*> oks;

	Texture* okTexture;
	vector<Texture*> playerTexture;
	vector<Sprite*> okSprites;

	int playerCount = 0;

	vector<bool> isReady;

};

