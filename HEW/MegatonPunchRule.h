#pragma once
#include "Scene.h"
#include "Sprite.h"
class MegatonPunchRule : public Scene {
public:
	MegatonPunchRule(string name);
	~MegatonPunchRule();

	void Load();
	void Start();
	void Update();

	void UnLoad();

private:
	GameObject* backgroundObject;
	Sprite* backgroundSprite;

	GameObject* manualObject;
	Sprite* manualSprite;

	vector<Sprite*> players;
	vector<Sprite*> oks;

	Texture* okTexture;
	vector<Texture*> playerTexture;

	int playerCount = 0;

	vector<bool> isReady;
};

