#pragma once
#include "Object.h"

class GameObject;
class Component : public Object {
public:
	Component();
	~Component();

	//�������̈�ԍŏ��Ɏg�p�B
	virtual void Awake() {

	}

	//��ʓI�ȏ������Ɏg�p�B
	virtual void Start() {
		
	}

	//��ԍŏ��̖��t���[�����Ƃ̍X�V�Ɏg�p�B
	virtual void FirstUpdate() {

	}

	//��ʓI�Ȗ��t���[�����Ƃ̍X�V�Ɏg�p�B
	virtual void Update() {

	}

	//��ԍŌ�̖��t���[�����Ƃ̍X�V�Ɏg�p�B
	virtual void LateUpdate() {

	}

	GameObject* GetGameObject();
	void SetGameObject(GameObject* _gameObject);

protected :
	GameObject* gameObject;

};

class sampleComponent : public Component {
public :
	sampleComponent() {};
	~sampleComponent() {};

	void Awake() {
		//
	}

	void Start() {

	}

	void FirstUpdate() {

	}

	void Update() {

	}

	void LateUpdate() {

	}
};