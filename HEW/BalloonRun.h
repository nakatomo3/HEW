#pragma once
#include "ScriptBase.h"
#include "Sprite.h"

class BalloonRun : public ScriptBase {
public:
	BalloonRun();
	~BalloonRun();

private:
	Sprite* sprite;
};

