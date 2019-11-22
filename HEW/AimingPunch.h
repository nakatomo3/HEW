#pragma once
#include "ScriptBase.h"
#include "Sprite.h"

class AimingPunch : public ScriptBase {
public:
	AimingPunch();
	~AimingPunch();

	void Start();
	void Update();

	void SetSprite(bool isA, Sprite* sprite);

	float GetValue();

	void SetNormalTexture(Texture* _texture);
	void SetWhiteTexture(Texture* _texture);

private:
	Sprite* aimingA;
	Sprite* aimingB;

	Texture* normal;
	Texture* white;

	float rad;

	const float PI = 3.1415926f;

	const float speed = 0.07f;
	const float radiusX = 50;
	const float radiusY = 10;

	const float whiteRange = 0.2f;
};

