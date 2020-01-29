#include "MegatonPunchResult.h"
#include "VariableManager.h"
#include "Time.h"
#include "SceneManager.h"
#include <algorithm>

MegatonPunchResult::MegatonPunchResult(string name) : Scene(name) {

}

MegatonPunchResult::~MegatonPunchResult() {
}

void MegatonPunchResult::Start() {
	
	//�C���X�^���X
	ObjectManager::GetInstance().Instantiate(rankingBackground);
	ObjectManager::GetInstance().Instantiate(ranking);

	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Instantiate(rankingScore[i]);
		ObjectManager::GetInstance().Instantiate(rankingPoint[i]);
	}

	//�O�̎��(100m��)�̏��ʓ_���̈����p������
	for (int i = 0; i < playerCount; i++) {
		point.emplace_back(VariableManager::GetInstance().GetInt("point" + to_string(i)));
		LogWriter::GetInstance().Log("point:%d\nplayerNumber:%d", point[i],i);
	}

	//�\�[�g�̏���
	vector<pair<int, int>> sortScores;
	for (int i = 0; i < playerCount; i++) {
		scores.emplace_back(VariableManager::GetInstance().GetInt("megatonScore" + to_string(i)));
		sortScores.emplace_back(scores[i], i);
	}
	sort(sortScores.begin(), sortScores.end());

	for (int i = playerCount - 1; i >= 0; i--) {
		//sortTimes[i].first	-> i�Ԗڂ̃v���C���[�̃^�C��
		//sortTimes[i].second	-> i�Ԗڂ̃v���C���[�̃v���C���[�ԍ�
		LogWriter::GetInstance().Log("sortTime:%d\nplayerNumber:%d", sortScores[i].first, sortScores[i].second);
		rankingScoreText[playerCount - 1 - i]->text = to_string(sortScores[i].first) + "km";
		point.emplace_back(0);
	}


	int intPoint;
	for (int i = 0; i < playerCount; i++) {
		if (sortScores[0].second == i) {
			point[i] += 3;
			intPoint = floor(point[sortScores[0].second]);
			rankingPointText[sortScores[0].second]->text = to_string(intPoint);
		}
		if (sortScores[1].second == i) {
			point[i] += 2;
			intPoint = floor(point[sortScores[1].second]);
			rankingPointText[sortScores[1].second]->text = to_string(intPoint);
		}
		if (sortScores[2].second == i) {
			point[i] += 1;
			intPoint = floor(point[sortScores[2].second]);
			rankingPointText[sortScores[2].second]->text = to_string(intPoint);
		}
		if (sortScores[3].second == i) {
			point[i] = point[i];
			intPoint = floor(point[sortScores[3].second]);
			rankingPointText[sortScores[3].second]->text = to_string(intPoint);
		}
		VariableManager::GetInstance().SetInt("point" + to_string(i), point[i]);
		LogWriter::GetInstance().Log("+point:%d\nplayerNumber:%d", point[i], i);
	}



	if (isRanking == false) {

		//�����L���O����
		if (playerCount >= 1) {
			rankingScore[0]->SetActive(true);
			rankingScoreText[0]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[0]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.34f, -0.01));

			rankingPoint[0]->SetActive(true);
			rankingPointText[sortScores[0].second]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingPointText[sortScores[0].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.7f, SCREEN_HEIGHT*0.34f, 0));
		}

		if (playerCount >= 2) {
			rankingScore[1]->SetActive(true);
			rankingScoreText[1]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[1]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.48f, -0.01));

			rankingPoint[1]->SetActive(true);
			rankingPointText[sortScores[1].second]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingPointText[sortScores[1].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.7f, SCREEN_HEIGHT*0.48f, 0));
		}

		if (playerCount >= 3) {
			rankingScore[2]->SetActive(true);
			rankingScoreText[2]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[2]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.62f, -0.01));

			rankingPoint[2]->SetActive(true);
			rankingPointText[sortScores[2].second]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingPointText[sortScores[2].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.7f, SCREEN_HEIGHT*0.62f, 0));
		}

		if (playerCount >= 4) {
			//�X�R�A�\��
			rankingScore[3]->SetActive(true);
			rankingScoreText[3]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingScoreText[3]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.76f, -0.01));
			//���ʃ|�C���g�\��
			rankingPoint[3]->SetActive(true);
			rankingPointText[sortScores[3].second]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingPointText[sortScores[3].second]->SetPosition(new Vector3(SCREEN_WIDTH*0.7f, SCREEN_HEIGHT*0.76f, 0));
		}

		isRanking = true;
	}
}

void MegatonPunchResult::Load() {
	playerCount = VariableManager::GetInstance().GetInt("playerCount");
	vector<pair<int, int>> sortScores;

	//�����L���O��ʕ\��
	rankingSprite = new Sprite();
	rankingSprite->SetScale(new Vector2(SCREEN_WIDTH*0.8f, SCREEN_HEIGHT*0.8f));
	ranking = new GameObject();
	rankingSprite->SetColor(new Color(255, 0, 0, 255));
	ranking->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));

	//�����L���O�w�i�\��
	rankingBackgroundSprite = new Sprite();
	rankingBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	rankingBackground = new GameObject();
	rankingBackground->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.01));
	rankingBackgroundSprite->SetColor(new Color(0, 0, 0, 255));

	//���ʕ\��
	for (int i = 0; i < playerCount; i++) {
		rankingScoreText.emplace_back(new Text());
		rankingScore.emplace_back(new GameObject());
		rankingScore[i]->AddComponent(rankingScoreText[i]);
		int intValue = floor(sortScores[i].first);

		//���ʃ|�C���g�\��
		rankingPointText.emplace_back(new Text());
		rankingPoint.emplace_back(new GameObject());
		rankingPoint[i]->AddComponent(rankingPointText[i]);
		rankingPoint[i]->SetActive(false);
	}


}

void MegatonPunchResult::UnLoad() {
	ObjectManager::GetInstance().Destroy(ranking);
	ObjectManager::GetInstance().Destroy(rankingBackground);
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Destroy(rankingScore[i]);
	}
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Destroy(rankingPoint[i]);
	}
}

void MegatonPunchResult::Update() {
	timer += Time::GetInstance().GetDeltaTime();

	if (timer > 5) {
		SceneManager::GetInstance().LoadScene("archeryTitle");// archeryTitle�ɑJ��
	}
}