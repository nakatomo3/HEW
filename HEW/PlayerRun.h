#pragma once
#include "ScriptBase.h"
#include "Run.h"
#include "SceneManager.h"
class PlayerRun : public ScriptBase {
public:
	PlayerRun();
	~PlayerRun();

	float GetCharge();
	int SetplayerID(int id);

	void Update();

private:
	float charge = 0;

	int playerID = 0;
};