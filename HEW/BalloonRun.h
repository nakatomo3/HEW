#pragma once
#include "ScriptBase.h"
#include "Sprite.h"

class BalloonRun : public ScriptBase {
public:
	BalloonRun();
	~BalloonRun();

	void Start();
	void Update();

	void SetSprite(Sprite* _sprite);

private:
	Sprite* sprite;

	Sprite* threeSprite;
	Sprite* twoSprite;
	Sprite* oneSprite;


};

