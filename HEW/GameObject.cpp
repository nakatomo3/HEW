#include "GameObject.h"



GameObject::GameObject() {
}


GameObject::~GameObject() {
}

Component * GameObject::GetComponent(unsigned int num) {
	if (num >= components.size() || num < 0) {
		LogWriter::GetInstance().LogWorning("コンポーネントの取得に失敗しました。\nゲームオブジェクト名：%s\nコンポーネント引数：%d", name, num);
		return nullptr;
	}
	return components[num];
}

unsigned int GameObject::GetComponentCount() {
	return components.size();
}


void GameObject::AddComponent(Component * component) {
	components.emplace_back(component);
}

