#include "MegatonPunchResult.h"
#include "VariableManager.h"
#include <algorithm>

MegatonPunchResult::MegatonPunchResult(string name) : Scene(name) {

}

MegatonPunchResult::~MegatonPunchResult() {
}

void MegatonPunchResult::Start() {
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
}

void MegatonPunchResult::UnLoad() {
}
