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
}

void RunTitle::Update() {
	//isManualがfalseかつ説明に行く条件を満たしたらここでtrue、Instantiate
	//isManual = true;
	//Instantiate
}
