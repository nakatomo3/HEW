#pragma once
#include "Object.h"

class GameObject;
class Component : public Object {
public:
	Component();

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

	//使用禁止。gameObject.RemoveComponent(this)をすること
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