#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "TitleAnimation.h"

class Title : public Scene {
public:
	Title(string name);
	~Title();

	void Start();
	void Load();

	void Update();

private:
	GameObject* titleObject;
	Sprite* titleSprite;

	Sprite* titleLogo1;
	Sprite* titleLogo2;
	Sprite* titleLogo3;
	Sprite* titleLogo4;
	Sprite* titleLogo5;
	Sprite* titleLogo6;

	TitleAnimation* titleAnimation;

	Texture* logoTexture1;
	Texture* logoTexture2;
	Texture* logoTexture3;
	Texture* logoTexture4;
	Texture* logoTexture5;
	Texture* logoTexture6;

	//GameObject* player1Object;
	//Sprite* player1Sprite;

	float timer;

	int logoSpeed = 4000;

};