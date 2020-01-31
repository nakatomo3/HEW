#include "SelectCharacter.h"
#include "VariableManager.h"
#include "Input.h"
#include "SceneManager.h"
#include <XInput.h>


void SelectCharacter::Start() {

	// キャラ背景
	ObjectManager::GetInstance().Instantiate(selectCharacterObject1);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject2);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject3);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject4);

	//カーソル
	ObjectManager::GetInstance().Instantiate(selectCursorObject);

	//現在選択しているキャラクター
	ObjectManager::GetInstance().Instantiate(selectingCharacterObject);

	//バナー
	ObjectManager::GetInstance().Instantiate(bannerObject);	

	// 背景
	ObjectManager::GetInstance().Instantiate(backgroundObject);

	// プレイヤー背景
	ObjectManager::GetInstance().Instantiate(playerBackgroundObject);


	for (int i = 0; i < playerCount; i++) {
		isReady.emplace_back(false);
	}

}


void SelectCharacter::Load() {//背景　上がプレイヤー背景(1枚)　下がキャラ背景(4枚)

	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	// プレイヤー背景
	characterSelect = new Texture("assets/textures/System/characterSelect.png", "characterSelect");
	playerBackgroundObject = new GameObject();
	selectingPlayerBackground = new Sprite();
	selectingPlayerBackground->SetScale(new Vector2(SCREEN_WIDTH*0.6f, SCREEN_HEIGHT *0.54f));
	selectingPlayerBackground->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3.55f, -0.01f));
	selectingPlayerBackground->SetColor(new Color(128, 128, 128));
	playerBackgroundObject->AddComponent(selectingPlayerBackground);
	playerBackgroundSprite = new Sprite(characterSelect);
	playerBackgroundObject->AddComponent(playerBackgroundSprite);
	playerBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH*0.6f, SCREEN_HEIGHT *0.54f));// 背景の大きさ
	playerBackgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3.55f, -0.02f));// 背景の位置

	// キャラ背景
	characterMask = new Texture("assets/textures/All/CharacterSelection/Mask.png", "characterMask");
	selectCharacterObject1 = new GameObject();
	selectCharacterSprite1 = new Sprite(characterMask);
	selectCharacterObject1->AddComponent(selectCharacterSprite1);
	selectCharacterSprite1->SetScale(new Vector2(SCREEN_HEIGHT * 0.3f, SCREEN_HEIGHT * 0.3f));// 背景の大きさ       // 仕様書の3割=0.3
	selectCharacterSprite1->SetPosition(new Vector3(SCREEN_WIDTH *0.2f, SCREEN_HEIGHT / 1.4f + SD_HEIGHT * 0.5, -0.01f));// 背景の位置
	//selectCharacterSprite1->SetColor(new Color(255, 255, 255, 255));// 白色背景

	characterRobot = new Texture("assets/textures/All/CharacterSelection/Robot.png", "characterRobot");
	selectCharacterObject2 = new GameObject();
	selectCharacterSprite2 = new Sprite(characterRobot);
	selectCharacterObject2->AddComponent(selectCharacterSprite2);
	selectCharacterSprite2->SetScale(new Vector2(SCREEN_HEIGHT * 0.3f, SCREEN_HEIGHT * 0.3f));// 背景の大きさ
	selectCharacterSprite2->SetPosition(new Vector3(SCREEN_WIDTH *0.4f, SCREEN_HEIGHT / 1.4f + SD_HEIGHT * 0.5, -0.01f));// 背景の位置
	//selectCharacterSprite2->SetColor(new Color(255, 255, 0, 255));// 赤色背景

	characterWitch = new Texture("assets/textures/All/CharacterSelection/Witch.png", "characterWitch");
	selectCharacterObject3 = new GameObject();
	selectCharacterSprite3 = new Sprite(characterWitch);
	selectCharacterObject3->AddComponent(selectCharacterSprite3);
	selectCharacterSprite3->SetScale(new Vector2(SCREEN_HEIGHT * 0.3f, SCREEN_HEIGHT *0.3f));// 背景の大きさ
	selectCharacterSprite3->SetPosition(new Vector3(SCREEN_WIDTH *0.6f, SCREEN_HEIGHT / 1.4f + SD_HEIGHT * 0.5, -0.01f));// 背景の位置
	//selectCharacterSprite3->SetColor(new Color(255, 255, 255, 255));// 白色背景

	characterAlien = new Texture("assets/textures/All/CharacterSelection/Alien.png", "characterAlien");
	selectCharacterObject4 = new GameObject();
	selectCharacterSprite4 = new Sprite(characterAlien);
	selectCharacterObject4->AddComponent(selectCharacterSprite4);
	selectCharacterSprite4->SetScale(new Vector2(SCREEN_HEIGHT * 0.3f, SCREEN_HEIGHT * 0.3f));// 背景の大きさ
	selectCharacterSprite4->SetPosition(new Vector3(SCREEN_WIDTH *0.8f, SCREEN_HEIGHT / 1.4f + SD_HEIGHT * 0.5, -0.01f));// 背景の位置
	//selectCharacterSprite4->SetColor(new Color(255, 255, 0, 255));// 赤色背景

	for (int i = 0; i < playerCount; i++) {
		cursorPositions.emplace_back(0);
	}

	bannerObject = new GameObject();
	selectBannerTexture = new Texture("assets/textures/System/banner.png");
	readyBannerTexture = new Texture("assets/textures/System/ReadyToFight.png");
	bannerSprite = new Sprite(selectBannerTexture);
	bannerSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	bannerSprite->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, -0.03f));
	bannerObject->AddComponent(bannerSprite);

	backgroundObject = new GameObject();
	backgroundTexture = new Texture("assets/textures/System/characterSelectBackground.png");
	backgroundSprite = new Sprite(backgroundTexture);
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	backgroundObject->AddComponent(backgroundSprite);
	backgroundSprite->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, 0.05));

	selectCursorObject = new GameObject();
	for (int i = 0; i < playerCount; i++) {
		//カーソル
		selectCursorSprite.emplace_back(new Sprite());
		selectCursorObject->AddComponent(selectCursorSprite[i]);
		selectCursorSprite[i]->SetScale(new Vector2(SCREEN_WIDTH *0.05f, SCREEN_HEIGHT *0.08f));// カーソルの大きさ
		selectCursorSprite[i]->SetColor(new Color(0, 0, 255, 255));// 水色

	}

	selectingCharacterObject = new GameObject();

	for (int i = 0; i < 4; i++) {
		isSelected.emplace_back(false);
		wasInput.emplace_back(false);
		selectingCharacterSprites.emplace_back(new Sprite());
		selectingCharacterObject->AddComponent(selectingCharacterSprites[i]);
		selectingCharacterSprites[i]->SetScale(new Vector2(SCREEN_WIDTH * 0.13f, SCREEN_WIDTH * 0.13f));
		if (i >= playerCount) {
			selectingCharacterSprites[i]->SetActive(false);
		}
	}

	selectingCharacterSprites[0]->SetPosition(new Vector3(SCREEN_WIDTH * 0.35f, SCREEN_HEIGHT * 0.15f, -0.01f));
	selectingCharacterSprites[1]->SetPosition(new Vector3(SCREEN_WIDTH * 0.65f, SCREEN_HEIGHT * 0.15f, -0.01f));
	selectingCharacterSprites[2]->SetPosition(new Vector3(SCREEN_WIDTH * 0.35f, SCREEN_HEIGHT * 0.41f, -0.01f));
	selectingCharacterSprites[3]->SetPosition(new Vector3(SCREEN_WIDTH * 0.65f, SCREEN_HEIGHT * 0.41f, -0.01f));

}

