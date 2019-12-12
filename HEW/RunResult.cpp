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

		//�����Ƀ����L���O�̏���������
	}

	//-----------�\�[�g�����܂�--------------

	
}

void RunResult::Load() {
	//�����L���O��ʕ\��
	rankingSprite = new Sprite();
	rankingSprite->SetScale(new Vector2(SCREEN_WIDTH*0.8f, SCREEN_HEIGHT*0.8f));
	ranking = new GameObject();
	ranking->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0));
	ranking->AddComponent(rankingSprite);

	//�����L���O�w�i�\��
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
		SceneManager::GetInstance().LoadScene("megatonPunchTitle");// megatonPunchTitle�ɑJ��
	}
}
