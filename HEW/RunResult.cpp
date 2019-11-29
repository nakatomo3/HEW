#include "RunResult.h"
#include "Run.h"


RunResult::RunResult(string name) : Scene(name){
}


RunResult::~RunResult() {
}

void RunResult::Start() {

	ObjectManager::GetInstance().Instantiate(background);
	ObjectManager::GetInstance().Instantiate(ranking);
}

void RunResult::Load() {
	//ƒ‰ƒ“ƒLƒ“ƒO‰æ–Ê•\Ž¦
	rankingSprite = new Sprite();
	rankingSprite->SetScale(new Vector2(SCREEN_WIDTH*0.8f, SCREEN_HEIGHT*0.8f));
	ranking = new GameObject();
	ranking->SetPosition(new Vector3(SCREEN_CEMTER_X, SCREEN_CEMTER_Y, 0));
	ranking->AddComponent(rankingSprite);

	//ƒ‰ƒ“ƒLƒ“ƒO”wŒi•\Ž¦
	backgroundSprite = new Sprite();
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	background = new GameObject();
	background->SetPosition(new Vector3(SCREEN_CEMTER_X, SCREEN_CEMTER_Y, 0));
	backgroundSprite->SetColor(new Color(0, 0, 0, 0));
	background->AddComponent(backgroundSprite);
}

void RunResult::UnLoad() {
	ObjectManager::GetInstance().Destroy(ranking);
	ObjectManager::GetInstance().Destroy(background);
}

void RunResult::Update() {
	timer += Time::GetInstance().GetDeltaTime();

	if (timer > 5) {
		SceneManager::GetInstance().LoadScene("megatonPunchTitle");// megatonPunchTitle‚É‘JˆÚ
	}
}
