#include "SelectCharacter.h"
#include "VariableManager.h"
#include "Input.h"
#include "SceneManager.h"



void SelectCharacter::Start() {

	// �w�i
	//ObjectManager::GetInstance().Instantiate(backgroundObject);

	// �v���C���[�w�i
	ObjectManager::GetInstance().Instantiate(playerBackgroundObject);

	// �L�����w�i
	ObjectManager::GetInstance().Instantiate(selectCharacterObject1);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject2);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject3);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject4);

	//�J�[�\��
	ObjectManager::GetInstance().Instantiate(selectCursorObject);

	for (int i = 0; i < playerCount; i++) {
		isReady.emplace_back(false);
	}

}


void SelectCharacter::Load() {//�w�i�@�オ�v���C���[�w�i(1��)�@�����L�����w�i(4��)

	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	// �w�i
	backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// �w�i�̑傫�� // ��,����
	backgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.01f));// �w�i�̈ʒu
	backgroundSprite->SetColor(new Color(0, 0, 0, 255));// ���F�w�i

	// �v���C���[�w�i
	playerBackgroundObject = new GameObject();
	playerBackgroundSprite = new Sprite();
	playerBackgroundObject->AddComponent(playerBackgroundSprite);
	playerBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH*0.6f, SCREEN_HEIGHT *0.54f));// �w�i�̑傫��
	playerBackgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3.55f, -0.01f));// �w�i�̈ʒu
	playerBackgroundSprite->SetColor(new Color(255, 255, 255, 255));// ���F�w�i

	// �L�����w�i
	selectCharacterObject1 = new GameObject();
	selectCharacterSprite1 = new Sprite();
	selectCharacterObject1->AddComponent(selectCharacterSprite1);
	selectCharacterSprite1->SetScale(new Vector2(SCREEN_HEIGHT * 0.3f, SCREEN_HEIGHT * 0.3f));// �w�i�̑傫��       // �d�l����3��=0.3
	selectCharacterSprite1->SetPosition(new Vector3(SCREEN_WIDTH *0.2f, SCREEN_HEIGHT / 1.4f, -0.01f));// �w�i�̈ʒu
	selectCharacterSprite1->SetColor(new Color(255, 255, 255, 255));// ���F�w�i

	selectCharacterObject2 = new GameObject();
	selectCharacterSprite2 = new Sprite();
	selectCharacterObject2->AddComponent(selectCharacterSprite2);
	selectCharacterSprite2->SetScale(new Vector2(SCREEN_HEIGHT * 0.3f, SCREEN_HEIGHT * 0.3f));// �w�i�̑傫��
	selectCharacterSprite2->SetPosition(new Vector3(SCREEN_WIDTH *0.4f, SCREEN_HEIGHT / 1.4f, -0.01f));// �w�i�̈ʒu
	selectCharacterSprite2->SetColor(new Color(255, 255, 0, 255));// �ԐF�w�i

	selectCharacterObject3 = new GameObject();
	selectCharacterSprite3 = new Sprite();
	selectCharacterObject3->AddComponent(selectCharacterSprite3);
	selectCharacterSprite3->SetScale(new Vector2(SCREEN_HEIGHT * 0.3f, SCREEN_HEIGHT *0.3f));// �w�i�̑傫��
	selectCharacterSprite3->SetPosition(new Vector3(SCREEN_WIDTH *0.6f, SCREEN_HEIGHT / 1.4f, -0.01f));// �w�i�̈ʒu
	selectCharacterSprite3->SetColor(new Color(255, 255, 255, 255));// ���F�w�i

	selectCharacterObject4 = new GameObject();
	selectCharacterSprite4 = new Sprite();
	selectCharacterObject4->AddComponent(selectCharacterSprite4);
	selectCharacterSprite4->SetScale(new Vector2(SCREEN_HEIGHT * 0.3f, SCREEN_HEIGHT * 0.3f));// �w�i�̑傫��
	selectCharacterSprite4->SetPosition(new Vector3(SCREEN_WIDTH *0.8f, SCREEN_HEIGHT / 1.4f, -0.01f));// �w�i�̈ʒu
	selectCharacterSprite4->SetColor(new Color(255, 255, 0, 255));// �ԐF�w�i

	for (int i = 0; i < playerCount; i++) {
		cursorPositions.emplace_back(0);
	}

	selectCursorObject = new GameObject();
	for (int i = 0; i < playerCount; i++) {
		//�J�[�\��
		selectCursorSprite.emplace_back(new Sprite());
		selectCursorObject->AddComponent(selectCursorSprite[i]);
		selectCursorSprite[i]->SetScale(new Vector2(SCREEN_WIDTH *0.05f, SCREEN_HEIGHT *0.08f));// �J�[�\���̑傫��
		selectCursorSprite[i]->SetColor(new Color(0, 0, 255, 255));// ���F

	}

	for (int i = 0; i < 4; i++) {
		isSelected.emplace_back(false);
	}

}

