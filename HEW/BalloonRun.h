#pragma once
#include "ScriptBase.h"
#include "Sprite.h"
#include <vector>

using namespace std;

class Run;
class BalloonRun : public ScriptBase {
public:
	BalloonRun();
	~BalloonRun();

	void Start();
	void Update();

	void SetSprite(Sprite* _sprite);

	void SetTexture(Texture* texture);

private:

	GameObject* runObject;

	Sprite* sprite;

	vector<Texture*> textures;

	Run* run = nullptr;
};

