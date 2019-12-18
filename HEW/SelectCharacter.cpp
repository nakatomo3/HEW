#include "SelectCharacter.h"
#include "VariableManager.h"
#include "Input.h"
#include "SceneManager.h"



void SelectCharacter::Start() {

	// ”wŒi
	ObjectManager::GetInstance().Instantiate(backgroundObject);

	// ƒvƒŒƒCƒ„[”wŒi
	ObjectManager::GetInstance().Instantiate(playerBackgroundObject);

	// ƒLƒƒƒ‰”wŒi
	ObjectManager::GetInstance().Instantiate(selectCharacterObject1);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject2);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject3);
	ObjectManager::GetInstance().Instantiate(selectCharacterObject4);

	//ƒJ[ƒ\ƒ‹
	ObjectManager::GetInstance().Instantiate(selectCursorObject);

	for (int i = 0; i < playerCount; i++) {
		isReady.emplace_back(false);
	}

}


void SelectCharacter::Load() {//”wŒi@ã‚ªƒvƒŒƒCƒ„[”wŒi(1–‡)@‰º‚ªƒLƒƒƒ‰”wŒi(4–‡)

	playerCount = VariableManager::GetInstance().GetInt("playerCount");

	// ”wŒi
	backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// ”wŒi‚Ì‘å‚«‚³ // •,‚‚³
	backgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0.01));// ”wŒi‚ÌˆÊ’u
	backgroundSprite->SetColor(new Color(0, 0, 0, 255));// •F”wŒi

	// ƒvƒŒƒCƒ„[”wŒi
	playerBackgroundObject = new GameObject();
	playerBackgroundSprite = new Sprite();
	playerBackgroundObject->AddComponent(playerBackgroundSprite);
	playerBackgroundSprite->SetScale(new Vector2(SCREEN_WIDTH*0.6, SCREEN_HEIGHT *0.54));// ”wŒi‚Ì‘å‚«‚³
	playerBackgroundSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 3.55, -0.01));// ”wŒi‚ÌˆÊ’u
	playerBackgroundSprite->SetColor(new Color(255, 255, 255, 255));// ”’F”wŒi

	// ƒLƒƒƒ‰”wŒi
	selectCharacterObject1 = new GameObject();
	selectCharacterSprite1 = new Sprite();
	selectCharacterObject1->AddComponent(selectCharacterSprite1);
	selectCharacterSprite1->SetScale(new Vector2(SCREEN_HEIGHT * 0.3, SCREEN_HEIGHT * 0.3));// ”wŒi‚Ì‘å‚«‚³       // d—l‘‚Ì3Š„=0.3
	selectCharacterSprite1->SetPosition(new Vector3(SCREEN_WIDTH *0.2, SCREEN_HEIGHT / 1.4, -0.01));// ”wŒi‚ÌˆÊ’u
	selectCharacterSprite1->SetColor(new Color(255, 255, 255, 255));// ”’F”wŒi

	selectCharacterObject2 = new GameObject();
	selectCharacterSprite2 = new Sprite();
	selectCharacterObject2->AddComponent(selectCharacterSprite2);
	selectCharacterSprite2->SetScale(new Vector2(SCREEN_HEIGHT * 0.3, SCREEN_HEIGHT * 0.3));// ”wŒi‚Ì‘å‚«‚³
	selectCharacterSprite2->SetPosition(new Vector3(SCREEN_WIDTH *0.4, SCREEN_HEIGHT / 1.4, -0.01));// ”wŒi‚ÌˆÊ’u
	selectCharacterSprite2->SetColor(new Color(255, 255, 0, 255));// ÔF”wŒi

	selectCharacterObject3 = new GameObject();
	selectCharacterSprite3 = new Sprite();
	selectCharacterObject3->AddComponent(selectCharacterSprite3);
	selectCharacterSprite3->SetScale(new Vector2(SCREEN_HEIGHT * 0.3, SCREEN_HEIGHT *0.3));// ”wŒi‚Ì‘å‚«‚³
	selectCharacterSprite3->SetPosition(new Vector3(SCREEN_WIDTH *0.6, SCREEN_HEIGHT / 1.4, -0.01));// ”wŒi‚ÌˆÊ’u
	selectCharacterSprite3->SetColor(new Color(255, 255, 255, 255));// ”’F”wŒi

	selectCharacterObject4 = new GameObject();
	selectCharacterSprite4 = new Sprite();
	selectCharacterObject4->AddComponent(selectCharacterSprite4);
	selectCharacterSprite4->SetScale(new Vector2(SCREEN_HEIGHT * 0.3, SCREEN_HEIGHT * 0.3));// ”wŒi‚Ì‘å‚«‚³
	selectCharacterSprite4->SetPosition(new Vector3(SCREEN_WIDTH *0.8, SCREEN_HEIGHT / 1.4, -0.01));// ”wŒi‚ÌˆÊ’u
	selectCharacterSprite4->SetColor(new Color(255, 255, 0, 255));// ÔF”wŒi

	for (int i = 0; i < playerCount; i++) {
		cursorPositions.emplace_back(0);
	}

	for (int i = 0; i < playerCount; i++) {
		//ƒJ[ƒ\ƒ‹
		selectCursorObject = new GameObject();
		selectCursorSprite = new Sprite();
		selectCursorObject->AddComponent(selectCursorSprite);
		selectCursorSprite->SetScale(new Vector2(SCREEN_WIDTH *0.05, SCREEN_HEIGHT *0.08));// ƒJ[ƒ\ƒ‹‚Ì‘å‚«‚³
		selectCursorSprite->SetColor(new Color(0, 0, 255, 255));// …F

	}

}

