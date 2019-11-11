#include "RunResult.h"
#include "Run.h"


RunResult::RunResult(string name) : Scene(name){
}


RunResult::~RunResult() {
}

void RunResult::Start() {
	Run* run;
	run = dynamic_cast<Run*>(SceneManager::GetInstance().GetNowScene());

	ObjectManager::GetInstance().Instantiate(background);
	ObjectManager::GetInstance().Instantiate(ranking);
}

void RunResult::Load() {
	//ランキング画面表示
	rankingSprite = new Sprite();
	rankingSprite->SetScale(new Vector2(SCREEN_WIDTH*0.8f, SCREEN_HEIGHT*0.8f));
	ranking = new GameObject();
	ranking->SetPosition(new Vector3(SCREEN_CEMTER_X, SCREEN_CEMTER_Y, 0));
	ranking->AddComponent(rankingSprite);

	//ランキング背景表示
	backgroundSprite = new Sprite();
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	background = new GameObject();
	background->SetPosition(new Vector3(SCREEN_CEMTER_X, SCREEN_CEMTER_Y, 0));
	backgroundSprite->SetColor(new Color(0, 0, 0, 0));
	background->AddComponent(backgroundSprite);
}

void RunResult::Update() {
}
