#include "MegatonPunch.h"
#include "Setting.h"
#include "Time.h"
#include "SceneManager.h"

MegatonPunch::MegatonPunch(string name) : Scene(name) {

}


MegatonPunch::~MegatonPunch() {
}

void MegatonPunch::Load() {

	playerCount = VariableManager::GetInstance().GetInt("playerCount");
	gaugeTexture = new Texture("assets/textures/Run/UI/gauge.png");

	aimingTexture = new Texture("assets/textures/MegatonPunch/UI/Aiming.png");
	aimingWhiteTexture = new Texture("assets/textures/MegatonPunch/UI/AimingWhite.png");

	pendulumCenterTexture = new Texture("assets/textures/MegatonPunch/UI/PendulumCenter.png");
	pendulumTexture = new Texture("assets/textures/MegatonPunch/UI/Pendulum.png");
	pendulumWhiteTexture = new Texture("assets/textures/MegatonPunch/UI/PendulumWhite.png");

	earth = new Texture("assets/textures/MegatonPunch/UI/Earth.png");
	breaking = new Texture("assets/textures/MegatonPunch/UI/Breaking.png");

	breakingEarthTexture = new Texture("assets/textures/MegatonPunch/UI/BreakingEarth.png");
	backgroundTexture = new Texture("assets/textures/MegatonPunch/UI/backgroundTexture.png");

	const float PLAYER_WIDTH = SCREEN_WIDTH / 10;

	const float GAUGE_WIDTH = SCREEN_WIDTH / 20;
	const float GAUGE_HEIGHT = SCREEN_HEIGHT / 5 * 2;

	const float AIMING_WIDTH = SCREEN_WIDTH / 15;

	for (int i = 0; i < playerCount; i++) {
		auto player = new PlayerPunch();
		players.push_back(player);
		auto playerObject = new GameObject();
		playerObjects.push_back(playerObject);
		playerObject->AddComponent(player);
		playerObject->SetPosition(new Vector3((SCREEN_WIDTH - PLAYER_WIDTH * 4) / 5 * (i + 1) + PLAYER_WIDTH * (0.5f + i), SCREEN_HEIGHT / 2, 0));
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
		gaugeObject->SetPosition(new Vector3((SCREEN_WIDTH - PLAYER_WIDTH * 4) / 5 * (i + 1) + PLAYER_WIDTH * (0.5f + i) - SCREEN_WIDTH / 10, SCREEN_HEIGHT / 3 * 2, 0));
		gauge->SetSprite(gaugeSprite);
		gaugeSprite->SetPosition(new Vector3(0, -SCREEN_HEIGHT * 0.01f, 0));
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
		aimingObject->SetPosition(new Vector3((SCREEN_WIDTH - PLAYER_WIDTH * 4) / 5 * (i + 1) + PLAYER_WIDTH * (0.5f + i), SCREEN_HEIGHT / 2 + SCREEN_HEIGHT * 0.2f, 0));
		aiming->SetNormalTexture(aimingTexture);
		aiming->SetWhiteTexture(aimingWhiteTexture);

		auto pendulum = new PendulumPunch();
		auto pendulumObject = new GameObject();
		pendulumObject->AddComponent(pendulum);
		auto pendulumCenterSprite = new Sprite();
		auto pendulumSprite = new Sprite();
		pendulumCenterSprite->SetTexture(pendulumCenterTexture);
		pendulumCenterSprite->SetColor(new Color(255, 50, 50));
		pendulumSprite->SetTexture(pendulumTexture);
		player->SetPendulum(pendulum);
		pendulum->SetSprite(pendulumSprite);
		pendulumSprite->SetScale(new Vector2(30, 30));
		pendulumCenterSprite->SetScale(new Vector2(30, 30));
		pendulumObject->SetPosition(new Vector3((SCREEN_WIDTH - PLAYER_WIDTH * 4) / 5 * (i + 1) + PLAYER_WIDTH * (0.5f + i), SCREEN_HEIGHT / 2 - SCREEN_HEIGHT * 0.2f, 0));
		pendulumObject->AddComponent(pendulumCenterSprite);
		pendulumObject->AddComponent(pendulumSprite);

		pendulum->SetNormalTexture(pendulumTexture);
		pendulum->SetWhiteTexutre(pendulumWhiteTexture);

		Text* text = new Text();
		text->SetActive(false);
		playerObject->AddComponent(text);
		texts.emplace_back(text);
		player->SetText(text);
		text->SetPosition(new Vector3(-SCREEN_WIDTH * 0.1f, -SCREEN_HEIGHT * 0.2, 0));
		text->isOutline = true;
		text->isBeautifulOutline = true;
		text->SetOutlineColor(new Color(0, 0, 0, 255));
		text->outlineDistance = SCREEN_HEIGHT * 0.007f;
		text->SetSize(SCREEN_HEIGHT*0.1f);

		GameObject* breakingEarth = new GameObject();
		breakingEarths.emplace_back(breakingEarth);
		Sprite* breakingEarthSprite = new Sprite(breakingEarthTexture);
		breakingEarthSprites.emplace_back(breakingEarthSprite);
		breakingEarth->AddComponent(breakingEarthSprite);
		breakingEarthSprite->SetTextureScale(1, 0);
		breakingEarthSprite->SetScale(new Vector2(SCREEN_WIDTH * 0.1f, SCREEN_HEIGHT * 0.0f));
		breakingEarthSprite->SetPosition(new Vector3(SCREEN_WIDTH * 0.48f + SCREEN_WIDTH * 0.04f * i / (playerCount - 1), SCREEN_HEIGHT * 0.063f));
		breakingEarthSprite->SetCriterion(UP);
		player->SetBreaking(breakingEarthSprite);
	}

	earthObject = new GameObject();
	earthSprite = new Sprite(earth);
	earthObject->AddComponent(earthSprite);
	earthSprite->SetActive(false);
	earthSprite->SetScale(new Vector2(SCREEN_HEIGHT * 0.9, SCREEN_HEIGHT * 0.9));
	earthSprite->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, -0.01));

	breakingSprite = new Sprite(breaking);
	breakingSprite->SetScale(new Vector2(SCREEN_WIDTH * 1.5, SCREEN_WIDTH * 0.75));
	breakingSprite->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, -0.01));
	breakingSprite->SetActive(false);
	earthObject->AddComponent(breakingSprite);

	background = new GameObject();
	backgroundSprite = new Sprite(backgroundTexture);
	background->AddComponent(backgroundSprite);
	backgroundSprite->SetActive(false);
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));
	backgroundSprite->SetPosition(new Vector3(SCREEN_CENTER_X, SCREEN_CENTER_Y, -0.0));


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

