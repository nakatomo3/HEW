#include "RunTitle.h"


RunTitle::RunTitle(string name) : Scene(name){

}

RunTitle::~RunTitle() {
}

void RunTitle::Start() {
	//説明のオブジェクトは条件を満たしたときに一回だけInstantiate
	ObjectManager::GetInstance().Instantiate(titleObject);
}

void RunTitle::Load() {
	titleObject = new GameObject();
	titleSprite = new Sprite();
	runTitleAnimation = new RunTitleAnimation();
	titleObject->AddComponent(titleSprite);
	titleObject->AddComponent(runTitleAnimation);

	manualObject = new GameObject();
	manualSprite = new Sprite();
	runManual = new RunManual();
	manualObject->AddComponent(manualSprite);
	manualObject->AddComponent(runManual);

	backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);

	backgroundObject->SetPosition(new Vector3(1, 1, 0));
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));

	titleObject->SetPosition(new Vector3(500, 100, 0));
	titleSprite->SetScale(new Vector2(300, 300));

}

void RunTitle::Update() {
	//isManualがfalseかつ説明に行く条件を満たしたらここでtrue、Instantiate
	//isManual = true;
	//Instantiate
}
