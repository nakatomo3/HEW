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

	//タイトルの初期化周りはこの下に

}

void Title::Update() {

}
