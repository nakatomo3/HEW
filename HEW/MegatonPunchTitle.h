#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Texture.h"
class MegatonPunchTitle : public Scene {
public:
	MegatonPunchTitle(string name);
	~MegatonPunchTitle();

	void Start();
	void Load();
	void UnLoad();

	void Update();

	GameObject* titleObject;
	Sprite* titleSprite;

	GameObject* backgroundObject;
	Sprite* backgroundSprite;

	Sprite* titleLogo1;
	Sprite* titleLogo2;

	Texture* logoTexture1;
	Texture* logoTexture2;
	Texture* logoTexture3;

	float timer = 0;

	//int logoSpeed = 4000; ˆê‰ž‚ ‚é‚¾‚¯
};