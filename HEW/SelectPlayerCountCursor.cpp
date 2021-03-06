#include "SelectPlayerCountCursor.h"
#include "VariableManager.h"
#include "SceneManager.h"

void SelectPlayerCountCursor::Update() {
	gameObject->SetPosition(new Vector3(SCREEN_WIDTH * 0.3, (cursorPosition) * SCREEN_HEIGHT * 0.3 + SCREEN_HEIGHT * 0.2, 0));

	if (Input::GetInstance().GetKeyDown(DIK_S)) {
		cursorPosition++;
	}
	if (Input::GetInstance().GetController(0).Gamepad.sThumbLY > 5000) {
		if (wasInput == false) {
			cursorPosition++;
		}
		wasInput = true;
	}
	if (Input::GetInstance().GetKeyDown(DIK_W)) {
		cursorPosition--;
	}
	if (Input::GetInstance().GetController(0).Gamepad.sThumbLY < -5000) {
		if (wasInput == false) {
			cursorPosition--;
		}
		wasInput = true;
	}

	cursorPosition = (cursorPosition + 3) % 3;

	if (Input::GetInstance().GetKeyDown(DIK_SPACE) || Input::GetInstance().GetKeyDown(DIK_RETURN) || Input::GetInstance().GetController(0).Gamepad.wButtons & VK_GAMEPAD_A || Input::GetInstance().GetController(0).Gamepad.wButtons & VK_GAMEPAD_B || Input::GetInstance().GetController(0).Gamepad.wButtons & VK_GAMEPAD_X || Input::GetInstance().GetController(0).Gamepad.wButtons & VK_GAMEPAD_Y) {
		VariableManager::GetInstance().SetInt("playerCount", cursorPosition + 2);
		SceneManager::GetInstance().LoadScene("selectCharacter");

	}
}
