#include "ScriptBase.h"
#include "GameObject.h"

ScriptBase::~ScriptBase() {
}

ScriptBase::ScriptBase() {
}

ScriptBase::ScriptBase(GameObject * _gameObject) {
	/*gameObject = _gameObject;
	_gameObject->AddComponent(this);*/
}


void ScriptBase::Awake() {

}

void ScriptBase::Start() {

}

void ScriptBase::FirstUpdate() {

}

void ScriptBase::Update() {

}

void ScriptBase::LateUpdate() {

}

