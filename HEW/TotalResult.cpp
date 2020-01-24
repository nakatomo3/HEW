#include "TotalResult.h"
#include "Time.h"
#include "SceneManager.h"

TotalResult::TotalResult(string name) : Scene(name){

}

TotalResult::~TotalResult() {
}

void TotalResult::Load() {
	titleObject = new GameObject();
	titleSprite = new Sprite();
	titleObject->AddComponent(titleSprite);

	backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);

	backgroundObject->SetPosition(new Vector3(1, 1, 0));
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));

	// 背景
	titleSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// 背景の大きさ
	titleSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 背景の位置
	titleSprite->SetColor(new Color(0, 0, 0, 0));// 黒色背景

	//----------------------------------------------------------------------------------------------総合結果発表↓
	logoTexture1 = new Texture("assets/textures/TotalResult/総合結果発表ロゴ1.png", "総合結果発表ロゴ1");//"総"
	totalresultLogo = new Sprite(logoTexture1);
	titleObject->AddComponent(totalresultLogo);
	totalresultLogo->SetScale(new Vector2(SD_WIDTH *4.0f, SD_WIDTH *4.0f));// 画像の横、横の大きさ
	totalresultLogo->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// 開始位置 x,y,z座標

	totalresultLogo1 = new Sprite(logoTexture1);
	titleObject->AddComponent(totalresultLogo1);
	totalresultLogo1->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// 画像の横、横の大きさ
	totalresultLogo1->SetPosition(new Vector3(SCREEN_WIDTH *0.09, SCREEN_HEIGHT*-0.2, 0));// 開始位置 x,y,z座標


	logoTexture2 = new Texture("assets/textures/TotalResult/総合結果発表ロゴ2.png", "総合結果発表ロゴ2");//"合"
	totalresultLogo2 = new Sprite(logoTexture2);
	titleObject->AddComponent(totalresultLogo2);
	totalresultLogo2->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// 画像の横、横の大きさ
	totalresultLogo2->SetPosition(new Vector3(SCREEN_WIDTH *0.255, SCREEN_HEIGHT*-0.2, 0));// 開始位置 x,y,z座標


	logoTexture3 = new Texture("assets/textures/TotalResult/総合結果発表ロゴ3.png", "総合結果発表ロゴ3");//"結"
	totalresultLogo3 = new Sprite(logoTexture3);
	titleObject->AddComponent(totalresultLogo3);
	totalresultLogo3->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// 画像の横、横の大きさ
	totalresultLogo3->SetPosition(new Vector3(SCREEN_WIDTH *0.42, SCREEN_HEIGHT *-0.2, 0));// 開始位置 x,y,z座標


	logoTexture4 = new Texture("assets/textures/TotalResult/総合結果発表ロゴ4.png", "総合結果発表ロゴ4");//"果"
	totalresultLogo4 = new Sprite(logoTexture4);
	titleObject->AddComponent(totalresultLogo4);
	totalresultLogo4->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// 画像の横、横の大きさ
	totalresultLogo4->SetPosition(new Vector3(SCREEN_WIDTH *0.58, SCREEN_HEIGHT *-0.2, 0));// 開始位置 x,y,z座標


	logoTexture5 = new Texture("assets/textures/TotalResult/総合結果発表ロゴ5.png", "総合結果発表ロゴ5");//"発"
	totalresultLogo5 = new Sprite(logoTexture5);
	titleObject->AddComponent(totalresultLogo5);
	totalresultLogo5->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// 画像の横、横の大きさ
	totalresultLogo5->SetPosition(new Vector3(SCREEN_WIDTH *0.74, SCREEN_HEIGHT *-0.2, 0));// 開始位置 x,y,z座標


	logoTexture6 = new Texture("assets/textures/TotalResult/総合結果発表ロゴ6.png", "総合結果発表ロゴ6");//"表"
	totalresultLogo6 = new Sprite(logoTexture6);
	titleObject->AddComponent(totalresultLogo6);
	totalresultLogo6->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// 画像の横、横の大きさ
	totalresultLogo6->SetPosition(new Vector3(SCREEN_WIDTH *0.91, SCREEN_HEIGHT *-0.2, 0));// 開始位置 x,y,z座標


	//----------------------------------------------------------------------------------------------総合結果発表↑
}

