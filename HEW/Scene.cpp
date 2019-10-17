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
