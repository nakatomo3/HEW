#include "Title.h"



Title::Title(string name) : Scene(name){

}


Title::~Title() {
}

void Title::Start() {
	ObjectManager::GetInstance().Instantiate(titleObjct);
}

void Title::Load() {
	titleObjct = new GameObject();
	titleSprite = new Sprite();
	titleObjct->AddComponent(titleSprite);
	titleAnimation = new TitleAnimation();
	titleObjct->AddComponent(titleAnimation);

	//ƒ^ƒCƒgƒ‹‚Ì‰Šú‰»ü‚è‚Í‚±‚Ì‰º‚É

}

void Title::Update() {

}
