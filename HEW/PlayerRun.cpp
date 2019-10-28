#include "PlayerRun.h"
#include "Input.h"



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
}
