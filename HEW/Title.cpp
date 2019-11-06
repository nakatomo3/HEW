#include "Title.h"



Title::Title(string name) : Scene(name){

}


Title::~Title() {
}

void Title::Start() {
	ObjectManager::GetInstance().Instantiate(titleObject);
}

void Title::Load() {
	titleObject = new GameObject();
	titleSprite = new Sprite();
	titleObject->AddComponent(titleSprite);
	titleAnimation = new TitleAnimation();
	titleObject->AddComponent(titleAnimation);

	//�^�C�g���̏���������͂��̉���
}

void Title::Update() {

}
