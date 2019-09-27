#include "GameObject.h"
#include "NonComponentGameObject.h"

NonComponentGameObject::NonComponentGameObject() {
	position = Vector3(0,0,0);
	localPosition = Vector3(0,0,0);
	scale = Vector3(1, 1, 1);
	localScale = Vector3(1, 1, 1);
	rotation = Vector3(0, 0, 0);
	velocity = Vector3(0,0,0);
	LogWriter::GetInstance().Log("生成されました\n");
}

NonComponentGameObject::~NonComponentGameObject() {
	int childSize = child.size();
	LogWriter::GetInstance().Log("子供の数：%d\n", childSize);
	for (int i = 0; i < childSize; i++) {
		delete child[i];
	}
	LogWriter::GetInstance().Log("ゲームオブジェクトを削除しました\n");
}

Vector3 NonComponentGameObject::GetPosition() {
	return position;
}

void NonComponentGameObject::SetPosition(Vector3 newPos) {
	position = newPos;
}

Vector3 NonComponentGameObject::GetLocalPosition() {
	return localPosition;
}

void NonComponentGameObject::SetLocalPosition(Vector3 newPos) {
	localPosition = newPos;
}

Vector3 NonComponentGameObject::GetScale() {
	return scale;
}

void NonComponentGameObject::SetScale(Vector3 newScale) {
	scale = newScale;
}

Vector3 NonComponentGameObject::GetRotation() {
	return rotation;
}

void NonComponentGameObject::SetRotation(Vector3 newRotation) {
	rotation = newRotation;
}

Vector3 NonComponentGameObject::GetLocalScale() {
	return localScale;
}

void NonComponentGameObject::SetLocalScale(Vector3 newScale) {
	localScale = newScale;
}

void NonComponentGameObject::SetVelocity(Vector3 newVelocity) {
	velocity = newVelocity;
}

Vector3 NonComponentGameObject::GetVelocity() {
	return velocity;
}

string NonComponentGameObject::GetName() {
	return name;
}

void NonComponentGameObject::SetName(string newName) {
	name = newName;
}

string NonComponentGameObject::GetTag() {
	return tag;
}

void NonComponentGameObject::SetTag(string newTag) {
	tag = newTag;
}

bool NonComponentGameObject::CompareTag(string target) {
	return tag == target;
}

NonComponentGameObject * NonComponentGameObject::GetParent() {
	return nullptr;
}

void NonComponentGameObject::SetParent(NonComponentGameObject * parent) {
}

NonComponentGameObject * NonComponentGameObject::GetChild(int index) {
	return nullptr;
}

int NonComponentGameObject::GetChildCount() {
	return child.size();
}

void NonComponentGameObject::AddChild(NonComponentGameObject * child) {
}

void NonComponentGameObject::Rotate(Vector3 angle) {
	for (int i = 0; i < GetChildCount(); i++) {
		GetChild(i)->Rotate(angle * -1);
	}
}

void NonComponentGameObject::Move(Vector3 range) {
	for (int i = 0; i < GetChildCount(); i++) {
		GetChild(i)->Move(range);
	}
	SetPosition(position + range);
}
