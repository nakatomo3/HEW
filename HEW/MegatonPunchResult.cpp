#include "MegatonPunchResult.h"
#include "VariableManager.h"
#include <algorithm>

MegatonPunchResult::MegatonPunchResult(string name) : Scene(name) {

}

MegatonPunchResult::~MegatonPunchResult() {
}

void MegatonPunchResult::Start() {
	
	//�C���X�^���X
	ObjectManager::GetInstance().Instantiate(rankingBackground);
	ObjectManager::GetInstance().Instantiate(ranking);

	vector<pair<int, int>> sortScores;
	for (int i = 0; i < playerCount; i++) {
		scores.emplace_back(VariableManager::GetInstance().GetFloat("megatonScore" + to_string(i)));
		sortScores.emplace_back(scores[i], i);
	}
	sort(sortScores.begin(), sortScores.end());

	for (int i = 0; i < playerCount; i++) {
		//sortTimes[i].first	-> i�Ԗڂ̃v���C���[�̃^�C��
		//sortTimes[i].second	-> i�Ԗڂ̃v���C���[�̃v���C���[�ԍ�
	}
}

void MegatonPunchResult::Load() {
	playerCount = VariableManager::GetInstance().GetInt("playerCount");

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

}

void MegatonPunchResult::UnLoad() {
	ObjectManager::GetInstance().Destroy(ranking);
	ObjectManager::GetInstance().Destroy(rankingBackground);
}
