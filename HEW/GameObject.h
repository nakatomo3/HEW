#pragma once
#include "NonComponentGameObject.h"
#include "Component.h"
#include "LogWriter.h"
#include <vector>
#include <typeinfo.h>

class GameObject : public NonComponentGameObject {
public:
	GameObject();
	~GameObject();

	template<typename T>
	Component* GetComponent(T* t) {
		//そもそもComponent型なのかをチェックする
		Component* cast_t = dynamic_cast<Component*>(t);
		//引数はコンポーネントである
		if (cast_t != NULL) {
			for (unsigned int i = 0; i < components.size(); i++) {
				Component* checkComponent = dynamic_cast<T*>(components[i]);
				if (checkComponent != NULL) {
					//正常に見つかった
					return components[i];
				}
			}
			//引数はコンポーネントだったが見つからなかった
			return nullptr;
		} else {
			//引数がコンポーネントじゃなかった
			return nullptr;
		}
	}

	//[非推奨]　コンポーネントを取得します。num=上から数えたコンポーネントの数。
	Component* GetComponent(unsigned int num);

	//コンポーネントがどれだけアタッチされているかをカウントします。
	unsigned int GetComponentCount();

	void AddComponent(Component* component);

	template<typename T>
	void RemoveComponent(T* t) {
		Component* cast_t = dynamic_cast<Component*>(t);
		if (cast_t != NULL) {
			for (unsigned int i = 0; i < components.size(); i++) {
				Component* checkComponent = dynamic_cast<T*>(components[i]);
				if (checkComponent != NULL) {
					//正常に見つかった
					components.erase(components.begin() + i);
					return;
				}
			}
			//引数はコンポーネントだったが見つからなかった
			return;
		} else {
			//引数がコンポーネントじゃなかった
			return;
		}
	
	}

protected:
	vector<Component*> components;

};
