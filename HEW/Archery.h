#pragma once
#include <vector>
#include "Scene.h"
#include "Time.h"
#include "BalloonArchery.h"
#include <string>
#include "HeroEngine.h"
#include "Input.h"
using namespace std;

class Archery : public Scene {
public:
	Archery(string name);
	~Archery();

	void Start();
	void Load();
	void Update();
	void UnLoad();

	double GetTimer();

	void ChangePlayerCount(unsigned int num);
	int GetPlayerCount();

	Sprite* GetPlayerSprite(int playerID);

	void SetSprite(Sprite* _sprite);

	void SetTime(int playerNumber, float time);

	double timer = -COUNT_DOWN_MAX;

private:

	const float COUNT_DOWN_MAX = 3;

	GameObject* backgroundObject;
	Sprite* backgroundSprite;

	GameObject* balloon;
	Texture* balloonTexture;
	Sprite* balloonSprite;
	BalloonArchery* balloonArchery;

	GameObject* playerObject;
	GameObject* numberObject;
	vector <GameObject*> targetObject{};
	GameObject* scoretitleObject;
	GameObject* scoreObject;
	
	vector<Sprite*> players;
	vector<Texture*> waitingPlayerTexture;
	vector<Texture*> shotPlayerTexture;
	vector<Sprite*> playerSprites;

	vector<Sprite*> numbers;
	vector<Texture*> numberTexture;
	vector<Sprite*> numberSprites;

	
	Texture* targetTexture1;
	Texture* targetTexture2;
	vector<Sprite*> targetSprites{};

	vector<Sprite*> scoretitles;
	vector<Texture*> scoretitleTexture;
	vector<Sprite*> scoretitleSprite;

	vector<int> scoreValues;

	int playerCount = 0;
	vector<Text*> marks;
	vector<float> times;

	vector<bool> wasInput;
};

