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

float PlayerRun::GetCharge() {
	return charge;
}

int PlayerRun::SetplayerID(int id) {
	return playerID = id;

}

void PlayerRun::Update() {
	//LogWriter::GetInstance().Log("hoge");
	//LogWriter::GetInstance().Log("%d:%f", playerID, charge);
	switch (playerID) {
	case 0:
		if (Input::GetInstance().GetKey(DIK_A)) {
			charge += 0.1f; //値は調整
			LogWriter::GetInstance().Log("A");
			LogWriter::GetInstance().Log("%d:%f", playerID, charge);
		}
		break;
	case 1:
		if (Input::GetInstance().GetKey(DIK_S)) {
			charge += 0.1f; //値は調整
			LogWriter::GetInstance().Log("S");
			LogWriter::GetInstance().Log("%d:%f", playerID, charge);
		}
		break;
	case 2:
		if (Input::GetInstance().GetKey(DIK_W)) {
			charge += 0.1f; //値は調整
			LogWriter::GetInstance().Log("W");
			LogWriter::GetInstance().Log("%d:%f", playerID, charge);
		}
		break;
	case 3:
		if (Input::GetInstance().GetKey(DIK_D)) {
			charge += 0.1f; //値は調整
			LogWriter::GetInstance().Log("D");
			LogWriter::GetInstance().Log("%d:%f", playerID, charge);
		}
		break;
	}

	if (charge >= 300.0f) {
		sprite->SetColor(D3DCOLOR_RGBA(100, 100, 0, 230));
	}

	else if (charge >= 600.0f) {
		sprite->SetColor(D3DCOLOR_RGBA(200, 0, 0, 230));
	}

	//角度8度ぐらいを0.1秒で移動
	if (run->GetTimer() >= 1) {
		gameObject->Move(Vector3(charge * 0.05f * SCREEN_WIDTH/1024, charge * -0.007f * SCREEN_HEIGHT/576, 0));
	}
}

void PlayerRun::SetSprite(Sprite * _sprite){
	sprite = _sprite;
}

void PlayerRun::SetScene(Run * _run){
	run = _run;
}