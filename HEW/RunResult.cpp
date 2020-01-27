#include "RunResult.h"
#include "Run.h"
#include "PlayerRun.h"
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

	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Instantiate(rankingTime[i]);
		ObjectManager::GetInstance().Instantiate(rankingPoint[i]);
	}


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
		point.emplace_back(0);
	}

	//順位順の点数を加算する処理
	//高い順に表示するのが未完成
	int intPoint;
	for (int i = 0; i < playerCount; i++) {
		if (sortTimes[0].second==i) {
			point[i] = 100003;
			intPoint = floor(point[sortTimes[0].second]);
			rankingPointText[sortTimes[0].second]->text = to_string(intPoint);
		}
		if (sortTimes[1].second == i) {
			point[i] = 100002;
			intPoint = floor(point[sortTimes[1].second]);
			rankingPointText[sortTimes[1].second]->text = to_string(intPoint);
		}
		if (sortTimes[2].second == i) {
			point[i] = 100001;
			intPoint = floor(point[sortTimes[2].second]);
			rankingPointText[sortTimes[2].second]->text = to_string(intPoint);
		}
		if (sortTimes[3].second == i) {
			point[i] = 100000;
			intPoint = floor(point[sortTimes[3].second]);
			rankingPointText[sortTimes[3].second]->text = to_string(intPoint);
		}
		VariableManager::GetInstance().SetInt("point" + to_string(i), point[i]);
		LogWriter::GetInstance().Log("point:%d\nplayerNumber:%d", point[i],i);
	}

	for (int i = 0; i < playerCount; i++) {
		//順位順にタイムを小数点第三位まで表示
		int intTimer = floor(sortTimes[i].first);
		int dicimalTimer = floor(sortTimes[i].first * 1000 - intTimer * 1000);
		rankingTimeText[i]->text = to_string(intTimer) + "." + to_string(dicimalTimer);
	}
			

	if (isRanking == false) {

		//ここにランキング表示の処理を書く
		if (playerCount >= 1) {
			rankingTime[0]->SetActive(true);
			rankingTimeText[0]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingTimeText[0]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.34f, 0));

			rankingPoint[0]->SetActive(true);
			rankingPointText[sortTimes[0].second]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingPointText[sortTimes[0].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.7f, SCREEN_HEIGHT*0.34f, 0));
		}

		if (playerCount >= 2) {
			rankingTime[1]->SetActive(true);
			rankingTimeText[1]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingTimeText[1]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.48f, 0));

			rankingPoint[1]->SetActive(true);
			rankingPointText[sortTimes[1].second]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingPointText[sortTimes[1].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.7f, SCREEN_HEIGHT*0.48f, 0));
		}

		if (playerCount >= 3) {
			rankingTime[2]->SetActive(true);
			rankingTimeText[2]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingTimeText[2]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.62f, 0));

			rankingPoint[2]->SetActive(true);
			rankingPointText[sortTimes[2].second]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingPointText[sortTimes[2].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.7f, SCREEN_HEIGHT*0.62f, 0));
		}

		if (playerCount >= 4) {
			rankingTime[3]->SetActive(true);
			rankingTimeText[3]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingTimeText[3]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.76f, 0));

			rankingPoint[3]->SetActive(true);
			rankingPointText[sortTimes[3].second]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingPointText[sortTimes[3].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.7f, SCREEN_HEIGHT*0.76f, 0));
		}

		isRanking = true;

	}

	

	//-----------ソートここまで--------------

	
}

void RunResult::Load() {

	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	//ランキング画面表示
	rankingSprite = new Sprite();
	rankingSprite->SetScale(new Vector2(SCREEN_WIDTH*0.8f, SCREEN_HEIGHT*0.8f));
	ranking = new GameObject();
	rankingSprite->SetColor(new Color(255, 0, 0, 255));
	ranking->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	ranking->AddComponent(rankingSprite);

	//ランキング背景表示
	backgroundSprite = new Sprite();
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	background = new GameObject();
	background->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	backgroundSprite->SetColor(new Color(0, 0, 0, 255));
	background->AddComponent(backgroundSprite);

	
	for (int i = 0; i < playerCount; i++) {
		//順位表示
		rankingTimeText.emplace_back(new Text());
		rankingTime.emplace_back(new GameObject());
		rankingTime[i]->AddComponent(rankingTimeText[i]);
		rankingTime[i]->SetActive(false);

		//順位ポイント表示
		rankingPointText.emplace_back(new Text());
		rankingPoint.emplace_back(new GameObject());
		rankingPoint[i]->AddComponent(rankingPointText[i]);
		rankingPoint[i]->SetActive(false);
	}
	
}

void RunResult::UnLoad() {
	ObjectManager::GetInstance().Destroy(ranking);
	ObjectManager::GetInstance().Destroy(background);
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Destroy(rankingTime[i]);
	}
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Destroy(rankingPoint[i]);
	}
}

void RunResult::Update() {
	timer += Time::GetInstance().GetDeltaTime();

	if (timer > 5) {
		SceneManager::GetInstance().LoadScene("megatonPunchTitle");// megatonPunchTitleに遷移
	}
}
