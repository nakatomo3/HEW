#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "HeroEngine.h"
#include <vector>

using namespace std;
class RunResult : public Scene {
public:
	RunResult(string name);
	~RunResult();

	void Start();
	void Load();
	void UnLoad();
	void Update();

private:

	int playerCount;

	///�����L���O�̃I�u�W�F�N�g
	GameObject* ranking;

	//�����L���O�̃X�v���C�g
	Sprite* rankingSprite;

	//�����L���O�̃e�N�X�`��
	Texture* rankingTexture;

	//�����L���O�w�i�̃I�u�W�F�N�g
	GameObject* background;

	//�����L���O�w�i�̃X�v���C�g
	Sprite* backgroundSprite;

	//���ʂ̃I�u�W�F�N�g
	vector<GameObject*> rankingTime{};

	//���ʂ̃e�L�X�g
	vector<Text*> rankingTimeText{};

	//���ʃ|�C���g�̃I�u�W�F�N�g
	vector<GameObject*> rankingPoint{};

	//���ʃ|�C���g�̃e�L�X�g
	vector<Text*> rankingPointText{};

	//���_���̃I�u�W�F�N�g
	vector <GameObject*> medal{};

	//���_���̃X�v���C�g
	vector <Sprite*> medalSprite{};

	//���_���̃e�N�X�`��
	vector <Texture*> medalTexture{};

	RunResult* runResult;

	float timer = 0;

	bool isRanking = false;

	vector<float> times;
	vector<int> ranks;
	vector<int> point;
};