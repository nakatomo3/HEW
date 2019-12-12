#pragma once
#include <vector>
#include "Scene.h"
#include "Time.h"
#include <string>
#include "HeroEngine.h"
using namespace std;

class Archery : public Scene {
public:
	Archery(string name);
	~Archery();

	void Start();
	void Load();
	void Update();
	void UnLoad();

private:

	GameObject* backgroundObject;
	Sprite* backgroundSprite;

	vector<Sprite*> players;
	vector<Sprite*> numbers;
	vector<Sprite*> targets;

	Texture* numberTexture;
	vector<Texture*> playerTexture;
	vector<Sprite*> numberSprites;

	Texture* targetTexture;
	vector<Sprite*> targetSprites;

	int playerCount = 0;

};

