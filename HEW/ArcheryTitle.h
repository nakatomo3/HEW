#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Texture.h"
#include <string>

#include <vector>
using namespace std;


class ArcheryTitle : public Scene {
public:
	ArcheryTitle(string name);
	~ArcheryTitle();

	void Start();
	void Load();
	void UnLoad();

	void Update();

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

