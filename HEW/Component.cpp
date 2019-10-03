#include "Component.h"
#include "LogWriter.h"
#include "GameObject.h"

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

void Component::Destroy() {
	if (gameObject == nullptr) {
		LogWriter::GetInstance().LogWorning("ゲームオブジェクトにアタッチされていないコンポーネントがDestroyされました。適切な挙動かどうか確認してください");
		delete this;
	} else {
		gameObject->RemoveComponent(this);
		LogWriter::GetInstance().Log("コンポーネントは正常に削除されました");
		delete this;
	}
}
