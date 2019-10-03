#pragma once
using namespace std;
#include "GameObject.h"
#include "Singleton.h"
#include<vector>
class GameObject;
class ObjectManager : public Singleton<ObjectManager> {
public:
	friend class Singleton<ObjectManager>;

	//�I�u�W�F�N�g�}�l�[�W���[�ɓo�^����B�Ǘ��ΏۂłȂ��Ǝ����I��Start��Update���Ă΂�Ȃ��B
	void Instantiate(GameObject* instance);

	//�Ǘ��Ώۂ���O��delete����B
	void Destroy(GameObject* instance);

	//instance���Ǘ��Ώۂɓ����Ă��邩�ǂ����̊m�F
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