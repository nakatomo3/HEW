#include "ArcheryResult.h"
#include "SceneManager.h"
#include "VariableManager.h"
#include "Archery.h"
#include "Time.h"
#include <algorithm>

ArcheryResult::ArcheryResult(string name) : Scene(name) {
}

ArcheryResult::~ArcheryResult() {
}

void ArcheryResult::Start() {

	ObjectManager::GetInstance().Instantiate(rankingBackground);
	ObjectManager::GetInstance().Instantiate(ranking);
	
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Instantiate(rankingScore[i]);
		ObjectManager::GetInstance().Instantiate(rankingPoint[i]);
		ObjectManager::GetInstance().Instantiate(medal[i]);
		ObjectManager::GetInstance().Instantiate(rankingPlayer[i]);
	}

	//前の種目(瓦割)の順位点数の引き継ぎ処理
	for (int i = 0; i < playerCount; i++) {
		point.emplace_back(VariableManager::GetInstance().GetInt("point" + to_string(i)));
		LogWriter::GetInstance().Log("point:%d\nplayerNumber:%d", point[i], i);
	}

	vector<pair<int, int>> sortScores;
	for (int i = 0; i < playerCount; i++) {
		scores.emplace_back(VariableManager::GetInstance().GetInt("archeryScore" + to_string(i)));
		sortScores.emplace_back(scores[i], i);
	}
	sort(sortScores.begin(), sortScores.end());


	/*for (int i = playerCount - 1; i >= 0; i--) {
		//sortTimes[i].first	-> i番目のプレイヤーのタイム
		//sortTimes[i].second	-> i番目のプレイヤーのプレイヤー番号
		LogWriter::GetInstance().Log("sortArchery:%d\nplayerNumber:%d", sortScores[i].first, sortScores[i].second);
		rankingScoreText[playerCount - 1 - i]->text = to_string(sortScores[i].first) + "点";
	}*/

	//順位ポイント系の処理少し調整
	for (int i = 0; i < playerCount; i++) {
		//sortTimes[i].first	-> i番目のプレイヤーのタイム
		//sortTimes[i].second	-> i番目のプレイヤーのプレイヤー番号
		LogWriter::GetInstance().Log("sortArchery:%d\nplayerNumber:%d", sortScores[i].first, sortScores[i].second);
		rankingScoreText[playerCount - 1 - i]->text = to_string(sortScores[i].first) + "点";
		point.emplace_back(0);
	}

	int intPoint;
	for (int i = 0; i <= playerCount; i++) {
		if (sortScores[playerCount - 1].second == i) {
			point[i] += 3;
			intPoint = floor(point[sortScores[playerCount - 1].second]);
			rankingPointText[sortScores[playerCount - 1].second]->text = to_string(intPoint);
		}
		if (sortScores[playerCount - 2].second == i && playerCount >= 2) {
			point[i] += 2;
			intPoint = floor(point[sortScores[playerCount - 2].second]);
			rankingPointText[sortScores[playerCount - 2].second]->text = to_string(intPoint);
		}
		if (sortScores[playerCount - 3].second == i && playerCount >= 3) {
			point[i] += 1;
			intPoint = floor(point[sortScores[playerCount - 3].second]);
			rankingPointText[sortScores[playerCount - 3].second]->text = to_string(intPoint);
		}
		if (sortScores[playerCount - 4].second == i && playerCount == 4) {
			point[i] = point[i];
			intPoint = floor(point[sortScores[playerCount - 4].second]);
			rankingPointText[sortScores[playerCount - 4].second]->text = to_string(intPoint);
		}
		VariableManager::GetInstance().SetInt("point" + to_string(i), point[i]);
		LogWriter::GetInstance().Log("+point:%d\nplayerNumber:%d", point[i], i);
	}

	if (isRanking == false) {

		//ランキング処理
		if (playerCount >= 1) {
			rankingScore[0]->SetActive(true);
			rankingScoreText[0]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[0]->SetPosition(new Vector3(SCREEN_WIDTH*0.43f, SCREEN_HEIGHT*0.36f, 0));

			medal[0]->SetActive(true);
			medal[0]->SetPosition(new Vector3(SCREEN_WIDTH*0.064f, SCREEN_HEIGHT*0.412f, 0));

			rankingPlayer[sortScores[playerCount-1].second]->SetActive(true);
			rankingPlayer[sortScores[playerCount-1].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.236f, SCREEN_HEIGHT*0.412f, -0.02f));
		}

		if (playerCount >= 2) {
			rankingScore[1]->SetActive(true);
			rankingScoreText[1]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[1]->SetPosition(new Vector3(SCREEN_WIDTH*0.43f, SCREEN_HEIGHT*0.5f, 0));

			medal[1]->SetActive(true);
			medal[1]->SetPosition(new Vector3(SCREEN_WIDTH*0.064f, SCREEN_HEIGHT*0.552f, 0));

			rankingPlayer[sortScores[playerCount-2].second]->SetActive(true);
			rankingPlayer[sortScores[playerCount-2].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.236f, SCREEN_HEIGHT*0.552f, -0.02f));
		}

		if (playerCount >= 3) {
			rankingScore[2]->SetActive(true);
			rankingScoreText[2]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[2]->SetPosition(new Vector3(SCREEN_WIDTH*0.43f, SCREEN_HEIGHT*0.64f, 0));

			medal[2]->SetActive(true);
			medal[2]->SetPosition(new Vector3(SCREEN_WIDTH*0.064f, SCREEN_HEIGHT*0.692f, 0));

			rankingPlayer[sortScores[playerCount-3].second]->SetActive(true);
			rankingPlayer[sortScores[playerCount-3].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.236f, SCREEN_HEIGHT*0.692f, -0.02f));
		}

		if (playerCount >= 4) {
			LogWriter::GetInstance().Log("やあ\n");
			rankingScore[3]->SetActive(true);
			rankingScoreText[3]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[3]->SetPosition(new Vector3(SCREEN_WIDTH*0.43f, SCREEN_HEIGHT*0.78f, -0.02));

			medal[3]->SetActive(true);
			medal[3]->SetPosition(new Vector3(SCREEN_WIDTH*0.064f, SCREEN_HEIGHT*0.833f, 0));

			rankingPlayer[sortScores[playerCount-4].second]->SetActive(true);
			rankingPlayer[sortScores[playerCount-4].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.236f, SCREEN_HEIGHT*0.833f, -0.02f));
		}

		isRanking = true;
	}
}

