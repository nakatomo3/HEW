#include "SelectCharacter.h"
#include "Input.h"
#include "SceneManager.h"



void SelectCharacter::Start() {

	// îwåi
	ObjectManager::GetInstance().Instantiate(backgroundObject);
	// ÉvÉåÉCÉÑÅ[îwåi
	ObjectManager::GetInstance().Instantiate(playerBackgroundObject);
	// ÉLÉÉÉâîwåi
	ObjectManager::GetInstance().Instantiate(selectCharacterObject1);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject2);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject3);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject4);
}

void SelectCharacter::Load() {//îwåiÅ@è„Ç™ÉvÉåÉCÉÑÅ[îwåi(1ñá)Å@â∫Ç™ÉLÉÉÉâîwåi(4ñá)

	// îwåi
	backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// îwåiÇÃëÂÇ´Ç≥ // ïù,çÇÇ≥
	backgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.01));// îwåiÇÃà íu
	backgroundSprite->SetColor(new Color(0, 0, 0, 255));// çïêFîwåi

	// ÉvÉåÉCÉÑÅ[îwåi
	playerBackgroundObject = new GameObject();
	playerBackgroundSprite = new Sprite();
	playerBackgroundObject->AddComponent(playerBackgroundSprite);
	playerBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH*0.6, SCREEN_HEIGHT *0.54));// îwåiÇÃëÂÇ´Ç≥
	playerBackgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH/2, SCREEN_HEIGHT /3.55, -0.01));// îwåiÇÃà íu
	playerBackgroundSprite->SetColor(new Color(255, 255, 255, 255));// îíêFîwåi

	// ÉLÉÉÉâîwåi
	selectCharacterObject1 = new GameObject();
	selectCharacterSprite1 = new Sprite();
	selectCharacterObject1->AddComponent(selectCharacterSprite1);
	selectCharacterSprite1->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// îwåiÇÃëÂÇ´Ç≥
	selectCharacterSprite1->SetPosition(new Vector3(SCREEN_WIDTH *0.2, SCREEN_HEIGHT / 1.4, -0.01));// îwåiÇÃà íu
	selectCharacterSprite1->SetColor(new Color(255, 255, 255, 255));// îíêFîwåi

	selectCharacterObject2 = new GameObject();
	selectCharacterSprite2 = new Sprite();
	selectCharacterObject2->AddComponent(selectCharacterSprite2);
	selectCharacterSprite2->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// îwåiÇÃëÂÇ´Ç≥
	selectCharacterSprite2->SetPosition(new Vector3(SCREEN_WIDTH *0.4, SCREEN_HEIGHT / 1.4, -0.01));// îwåiÇÃà íu
	selectCharacterSprite2->SetColor(new Color(255, 255, 0, 255));// ê‘êFîwåi

	selectCharacterObject3 = new GameObject();
	selectCharacterSprite3 = new Sprite();
	selectCharacterObject3->AddComponent(selectCharacterSprite3);
	selectCharacterSprite3->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// îwåiÇÃëÂÇ´Ç≥
	selectCharacterSprite3->SetPosition(new Vector3(SCREEN_WIDTH *0.6, SCREEN_HEIGHT / 1.4, -0.01));// îwåiÇÃà íu
	selectCharacterSprite3->SetColor(new Color(255, 255, 255, 255));// îíêFîwåi

	selectCharacterObject4 = new GameObject();
	selectCharacterSprite4 = new Sprite();
	selectCharacterObject4->AddComponent(selectCharacterSprite4);
	selectCharacterSprite4->SetScale(new Vector2(SCREEN_WIDTH *0.15, SCREEN_HEIGHT *0.25));// îwåiÇÃëÂÇ´Ç≥
	selectCharacterSprite4->SetPosition(new Vector3(SCREEN_WIDTH *0.8, SCREEN_HEIGHT / 1.4, -0.01));// îwåiÇÃà íu
	selectCharacterSprite4->SetColor(new Color(255, 255, 0, 255));// ê‘êFîwåi
}

void SelectCharacter::Update() {

}

SelectCharacter::SelectCharacter(string name) : Scene(name) {

}


SelectCharacter::~SelectCharacter() {
}