void TotalResult::Start() {
	ObjectManager::GetInstance().Instantiate(titleObject);
}

void TotalResult::UnLoad() {
	ObjectManager::GetInstance().Destroy(titleObject);// オブジェクトを消している(こうしないと画面に残って遷移しちゃうから)
	ObjectManager::GetInstance().Destroy(backgroundObject);
}

void TotalResult::Update() {

	timer += Time::GetInstance().GetDeltaTime();

	//中央クソデカロゴ切替演出--------------------
	if (timer > 0.5f) {
		totalresultLogo->SetTexture(logoTexture2);
	}
	if (timer > 0.7f) {
		totalresultLogo->SetTexture(logoTexture3);
	}
	if (timer > 0.9f) {
		totalresultLogo->SetTexture(logoTexture4);
	}
	if (timer > 1.1f) {
		totalresultLogo->SetTexture(logoTexture5);
	}
	if (timer > 1.3f) {
		totalresultLogo->SetTexture(logoTexture6);
	}
	if (timer > 1.5f) {
		totalresultLogo->SetActive(false);
	}
	//--------------------------------------------
	
	//横並び[総合結果発表]ロゴ演出---------------------------------------------------------------------------------------------------------------------------
	//1.5秒ごと

	//総
	if (totalresultLogo1->GetPosition()->GetY() < SCREEN_HEIGHT /2 && timer > 2.5f) {//はやめに上から下
		//                                                              ↑ここでタイミングの調整
		totalresultLogo1->SetPosition(new Vector3(SCREEN_WIDTH *0.09, totalresultLogo1->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        ↑ロゴの出る速さ
		if (totalresultLogo1->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo1->SetPosition(new Vector3(SCREEN_WIDTH *0.09, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}

	//合
	if (totalresultLogo2->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 2.8f) {//はやめに上から下
		//                                                              ↑ここでタイミングの調整
		totalresultLogo2->SetPosition(new Vector3(SCREEN_WIDTH *0.255, totalresultLogo2->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        ↑ロゴの出る速さ
		if (totalresultLogo2->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo2->SetPosition(new Vector3(SCREEN_WIDTH *0.255, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}

	//結
	if (totalresultLogo3->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 3.1f) {//はやめに上から下
		//                                                              ↑ここでタイミングの調整
		totalresultLogo3->SetPosition(new Vector3(SCREEN_WIDTH *0.42, totalresultLogo3->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        ↑ロゴの出る速さ
		if (totalresultLogo3->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo3->SetPosition(new Vector3(SCREEN_WIDTH *0.42, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}

	//果
	if (totalresultLogo4->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 3.4f) {//はやめに上から下
		//                                                              ↑ここでタイミングの調整
		totalresultLogo4->SetPosition(new Vector3(SCREEN_WIDTH *0.58, totalresultLogo4->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        ↑ロゴの出る速さ
		if (totalresultLogo4->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo4->SetPosition(new Vector3(SCREEN_WIDTH *0.58, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}

	//発
	if (totalresultLogo5->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 3.7f) {//はやめに上から下
		//                                                              ↑ここでタイミングの調整
		totalresultLogo5->SetPosition(new Vector3(SCREEN_WIDTH *0.74, totalresultLogo5->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        ↑ロゴの出る速さ
		if (totalresultLogo5->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo5->SetPosition(new Vector3(SCREEN_WIDTH *0.74, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}

	//表
	if (totalresultLogo6->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 4.0f) {//はやめに上から下
		//                                                              ↑ここでタイミングの調整
		totalresultLogo6->SetPosition(new Vector3(SCREEN_WIDTH *0.91, totalresultLogo6->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        ↑ロゴの出る速さ
		if (totalresultLogo6->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo6->SetPosition(new Vector3(SCREEN_WIDTH *0.91, SCREEN_HEIGHT / 2, 0));// 動かす位置
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------

}