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

	TitleAnimation* titleAnimation;

	//GameObject* player1Object;
	//Sprite* player1Sprite;
};

