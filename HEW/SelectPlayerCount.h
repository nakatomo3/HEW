#pragma once
#include "Scene.h"
#include <string.h>
#include "Sprite.h"
#include <vector>
using namespace std;
class SelectPlayerCount : public Scene {
public:
	SelectPlayerCount(string name);
	~SelectPlayerCount();

	void Load();
	void UnLoad();
	void Start();
	void Update();

private:
	GameObject* cursorObject;
	Sprite* cursorSprite;
	Texture* cursorTexture;

	GameObject* playerCountObject;
	vector<Sprite*> playerCountSprites;
	vector<Texture*> playerCountTextures;

	GameObject* backGroundObject;
	Sprite* backGroundSprite;
	Texture* backGroundTexture;
};

