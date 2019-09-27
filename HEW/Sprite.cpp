#include "Sprite.h"

Sprite::Sprite(Texture * _texture, Vector2 * _scale, Vector3 * _position, Criterion _criterion) {
	texture = _texture;
	scale = _scale;
	position = _position;
	criterion = _criterion;
}

Sprite::~Sprite() {
	delete position;
	delete scale;
}

void Sprite::SetTexture(Texture * _texture) {
	texture = _texture;
}

void Sprite::SetScale(Vector2* _scale) {
	scale = _scale;
}

void Sprite::SetCriterion(Criterion _criterion) {
	criterion = _criterion;
}

void Sprite::SetPosition(Vector3* _position) {
	position = _position;
}