void SelectCharacter::Update() {

	//�J�[�\����ϐ��Ɂ@�J�[�\���̈ʒu������W�v�Z�@�J�[�\���̈ʒu�̕ϐ���z��ɂ��Ă��� �͈͂�0�`3�܂�
	if (playerCount >= 1) {// �v���C���[�K1�l�̎�
		if (isReady[0] == false) {
			if (Input::GetInstance().GetKeyDown(DIK_1)) {// 1���������Ƃ� ��
				if (cursorPositions[0] >= 1) {// 1�ȉ��ɂ��Ȃ�
					cursorPositions[0]--;
				}
			}

			if (Input::GetInstance().GetKeyDown(DIK_2)) {// 2���������Ƃ� �E
				if (cursorPositions[0] <= 2) {// 2�ȏ�ɂ��Ȃ�
					cursorPositions[0]++;
				}
			}
		} else {
			selectCursorSprite[0]->SetColor(new Color(0, 0, 128, 255));
		}
		selectCursorSprite[0]->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[0] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6, -0.02f));

		if (Input::GetInstance().GetKeyDown(DIK_A) && isSelected[cursorPositions[0]] == false) {
			isSelected[cursorPositions[0]] = true;
			isReady[0] = true;
		}
	}

	if (playerCount >= 2) {// �v���C���[��2�l�̎�
		if (isReady[1] == false) {
			if (Input::GetInstance().GetKeyDown(DIK_3)) {// 1���������Ƃ� ��
				if (cursorPositions[1] >= 1) {
					cursorPositions[1]--;
				}
			}

			if (Input::GetInstance().GetKeyDown(DIK_4)) {// 2���������Ƃ� �E
				if (cursorPositions[1] <= 2) {
					cursorPositions[1]++;
				}
			}
		} else {
			selectCursorSprite[1]->SetColor(new Color(0, 0, 128, 255));
		}
		selectCursorSprite[1]->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[1] + 1) + SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6, -0.02f));
	
		if (Input::GetInstance().GetKeyDown(DIK_S) && isSelected[cursorPositions[1]] == false) {
			isSelected[cursorPositions[1]] = true;
			isReady[1] = true;
		}
	}

	if (playerCount >= 3) {// �v���C���[��3�l�̎�
		if (isReady[2] == false) {
			if (Input::GetInstance().GetKeyDown(DIK_5)) {// 1���������Ƃ� ��
				if (cursorPositions[2] >= 1) {
					cursorPositions[2]--;
				}
			}

			if (Input::GetInstance().GetKeyDown(DIK_6)) {// 2���������Ƃ� �E
				if (cursorPositions[2] <= 2) {
					cursorPositions[2]++;
				}
			}
		} else {
			selectCursorSprite[2]->SetColor(new Color(0, 0, 128, 255));
		}
		selectCursorSprite[2]->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[2] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.25 , -0.02f));
	
		if (Input::GetInstance().GetKeyDown(DIK_D) && isSelected[cursorPositions[2]] == false) {
			isSelected[cursorPositions[2]] = true;
			isReady[2] = true;
		}
	}

	if (playerCount >= 4) {// �v���C���[��4�l�̎�
		if (isReady[3] == false) {
			if (Input::GetInstance().GetKeyDown(DIK_7)) {// 1���������Ƃ� ��
				if (cursorPositions[3] >= 1) {
					cursorPositions[3]--;
				}
			}

			if (Input::GetInstance().GetKeyDown(DIK_8)) {// 2���������Ƃ� �E
				if (cursorPositions[3] <= 2) {
					cursorPositions[3]++;
				}
			}
		} else {
			selectCursorSprite[3]->SetColor(new Color(0, 0, 128, 255));
		}
		selectCursorSprite[3]->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[3] + 1) + SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.25, -0.02f));

		if (Input::GetInstance().GetKeyDown(DIK_F) && isSelected[cursorPositions[3]] == false) {
			isSelected[cursorPositions[3]] = true;
			isReady[3] = true;
		}
	}



	bool isAllReady = true;
	for (int i = 0; i < playerCount; i++) {
		if (isReady[i] == false) {
			isAllReady = false;
		}
	}

	if (isAllReady == true) {

		if (Input::GetInstance().GetKey(DIK_SPACE) || Input::GetInstance().GetKey(DIK_RETURN)) {
			SceneManager::GetInstance().LoadScene("runTitle");
		}
	}
}

void SelectCharacter::UnLoad() {
	ObjectManager::GetInstance().Destroy(playerBackgroundObject);
	ObjectManager::GetInstance().Destroy(selectCharacterObject1);
	ObjectManager::GetInstance().Destroy(selectCharacterObject2);
	ObjectManager::GetInstance().Destroy(selectCharacterObject3);
	ObjectManager::GetInstance().Destroy(selectCharacterObject4);
	ObjectManager::GetInstance().Destroy(selectCursorObject);
}

SelectCharacter::SelectCharacter(string name) : Scene(name) {

}


SelectCharacter::~SelectCharacter() {
}