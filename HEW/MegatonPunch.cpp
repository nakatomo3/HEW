#include "MegatonPunch.h"
#include "Setting.h"


MegatonPunch::MegatonPunch(string name) : Scene(name) {

}


MegatonPunch::~MegatonPunch() {
}

void MegatonPunch::Load() {
	/*playerTextures[0] = new Texture("");
	playerTextures[1] = new Texture("");
	playerTextures[2] = new Texture("");
	playerTextures[3] = new Texture("");*/

	int playerCount = VariableManager::GetInstance().GetInt("playerCount");
	gaugeTexture = new Texture("assets/textures/Run/UI/gauge.png");

	aimingTexture = new Texture("assets/textures/MegatonPunch/UI/Aiming.png");

	//pendulumCenterTexture = new Texture("");
	pendulumTexture = new Texture("assets/textures/MegatonPunch/UI/Pendulum.png");

	const float PLAYER_WIDTH = SCREEN_WIDTH/10;

	const float GAUGE_WIDTH = SCREEN_WIDTH/20;
	const float GAUGE_HEIGHT = SCREEN_HEIGHT/5*2;

	const float AIMING_WIDTH = SCREEN_WIDTH / 15;

	for (int i = 0; i < playerCount; i++) {
		auto player = new PlayerPunch();
		players.push_back(player);
		auto playerObject = new GameObject();
		playerObjects.push_back(playerObject);
		playerObject->AddComponent(player);
		playerObject->SetPosition(new Vector3((SCREEN_WIDTH - PLAYER_WIDTH * 4) / 5 * (i+1) + PLAYER_WIDTH * (0.5f+i), SCREEN_HEIGHT / 2, 0));
		auto playerSprite = new Sprite();
		player->SetSprite(playerSprite);
		playerObject->AddComponent(playerSprite);
		playerSprite->SetScale(new Vector2(PLAYER_WIDTH, 100));
		player->SetPlayerNumber(i);
		isWaitings.emplace_back(false);

		auto gauge = new GaugePunch();
		auto gaugeObject = new GameObject();
		gaugeObjects.push_back(gaugeObject);
		gaugeObject->AddComponent(gauge);
		auto gaugeSprite = new Sprite();
		auto gaugeScalerSprite = new Sprite();
		gaugeObject->AddComponent(gaugeSprite);
		gaugeObject->AddComponent(gaugeScalerSprite);
		gaugeScalerSprite->SetTexture(gaugeTexture);
		gaugeSprite->SetCriterion(DOWN);
		gaugeScalerSprite->SetCriterion(DOWN);
		gaugeSprite->SetScale(new Vector2(GAUGE_WIDTH*0.9f, GAUGE_HEIGHT*0.95f));
		gaugeScalerSprite->SetScale(new Vector2(GAUGE_WIDTH, GAUGE_HEIGHT));
		gaugeObject->SetPosition(new Vector3((SCREEN_WIDTH - PLAYER_WIDTH * 4) / 5 * (i + 1) + PLAYER_WIDTH * (0.5f + i) - SCREEN_WIDTH/10, SCREEN_HEIGHT / 3*2, 0));
		gauge->SetSprite(gaugeSprite);
		gaugeSprite->SetPosition(new Vector3(0,-SCREEN_HEIGHT*0.01f,0));
		player->SetGauge(gauge);

		auto aiming = new AimingPunch();
		auto aimingObject = new GameObject();
		aimingObject->AddComponent(aiming);
		auto aimingSpriteA = new Sprite();
		auto aimingSpriteB = new Sprite();
		aimingObject->AddComponent(aimingSpriteA);
		aimingObject->AddComponent(aimingSpriteB);
		aimingSpriteA->SetTexture(aimingTexture);
		aimingSpriteB->SetTexture(aimingTexture);
		player->SetAiming(aiming);
		aiming->SetSprite(true, aimingSpriteA);
		aiming->SetSprite(false, aimingSpriteB);
		aimingSpriteA->SetScale(new Vector2(AIMING_WIDTH, AIMING_WIDTH));
		aimingSpriteB->SetScale(new Vector2(AIMING_WIDTH, AIMING_WIDTH));
		aimingObject->SetPosition(new Vector3((SCREEN_WIDTH - PLAYER_WIDTH * 4) / 5 * (i + 1) + PLAYER_WIDTH * (0.5f + i), SCREEN_HEIGHT / 2 + SCREEN_HEIGHT* 0.2f, 0));

		auto pendulum = new PendulumPunch();
		auto pendulumObject = new GameObject();
		pendulumObject->AddComponent(pendulum);
		auto pendulumCenterSprite = new Sprite();
		auto pendulumSprite = new Sprite();
		pendulumCenterSprite->SetTexture(pendulumCenterTexture);
		pendulumSprite->SetTexture(pendulumTexture);
		player->SetPendulum(pendulum);
		pendulum->SetSprite(pendulumSprite);
		pendulumSprite->SetScale(new Vector2(30, 30));
		pendulumCenterSprite->SetScale(new Vector2(30, 30));
		pendulumObject->SetPosition(new Vector3((SCREEN_WIDTH - PLAYER_WIDTH * 4) / 5 * (i + 1) + PLAYER_WIDTH * (0.5f + i), SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 0.2f, 0));
		pendulumObject->AddComponent(pendulumCenterSprite);
		pendulumObject->AddComponent(pendulumSprite);
	}


	//キャラスプライト周りと位置調節
	if (playerCount >= 1) {
		Player player = (Player)VariableManager::GetInstance().GetInt("player1");
		players[0]->SetPlayer(player);
	}
	if (playerCount >= 2) {
		Player player = (Player)VariableManager::GetInstance().GetInt("player2");
		players[1]->SetPlayer(player);
	}
	if (playerCount >= 3) {
		Player player = (Player)VariableManager::GetInstance().GetInt("player3");
		players[2]->SetPlayer(player);
	}
	if (playerCount >= 4) {
		Player player = (Player)VariableManager::GetInstance().GetInt("player4");
		players[3]->SetPlayer(player);
	}
}

void MegatonPunch::Start() {
	for (int i = 0; i < VariableManager::GetInstance().GetInt("playerCount"); i++) {
		ObjectManager::GetInstance().Instantiate(playerObjects[i]);
		ObjectManager::GetInstance().Instantiate(gaugeObjects[i]);
		
	}
}
