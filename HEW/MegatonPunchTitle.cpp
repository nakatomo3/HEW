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

	// �w�i
	titleSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// �w�i�̑傫��
	titleSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �w�i�̈ʒu
	titleSprite->SetColor(new Color(0, 0, 0, 0));// ���F�w�i


	logoTexture1 = new Texture("assets/textures/MegatonPunch\/Title/PunchTitle1.png", "PunchTitle1");//�@�����ĂȂ�����
	titleLogo1 = new Sprite(logoTexture1);
	titleObject->AddComponent(titleLogo1);
	titleLogo1->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// �摜�̉��A���̑傫��
	titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 1, 0));// �J�n�ʒu x,y,z���W /2, /1, 0

	logoTexture2 = new Texture("assets/textures/MegatonPunch\/Title/PunchTitle2.png", "PunchTitle2");//�@����l
	titleLogo2 = new Sprite(logoTexture2);
	titleObject->AddComponent(titleLogo2);
	titleLogo2->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_HEIGHT));// �摜�̉��A���̑傫��
	titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, -SCREEN_HEIGHT / 2, 0));// �J�n�ʒu x,y,z���W /2, /2, 0 ����ʊO�ɍs���Ȃ��Ȃ�SCREEN���}�C�i�X�ɂ��Ă��Ƃ����B

	logoTexture3 = new Texture("assets/textures/MegatonPunch\/Title/PunchTitle3.png", "PunchTitle3");//�@�����Ă銢��

}

void MegatonPunchTitle::UnLoad() {

}

void MegatonPunchTitle::Update() {

	timer += Time::GetInstance().GetDeltaTime();

	if (titleLogo1->GetPosition()->GetY() > SCREEN_HEIGHT / 2 && timer > 1) {// �����ĂȂ������@������艺�����
		//                                                              �������Ń^�C�~���O�̒���
		titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, titleLogo1->GetPosition()->GetY() - 200 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        �����S�̏o�鑬��//���ꂵ��������logoSpeed
		if (titleLogo1->GetPosition()->GetY() < SCREEN_HEIGHT / 2) {
			titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}

	if (titleLogo2->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 3.3) {// ����l�@�͂�߂ɏォ�牺
		//                                                              �������Ń^�C�~���O�̒���
		titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, titleLogo2->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        �����S�̏o�鑬��
		if (titleLogo2->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �������ʒu
		} 
	}
	if (timer > 3.48) {// �����Ă銢��
		LogWriter::GetInstance().Log("hoge");// �m�F���O
		titleLogo1->SetTexture(logoTexture3);// �����ĂȂ��������犄���Ă銢���ɐؑ�

	}

}