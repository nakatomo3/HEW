#include "Run.h"



Run::Run(string name) : Scene(name){
}


Run::~Run() {
}

void Run::Start() {
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Instantiate(playerObjects[i]);
	}
}

void Run::Load() {
	for (int i = 0; i < playerCount; i++) {
		players[i] = new PlayerRun();
		players[i]->SetplayerID(i);

		gauge[i] = new ChargeGaugeRun();
		playerSprite[i] = new Sprite();

		playerObjects[i] = new GameObject();
	}
}

void Run::Update() {
	//����ȊO���������Ȃ��ł��������I
	timer += Time::GetInstance().GetDeltaTime();
}

float Run::GetTimer() {
	return timer;
}

void Run::ChangePlayerCount(unsigned int num) {
	if (num > 4) {
		LogWriter::GetInstance().LogError("�v���C���[�̐��͍ő�4�ł�");
		return;
	}
	playerCount = num;
}
