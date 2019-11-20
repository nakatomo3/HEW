#include "RunTitle.h"
#include "Time.h"


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

	/*titleObject->SetPosition(new Vector3(500, 100, 0));
	titleSprite->SetScale(new Vector2(300, 300));*/

	// 背景
	titleSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// 背景の大きさ
	titleSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 背景の位置
	titleSprite->SetColor(new Color(0, 0, 0, 0));// 黒色背景


	logoTexture1 = new Texture("assets/textures/Run/Title/RunTitle1.png", "RunTitle1");// 100m  右から左
	titleLogo1 = new Sprite(logoTexture1);
	titleObject->AddComponent(titleLogo1);
	titleLogo1->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// 画像の横、横の大きさ
	titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH /0.6, SCREEN_HEIGHT/2 , 0));// 開始位置 x,y,z座標 /, /2, 0


	logoTexture2 = new Texture("assets/textures/Run/Title/RunTitle2.png", "RunTitle2");// 走　右から左
	titleLogo2 = new Sprite(logoTexture2);
	titleObject->AddComponent(titleLogo2);
	titleLogo2->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// 画像の横、横の大きさ
	titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH /0.6, SCREEN_HEIGHT/2 , 0));// 開始位置 x,y,z座標 /0.8, /2, 0

}

void RunTitle::Update() {
	//isManualがfalseかつ説明に行く条件を満たしたらここでtrue、Instantiate
	//isManual = true;
	//Instantiate

	timer += Time::GetInstance().GetDeltaTime();

	if (titleLogo1->GetPosition()->GetX() > SCREEN_WIDTH / 2 && timer > 1) {// 100m 右から左
		//                                                             ↑ここでタイミングの調整
		titleLogo1->SetPosition(new Vector3(titleLogo1->GetPosition()->GetX() - logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 2, 0));
		//                                                                      ↑ロゴの出る速さ
		if (titleLogo1->GetPosition()->GetX() < SCREEN_WIDTH / 2) {
			titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}


	if (titleLogo2->GetPosition()->GetX() > SCREEN_WIDTH / 2 && timer > 2) {// 走 右から左
		//                                                             ↑ここでタイミングの調整
		titleLogo2->SetPosition(new Vector3(titleLogo2->GetPosition()->GetX() - logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 2, 0));
		//                                                                      ↑ロゴの出る速さ
		if (titleLogo2->GetPosition()->GetX() < SCREEN_WIDTH / 2) {
			titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}
}
