#include "PlayerRun.h"
#include "Input.h"

#include "Sprite.h"
#include "Texture.h"
#include "Run.h"
#include "SceneManager.h"



PlayerRun::PlayerRun() {

}


PlayerRun::~PlayerRun() {

}

void PlayerRun::Start() {

}

float PlayerRun::GetCharge() {
	return charge;
}

int PlayerRun::SetplayerID(int id) {
	return playerID = id;

}

void PlayerRun::Update() {

	if (run == NULL) {
		run = (Run*)(SceneManager::GetInstance().GetNowScene());
	}

	switch (playerID) {
	case 0:
		if (Input::GetInstance().GetKey(DIK_A) && run->timer >= 4 && run->timer <= 10) { // 左上ゲージ 小さい振ってが表示されると同時にAキーでチャージ可能
			charge += 10.0f; // 値は調整                                                                         よーいが表示されるとチャージは不可能
			LogWriter::GetInstance().Log("A"); // 押されているかの確認ログ 表示：A
			LogWriter::GetInstance().Log("%d:%f", playerID, charge); // チャージされているかのログ
		}
		break;
	case 1:
		if (Input::GetInstance().GetKey(DIK_S) && run->timer >= 4 && run->timer <= 10) { // 右上ゲージ 小さい振ってが表示されると同時にSキーでチャージ可能
			charge += 10.0f; // 値は調整                                                                         よーいが表示されるとチャージは不可能
			LogWriter::GetInstance().Log("S"); // 押されているかの確認ログ 表示：S
			LogWriter::GetInstance().Log("%d:%f", playerID, charge); // チャージされているかのログ
		}
		break;
	case 2:
		if (Input::GetInstance().GetKey(DIK_D) && run->timer >= 4 && run->timer <= 10) { // 左下ゲージ 小さい振ってが表示されると同時にDキーでチャージ可能
			charge += 10.0f; // 値は調整                                                                         よーいが表示されるとチャージは不可能
			LogWriter::GetInstance().Log("D"); // 押されているかの確認ログ 表示：D
			LogWriter::GetInstance().Log("%d:%f", playerID, charge); // チャージされているかのログ
		}
		break;
	case 3:
		if (Input::GetInstance().GetKey(DIK_F) && run->timer >= 4 && run->timer <= 10) { // 右下ゲージ 小さい振ってが表示されると同時にFキーでチャージ可能
			charge += 10.0f; // 値は調整                                                                         よーいが表示されるとチャージは不可能
			LogWriter::GetInstance().Log("F"); // 押されているかの確認ログ 表示：F
			LogWriter::GetInstance().Log("%d:%f", playerID, charge); // チャージされているかのログ
		}
		break;
	}

	if (charge >= 600.0f) {
		sprite->SetColor(D3DCOLOR_RGBA(100, 100, 0, 230));
	}

	else if (charge >= 300.0f) {
		sprite->SetColor(D3DCOLOR_RGBA(200, 0, 0, 230));
	}

	//角度8度ぐらいを0.1秒で移動
	if (run->timer >= 12 && isReplay == false) {
		gameObject->Move(Vector3(charge * 0.05f * SCREEN_WIDTH/1024, charge * -0.00f  * SCREEN_HEIGHT/576, 0));
		run->SetTime(playerID, 500 / charge);
	}

	if (run->timer >= 16.5f) {
		isReplay = true;
		
	}

	//リプレイ速度の移動
	if (isReplay == true) {
		LogWriter::GetInstance().Log("charge:%f", charge);
		LogWriter::GetInstance().Log("all:%f", charge * 0.005 * SCREEN_WIDTH / 1024.0);
		gameObject->Move(Vector3(charge * 0.005 * SCREEN_WIDTH / 1024.0, charge * -0.00f  * SCREEN_HEIGHT / 576, 0));
	}
}

void PlayerRun::SetSprite(Sprite * _sprite){
	sprite = _sprite;
}

void PlayerRun::SetScene(Run * _run){
	run = _run;
}