#include "ArcheryResult.h"

ArcheryResult::ArcheryResult(string name) : Scene(name) {
}

ArcheryResult::~ArcheryResult() {
}

void ArcheryResult::Start() {

	ObjectManager::GetInstance().Instantiate(rankingBackground);
	ObjectManager::GetInstance().Instantiate(ranking);
}

void ArcheryResult::Load() {

	//ランキング画面表示
	rankingSprite = new Sprite();
	rankingSprite->SetScale(new Vector2(SCREEN_WIDTH*0.8f, SCREEN_HEIGHT*0.8f));
	ranking = new GameObject();
	rankingSprite->SetColor(new Color(255, 0, 0, 255));
	ranking->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	ranking->AddComponent(rankingSprite);

	//ランキング背景表示
	rankingBackgroundSprite = new Sprite();
	rankingBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	rankingBackground = new GameObject();
	rankingBackground->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	rankingBackgroundSprite->SetColor(new Color(0, 0, 0, 255));
	rankingBackground->AddComponent(rankingBackgroundSprite);

}

void ArcheryResult::UnLoad() {
	ObjectManager::GetInstance().Destroy(ranking);
	ObjectManager::GetInstance().Destroy(rankingBackground);
}
