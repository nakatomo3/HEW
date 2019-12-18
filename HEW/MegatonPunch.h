#pragma once
#include "Scene.h"
#include "PlayerPunch.h"
#include "AimingPunch.h"
#include "PendulumPunch.h"
#include "VariableManager.h"
#include <vector>
using namespace std;

class MegatonPunch : public Scene {
public:
	MegatonPunch(string name);
	~MegatonPunch();

	void Load();
	void Start();

	void Update();

	void SetWaiting(int number);

private :
	int playerCount;

	vector<Texture*> playerTextures;
	vector<PlayerPunch*> players;
	vector<GameObject*> playerObjects;

	vector<GaugePunch*> gauges;
	vector<GameObject*> gaugeObjects;
	Texture* gaugeTexture;

	vector<AimingPunch*> aimings;
	vector<GameObject*> aimingObjects;
	Texture* aimingTexture;
	Texture* aimingWhiteTexture;

	vector<PendulumPunch*> pendulums;
	vector<GameObject*> pendulumObjects;
	Texture* pendulumCenterTexture;
	Texture* pendulumTexture;
	Texture* pendulumWhiteTexture;

	GameObject* earthObject;
	Sprite* earthSprite;
	Texture* earth;
	Sprite* breakingSprite;
	Texture* breaking;

	vector<bool> isWaitings;
	bool isBreaking = false;

	vector<Text*> texts;

	float timer = 0;
};

