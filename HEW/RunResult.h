#pragma once
#include "Scene.h"
#include "Sprite.h"

class RunResult : public Scene {
public:
	RunResult(string name);
	~RunResult();

	void Start();
	void Load();
	void UnLoad();
	void Update();

private:
	///�����L���O�̃I�u�W�F�N�g
	GameObject* ranking;

	//�����L���O�̃X�v���C�g
	Sprite* rankingSprite;

	//�����L���O�w�i�̃I�u�W�F�N�g
	GameObject* background;

	//�����L���O�w�i�̃X�v���C�g
	Sprite* backgroundSprite;

	RunResult* runResult;

	float timer = 0;
};