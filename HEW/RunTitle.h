#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Texture.h"
#include "RunTitleAnimation.h"
#include "RunManual.h"

#include <vector>
using namespace std;

class RunTitle : public Scene {
public:
	RunTitle(string name);
	~RunTitle();

	void Start();
	void Load();
	void UnLoad();

	void Update();

private:
	GameObject* titleObject;
	Sprite* titleSprite;
	RunTitleAnimation* runTitleAnimation;

	bool isManual = false;

	GameObject* manualObject;
	Sprite* manualSprite;

	vector<Sprite*> players;
	vector<Sprite*> oks;

	Texture* okTexture;
	vector<Texture*> playerTexture;

	GameObject* backgroundObject;
	Sprite* backgroundSprite;

	Sprite* titleLogo1;
	Sprite* titleLogo2;

	Texture* logoTexture1;
	Texture* logoTexture2;

	float timer;

	int logoSpeed = 4000;

	int playerCount = 0;

	vector<bool> isReady;

};

