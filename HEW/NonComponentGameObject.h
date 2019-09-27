#pragma once
using namespace std;
#include "Object.h"
#include "Vector3.h"
#include <vector>
#include <string>

class NonComponentGameObject : public Object {
public:

	//オブジェクトの座標を取得します
	Vector3 GetPosition();
	//オブジェクトの座標を設定します
	void SetPosition(Vector3 newPos);

	//親との相対座標を取得します
	Vector3 GetLocalPosition();
	//親との相対座標を設定します
	void SetLocalPosition(Vector3 newPos);

	//現在の大きさを取得します
	Vector3 GetScale();
	//大きさを設定します
	void SetScale(Vector3 newScale);

	//現在の回転を取得します
	Vector3 GetRotation();
	//回転角度を設定します
	void SetRotation(Vector3 newRotation);

	//このオブジェクト自体の拡大率を取得します
	Vector3 GetLocalScale();
	//このオブジェクト自体の拡大率を設定します
	void SetLocalScale(Vector3 newScale);

	//現在の速度を取得します
	Vector3 GetVelocity();
	//速度を設定します
	void SetVelocity(Vector3 newVelocity);

	//このオブジェクトの名前を取得します
	string GetName();
	//このオブジェクトの名前を設定します
	void SetName(string newName);

	//このオブジェクトのタグを取得します
	string GetTag();
	//このオブジェクトにタグを設定します
	void SetTag(string newTag);
	//タグとtargetが一致しているかを返します
	bool CompareTag(string target);

	//親のオブジェクトを取得します
	NonComponentGameObject* GetParent();
	//親を設定します
	void SetParent(NonComponentGameObject* parent);

	//index番目の子供オブジェクトを取得します
	NonComponentGameObject* GetChild(int index);
	//子供オブジェクトの数を取得します
	int GetChildCount();
	//子供を追加します
	void AddChild(NonComponentGameObject* child);

	//オブジェクトを回転させます
	void Rotate(Vector3 angle);

	void Move(Vector3 range);

	NonComponentGameObject();
	~NonComponentGameObject();

protected:
	bool isActive;

	Vector3 position;
	Vector3 localPosition;
	Vector3 scale;
	Vector3 localScale;
	Vector3 rotation;
	Vector3 velocity;

	string name;
	string tag;

	NonComponentGameObject* parent;
	vector<NonComponentGameObject*> child{};

};

