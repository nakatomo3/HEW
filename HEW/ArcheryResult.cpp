#include "ArcheryResult.h"
#include "VariableManager.h"
#include "Archery.h"
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
	}

	vector<pair<int, int>> sortScores;
	for (int i = 0; i < playerCount; i++) {
		scores.emplace_back(VariableManager::GetInstance().GetInt("archeryScore" + to_string(i)));
		sortScores.emplace_back(scores[i], i);
	}
	sort(sortScores.begin(), sortScores.end());


	for (int i = playerCount - 1; i >= 0; i--) {
		//sortTimes[i].first	-> i�Ԗڂ̃v���C���[�̃^�C��
		//sortTimes[i].second	-> i�Ԗڂ̃v���C���[�̃v���C���[�ԍ�
		LogWriter::GetInstance().Log("sortTime:%d\nplayerNumber:%d", sortScores[i].first, sortScores[i].second);
		rankingScoreText[playerCount - 1 - i]->text = to_string(sortScores[i].first) + "�_";
	}

	if (isRanking == false) {

		//�����L���O����
		if (playerCount >= 1) {
			rankingScore[0]->SetActive(true);
			rankingScoreText[0]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[0]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.34f, -0.01));
		}

		if (playerCount >= 2) {
			rankingScore[1]->SetActive(true);
			rankingScoreText[1]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[1]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.48f, -0.01));
		}

		if (playerCount >= 3) {
			rankingScore[2]->SetActive(true);
			rankingScoreText[2]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[2]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.62f, -0.01));
		}

		if (playerCount >= 4) {
			rankingScore[3]->SetActive(true);
			rankingScoreText[3]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[3]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.76f, -0.01));
		}

		isRanking = true;
	}
}

void ArcheryResult::Load() {

	playerCount = VariableManager::GetInstance().GetInt("playerCount");
	vector<pair<int, int>> sortScores;

	//�����L���O��ʕ\��
	rankingSprite = new Sprite();
	rankingSprite->SetScale(new Vector2(SCREEN_WIDTH*0.8f, SCREEN_HEIGHT*0.8f));
	ranking = new GameObject();
	rankingSprite->SetColor(new Color(255, 0, 0, 255));
	ranking->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	ranking->AddComponent(rankingSprite);

	//�����L���O�w�i�\��
	rankingBackgroundSprite = new Sprite();
	rankingBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	rankingBackground = new GameObject();
	rankingBackground->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	rankingBackgroundSprite->SetColor(new Color(0, 0, 0, 255));
	rankingBackground->AddComponent(rankingBackgroundSprite);

	//���ʕ\��
	for (int i = 0; i < playerCount; i++) {
		rankingScoreText.emplace_back(new Text());
		rankingScore.emplace_back(new GameObject());
		rankingScore[i]->AddComponent(rankingScoreText[i]);
		int intValue = floor(sortScores[i].first);
	}
}

void ArcheryResult::UnLoad() {
	ObjectManager::GetInstance().Destroy(ranking);
	ObjectManager::GetInstance().Destroy(rankingBackground);
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Destroy(rankingScore[i]);
	}
}
