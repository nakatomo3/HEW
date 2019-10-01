#pragma once
using namespace std;
#include "Object.h"
#include "Vector3.h"
#include <vector>
#include <string>
#include "Component.h"

class GameObject : public Object {
public:

	//�I�u�W�F�N�g�̍��W���擾���܂�
	Vector3* GetPosition();
	//�I�u�W�F�N�g�̍��W��ݒ肵�܂�
	void SetPosition(Vector3* newPos);

	//�e�Ƃ̑��΍��W���擾���܂�
	Vector3* GetLocalPosition();
	//�e�Ƃ̑��΍��W��ݒ肵�܂�
	void SetLocalPosition(Vector3* newPos);

	//���݂̑傫�����擾���܂�
	Vector3* GetScale();
	//�傫����ݒ肵�܂�
	void SetScale(Vector3* newScale);

	//���݂̉�]���擾���܂�
	Vector3* GetRotation();
	//��]�p�x��ݒ肵�܂�
	void SetRotation(Vector3* newRotation);

	//���̃I�u�W�F�N�g���̂̊g�嗦���擾���܂�
	Vector3* GetLocalScale();
	//���̃I�u�W�F�N�g���̂̊g�嗦��ݒ肵�܂�
	void SetLocalScale(Vector3* newScale);

	//���݂̑��x���擾���܂�
	Vector3* GetVelocity();
	//���x��ݒ肵�܂�
	void SetVelocity(Vector3* newVelocity);

	//���̃I�u�W�F�N�g�̖��O���擾���܂�
	string GetName();
	//���̃I�u�W�F�N�g�̖��O��ݒ肵�܂�
	void SetName(string newName);

	//���̃I�u�W�F�N�g�̃^�O���擾���܂�
	string GetTag();
	//���̃I�u�W�F�N�g�Ƀ^�O��ݒ肵�܂�
	void SetTag(string newTag);
	//�^�O��target����v���Ă��邩��Ԃ��܂�
	bool CompareTag(string target);

	//�e�̃I�u�W�F�N�g���擾���܂�
	GameObject* GetParent();
	//�e��ݒ肵�܂�
	void SetParent(GameObject* parent);

	//index�Ԗڂ̎q���I�u�W�F�N�g���擾���܂�
	GameObject* GetChild(int index);
	//�q���I�u�W�F�N�g�̐����擾���܂�
	int GetChildCount();
	//�q����ǉ����܂�
	void AddChild(GameObject* child);

	//�I�u�W�F�N�g����]�����܂�
	void Rotate(Vector3 angle);

	void Move(Vector3 range);

	template<typename T>
	Component* GetComponent(T* t) {
		//��������Component�^�Ȃ̂����`�F�b�N����
		Component* cast_t = dynamic_cast<Component*>(t);
		//�����̓R���|�[�l���g�ł���
		if (cast_t != NULL) {
			for (unsigned int i = 0; i < components.size(); i++) {
				Component* checkComponent = dynamic_cast<T*>(components[i]);
				if (checkComponent != NULL) {
					//����Ɍ�������
					return components[i];
				}
			}
			//�����̓R���|�[�l���g��������������Ȃ�����
			return nullptr;
		} else {
			//�������R���|�[�l���g����Ȃ�����
			return nullptr;
		}
	}

	//[�񐄏�]�@�R���|�[�l���g���擾���܂��Bnum=�ォ�琔�����R���|�[�l���g�̐��B
	Component* GetComponent(unsigned int num);

	//�R���|�[�l���g���ǂꂾ���A�^�b�`����Ă��邩���J�E���g���܂��B
	unsigned int GetComponentCount();

	void AddComponent(Component* component);

	template<typename T>
	void RemoveComponent(T* t) {
		Component* cast_t = dynamic_cast<Component*>(t);
		if (cast_t != NULL) {
			for (unsigned int i = 0; i < components.size(); i++) {
				Component* checkComponent = dynamic_cast<T*>(components[i]);
				if (checkComponent != NULL) {
					//����Ɍ�������
					components.erase(components.begin() + i);
					return;
				}
			}
			//�����̓R���|�[�l���g��������������Ȃ�����
			return;
		} else {
			//�������R���|�[�l���g����Ȃ�����
			return;
		}

	}

	GameObject();
	~GameObject();

protected:
	bool isActive;

	Vector3* position;
	Vector3* localPosition;
	Vector3* scale;
	Vector3* localScale;
	Vector3* rotation;
	Vector3* velocity;

	string name;
	string tag;

	GameObject* parent;
	vector<GameObject*> child{};

	vector<Component*> components;
};