void ArcheryResult::Load() {

	playerCount = VariableManager::GetInstance().GetInt("playerCount");
	vector<pair<int, int>> sortScores;

	//ランキング画面表示
	ranking = new GameObject();
	rankingTexture = new Texture("assets/textures/All/UI/ranking.png");
	rankingSprite = new Sprite(rankingTexture);
	rankingSprite->SetScale(new Vector2(SCREEN_WIDTH*1.1f, SCREEN_HEIGHT*1.1f));
	rankingSprite->SetColor(new Color(255, 255, 255, 255));
	ranking->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	ranking->AddComponent(rankingSprite);

	//ランキング背景表示
	rankingBackgroundSprite = new Sprite();
	rankingBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	rankingBackground = new GameObject();
	rankingBackground->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.01f));
	rankingBackgroundSprite->SetColor(new Color(0, 0, 0, 255));
	rankingBackground->AddComponent(rankingBackgroundSprite);

	if (playerCount >= 1) {
		rankingPlayerTexture.emplace_back(new Texture("assets/textures/All/UI/1P.png"));
	}
	if (playerCount >= 2) {
		rankingPlayerTexture.emplace_back(new Texture("assets/textures/All/UI/2P.png"));
	}
	if (playerCount >= 3) {
		rankingPlayerTexture.emplace_back(new Texture("assets/textures/All/UI/3P.png"));
	}
	if (playerCount >= 4) {
		rankingPlayerTexture.emplace_back(new Texture("assets/textures/All/UI/4P.png"));
	}

	if (playerCount >= 1) {
		medalTexture.emplace_back(new Texture("assets/textures/All/UI/medal_1st.png"));
	}
	if (playerCount >= 2) {
		medalTexture.emplace_back(new Texture("assets/textures/All/UI/medal_2nd.png"));
	}
	if (playerCount >= 3) {
		medalTexture.emplace_back(new Texture("assets/textures/All/UI/medal_3rd.png"));
	}
	if (playerCount >= 4) {
		medalTexture.emplace_back(new Texture("assets/textures/All/UI/medal_4th.png"));
	}

	//順位表示
	for (int i = 0; i < playerCount; i++) {
		rankingScoreText.emplace_back(new Text());
		rankingScore.emplace_back(new GameObject());
		rankingScore[i]->AddComponent(rankingScoreText[i]);
		int intValue = floor(sortScores[i].first);

		//順位ポイント表示
		rankingPointText.emplace_back(new Text());
		rankingPoint.emplace_back(new GameObject());
		rankingPoint[i]->AddComponent(rankingPointText[i]);
		rankingPoint[i]->SetActive(false);

		//プレイヤー順位表示
		rankingPlayer.emplace_back(new GameObject());
		rankingPlayerSprite.emplace_back(new Sprite(rankingPlayerTexture[i]));
		rankingPlayerSprite[i]->SetScale(new Vector2(SD_HEIGHT*1.4f, SD_HEIGHT*1.4f));
		rankingPlayerSprite[i]->SetColor(new Color(255, 255, 255, 255));
		rankingPlayer[i]->AddComponent(rankingPlayerSprite[i]);
		rankingPlayer[i]->SetActive(false);

		//メダル表示
		medal.emplace_back(new GameObject());
		medalSprite.emplace_back(new Sprite(medalTexture[i]));
		medalSprite[i]->SetScale(new Vector2(SD_HEIGHT*1.4f, SD_HEIGHT*1.4f));
		medalSprite[i]->SetColor(new Color(255, 255, 255, 255));
		medal[i]->AddComponent(medalSprite[i]);
		medal[i]->SetActive(false);
	}
}

void ArcheryResult::Update() {

	timer += Time::GetInstance().GetDeltaTime();

	if (timer >= 5) {
		SceneManager::GetInstance().LoadScene("totalResult");
	}
	

}

void ArcheryResult::UnLoad() {
	ObjectManager::GetInstance().Destroy(ranking);
	ObjectManager::GetInstance().Destroy(rankingBackground);
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Destroy(rankingScore[i]);
		ObjectManager::GetInstance().Destroy(rankingPoint[i]);
		ObjectManager::GetInstance().Destroy(medal[i]);
		ObjectManager::GetInstance().Destroy(rankingPlayer[i]);
	}
}
