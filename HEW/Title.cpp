#include "Title.h"
#include "Time.h"
#include "Input.h"



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

	//タイトルの初期化周りはこの下に

	//とりあえず適当な値を入れている。
	titleSprite->SetScale(new Vector2(SCREEN_WIDTH , SCREEN_HEIGHT));//横,縦 の大きさ
	titleObject->SetPosition(new Vector3(SCREEN_WIDTH/2, SCREEN_HEIGHT/2,0));//x,y,z座標

	//背景
	/*backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);

	backgroundObject->SetPosition(new Vector3(1, 1, 0));
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));*/
	
}

void Title::Update() {

	//titleObject->Move(Vector3(60 * Time::GetInstance().GetDeltaTime()* SCREEN_WIDTH / 1024.0f, 0, 0));  仮のアニメーション機能

}