void SelectCharacter::Update() {

	//ƒJ[ƒ\ƒ‹‚ğ•Ï”‚É@ƒJ[ƒ\ƒ‹‚ÌˆÊ’u‚©‚çÀ•WŒvZ@ƒJ[ƒ\ƒ‹‚ÌˆÊ’u‚Ì•Ï”‚ğ”z—ñ‚É‚µ‚Ä‚¢‚é ”ÍˆÍ‚Í0`3‚Ü‚Å
	if (playerCount >= 1) {// ƒvƒŒƒCƒ„[ƒK1l‚Ì
		if (Input::GetInstance().GetKeyDown(DIK_1)) {// 1‚ğ‰Ÿ‚µ‚½‚Æ‚« ¶
			if (cursorPositions[0] >= 1) {// 1ˆÈ‰º‚É‚µ‚È‚¢
				cursorPositions[0]--;
			}
		}

		if (Input::GetInstance().GetKeyDown(DIK_2)) {// 2‚ğ‰Ÿ‚µ‚½‚Æ‚« ‰E
			if (cursorPositions[0] <= 2) {// 2ˆÈã‚É‚µ‚È‚¢
				cursorPositions[0]++;
			}
		}
		selectCursorSprite->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[0] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6, -0.01));
	}

	if (playerCount >= 2) {// ƒvƒŒƒCƒ„[‚ª2l‚Ì
		if (Input::GetInstance().GetKeyDown(DIK_1)) {// 1‚ğ‰Ÿ‚µ‚½‚Æ‚« ¶
			if (cursorPositions[1] >= 1) {
				cursorPositions[1]--;
			}
		}

		if (Input::GetInstance().GetKeyDown(DIK_2)) {// 2‚ğ‰Ÿ‚µ‚½‚Æ‚« ‰E
			if (cursorPositions[1] <= 2) {
				cursorPositions[1]++;
			}
		}
		selectCursorSprite->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[1] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6, -0.01));
	}

	if (playerCount >= 3) {// ƒvƒŒƒCƒ„[‚ª3l‚Ì
		if (Input::GetInstance().GetKeyDown(DIK_1)) {// 1‚ğ‰Ÿ‚µ‚½‚Æ‚« ¶
			if (cursorPositions[2] >= 1) {
				cursorPositions[2]--;
			}
		}

		if (Input::GetInstance().GetKeyDown(DIK_2)) {// 2‚ğ‰Ÿ‚µ‚½‚Æ‚« ‰E
			if (cursorPositions[2] <= 2) {
				cursorPositions[2]++;
			}
		}
		selectCursorSprite->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[2] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6, -0.01));
	}

	if (playerCount >= 4) {// ƒvƒŒƒCƒ„[‚ª4l‚Ì
		if (Input::GetInstance().GetKeyDown(DIK_1)) {// 1‚ğ‰Ÿ‚µ‚½‚Æ‚« ¶
			if (cursorPositions[3] >= 1) {
				cursorPositions[3]--;
			}
		}

		if (Input::GetInstance().GetKeyDown(DIK_2)) {// 2‚ğ‰Ÿ‚µ‚½‚Æ‚« ‰E
			if (cursorPositions[3] <= 2) {
				cursorPositions[3]++;
			}
		}
		selectCursorSprite->SetPosition(new Vector3(SCREEN_WIDTH * 0.2 * (cursorPositions[3] + 1) - SCREEN_HEIGHT * 0.15, SCREEN_HEIGHT / 1.6, -0.01));
	}

}

SelectCharacter::SelectCharacter(string name) : Scene(name) {

}


SelectCharacter::~SelectCharacter() {
}