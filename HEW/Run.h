#pragma once
#include <vector>
#include "Scene.h"
#include "Time.h"
#include "ChargeGaugeRun.h"
#include "PlayerRun.h"
#include "BalloonRun.h"


using namespace std;

class Run :	public Scene {
public:
	Run(string name);
	~Run();

	void Start();
	void Load();

	void Update();

	double GetTimer();

	void ChangePlayerCount(unsigned int num);
	int GetPlayerCount();

	Sprite* GetPlayerSprite(int playerID);

	void SetSprite(Sprite* _sprite);

private:

	const float COUNT_DOWN_MAX = 3;

	double timer = -COUNT_DOWN_MAX;

	int playerCount = 4;//�Ƃ肠������4�l���ɂ��Ă���(�f�t�H��0)

	//�����o���̃I�u�W�F�N�g
	GameObject* balloon;

	//�����o���̃X�v���C�g
	Sprite* balloonSprite;

	//�����o���̃e�L�X�`���[
	Texture* balloonTexture;

	BalloonRun* balloonRun;


	//�v���C���[�X�N���v�g
	vector<PlayerRun*> players{};

	//�v���C���[�̃X�v���C�g
	vector<Sprite*> playerSprite{};

	//�v���C���[�̃I�u�W�F�N�g
	vector<GameObject*> playerObjects{};


	//�Q�[�W�X�N���v�g
	vector<ChargeGaugeRun*> gauges{};

	//�Q�[�W�̃X�v���C�g
	vector<Sprite*> gaugeSprites{};

	//�Q�[�W�̃I�u�W�F�N�g
	vector<GameObject*> gaugeObjects;

};