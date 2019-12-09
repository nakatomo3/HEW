#include "SelectCharacter.h"
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
}

void SelectCharacter::Load() {//�w�i�@�オ�v���C���[�w�i(1��)�@�����L�����w�i(4��)

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
	playerBackgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH/2, SCREEN_HEIGHT /3.55, -0.01));// �w�i�̈ʒu
	playerBackgroundSprite->SetColor(new Color(255, 255, 255, 255));// ���F�w�i

	// �L�����w�i
	selectCharacterObject1 = new GameObject();
	selectCharacterSprite1 = new Sprite();
	selectCharacterObject1->AddComponent(selectCharacterSprite1);
	selectCharacterSprite1->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// �w�i�̑傫��
	selectCharacterSprite1->SetPosition(new Vector3(SCREEN_WIDTH *0.2, SCREEN_HEIGHT / 1.4, -0.01));// �w�i�̈ʒu
	selectCharacterSprite1->SetColor(new Color(255, 255, 255, 255));// ���F�w�i

	selectCharacterObject2 = new GameObject();
	selectCharacterSprite2 = new Sprite();
	selectCharacterObject2->AddComponent(selectCharacterSprite2);
	selectCharacterSprite2->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// �w�i�̑傫��
	selectCharacterSprite2->SetPosition(new Vector3(SCREEN_WIDTH *0.4, SCREEN_HEIGHT / 1.4, -0.01));// �w�i�̈ʒu
	selectCharacterSprite2->SetColor(new Color(255, 255, 0, 255));// �ԐF�w�i

	selectCharacterObject3 = new GameObject();
	selectCharacterSprite3 = new Sprite();
	selectCharacterObject3->AddComponent(selectCharacterSprite3);
	selectCharacterSprite3->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// �w�i�̑傫��
	selectCharacterSprite3->SetPosition(new Vector3(SCREEN_WIDTH *0.6, SCREEN_HEIGHT / 1.4, -0.01));// �w�i�̈ʒu
	selectCharacterSprite3->SetColor(new Color(255, 255, 255, 255));// ���F�w�i

	selectCharacterObject4 = new GameObject();
	selectCharacterSprite4 = new Sprite();
	selectCharacterObject4->AddComponent(selectCharacterSprite4);
	selectCharacterSprite4->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// �w�i�̑傫��
	selectCharacterSprite4->SetPosition(new Vector3(SCREEN_WIDTH *0.8, SCREEN_HEIGHT / 1.4, -0.01));// �w�i�̈ʒu
	selectCharacterSprite4->SetColor(new Color(255, 255, 0, 255));// �ԐF�w�i
}

void SelectCharacter::Update() {

}

SelectCharacter::SelectCharacter(string name) : Scene(name) {

}


SelectCharacter::~SelectCharacter() {
}
