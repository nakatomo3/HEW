#include "SelectPlayerCount.h"
#include "SelectPlayerCountCursor.h"

SelectPlayerCount::SelectPlayerCount(string name) : Scene(name) {

}

SelectPlayerCount::~SelectPlayerCount() {
}

void SelectPlayerCount::Load() {
	cursorObject = new GameObject();
	//cursorTexture = new Texture("");
	cursorSprite = new Sprite();
	cursorObject->AddComponent(cursorSprite);
	cursorSprite->SetScale(new Vector2(100, 100));
	cursorObject->AddComponent(new SelectPlayerCountCursor());

	playerCountObject = new GameObject();
	playerCountTextures.emplace_back(new Texture("assets/textures/System/SelectPlayerCount/2.png"));
	playerCountTextures.emplace_back(new Texture("assets/textures/System/SelectPlayerCount/3.png"));
	playerCountTextures.emplace_back(new Texture("assets/textures/System/SelectPlayerCount/4.png"));

	playerCountSprites.emplace_back(new Sprite(playerCountTextures[0]));
	playerCountSprites.emplace_back(new Sprite(playerCountTextures[1]));
	playerCountSprites.emplace_back(new Sprite(playerCountTextures[2]));

	playerCountSprites[0]->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_HEIGHT*0.2f, -0.01f));
	playerCountSprites[1]->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_HEIGHT*0.5f, -0.01f));
	playerCountSprites[2]->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_HEIGHT*0.8f, -0.01f));

	playerCountSprites[0]->SetScale(new Vector2(SCREEN_HEIGHT*0.6f, SCREEN_HEIGHT*0.3f));
	playerCountSprites[1]->SetScale(new Vector2(SCREEN_HEIGHT*0.6f, SCREEN_HEIGHT*0.3f));
	playerCountSprites[2]->SetScale(new Vector2(SCREEN_HEIGHT*0.6f, SCREEN_HEIGHT*0.3f));

	playerCountObject->AddComponent(playerCountSprites[0]);
	playerCountObject->AddComponent(playerCountSprites[1]);
	playerCountObject->AddComponent(playerCountSprites[2]);

}

void SelectPlayerCount::UnLoad() {
	ObjectManager::GetInstance().Destroy(cursorObject);
	ObjectManager::GetInstance().Destroy(playerCountObject);
}

void SelectPlayerCount::Start() {
	ObjectManager::GetInstance().Instantiate(cursorObject);
	ObjectManager::GetInstance().Instantiate(playerCountObject);
}

void SelectPlayerCount::Update() {
}
