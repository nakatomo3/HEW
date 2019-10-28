#pragma once
#include <vector>
#include "Scene.h"
#include "Time.h"
#include "ChargeGaugeRun.h"
#include "PlayerRun.h"

using namespace std;

class Run :	public Scene {
public:
	Run(string name);
	~Run();

	void Start();
	void Load();

	void Update();

	float GetTimer();

	void ChangePlayerCount(unsigned int num);
	int GetPlayerCount();

private:

	const float COUNT_DOWN_MAX = 3;

	float timer = -COUNT_DOWN_MAX;

	int playerCount = 4;

	//�����o���̃I�u�W�F�N�g
	GameObject* balloon;

	//�����o���̃X�v���C�g
	Sprite* balloonSprite;


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