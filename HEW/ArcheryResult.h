#pragma once
#include "Scene.h"
#include "Archery.h"
#include <string>
using namespace std;
class ArcheryResult : public Scene {
public :
	ArcheryResult(string name);
	~ArcheryResult();

	void Start();
	void Load();
	void Update();
	void UnLoad();

private:

	vector<int> scores;

	//�����L���O�̃I�u�W�F�N�g
	GameObject* ranking;

	//�����L���O�̃X�v���C�g
	Sprite* rankingSprite;

	//�����L���O�̃e�N�X�`��
	Texture* rankingTexture;

	//�����L���O�w�i�̃I�u�W�F�N�g
	GameObject* rankingBackground;

	//�����L���O�w�i�̃X�v���C�g
	Sprite* rankingBackgroundSprite;

	//���ʂ̃I�u�W�F�N�g
	vector<GameObject*> rankingScore{};

	//���ʂ̃e�L�X�g
	vector<Text*> rankingScoreText{};

	//���ʃ|�C���g�̃I�u�W�F�N�g
	vector<GameObject*> rankingPoint{};

	//���ʃ|�C���g�̃e�L�X�g
	vector<Text*> rankingPointText{};

	ArcheryResult* archeryresult;
	
	float timer;

	int playerCount = 0;

	bool isRanking = false;

	vector<int> point;
};

