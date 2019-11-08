#include "Scene.h"
#include "SceneManager.h"

Scene::Scene(string _name) {
	name = _name;
	SceneManager::GetInstance().AddScene(this);
}

Scene::~Scene() {

}

void Scene::Start() {
	
}

void Scene::Load() {

}

void Scene::UnLoad() {
	delete this;
}

void Scene::Update() {
}

void Scene::Destroy() {
	delete this;
}

bool Scene::GetBool(string name) {
	return boolMap[name];
}

int Scene::GetInt(string name) {
	return intMap[name];
}

float Scene::GetFloat(string name) {
	return floatMap[name];
}

string Scene::GetString(string name) {
	return stringMap[name];
}

void Scene::SetBool(string name, bool value) {
	boolMap[name] = value;
}

void Scene::SetInt(string name, int value) {
	intMap[name] = value;
}

void Scene::SetFloat(string name, float value) {
	floatMap[name] = value;
}

void Scene::SetString(string name, string value) {
	stringMap[name] = value;
}
