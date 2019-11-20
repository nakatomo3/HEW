#include "Title.h"
#include "Time.h"
#include "Input.h"
#include "SceneManager.h"

Title::Title(string name) : Scene(name) {

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

	// 背景
	titleSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// 背景の大きさ
	titleSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 背景の位置
	titleSprite->SetColor(new Color(0, 0, 0, 0));// 黒色背景

	//タイトルロゴ
	logoTexture5 = new Texture("assets/textures/Title/Title5.png", "Title5");// 黒逆三角　上から下
	titleLogo5 = new Sprite(logoTexture5);
	titleObject->AddComponent(titleLogo5);
	titleLogo5->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// 画像の横、横の大きさ
	titleLogo5->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 15, 0));// 開始位置 x,y,z座標 /2, /15, 0


	logoTexture1 = new Texture("assets/textures/Title/Title1.png", "Title1");// 爆裂  左から右
	titleLogo1 = new Sprite(logoTexture1);
	titleObject->AddComponent(titleLogo1);
	titleLogo1->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// 画像の横、横の大きさ
	titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 18, SCREEN_HEIGHT / 2, 0));// 開始位置 x,y,z座標 /18, /2, 0


	logoTexture2 = new Texture("assets/textures/Title/Title2.png", "Title2");// 超人　右から左
	titleLogo2 = new Sprite(logoTexture2);
	titleObject->AddComponent(titleLogo2);
	titleLogo2->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// 画像の横、横の大きさ
	titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 1, SCREEN_HEIGHT / 2, 0));// 開始位置 x,y,z座標 /1, /2, 0


	logoTexture3 = new Texture("assets/textures/Title/Title3.png", "Title3");// オリン　下から上
	titleLogo3 = new Sprite(logoTexture3);
	titleObject->AddComponent(titleLogo3);
	titleLogo3->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// 画像の横、横の大きさ
	titleLogo3->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT /0.8, 0));// 開始位置 x,y,z座標 /2, /0.8, 0


	logoTexture4 = new Texture("assets/textures/Title/Title4.png", "Title4");// ピック　下から上
	titleLogo4 = new Sprite(logoTexture4);
	titleObject->AddComponent(titleLogo4);
	titleLogo4->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// 画像の横、横の大きさ
	titleLogo4->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 0.8, 0));// 開始位置 x,y,z座標 /2, /0.8, 0


	logoTexture6 = new Texture("assets/textures/Title/Title6.png", "Title6");// 白マッチョ　上から下
	titleLogo6 = new Sprite(logoTexture6);
	titleObject->AddComponent(titleLogo6);
	titleLogo6->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// 画像の横、横の大きさ
	titleLogo6->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5, 0));// 開始位置 x,y,z座標 /2, /5, 0

	//ゲームオブジェ1　スプライト5　スクリプト1

}

void Title::Update() {

	

	timer += Time::GetInstance().GetDeltaTime();


	if (titleLogo1->GetPosition()->GetX() < SCREEN_WIDTH / 2 && timer > 3) {// 爆裂 左から右
		//                                                             ↑ここでタイミングの調整
		titleLogo1->SetPosition(new Vector3(titleLogo1->GetPosition()->GetX() + logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 2, 0));
		//                                                                      ↑ロゴの出る速さ
		if (titleLogo1->GetPosition()->GetX() > SCREEN_WIDTH / 2) {
			titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}


	if (titleLogo2->GetPosition()->GetX() > SCREEN_WIDTH / 2 && timer > 4) {// 超人 右から左
		//                                                             ↑ここでタイミングの調整
		titleLogo2->SetPosition(new Vector3(titleLogo2->GetPosition()->GetX() - logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 2, 0));
		//                                                                      ↑ロゴの出る速さ
		if (titleLogo2->GetPosition()->GetX() < SCREEN_WIDTH / 2) {
			titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}


	if (titleLogo3->GetPosition()->GetY() > SCREEN_HEIGHT / 2 && timer > 5) {// オリン 下から上
		//                                                              ↑ここでタイミングの調整
		titleLogo3->SetPosition(new Vector3( SCREEN_WIDTH/2,titleLogo3->GetPosition()->GetY() - logoSpeed * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                      ↑ロゴの出る速さ
		if (titleLogo3->GetPosition()->GetY() < SCREEN_HEIGHT / 2) {
			titleLogo3->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}


	if (titleLogo4->GetPosition()->GetY() > SCREEN_HEIGHT / 2 && timer > 6) {// ピック 下から上
		//                                                              ↑ここでタイミングの調整
		titleLogo4->SetPosition(new Vector3( SCREEN_WIDTH / 2,titleLogo4->GetPosition()->GetY() - logoSpeed * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        ↑ロゴの出る速さ
		if (titleLogo4->GetPosition()->GetY() < SCREEN_HEIGHT / 2) {
			titleLogo4->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}

	if (titleLogo5->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 1) {// 黒逆三角 上から下
		//                                                              ↑ここでタイミングの調整
		titleLogo5->SetPosition(new Vector3(SCREEN_WIDTH / 2, titleLogo5->GetPosition()->GetY() + logoSpeed * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        ↑ロゴの出る速さ
		if (titleLogo5->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			titleLogo5->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}

	if (titleLogo6->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 1) {// 白マッチョ 上から下
		//                                                              ↑ここでタイミングの調整
		titleLogo6->SetPosition(new Vector3(SCREEN_WIDTH / 2, titleLogo6->GetPosition()->GetY() + 200 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        ↑ロゴの出る速さ
		if (titleLogo6->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			titleLogo6->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}

	if (Input::GetInstance().GetKey(DIK_Q)) {
		SceneManager::GetInstance().LoadScene("runTitle");
	}

}

void Title::UnLoad() {
	ObjectManager::GetInstance().Destroy(titleObject);
}
