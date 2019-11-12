#pragma once
#include "ScriptBase.h"
#include "Sprite.h"
#include "GaugePunch.h"
#include "Player.h"
class PlayerPunch :	public ScriptBase {
public:
	PlayerPunch();
	~PlayerPunch();

	void SetSprite(Sprite* _sprite);
	void SetPlayer(Player player);

private :
	Player thisPlayer;

	Sprite* sprite;

	Texture* readySprite;
	Texture* punchSprite;
};

