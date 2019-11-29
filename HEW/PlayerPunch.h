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
	BREAKING
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

private :
	Player thisPlayer;

	int playerNumber;

	Sprite* sprite;

	Texture* readySprite;
	Texture* punchSprite;

	MegatonMode nowMode = GAUGE;

	GaugePunch* gauge;
	AimingPunch* aiming;
	PendulumPunch* pendulum;

	float gaugeValue;
	float aimingValue;
	float pendulumValue;

	double value = 0;

	int KEY;

	MegatonPunch* megatonPunch;

	Text* text;
};

