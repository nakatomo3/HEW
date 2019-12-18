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
	}


	//-----------�\�[�g��������--------------

	// time, playerNumber�����[�Bsort���time��(�������)�ɕ���
	// time�������̎���playerNumber���ɕ���
	vector<pair<float, int>> sortTimes;
	for (int i = 0; i < playerCount; i++) {
		times.emplace_back(VariableManager::GetInstance().GetFloat("time"+to_string(i)));
		sortTimes.emplace_back(times[i], i);
	}
	sort(sortTimes.begin(), sortTimes.end());

	for (int i = 0; i < playerCount; i++) {
		//sortTimes[i].first	-> i�Ԗڂ̃v���C���[�̃^�C��
		//sortTimes[i].second	-> i�Ԗڂ̃v���C���[�̃v���C���[�ԍ�
		LogWriter::GetInstance().Log("sortTime:%f\nplayerNumber:%d",sortTimes[i].first, sortTimes[i].second);
		
	}

	//�����_��O�ʂ܂ŕ\��
	for (int i = 0; i < playerCount; i++) {
		int intTimer = floor(sortTimes[i].first);
		int dicimalTimer = floor(sortTimes[i].first * 1000 - intTimer * 1000);
		rankingTimeText[i]->text = to_string(intTimer) + "." + to_string(dicimalTimer);
	}

	if (isRanking == false) {

		//�����Ƀ����L���O�̏���������
		if (playerCount >= 1) {
			rankingTime[0]->SetActive(true);
			rankingTimeText[0]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingTimeText[0]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.34f, 0));
		}

		if (playerCount >= 2) {
			rankingTime[1]->SetActive(true);
			rankingTimeText[1]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingTimeText[1]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.48f, 0));
		}

		if (playerCount >= 3) {
			rankingTime[2]->SetActive(true);
			rankingTimeText[2]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingTimeText[2]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.62f, 0));
		}

		if (playerCount >= 4) {
			rankingTime[3]->SetActive(true);
			rankingTimeText[3]->SetSize(SCREEN_HEIGHT*0.1f);
			rankingTimeText[3]->SetPosition(new Vector3(SCREEN_WIDTH*0.5f, SCREEN_HEIGHT*0.76f, 0));
		}

		isRanking == true;

	}

	

	//-----------�\�[�g�����܂�--------------

	
}

void RunResult::Load() {

	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	//�����L���O��ʕ\��
	rankingSprite = new Sprite();
	rankingSprite->SetScale(new Vector2(SCREEN_WIDTH*0.8f, SCREEN_HEIGHT*0.8f));
	ranking = new GameObject();
	rankingSprite->SetColor(new Color(255, 0, 0, 255));
	ranking->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	ranking->AddComponent(rankingSprite);

	//�����L���O�w�i�\��
	backgroundSprite = new Sprite();
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	background = new GameObject();
	background->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	backgroundSprite->SetColor(new Color(0, 0, 0, 255));
	background->AddComponent(backgroundSprite);

	//���ʕ\��
	for (int i = 0; i < playerCount; i++) {
		rankingTimeText.emplace_back(new Text());
		rankingTime.emplace_back(new GameObject());
		rankingTime[i]->AddComponent(rankingTimeText[i]);
		rankingTime[i]->SetActive(false);
	}
	
}

void RunResult::UnLoad() {
	ObjectManager::GetInstance().Destroy(ranking);
	ObjectManager::GetInstance().Destroy(background);
}

void RunResult::Update() {
	timer += Time::GetInstance().GetDeltaTime();

	if (timer > 5) {
		SceneManager::GetInstance().LoadScene("megatonPunchTitle");// megatonPunchTitle�ɑJ��
	}
}
