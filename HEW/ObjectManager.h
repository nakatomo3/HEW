#pragma once
using namespace std;
#include "GameObject.h"
#include "Singleton.h"
#include<vector>
class GameObject;
class ObjectManager : public Singleton<ObjectManager> {
public:
	friend class Singleton<ObjectManager>;

	//オブジェクトマネージャーに登録する。管理対象でないと自動的にStartもUpdateも呼ばれない。
	void Instantiate(GameObject* instance);

	//管理対象から外しdeleteする。
	void Destroy(GameObject* instance);

	//instanceが管理対象に入っているかどうかの確認
	bool CheckInstance(GameObject* instance);

	void Awake();
	void Start();
	void FirstUpdate();
	void Update();
	void LateUpdate();

	void Draw();
	void LateDraw();


private:

	ObjectManager();
	~ObjectManager() {
		
	}
	
	vector<GameObject*> objects;
	
};