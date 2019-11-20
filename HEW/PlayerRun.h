#pragma once
#include "ScriptBase.h"
#include "SceneManager.h"
#include "Sprite.h"

class Run;
class PlayerRun : public ScriptBase {
public:
	PlayerRun();
	~PlayerRun();

	float GetCharge();
	int SetplayerID(int id);

	void Start();
	void Update()override;

	void SetSprite(Sprite* sprite);
	void SetScene(Run* run);

private:
	float charge = 0;

	int playerID = 0;

	Sprite* sprite;
	Run* run;
};