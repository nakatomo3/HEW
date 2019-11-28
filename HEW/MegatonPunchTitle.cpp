#include "MegatonPunchTitle.h"
#include "Time.h"
#include "SceneManager.h"



MegatonPunchTitle::MegatonPunchTitle(string name) : Scene(name) {
}


MegatonPunchTitle::~MegatonPunchTitle() {
}


void MegatonPunchTitle::Start() {
	ObjectManager::GetInstance().Instantiate(titleObject);


}

void MegatonPunchTitle::Load() {
	titleObject = new GameObject();
	titleSprite = new Sprite();
	titleObject->AddComponent(titleSprite);

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


	logoTexture1 = new Texture("assets/textures/MegatonPunch\/Title/PunchTitle1.png", "PunchTitle1");//　割られてない瓦割
	titleLogo1 = new Sprite(logoTexture1);
	titleObject->AddComponent(titleLogo1);
	titleLogo1->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// 画像の横、横の大きさ
	titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 1, 0));// 開始位置 x,y,z座標 /2, /1, 0

	logoTexture2 = new Texture("assets/textures/MegatonPunch\/Title/PunchTitle2.png", "PunchTitle2");//　割る人
	titleLogo2 = new Sprite(logoTexture2);
	titleObject->AddComponent(titleLogo2);
	titleLogo2->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// 画像の横、横の大きさ
	titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, -SCREEN_HEIGHT / 2, 0));// 開始位置 x,y,z座標 /2, /2, 0 ※画面外に行かないならSCREENをマイナスにしてやるといい。

	logoTexture3 = new Texture("assets/textures/MegatonPunch\/Title/PunchTitle3.png", "PunchTitle3");//　割られてる瓦割

}

void MegatonPunchTitle::UnLoad() {

}

void MegatonPunchTitle::Update() {

	timer += Time::GetInstance().GetDeltaTime();

	if (titleLogo1->GetPosition()->GetY() > SCREEN_HEIGHT / 2 && timer > 1) {// 割られてない瓦割　ゆっくり下から上
		//                                                              ↑ここでタイミングの調整
		titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, titleLogo1->GetPosition()->GetY() - 200 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        ↑ロゴの出る速さ//統一したい時はlogoSpeed
		if (titleLogo1->GetPosition()->GetY() < SCREEN_HEIGHT / 2) {
			titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}

	if (titleLogo2->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 3.3) {// 割る人　はやめに上から下
		//                                                              ↑ここでタイミングの調整
		titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, titleLogo2->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        ↑ロゴの出る速さ
		if (titleLogo2->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 動かす位置
		} 
	}
	if (timer > 3.48) {// 割られてる瓦割
		LogWriter::GetInstance().Log("hoge");// 確認ログ
		titleLogo1->SetTexture(logoTexture3);// 割られてない瓦割から割られてる瓦割に切替

	}

}