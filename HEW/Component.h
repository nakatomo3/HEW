#pragma once
#include "Object.h"

class GameObject;
class Component : public Object {
public:
	Component();

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

	//�g�p�֎~�BgameObject.RemoveComponent(this)�����邱��
	void Destroy() override final;

protected :
	GameObject* gameObject;
	~Component();

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