void MegatonPunch::UnLoad() {
	for (int i = 0; i < VariableManager::GetInstance().GetInt("playerCount"); i++) {
		ObjectManager::GetInstance().Destroy(playerObjects[i]);
		ObjectManager::GetInstance().Destroy(breakingEarths[i]);
	}
	ObjectManager::GetInstance().Destroy(earthObject);
	ObjectManager::GetInstance().Destroy(background);
	breakingEarths.clear();
}

void MegatonPunch::Start() {
	for (int i = 0; i < VariableManager::GetInstance().GetInt("playerCount"); i++) {
		ObjectManager::GetInstance().Instantiate(playerObjects[i]);
		ObjectManager::GetInstance().Instantiate(gaugeObjects[i]);
		ObjectManager::GetInstance().Instantiate(breakingEarths[i]);
	}
	ObjectManager::GetInstance().Instantiate(earthObject);
	ObjectManager::GetInstance().Instantiate(background);
}

void MegatonPunch::Update() {
	bool isAllWaiting = true;
	for (int i = 0; i < playerCount; i++) {
		if (isWaitings[i] == false) {
			isAllWaiting = false;
			break;
		}
	}

	if (isAllWaiting == true && isBreaking == false) {
		for (int i = 0; i < playerCount; i++) {
			players[i]->SetBreakingFlag();
		}
		isBreaking = true;
	}

	if (isBreaking == true) {
		backgroundSprite->SetActive(true);
		earthSprite->SetActive(true);
		timer += Time::GetInstance().GetDeltaTime();
		if(timer >= 10){
			SceneManager::GetInstance().LoadScene("megatonPunchResult");
		} else if (timer >= 1) {
			breakingSprite->SetActive(true);
		}
	}
}

void MegatonPunch::SetWaiting(int number) {
	isWaitings[number] = true;
}
