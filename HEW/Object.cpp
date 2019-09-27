#include "Object.h"

Object::Object() {
	isActive = true;
}

void Object::Destroy() {
	delete this;
}

bool Object::IsActive() {
	return isActive;
}

void Object::SetActive(bool active) {
	isActive = active;
}


Object::~Object() {
}