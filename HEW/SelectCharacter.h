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
	void Update();

private:
	vector<bool> isReady;

	GameObject* backgroundObject;
	Sprite* backgroundSprite;

	GameObject* playerBackgroundObject;
	Sprite*  playerBackgroundSprite;

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

	float cursorPosition = 0.0f;
	int playerCount = 0;
	vector<int> cursorPositions;

	vector<bool> isSelected;
	vector<bool> isReadys;
};