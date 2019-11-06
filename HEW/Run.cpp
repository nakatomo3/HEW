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
	
	ObjectManager::GetInstance().Instantiate(balloon);
}

void Run::Load() {
	for (int i = 0; i < playerCount; i++) {//�v���C���[�̃J�E���g(playerCount)�̐��ɂ���ăQ�[�W�̕\��
		gauges.emplace_back(new ChargeGaugeRun());
		gaugeSprites.emplace_back(new Sprite());
		gaugeObjects.emplace_back(new GameObject());
		gaugeObjects[i]->AddComponent(gauges[i]);
		gaugeObjects[i]->AddComponent(gaugeSprites[i]);
		gaugeSprites[i]->SetCriterion(DOWN);
		gauges[i]->SetSprite(gaugeSprites[i]);
		

		players.emplace_back(new PlayerRun());
		players[i]->SetplayerID(i);
		playerSprite.emplace_back(new Sprite());
		playerObjects.emplace_back(new GameObject());
		playerObjects[i]->AddComponent(players[i]);
		playerObjects[i]->AddComponent(playerSprite[i]);

		gauges[i]->SetPlayer(players[i]);

	}

	//���̃R�����g�̉��ɃQ�[�W�֘A�̏�����ǉ�

	float gaugeWidth = SCREEN_WIDTH / 30;	//�Q�[�W�̉��̑傫��
	float gaugeHeight = SCREEN_HEIGHT / 3;	//�Q�[�W�̏c�̑傫��

	float sideBuffer = SCREEN_WIDTH / 18;	//��ʂ̏㉺���E����̋���

	if (playerCount >= 1) {
		//���㉼�Q�[�W
		gaugeSprites[0]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//��,�c �̑傫��
		gaugeObjects[0]->SetPosition(new Vector3(sideBuffer, sideBuffer + gaugeHeight, 0));//x,y,z���W
		gaugeObjects[0]->AddComponent(gaugeSprites[0]);
		playerObjects[1]->SetName("1");
		playerObjects[2]->SetName("2");
	}

	if (playerCount >= 2) {
		//�E�㉼�Q�[�W
		gaugeSprites[1]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//��,�c �̑傫��
		gaugeObjects[1]->SetPosition(new Vector3(SCREEN_WIDTH - sideBuffer, sideBuffer + gaugeHeight, 0));//x,y,z���W
		gaugeObjects[1]->AddComponent(gaugeSprites[1]);
	}

	if (playerCount >= 3) {
		//�������Q�[�W
		gaugeSprites[2]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//��,�c �̑傫��
		gaugeObjects[2]->SetPosition(new Vector3(sideBuffer, SCREEN_HEIGHT - sideBuffer, 0));//x,y,z���W
		gaugeObjects[2]->AddComponent(gaugeSprites[2]);
	}

	if (playerCount >= 4) {
		//�E�����Q�[�W
		gaugeSprites[3]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//��,�c �̑傫��
		gaugeObjects[3]->SetPosition(new Vector3(SCREEN_WIDTH - sideBuffer, SCREEN_HEIGHT - sideBuffer, 0));//x,y,z���W
		gaugeObjects[3]->AddComponent(gaugeSprites[3]);
	}


	//���̃R�����g�̉��Ƀv���C���[�֘A�̏�����ǉ�
	if (playerCount >= 1) {
		//��Ԗڂ̃v���C���[
		playerObjects[0]->SetPosition(new Vector3(99, 155, 0));
		playerSprite[0]->SetScale(new Vector2(50, 50));
		players[0]->SetSprite(playerSprite[0]);
		players[0]->SetScene(this);
	}
	
	if (playerCount >= 2) {
		//��Ԗڂ̃v���C���[
		playerObjects[1]->SetPosition(new Vector3(925, 155, 0));
		playerSprite[1]->SetScale(new Vector2(50, 50));
		players[1]->SetSprite(playerSprite[1]);
		players[1]->SetScene(this);
	}

	if (playerCount >= 3) {
		//�O�Ԗڂ̃v���C���[
		playerObjects[2]->SetPosition(new Vector3(95,425, 0));
		playerSprite[2]->SetScale(new Vector2(50, 50));
		players[2]->SetSprite(playerSprite[2]);
		players[2]->SetScene(this);
	}

	if (playerCount >= 4) {
		//�l�Ԗڂ̃v���C���[
		playerObjects[3]->SetPosition(new Vector3(925, 425, 0));
		playerSprite[3]->SetScale(new Vector2(50, 50));
		players[3]->SetSprite(playerSprite[3]);
		players[3]->SetScene(this);
	}

	//�����o���̏���
	balloonSprite = new Sprite();
	balloonSprite->SetScale(new Vector2(0, 0)); //saisyohahihyouzi 
	balloon = new GameObject();
	balloon->SetPosition(new Vector3(500, 300, 0));
	balloon->AddComponent(balloonSprite);
	balloonRun = new BalloonRun();
	balloon->AddComponent(balloonRun);
	balloonRun->SetSprite(balloonSprite);
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

Sprite * Run::GetPlayerSprite(int playerID){
	return playerSprite[playerID];
}
