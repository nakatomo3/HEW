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

	GameObject* numberObject;
	
	vector<Sprite*> players;
	vector<Texture*> playerTexture;
	vector<Sprite*> playerSprites;

	vector<Sprite*> numbers;
	vector<Texture*> numberTexture;
	vector<Sprite*> numberSprites;

	vector<Sprite*> targets;
	vector<Texture*> targetTexture;
	vector<Sprite*> targetSprites;

	int playerCount = 0;

};

