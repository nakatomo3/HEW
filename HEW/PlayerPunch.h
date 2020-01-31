#pragma once
#include "ScriptBase.h"
#include "Sprite.h"
#include "GaugePunch.h"
#include "Player.h"

#include "AimingPunch.h"
#include "PendulumPunch.h"
#include "Text.h"

class MegatonPunch;

typedef enum MegatonMode {
	GAUGE,
	AIMING,
	PENDULUM,
	WAIT,
	BREAKING,
	VIEWSCORE
}MegatonMode;

class PlayerPunch :	public ScriptBase {
public:
	PlayerPunch();
	~PlayerPunch();

	void SetSprite(Sprite* _sprite);
	void SetPlayer(Player player);

	void SetPlayerNumber(int number);

	void SetGauge(GaugePunch* _gauge);
	void SetAiming(AimingPunch* _aiming);
	void SetPendulum(PendulumPunch* _pendulum);

	void Start();
	void Update();

	void SetBreakingFlag();

	void SetText(Text* _text);

	void SetBreaking(Sprite* sprite);

private :
	Player thisPlayer;

	int playerNumber;
	int characterID = 0;

	Sprite* sprite;

	Texture* readyTexture;
	Texture* punchTexture;

	MegatonMode nowMode = GAUGE;

	GaugePunch* gauge;
	AimingPunch* aiming;
	PendulumPunch* pendulum;

	float gaugeValue;
	float aimingValue;
	float pendulumValue;

	double value = 0;

	int KEY;

	Sprite* breaking;

	MegatonPunch* megatonPunch;

	Text* text;

	float waitTimer = 0;
	bool isBreaking = false;
};

