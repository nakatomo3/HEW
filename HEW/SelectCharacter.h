#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Texture.h"
class SelectCharacter : public Scene {
public:
	SelectCharacter(string name);
	~SelectCharacter();

	void Start();
	void Load();
	void UnLoad();
	void Update();

private:
	vector<bool> isReady;

	GameObject* backgroundObject;
	Sprite* backgroundSprite;
	Texture* backgroundTexture;

	GameObject* playerBackgroundObject;
	Sprite* playerBackgroundSprite;
	Sprite* selectingPlayerBackground;

	GameObject* selectCursorObject;
	vector<Sprite*> selectCursorSprite;

	GameObject* selectCharacterObject1;
	GameObject* selectCharacterObject2;
	GameObject* selectCharacterObject3;
	GameObject* selectCharacterObject4;

	Sprite*  selectCharacterSprite1;
	Sprite*  selectCharacterSprite2;
	Sprite*  selectCharacterSprite3;
	Sprite*  selectCharacterSprite4;

	GameObject* selectingCharacterObject;
	vector<Sprite*> selectingCharacterSprites;

	Texture* characterSelect;

	Texture* characterMask;
	Texture* characterRobot;
	Texture* characterWitch;
	Texture* characterAlien;

	float cursorPosition = 0.0f;
	int playerCount = 0;
	vector<int> cursorPositions;

	vector<bool> isSelected;

	vector<bool> wasInput;

	GameObject* bannerObject;
	Sprite* bannerSprite;
	Texture* readyBannerTexture;
	Texture* selectBannerTexture;

};