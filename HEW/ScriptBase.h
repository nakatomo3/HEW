#pragma once
#include "GameObject.h"
#include "Component.h"
class ScriptBase : public Component{
public:
	ScriptBase();
	ScriptBase(GameObject* gameObject);
	~ScriptBase();

	//生成されたときに一番最初に呼び出されます。Start関数よりも先に呼び出されます
	virtual void Awake();
	//生成されたときに呼び出されます。Awake関数よりも後に呼び出されます。
	virtual void Start();
	//最初に呼び出されるUpdateです。
	virtual void FirstUpdate();
	//通常呼び出されるUpdateです。
	virtual void Update();
	//最後に呼び出されるUpdateです。
	virtual void LateUpdate();

protected:

private:

};