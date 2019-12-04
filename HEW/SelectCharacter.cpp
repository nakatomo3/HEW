#include "SelectCharacter.h"
#include "Input.h"
#include "SceneManager.h"



void SelectCharacter::Start() {

	// 背景
	ObjectManager::GetInstance().Instantiate(backgroundObject);
	// プレイヤー背景
	ObjectManager::GetInstance().Instantiate(playerBackgroundObject);
	// キャラ背景
	ObjectManager::GetInstance().Instantiate(selectCharacterObject1);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject2);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject3);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject4);
}

void SelectCharacter::Load() {//背景　上がプレイヤー背景(1枚)　下がキャラ背景(4枚)

	// 背景
	backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// 背景の大きさ // 幅,高さ
	backgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 背景の位置
	backgroundSprite->SetColor(new Color(0, 0, 0, 0));// 黒色背景

	// プレイヤー背景
	playerBackgroundObject = new GameObject();
	playerBackgroundSprite = new Sprite();
	playerBackgroundObject->AddComponent(playerBackgroundSprite);
	playerBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH*0.6, SCREEN_HEIGHT *0.54));// 背景の大きさ
	playerBackgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH/2, SCREEN_HEIGHT /3.55, 0));// 背景の位置
	playerBackgroundSprite->SetColor(new Color(255, 255, 255, 0));// 白色背景

	// キャラ背景
	selectCharacterObject1 = new GameObject();
	selectCharacterSprite1 = new Sprite();
	selectCharacterObject1->AddComponent(selectCharacterSprite1);
	selectCharacterSprite1->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// 背景の大きさ
	selectCharacterSprite1->SetPosition(new Vector3(SCREEN_WIDTH *0.2, SCREEN_HEIGHT / 1.4, 0));// 背景の位置
	selectCharacterSprite1->SetColor(new Color(255, 255, 255, 0));// 白色背景

	selectCharacterObject2 = new GameObject();
	selectCharacterSprite2 = new Sprite();
	selectCharacterObject2->AddComponent(selectCharacterSprite2);
	selectCharacterSprite2->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// 背景の大きさ
	selectCharacterSprite2->SetPosition(new Vector3(SCREEN_WIDTH *0.4, SCREEN_HEIGHT / 1.4, 0));// 背景の位置
	selectCharacterSprite2->SetColor(new Color(255, 255, 0, 0));// 赤色背景

	selectCharacterObject3 = new GameObject();
	selectCharacterSprite3 = new Sprite();
	selectCharacterObject3->AddComponent(selectCharacterSprite3);
	selectCharacterSprite3->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// 背景の大きさ
	selectCharacterSprite3->SetPosition(new Vector3(SCREEN_WIDTH *0.6, SCREEN_HEIGHT / 1.4, 0));// 背景の位置
	selectCharacterSprite3->SetColor(new Color(255, 255, 255, 0));// 白色背景

	selectCharacterObject4 = new GameObject();
	selectCharacterSprite4 = new Sprite();
	selectCharacterObject4->AddComponent(selectCharacterSprite4);
	selectCharacterSprite4->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// 背景の大きさ
	selectCharacterSprite4->SetPosition(new Vector3(SCREEN_WIDTH *0.8, SCREEN_HEIGHT / 1.4, 0));// 背景の位置
	selectCharacterSprite4->SetColor(new Color(255, 255, 0, 0));// 赤色背景
}

void SelectCharacter::Update() {

}

SelectCharacter::SelectCharacter(string name) : Scene(name) {

}


SelectCharacter::~SelectCharacter() {
}
