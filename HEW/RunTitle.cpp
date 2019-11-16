#include "RunTitle.h"
#include "Time.h"


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

	backgroundObject = new GameObject();
	backgroundSprite = new Sprite();
	backgroundObject->AddComponent(backgroundSprite);

	backgroundObject->SetPosition(new Vector3(1, 1, 0));
	backgroundSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));

	/*titleObject->SetPosition(new Vector3(500, 100, 0));
	titleSprite->SetScale(new Vector2(300, 300));*/

	// �w�i
	titleSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// �w�i�̑傫��
	titleSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �w�i�̈ʒu
	titleSprite->SetColor(new Color(0, 0, 0, 0));// ���F�w�i


	logoTexture1 = new Texture("assets/textures/Run/Title/RunTitle1.png", "RunTitle1");// 100m  �E���獶
	titleLogo1 = new Sprite(logoTexture1);
	titleObject->AddComponent(titleLogo1);
	titleLogo1->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// �摜�̉��A���̑傫��
	titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH /0.6, SCREEN_HEIGHT/2 , 0));// �J�n�ʒu x,y,z���W /, /2, 0


	logoTexture2 = new Texture("assets/textures/Run/Title/RunTitle2.png", "RunTitle2");// ���@�E���獶
	titleLogo2 = new Sprite(logoTexture2);
	titleObject->AddComponent(titleLogo2);
	titleLogo2->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// �摜�̉��A���̑傫��
	titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH /0.6, SCREEN_HEIGHT/2 , 0));// �J�n�ʒu x,y,z���W /0.8, /2, 0

}

void RunTitle::Update() {
	//isManual��false�������ɍs�������𖞂������炱����true�AInstantiate
	//isManual = true;
	//Instantiate

	timer += Time::GetInstance().GetDeltaTime();

	if (titleLogo1->GetPosition()->GetX() > SCREEN_WIDTH / 2 && timer > 1) {// 100m �E���獶
		//                                                             �������Ń^�C�~���O�̒���
		titleLogo1->SetPosition(new Vector3(titleLogo1->GetPosition()->GetX() - logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 2, 0));
		//                                                                      �����S�̏o�鑬��
		if (titleLogo1->GetPosition()->GetX() < SCREEN_WIDTH / 2) {
			titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}


	if (titleLogo2->GetPosition()->GetX() > SCREEN_WIDTH / 2 && timer > 2) {// �� �E���獶
		//                                                             �������Ń^�C�~���O�̒���
		titleLogo2->SetPosition(new Vector3(titleLogo2->GetPosition()->GetX() - logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 2, 0));
		//                                                                      �����S�̏o�鑬��
		if (titleLogo2->GetPosition()->GetX() < SCREEN_WIDTH / 2) {
			titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}
}
