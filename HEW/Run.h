#pragma once
#include "Scene.h"
#include "Time.h"
#include "ChargeGaugeRun.h"
#include "PlayerRun.h"

class Run :	public Scene {
public:
	Run(string name);
	~Run();

	void Start();
	void Load();

	void Update();

	float GetTimer();

	void ChangePlayerCount(unsigned int num);

private:

	const float COUNT_DOWN_MAX = 3;

	float timer = -COUNT_DOWN_MAX;

	int playerCount = 0;

	//�����o���̃I�u�W�F�N�g
	GameObject* balloon;

	//�����o���̃X�v���C�g
	Sprite* balloonSprite;

	//�v���C���[�X�N���v�g
	PlayerRun* players[4];

	//�v���C���[�̃I�u�W�F�N�g
	GameObject* playerObjects[4];

	//�v���C���[�̃X�v���C�g
	Sprite* playerSprite[4];

	//�Q�[�W�X�N���v�g
	ChargeGaugeRun* gauge[4];

	//�Q�[�W�̃X�v���C�g
	Sprite* gaugeSprite[4];
};