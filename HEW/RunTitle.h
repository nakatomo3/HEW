#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Texture.h"
#include "RunTitleAnimation.h"
#include "RunManual.h"
class RunTitle : public Scene {
public:
	RunTitle(string name);
	~RunTitle();

	void Start();
	void Load();

	void Update();

private:
	GameObject* titleObject;
	Sprite* titleSprite;
	RunTitleAnimation* runTitleAnimation;

	bool isManual = false;

	GameObject* manualObject;
	Sprite* manualSprite;
	RunManual* runManual;

	GameObject* backgroundObject;
	Sprite* backgroundSprite;


	Sprite* titleLogo1;
	Sprite* titleLogo2;

	Texture* logoTexture1;
	Texture* logoTexture2;

	float timer;

	int logoSpeed = 4000;

};
