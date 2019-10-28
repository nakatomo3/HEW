#include "Run.h"



Run::Run(string name) : Scene(name){
}


Run::~Run() {
}

void Run::Start() {
	for (int i = 0; i < playerCount; i++) {
		ObjectManager::GetInstance().Instantiate(playerObjects[i]);
		ObjectManager::GetInstance().Instantiate(gaugeObjects[i]);
	}
}

void Run::Load() {
	for (int i = 0; i < playerCount; i++) {
		gauges.emplace_back(new ChargeGaugeRun());
		gaugeSprites.emplace_back(new Sprite());
		gaugeObjects.emplace_back(new GameObject());
		gaugeObjects[i]->AddComponent(gauges[i]);
		gaugeObjects[i]->AddComponent(gaugeSprites[i]);

		players.emplace_back(new PlayerRun());
		players[i]->SetplayerID(i);
		playerSprite.emplace_back(new Sprite());
		playerObjects.emplace_back(new GameObject());
		playerObjects[i]->AddComponent(players[i]);
		playerObjects[i]->AddComponent(playerSprite[i]);

	}

	//���̃R�����g�̉��ɃQ�[�W�֘A�̏�����ǉ�

	if (playerCount >= 1) {
		//���㉼�Q�[�W
		gaugeSprites[0]->SetScale(new Vector2(25, 200));//��,�c �̑傫��
		gaugeObjects[0]->SetPosition(new Vector3(50, 150, 0));//x,y,z���W
		gaugeObjects[0]->AddComponent(gaugeSprites[0]);
	}

	if (playerCount >= 2) {
		//�E�㉼�Q�[�W
		gaugeSprites[1]->SetScale(new Vector2(25, 200));//��,�c �̑傫��
		gaugeObjects[1]->SetPosition(new Vector3(550, 150, 0));//x,y,z���W
		gaugeObjects[1]->AddComponent(gaugeSprites[1]);
	}

	if (playerCount >= 3) {
		//�������Q�[�W
		gaugeSprites[2]->SetScale(new Vector2(25, 200));//��,�c �̑傫��
		gaugeObjects[2]->SetPosition(new Vector3(50, 450, 0));//x,y,z���W
		gaugeObjects[2]->AddComponent(gaugeSprites[2]);
	}

	if (playerCount >= 4) {
		//�E�����Q�[�W
		gaugeSprites[3]->SetScale(new Vector2(25, 200));//��,�c �̑傫��
		gaugeObjects[3]->SetPosition(new Vector3(550, 450, 0));//x,y,z���W
		gaugeObjects[3]->AddComponent(gaugeSprites[3]);
	}

	//���̃R�����g�̉��Ƀv���C���[�֘A�̏�����ǉ�

	

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

int Run::GetPlayerCount() {
	return playerCount;
}
