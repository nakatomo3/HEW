#include "RunResult.h"
#include "VariableManager.h"
#include "Time.h"
#include "SceneManager.h"
#include <algorithm>

RunResult::RunResult(string name) : Scene(name){
}


RunResult::~RunResult() {
}

void RunResult::Start() {

	ObjectManager::GetInstance().Instantiate(background);
	ObjectManager::GetInstance().Instantiate(ranking);

	int playerCount = VariableManager::GetInstance().GetInt("playerCount");

	//-----------ソートここから--------------

	// time, playerNumberを収納。sort後はtime順(小→大へ)に並ぶ
	// timeが同じの時はplayerNumber順に並ぶ
	vector<pair<float, int>> sortTimes;
	for (int i = 0; i < playerCount; i++) {
		times.emplace_back(VariableManager::GetInstance().GetFloat("time"+to_string(i)));
		sortTimes.emplace_back(times[i], i);
	}
	sort(sortTimes.begin(), sortTimes.end());

	for (int i = 0; i < playerCount; i++) {
		//sortTimes[i].first	-> i番目のプレイヤーのタイム
		//sortTimes[i].second	-> i番目のプレイヤーのプレイヤー番号
		LogWriter::GetInstance().Log("sortTime:%f\nplayerNumber:%d",sortTimes[i].first, sortTimes[i].second);

		//ここにランキングの処理を書く
	}

	//-----------ソートここまで--------------

	
}

void RunResult::Load() {
	//ランキング画面表示
	rankingSprite = new Sprite();
	rankingSprite->SetScale(new Vector2(SCREEN_WIDTH*0.8f, SCREEN_HEIGHT*0.8f));
	ranking = new GameObject();
	ranking->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	ranking->AddComponent(rankingSprite);

	//ランキング背景表示
	backgroundSprite = new Sprite();
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	background = new GameObject();
	background->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
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
		SceneManager::GetInstance().LoadScene("megatonPunchTitle");// megatonPunchTitleに遷移
	}
}
