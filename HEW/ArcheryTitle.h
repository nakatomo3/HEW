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

	bool isManual = false;

	GameObject* backgroundObject;
	Sprite* backgroundSprite;

	GameObject* manualObject;
	Sprite* manualSprite;

	vector<Sprite*> players;
	vector<Sprite*> oks;

	Texture* okTexture;
	vector<Texture*> playerTexture;

	GameObject* archeryObject;
	Sprite* archerySprite;

	Sprite* archeryLogo1;
	Sprite* archeryLogo2;
	Sprite* archeryLogo3;
	Sprite* archeryLogo4;
	Sprite* archeryLogo5;
	Sprite* archeryLogo6;

	Texture* archeryTexture1;
	Texture* archeryTexture2;
	Texture* archeryTexture3;
	Texture* archeryTexture4;
	Texture* archeryTexture5;
	Texture* archeryTexture6;

	int logoSpeed = 4000;

	int playerCount = 0;

	float timer = 0;

	vector<bool> isReady;
	
};

