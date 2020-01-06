#pragma once
#include "ScriptBase.h"
#include "Sprite.h"
#include <vector>

using namespace std;

class Archery;
class BalloonArchery : public ScriptBase {
public:
	BalloonArchery();
	~BalloonArchery();

	void Start();
	void Update();

	void SetSprite(Sprite* _sprite);

	void SetTexture(Texture* texture);

private:

	GameObject* archeryObject;

	Sprite* sprite;

	vector<Texture*> textures;

	Archery* archery = nullptr;
};
