#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Texture.h"
class TotalResult : public Scene {
public:
	TotalResult(string name);
	~TotalResult();

	void Load();
	void Start();
	void UnLoad();
	void Update();

private:

	GameObject* titleObject;
	Sprite* titleSprite;

	GameObject* backgroundObject;
	Sprite* backgroundSprite;

	Sprite* totalresultTableSprite;
	Texture* totalresultTableTexture;

	Sprite* totalresultLogo;
	Sprite* totalresultLogo1;
	Sprite* totalresultLogo2;
	Sprite* totalresultLogo3;
	Sprite* totalresultLogo4;
	Sprite* totalresultLogo5;
	Sprite* totalresultLogo6;
	

	Texture* logoTexture1;
	Texture* logoTexture2;
	Texture* logoTexture3;
	Texture* logoTexture4;
	Texture* logoTexture5;
	Texture* logoTexture6;

	float timer = 0;

};

