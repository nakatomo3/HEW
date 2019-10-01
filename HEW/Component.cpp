#include "Component.h"



Component::Component() {

}


Component::~Component() {
}

GameObject* Component::GetGameObject() {
	return gameObject;
}

void Component::SetGameObject(GameObject* _gameObject) {
	gameObject = _gameObject;
}
