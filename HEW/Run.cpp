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
	//LogWriter::GetInstance().Log("hoge");
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

	//���㉼�Q�[�W
	Sprite* gaugeSprites = new Sprite();
	gaugeSprites->SetScale(new Vector2(25, 200));//��,�c �̑傫��
	GameObject* gaugeObjects = new GameObject();
	gaugeObjects->SetPosition(new Vector3(50, 150, 0));//x,y,z���W
	gaugeObjects->AddComponent(gaugeSprites);
	ObjectManager::GetInstance().Instantiate(gaugeObjects);

	//�E�㉼�Q�[�W
	Sprite* gaugeSprites2 = new Sprite();
	gaugeSprites2->SetScale(new Vector2(25, 200));//��,�c �̑傫��
	GameObject* gaugeObjects2 = new GameObject();
	gaugeObjects2->SetPosition(new Vector3(550, 150, 0));//x,y,z���W
	gaugeObjects2->AddComponent(gaugeSprites2);
	ObjectManager::GetInstance().Instantiate(gaugeObjects2);

	//�������Q�[�W
	Sprite* gaugeSprites3 = new Sprite();
	gaugeSprites3->SetScale(new Vector2(25, 200));//��,�c �̑傫��
	GameObject* gaugeObjects3 = new GameObject();
	gaugeObjects3->SetPosition(new Vector3(50, 450, 0));//x,y,z���W
	gaugeObjects3->AddComponent(gaugeSprites3);
	ObjectManager::GetInstance().Instantiate(gaugeObjects3);

	//�E�����Q�[�W
	Sprite* gaugeSprites4 = new Sprite();
	gaugeSprites4->SetScale(new Vector2(25, 200));//��,�c �̑傫��
	GameObject* gaugeObjects4 = new GameObject();
	gaugeObjects4->SetPosition(new Vector3(550, 450, 0));//x,y,z���W
	gaugeObjects4->AddComponent(gaugeSprites4);
	ObjectManager::GetInstance().Instantiate(gaugeObjects4);


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
