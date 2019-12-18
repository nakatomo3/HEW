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

	GameObject* playerObject;
	GameObject* numberObject;
	GameObject* targetObject;
	GameObject* scoretitleObject;
	GameObject* scoreObject;
	
	vector<Sprite*> players;
	vector<Texture*> playerTexture;
	vector<Sprite*> playerSprites;

	vector<Sprite*> numbers;
	vector<Texture*> numberTexture;
	vector<Sprite*> numberSprites;

	vector<Sprite*> targets;
	vector<Texture*> targetTexture;
	vector<Sprite*> targetSprites;

	vector<Sprite*> scoretitles;
	vector<Texture*> scoretitleTexture;
	vector<Sprite*> scoretitleSprite;

	vector<Sprite*> scores;
	vector<Text*> scoreText;
	vector<Sprite*> scoreSprite;

	vector<int> scoreValues;

	int playerCount = 0;
	vector<Text*> marks;
};

