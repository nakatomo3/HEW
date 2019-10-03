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
		LogWriter::GetInstance().LogWorning("�Q�[���I�u�W�F�N�g�ɃA�^�b�`����Ă��Ȃ��R���|�[�l���g��Destroy����܂����B�K�؂ȋ������ǂ����m�F���Ă�������");
		delete this;
	} else {
		gameObject->RemoveComponent(this);
		LogWriter::GetInstance().Log("�R���|�[�l���g�͐���ɍ폜����܂���");
		delete this;
	}
}
