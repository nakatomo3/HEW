#pragma once
#include "ScriptBase.h"
#include "Sprite.h"
class PendulumPunch : public ScriptBase {
public:
	PendulumPunch();
	~PendulumPunch();

	void Start();
	void Update();

	void SetSprite(Sprite* sprite);

	float GetValue();

	void SetNormalTexture(Texture* _texture);
	void SetWhiteTexutre(Texture* _texture);

private:
	Sprite* sprite;

	Texture* normal;
	Texture* white;

	bool isRight = true;

	float rad;

	const float PI = 3.1415926f;
};

