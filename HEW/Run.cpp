#include "Run.h"
#include "Input.h"

#include "Sprite.h"
#include "Texture.h"
#include "PlayerRun.h"


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
	Texture* normalGaugeTexture = new Texture("assets/textures/Run/UI/gauge.png");
	Texture* brokenGaugeTexture = new Texture("assets/textures/Run/UI/gauge2.png");
	for (int i = 0; i < playerCount; i++) {//�v���C���[�̃J�E���g(playerCount)�̐��ɂ���ăQ�[�W�̕\��
		ChargeGaugeRun* gauge = new ChargeGaugeRun();
		gauges.emplace_back(gauge);
		gaugeSprites.emplace_back(new Sprite());
		gaugeObjects.emplace_back(new GameObject());
		gaugeObjects[i]->AddComponent(gauges[i]);
		gaugeSprites[i]->SetCriterion(DOWN);
		gauges[i]->SetSprite(gaugeSprites[i]);
		Sprite* scaler = new Sprite(normalGaugeTexture);
		gauge->SetScalerSprite(scaler);
		gaugeObjects[i]->AddComponent(gaugeSprites[i]);
		gaugeObjects[i]->AddComponent(scaler);
		scaler->SetScale(new Vector2(SCREEN_WIDTH / 30, SCREEN_HEIGHT / 3 * 1.0f));
		scaler->SetCriterion(DOWN);

		PlayerRun* player = new PlayerRun();
		players.emplace_back(player);
		players[i]->SetplayerID(i);
		playerSprite.emplace_back(new Sprite());
		playerObjects.emplace_back(new GameObject());
		playerObjects[i]->AddComponent(players[i]);
		playerObjects[i]->AddComponent(playerSprite[i]);

		LogWriter::GetInstance().Log("%d", player);
		gauge->SetPlayer(player);
		gauge->SetBrokenTexture(brokenGaugeTexture);
	}

	//���̃R�����g�̉��ɃQ�[�W�֘A�̏�����ǉ�
	float sdWidth = SCREEN_WIDTH / 10;
	float sdHeight = SCREEN_HEIGHT / 10;

	float gaugeWidth = SCREEN_WIDTH / 30;	//�Q�[�W�̉��̑傫��
	float gaugeHeight = SCREEN_HEIGHT / 3;	//�Q�[�W�̏c�̑傫��

	float playerWidth = gaugeHeight / 5;
	float playerHeight = gaugeHeight / 5 * 4;

	float sideBuffer = SCREEN_WIDTH / 18;	//��ʂ̏㉺���E����̋���


	if (playerCount >= 1) {
		//���㉼�Q�[�W
		gaugeSprites[0]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//��,�c �̑傫��
		gaugeObjects[0]->SetPosition(new Vector3(sideBuffer, sideBuffer + gaugeHeight, 0));//x,y,z���W
		gaugeSprites[0]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}

	if (playerCount >= 2) {
		//�E�㉼�Q�[�W
		gaugeSprites[1]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//��,�c �̑傫��
		gaugeObjects[1]->SetPosition(new Vector3(SCREEN_WIDTH - sideBuffer, sideBuffer + gaugeHeight - 0.0f, 0));//x,y,z���W
		gaugeSprites[1]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}

	if (playerCount >= 3) {
		//�������Q�[�W
		gaugeSprites[2]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//��,�c �̑傫��
		gaugeObjects[2]->SetPosition(new Vector3(sideBuffer, SCREEN_HEIGHT - sideBuffer, 0));//x,y,z���W
		gaugeSprites[2]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}

	if (playerCount >= 4) {
		//�E�����Q�[�W
		gaugeSprites[3]->SetScale(new Vector2(gaugeWidth, gaugeHeight));//��,�c �̑傫��
		gaugeObjects[3]->SetPosition(new Vector3(SCREEN_WIDTH - sideBuffer, SCREEN_HEIGHT - sideBuffer, 0));//x,y,z���W
		gaugeSprites[3]->SetPosition(new Vector3(0, SCREEN_HEIGHT * -0.007f, 0));
	}


	//���̃R�����g�̉��Ƀv���C���[�֘A�̏�����ǉ�
	if (playerCount >= 1) {
		//��Ԗڂ̃v���C���[
		playerSprite[0]->SetScale(new Vector2(50, 50));
		playerObjects[0]->SetPosition(new Vector3(99, 155, 0));
		players[0]->SetSprite(playerSprite[0]);
		players[0]->SetScene(this);
	}
	
	if (playerCount >= 2) {
		//��Ԗڂ̃v���C���[
		playerSprite[1]->SetScale(new Vector2(50, 50));
		playerObjects[1]->SetPosition(new Vector3(925, 155, 0));
		players[1]->SetSprite(playerSprite[1]);
		players[1]->SetScene(this);
	}

	if (playerCount >= 3) {
		//�O�Ԗڂ̃v���C���[
		playerSprite[2]->SetScale(new Vector2(50, 50));
		playerObjects[2]->SetPosition(new Vector3(99,425, 0));
		players[2]->SetSprite(playerSprite[2]);
		players[2]->SetScene(this);
	}

	if (playerCount >= 4) {
		//�l�Ԗڂ̃v���C���[
		playerSprite[3]->SetScale(new Vector2(50, 50));
		playerObjects[3]->SetPosition(new Vector3(925, 425, 0));
		players[3]->SetSprite(playerSprite[3]);
		players[3]->SetScene(this);
	}

	//�����o���̏���
	balloonSprite = new Sprite();
	balloonSprite->SetScale(new Vector2(0, 0)); //�ŏ��͔�\��
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

double Run::GetTimer() {
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
