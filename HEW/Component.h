#pragma once
#include "NonComponentGameObject.h"
#include "Object.h"

class Component : public Object {
public:
	Component();
	~Component();

	//GameObjectを親にしたいが、それだと変になってしまうので、いったん一つ上の基底クラスを参照。WIP
	NonComponentGameObject* gameObject;


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