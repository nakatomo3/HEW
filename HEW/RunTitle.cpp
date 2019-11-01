#include "RunTitle.h"


RunTitle::RunTitle(string name) : Scene(name){

}

RunTitle::~RunTitle() {
}

void RunTitle::Start() {
	//�����̃I�u�W�F�N�g�͏����𖞂������Ƃ��Ɉ�񂾂�Instantiate
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
	//isManual��false�������ɍs�������𖞂������炱����true�AInstantiate
	//isManual = true;
	//Instantiate
}
