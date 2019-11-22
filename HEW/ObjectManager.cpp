#include "ObjectManager.h"
#include <list>
#include "LogWriter.h"
#include "VisualComponent.h"

void ObjectManager::Instantiate(GameObject* instance) {
	objects.emplace_back(instance);
	for (int i = 0; i < instance->GetComponentCount(); i++) {
		instance->GetComponent(i)->Awake();
		instance->GetComponent(i)->Start();
	}
}

void ObjectManager::Destroy(GameObject* instance) {
	for (unsigned int i = 0; i < objects.size(); i++) {
		if (objects[i] == instance) {
			GameObject* removeObject = instance;
			objects[i] = objects[objects.size() - 1];
			objects.pop_back();
			instance->Destroy();
			return;
		}
	}
	LogWriter::GetInstance().LogError("オブジェクトマネージャーに登録されていないオブジェクトがDestroyされました");
	instance->Destroy();
}

bool ObjectManager::CheckInstance(GameObject* instance) {
	for (unsigned int i = 0; i < objects.size(); i++) {
		if (objects[i] == instance) {
			return true;
		}
	}
	return false;
}

void ObjectManager::Awake() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		if (objects[i]->GetActive() == false) {
			continue;
		}
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			if (objects[i]->GetComponent(j)->GetActive() == true) {
				objects[i]->GetComponent(j)->Awake();
			}
		}
	}
}

void ObjectManager::Start() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		if (objects[i]->GetActive() == false) {
			continue;
		}
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			if (objects[i]->GetComponent(j)->GetActive() == true) {
				objects[i]->GetComponent(j)->Start();
			}
		}
	}
}

void ObjectManager::FirstUpdate() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		if (objects[i]->GetActive() == false) {
			continue;
		}
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			if (objects[i]->GetComponent(j)->GetActive() == true) {
				objects[i]->GetComponent(j)->FirstUpdate();
			}
		}
	}
}

void ObjectManager::Update() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		if (objects[i]->GetActive() == false) {
			continue;
		}
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			if (objects[i]->GetComponent(j)->GetActive() == true) {
				objects[i]->GetComponent(j)->Update();
			}
		}
	}
}

void ObjectManager::LateUpdate() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		if (objects[i]->GetActive() == false) {
			continue;
		}
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			if (objects[i]->GetComponent(j)->GetActive() == true) {
				objects[i]->GetComponent(j)->LateUpdate();
			}
		}
	}
}

void ObjectManager::Draw() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		if (objects[i]->GetActive() == false) {
			continue;
		}
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			VisualComponent* cast_c = dynamic_cast<VisualComponent*>(objects[i]->GetComponent(j));
			if (cast_c != NULL && objects[i]->GetComponent(j)->GetActive() == true) {
				cast_c->Draw();
			}
		}
	}
}

void ObjectManager::LateDraw() {
	for (unsigned int i = 0; i < objects.size(); i++) {
		if (objects[i]->GetActive() == false) {
			continue;
		}
		for (unsigned int j = 0; j < objects[i]->GetComponentCount(); j++) {
			VisualComponent* cast_c = dynamic_cast<VisualComponent*>(objects[i]->GetComponent(j));
			if (cast_c != NULL && objects[i]->GetComponent(j)->GetActive() == true) {
				cast_c->LateDraw();
			}
		}
	}
}

ObjectManager::ObjectManager() {
	LogWriter::GetInstance().Log("オブジェクトマネージャーが初期化されました");
}