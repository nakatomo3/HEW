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
	//‚¢‚Á‚½‚ñì‚é‚¾‚¯ì‚Á‚½
};