void SelectCharacter::Update() {

	//カーソルを変数に　カーソルの位置から座標計算　カーソルの位置の変数を配列にしている 範囲は0～3まで
	if (playerCount >= 1) {// プレイヤーガ1人の時
		if (isReady[0] == false) {
			if (Input::GetInstance().GetKeyDown(DIK_1)) {// 1を押したとき 左
				if (cursorPositions[0] >= 1) {// 1以下にしない
					cursorPositions[0]--;
				}
			}
			if (Input::GetInstance().GetKeyDown(DIK_2)) {// 2を押したとき 右
				if (cursorPositions[0] <= 2) {// 2以上にしない
					cursorPositions[0]++;
				}
			}

			if (Input::GetInstance().GetController(0).Gamepad.sThumbLX > 5000) {
				if (wasInput[0] == false) {
					if (cursorPositions[0] <= 2) {// 2以上にしない
						cursorPositions[0]++;
					}
				}
				wasInput[0] = true;
			} else if(Input::GetInstance().GetController(0).Gamepad.sThumbLX < -5000){
				if (wasInput[0] == false) {
					if (cursorPositions[0] >= 1) {// 1以下にしない
						cursorPositions[0]--;
					}
				}
				wasInput[0] = true;
			} else {
				wasInput[0] = false;
			}

		} else {
			selectCursorSprite[0]->SetColor(new Color(0, 0, 128, 255));
		}
		selectCursorSprite[0]->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[0] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6 + SD_HEIGHT * 0.5, -0.02f));

		if ((Input::GetInstance().GetKeyDown(DIK_A) || Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(0).Gamepad.wButtons & XINPUT_GAMEPAD_Y) && isSelected[cursorPositions[0]] == false) {
			isSelected[cursorPositions[0]] = true;
			isReady[0] = true;
		}
	}

	if (playerCount >= 2) {// プレイヤーが2人の時
		if (isReady[1] == false) {
			if (Input::GetInstance().GetKeyDown(DIK_3)) {// 1を押したとき 左
				if (cursorPositions[1] >= 1) {
					cursorPositions[1]--;
				}
			}

			if (Input::GetInstance().GetKeyDown(DIK_4)) {// 2を押したとき 右
				if (cursorPositions[1] <= 2) {
					cursorPositions[1]++;
				}
			}

			if (Input::GetInstance().GetController(1).Gamepad.sThumbLX > 5000) {
				if (wasInput[1] == false) {
					if (cursorPositions[1] <= 2) {// 2以上にしない
						cursorPositions[1]++;
					}
				}
				wasInput[1] = true;
			} else if (Input::GetInstance().GetController(1).Gamepad.sThumbLX < -5000) {
				if (wasInput[1] == false) {
					if (cursorPositions[1] >= 1) {// 1以下にしない
						cursorPositions[1]--;
					}
				}
				wasInput[1] = true;
			} else {
				wasInput[1] = false;
			}
		} else {
			selectCursorSprite[1]->SetColor(new Color(0, 0, 128, 255));
		}
		selectCursorSprite[1]->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[1] + 1) + SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6 + SD_HEIGHT * 0.5, -0.02f));
	
		if ((Input::GetInstance().GetKeyDown(DIK_S) || Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(1).Gamepad.wButtons & XINPUT_GAMEPAD_Y) && isSelected[cursorPositions[1]] == false) {
			isSelected[cursorPositions[1]] = true;
			isReady[1] = true;
		}
	}

	if (playerCount >= 3) {// プレイヤーが3人の時
		if (isReady[2] == false) {
			if (Input::GetInstance().GetKeyDown(DIK_5)) {// 1を押したとき 左
				if (cursorPositions[2] >= 1) {
					cursorPositions[2]--;
				}
			}

			if (Input::GetInstance().GetKeyDown(DIK_6)) {// 2を押したとき 右
				if (cursorPositions[2] <= 2) {
					cursorPositions[2]++;
				}
			}

			if (Input::GetInstance().GetController(2).Gamepad.sThumbLX > 5000) {
				if (wasInput[2] == false) {
					if (cursorPositions[2] <= 2) {// 2以上にしない
						cursorPositions[2]++;
					}
				}
				wasInput[2] = true;
			} else if (Input::GetInstance().GetController(2).Gamepad.sThumbLX < -5000) {
				if (wasInput[2] == false) {
					if (cursorPositions[2] >= 1) {// 1以下にしない
						cursorPositions[2]--;
					}
				}
				wasInput[2] = true;
			} else {
				wasInput[2] = false;
			}
		} else {
			selectCursorSprite[2]->SetColor(new Color(0, 0, 128, 255));
		}
		selectCursorSprite[2]->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[2] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.25 + SD_HEIGHT * 0.5, -0.02f));
	
		if ((Input::GetInstance().GetKeyDown(DIK_D) || Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(2).Gamepad.wButtons & XINPUT_GAMEPAD_Y) && isSelected[cursorPositions[2]] == false) {
			isSelected[cursorPositions[2]] = true;
			isReady[2] = true;
		}
	}

	if (playerCount >= 4) {// プレイヤーが4人の時
		if (isReady[3] == false) {
			if (Input::GetInstance().GetKeyDown(DIK_7)) {// 1を押したとき 左
				if (cursorPositions[3] >= 1) {
					cursorPositions[3]--;
				}
			}

			if (Input::GetInstance().GetKeyDown(DIK_8)) {// 2を押したとき 右
				if (cursorPositions[3] <= 2) {
					cursorPositions[3]++;
				}
			}

			if (Input::GetInstance().GetController(3).Gamepad.sThumbLX > 5000) {
				if (wasInput[3] == false) {
					if (cursorPositions[3] <= 2) {// 2以上にしない
						cursorPositions[3]++;
					}
				}
				wasInput[3] = true;
			} else if (Input::GetInstance().GetController(3).Gamepad.sThumbLX < -5000) {
				if (wasInput[3] == false) {
					if (cursorPositions[3] >= 1) {// 1以下にしない
						cursorPositions[3]--;
					}
				}
				wasInput[3] = true;
			} else {
				wasInput[3] = false;
			}
		} else {
			selectCursorSprite[3]->SetColor(new Color(0, 0, 128, 255));
		}
		selectCursorSprite[3]->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[3] + 1) + SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.25 + SD_HEIGHT * 0.5, -0.02f));

		if ((Input::GetInstance().GetKeyDown(DIK_F) || Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_A || Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_B || Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_X || Input::GetInstance().GetController(3).Gamepad.wButtons & XINPUT_GAMEPAD_Y) && isSelected[cursorPositions[3]] == false) {
			isSelected[cursorPositions[3]] = true;
			isReady[3] = true;
		}
	}

	for (int i = 0; i < playerCount; i++) {
		int cursorPos = cursorPositions[i];
		Texture* texture;
		switch (cursorPos) {
		default :
			texture = characterMask;
			break;
		case 0:
			texture = characterMask;
			break;
		case 1:
			texture = characterRobot;
			break;
		case 2:
			texture = characterWitch;
			break;
		case 3:
			texture = characterAlien;
			break;
		}
		selectingCharacterSprites[i]->SetTexture(texture);
		if (isReady[i] == true) {
			selectingCharacterSprites[i]->SetColor(new Color(255, 255, 255, 255));
		}else{
			selectingCharacterSprites[i]->SetColor(new Color(128, 128, 128, 255));
		}
	}


	bool isAllReady = true;
	for (int i = 0; i < playerCount; i++) {
		if (isReady[i] == false) {
			isAllReady = false;
		}
	}

	if (isAllReady == true) {
		bannerSprite->SetTexture(readyBannerTexture);
		if (Input::GetInstance().GetKey(DIK_SPACE) || Input::GetInstance().GetKey(DIK_RETURN)) {
			for (int i = 0; i < playerCount; i++) {
				VariableManager::GetInstance().SetInt("character" + to_string(i), cursorPositions[i]);
			}
			SceneManager::GetInstance().LoadScene("runTitle");
		}
	} else {
		bannerSprite->SetTexture(selectBannerTexture);
	}
}

void SelectCharacter::UnLoad() {
	ObjectManager::GetInstance().Destroy(playerBackgroundObject);
	ObjectManager::GetInstance().Destroy(selectCharacterObject1);
	ObjectManager::GetInstance().Destroy(selectCharacterObject2);
	ObjectManager::GetInstance().Destroy(selectCharacterObject3);
	ObjectManager::GetInstance().Destroy(selectCharacterObject4);
	ObjectManager::GetInstance().Destroy(selectCursorObject);
}

SelectCharacter::SelectCharacter(string name) : Scene(name) {

}


SelectCharacter::~SelectCharacter() {
}