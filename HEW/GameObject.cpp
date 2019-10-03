#include "GameObject.h"
#include "LogWriter.h"
#include "ObjectManager.h"

void GameObject::Destroy() {

	for (int i = 0; i < components.size(); i++) {
		Component* removeComponent = components.at(0);
		RemoveComponent(removeComponent);
	}

	for (int i = 0; i < children.size(); i++) {
		GameObject* child = children.at(0);
		child->Destroy();
	}

	delete this;
}

GameObject::GameObject() {
	position = new Vector3(0,0,0);
	localPosition = new Vector3(0,0,0);
	scale = new Vector3(1, 1, 1);
	localScale = new Vector3(1, 1, 1);
	rotation = new Vector3(0, 0, 0);
	velocity = new Vector3(0,0,0);
	LogWriter::GetInstance().Log("ゲームオブジェクトが生成されました\n");
}

GameObject::~GameObject() {
	int childSize = children.size();
	LogWriter::GetInstance().Log("子供の数：%d\n", childSize);
	for (int i = 0; i < childSize; i++) {
		delete children[i];
	}
	delete position;
	delete localPosition;
	delete scale;
	delete localScale;
	delete rotation;
	delete velocity;
	LogWriter::GetInstance().Log("ゲームオブジェクトを削除しました\n");
}

Vector3* GameObject::GetPosition() {
	return position;
}

void GameObject::SetPosition(Vector3* newPos) {
	delete position;
	position = newPos;
}

Vector3* GameObject::GetLocalPosition() {
	return localPosition;
}

void GameObject::SetLocalPosition(Vector3* newPos) {
	localPosition = newPos;
}

Vector3* GameObject::GetScale() {
	return scale;
}

void GameObject::SetScale(Vector3* newScale) {
	scale = newScale;
}

Vector3* GameObject::GetRotation() {
	return rotation;
}

void GameObject::SetRotation(Vector3* newRotation) {
	delete rotation;
	rotation = newRotation;
}

Vector3* GameObject::GetLocalScale() {
	return localScale;
}

void GameObject::SetLocalScale(Vector3* newScale) {
	delete localScale;
	localScale = newScale;
}

void GameObject::SetVelocity(Vector3* newVelocity) {
	velocity = newVelocity;
}

Vector3* GameObject::GetVelocity() {
	return velocity;
}

string GameObject::GetName() {
	return name;
}

void GameObject::SetName(string newName) {
	name = newName;
}

string GameObject::GetTag() {
	return tag;
}

void GameObject::SetTag(string newTag) {
	tag = newTag;
}

bool GameObject::CompareTag(string target) {
	return tag == target;
}

GameObject * GameObject::GetParent() {
	return nullptr;
}

void GameObject::SetParent(GameObject * parent) {
}

GameObject * GameObject::GetChild(int index) {
	return nullptr;
}

int GameObject::GetChildCount() {
	return children.size();
}

void GameObject::AddChild(GameObject * child) {
}

void GameObject::Rotate(Vector3 angle) {
	for (int i = 0; i < GetChildCount(); i++) {
		GetChild(i)->Rotate(angle * -1);
	}
}

void GameObject::Move(Vector3 range) {
	for (int i = 0; i < GetChildCount(); i++) {
		GetChild(i)->Move(range);
	}
	SetPosition(new Vector3(position->GetX() + range.GetX(), position->GetY() + range.GetY(), position->GetZ()+ range.GetZ()));
}

Component* GameObject::GetComponent(unsigned int num) {
	if (num >= components.size() || num < 0) {
		LogWriter::GetInstance().LogWorning("コンポーネントの取得に失敗しました。\nゲームオブジェクト名：%s\nコンポーネント引数：%d", name, num);
		return nullptr;
	}
	return components[num];
}

unsigned int GameObject::GetComponentCount() {
	return components.size();
}


void GameObject::AddComponent(Component* component) {
	components.emplace_back(component);
	component->SetGameObject(this);
}
