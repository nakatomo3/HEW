#pragma once
#include "Scene.h"
class RunResult : public Scene {
public:
	RunResult(string name);
	~RunResult();

	void Start();
	void Load();
	void Update();

private:
	//���������邾�������
};