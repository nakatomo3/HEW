#pragma once
#include "Texture.h"
#include "Vector3.h"
#include "Vector2.h"
#include "VisualComponent.h"

class Sprite : public VisualComponent{
public:
	Sprite(Texture* _texture, Vector2* _scale = new Vector2(1,1), Vector3* _position = new Vector3(0,0,0),Criterion _criterion = CENTER);
	~Sprite();

	void SetTexture(Texture* _texture);
	void SetScale(Vector2* _scale);
	void SetCriterion(Criterion _criterion);
	void SetPosition(Vector3* _position);

private :
	Texture* texture;

	Vector2* scale;

	Criterion criterion = CENTER;
	Vector3* position;
};

