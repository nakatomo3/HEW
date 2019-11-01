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
	GameObject* titleObjct;
	Sprite* titleSprite;

	TitleAnimation* titleAnimation;
};

