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
	string path = "";

	switch (characterID) {
	case 0://ウルフ
		path = "assets/textures/Run/Player/masukudourufu/"; //ここを画像名に変える　　各ファイルまでぶち込み
		break;
	case 1://かしこま
		path = "assets/textures/Run/Player/kasikomk2/"; //ここを画像名に変える
		break;
	case 2://せん
		path = "assets/textures/Run/Player/senntyann/"; //ここを画像名に変える
		break;
	case 3://宇宙
		path = "assets/textures/Run/Player/utyuujinn/"; //ここを画像名に変える
		break;
	}

	playerTexture = new Texture(path + "waiting1.png"/*+個別画像名*/);//画像の名前は統一しそれをぶち込む  クラウチング
	sprite->SetTexture(playerTexture);
	playerTexture2 = new Texture(path + "waiting2.png"/*+個別画像名*/);
	playerTexture3 = new Texture(path + "waiting3.png"/*+個別画像名*/);

	runTextureA = new Texture(path + "runA.png"/*+ run.pngとか画像名*/);//走ってる
	runTextureB = new Texture(path + "runB.png"/*+ run.pngとか画像名*/);
	runTextureC = new Texture(path + "runC.png");
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
		}
		break;
	case 1:
		if (Input::GetInstance().GetKey(DIK_S) && run->timer >= 4 && run->timer <= 10) { // 右上ゲージ 小さい振ってが表示されると同時にSキーでチャージ可能
			charge += 10.0f; // 値は調整                                                                         よーいが表示されるとチャージは不可能
		}
		break;
	case 2:
		if (Input::GetInstance().GetKey(DIK_D) && run->timer >= 4 && run->timer <= 10) { // 左下ゲージ 小さい振ってが表示されると同時にDキーでチャージ可能
			charge += 10.0f; // 値は調整                                                                         よーいが表示されるとチャージは不可能
		}
		break;
	case 3:
		if (Input::GetInstance().GetKey(DIK_F) && run->timer >= 4 && run->timer <= 10) { // 右下ゲージ 小さい振ってが表示されると同時にFキーでチャージ可能
			charge += 10.0f; // 値は調整                                                                         よーいが表示されるとチャージは不可能
		}
		break;
	}

	if (charge >= 600.0f) {
		sprite->SetTexture(playerTexture3);
	}

	else if (charge >= 300.0f) {
		sprite->SetTexture(playerTexture2);
	}

	//角度8度ぐらいを0.1秒で移動
	if (run->timer >= 12 && isReplay == false) {
		gameObject->Move(Vector3(charge * 0.03f * SCREEN_WIDTH/1024, charge * -0.00f  * SCREEN_HEIGHT/576, 0));
		run->SetTime(playerID, 500 / charge);
	}

	if (run->timer >= 16.5f) {
		isReplay = true;
		
	}

	//リプレイ速度の移動
	if (isReplay == true) {
		if (run->timer <= 22.5f) {
			gameObject->Move(Vector3(charge * 0.003f * SCREEN_WIDTH / 1024.0, charge * -0.00f  * SCREEN_HEIGHT / 576, 0));
		} else {
			gameObject->Move(Vector3(charge * 0.002f * SCREEN_WIDTH / 1024.0, charge * -0.00f  * SCREEN_HEIGHT / 576, 0));
		}
	}
}

void PlayerRun::SetSprite(Sprite * _sprite){
	sprite = _sprite;
}

void PlayerRun::SetScene(Run * _run){
	run = _run;
}

void PlayerRun::SetCharacterID(int id) {
	characterID = id;
}
