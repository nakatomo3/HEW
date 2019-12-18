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
		//sortTimes[i].first	-> i番目のプレイヤーのタイム
		//sortTimes[i].second	-> i番目のプレイヤーのプレイヤー番号
	}
}

void MegatonPunchResult::Load() {
	playerCount = VariableManager::GetInstance().GetInt("playerCount");
}

void MegatonPunchResult::UnLoad() {
}
