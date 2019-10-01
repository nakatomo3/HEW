#pragma once
#include "Object.h"

class GameObject;
class Component : public Object {
public:
	Component();
	~Component();

	//初期化の一番最初に使用。
	virtual void Awake() {

	}

	//一般的な初期化に使用。
	virtual void Start() {
		
	}

	//一番最初の毎フレームごとの更新に使用。
	virtual void FirstUpdate() {

	}

	//一般的な毎フレームごとの更新に使用。
	virtual void Update() {

	}

	//一番最後の毎フレームごとの更新に使用。
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