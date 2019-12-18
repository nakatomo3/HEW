#include "SelectCharacter.h"
#include "VariableManager.h"
#include "Input.h"
#include "SceneManager.h"



void SelectCharacter::Start() {

	// �w�i
	ObjectManager::GetInstance().Instantiate(backgroundObject);

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
	backgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.01));// �w�i�̈ʒu
	backgroundSprite->SetColor(new Color(0, 0, 0, 255));// ���F�w�i

	// �v���C���[�w�i
	playerBackgroundObject = new GameObject();
	playerBackgroundSprite = new Sprite();
	playerBackgroundObject->AddComponent(playerBackgroundSprite);
	playerBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH*0.6, SCREEN_HEIGHT *0.54));// �w�i�̑傫��
	playerBackgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3.55, -0.01));// �w�i�̈ʒu
	playerBackgroundSprite->SetColor(new Color(255, 255, 255, 255));// ���F�w�i

	// �L�����w�i
	selectCharacterObject1 = new GameObject();
	selectCharacterSprite1 = new Sprite();
	selectCharacterObject1->AddComponent(selectCharacterSprite1);
	selectCharacterSprite1->SetScale(new Vector2(SCREEN_HEIGHT * 0.3, SCREEN_HEIGHT * 0.3));// �w�i�̑傫��       // �d�l����3��=0.3
	selectCharacterSprite1->SetPosition(new Vector3(SCREEN_WIDTH *0.2, SCREEN_HEIGHT / 1.4, -0.01));// �w�i�̈ʒu
	selectCharacterSprite1->SetColor(new Color(255, 255, 255, 255));// ���F�w�i

	selectCharacterObject2 = new GameObject();
	selectCharacterSprite2 = new Sprite();
	selectCharacterObject2->AddComponent(selectCharacterSprite2);
	selectCharacterSprite2->SetScale(new Vector2(SCREEN_HEIGHT * 0.3, SCREEN_HEIGHT * 0.3));// �w�i�̑傫��
	selectCharacterSprite2->SetPosition(new Vector3(SCREEN_WIDTH *0.4, SCREEN_HEIGHT / 1.4, -0.01));// �w�i�̈ʒu
	selectCharacterSprite2->SetColor(new Color(255, 255, 0, 255));// �ԐF�w�i

	selectCharacterObject3 = new GameObject();
	selectCharacterSprite3 = new Sprite();
	selectCharacterObject3->AddComponent(selectCharacterSprite3);
	selectCharacterSprite3->SetScale(new Vector2(SCREEN_HEIGHT * 0.3, SCREEN_HEIGHT *0.3));// �w�i�̑傫��
	selectCharacterSprite3->SetPosition(new Vector3(SCREEN_WIDTH *0.6, SCREEN_HEIGHT / 1.4, -0.01));// �w�i�̈ʒu
	selectCharacterSprite3->SetColor(new Color(255, 255, 255, 255));// ���F�w�i

	selectCharacterObject4 = new GameObject();
	selectCharacterSprite4 = new Sprite();
	selectCharacterObject4->AddComponent(selectCharacterSprite4);
	selectCharacterSprite4->SetScale(new Vector2(SCREEN_HEIGHT * 0.3, SCREEN_HEIGHT * 0.3));// �w�i�̑傫��
	selectCharacterSprite4->SetPosition(new Vector3(SCREEN_WIDTH *0.8, SCREEN_HEIGHT / 1.4, -0.01));// �w�i�̈ʒu
	selectCharacterSprite4->SetColor(new Color(255, 255, 0, 255));// �ԐF�w�i

	for (int i = 0; i < playerCount; i++) {
		cursorPositions.emplace_back(0);
	}

	for (int i = 0; i < playerCount; i++) {
		//�J�[�\��
		selectCursorObject = new GameObject();
		selectCursorSprite = new Sprite();
		selectCursorObject->AddComponent(selectCursorSprite);
		selectCursorSprite->SetScale(new Vector2(SCREEN_WIDTH *0.05, SCREEN_HEIGHT *0.08));// �J�[�\���̑傫��
		selectCursorSprite->SetColor(new Color(0, 0, 255, 255));// ���F

	}

}

void SelectCharacter::Update() {

	//�J�[�\����ϐ��Ɂ@�J�[�\���̈ʒu������W�v�Z�@�J�[�\���̈ʒu�̕ϐ���z��ɂ��Ă��� �͈͂�0�`3�܂�
	if (playerCount >= 1) {// �v���C���[�K1�l�̎�
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
		selectCursorSprite->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[0] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6, -0.01));
	}

	if (playerCount >= 2) {// �v���C���[��2�l�̎�
		if (Input::GetInstance().GetKeyDown(DIK_1)) {// 1���������Ƃ� ��
			if (cursorPositions[1] >= 1) {
				cursorPositions[1]--;
			}
		}

		if (Input::GetInstance().GetKeyDown(DIK_2)) {// 2���������Ƃ� �E
			if (cursorPositions[1] <= 2) {
				cursorPositions[1]++;
			}
		}
		selectCursorSprite->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[1] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6, -0.01));
	}

	if (playerCount >= 3) {// �v���C���[��3�l�̎�
		if (Input::GetInstance().GetKeyDown(DIK_1)) {// 1���������Ƃ� ��
			if (cursorPositions[2] >= 1) {
				cursorPositions[2]--;
			}
		}

		if (Input::GetInstance().GetKeyDown(DIK_2)) {// 2���������Ƃ� �E
			if (cursorPositions[2] <= 2) {
				cursorPositions[2]++;
			}
		}
		selectCursorSprite->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[2] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6, -0.01));
	}

	if (playerCount >= 4) {// �v���C���[��4�l�̎�
		if (Input::GetInstance().GetKeyDown(DIK_1)) {// 1���������Ƃ� ��
			if (cursorPositions[3] >= 1) {
				cursorPositions[3]--;
			}
		}

		if (Input::GetInstance().GetKeyDown(DIK_2)) {// 2���������Ƃ� �E
			if (cursorPositions[3] <= 2) {
				cursorPositions[3]++;
			}
		}
		selectCursorSprite->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[3] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6, -0.01));
	}

}

SelectCharacter::SelectCharacter(string name) : Scene(name) {

}


SelectCharacter::~SelectCharacter() {
}