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

	// �w�i
	titleSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// �w�i�̑傫��
	titleSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �w�i�̈ʒu
	titleSprite->SetColor(new Color(0, 0, 0, 0));// ���F�w�i

	//----------------------------------------------------------------------------------------------�������ʔ��\��
	logoTexture1 = new Texture("assets/textures/TotalResult/�������ʔ��\���S1.png", "�������ʔ��\���S1");//"��"
	totalresultLogo = new Sprite(logoTexture1);
	titleObject->AddComponent(totalresultLogo);
	totalresultLogo->SetScale(new Vector2(SD_WIDTH *4.0f, SD_WIDTH *4.0f));// �摜�̉��A���̑傫��
	totalresultLogo->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �J�n�ʒu x,y,z���W

	totalresultLogo1 = new Sprite(logoTexture1);
	titleObject->AddComponent(totalresultLogo1);
	totalresultLogo1->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// �摜�̉��A���̑傫��
	totalresultLogo1->SetPosition(new Vector3(SCREEN_WIDTH *0.09, SCREEN_HEIGHT*-0.2, 0));// �J�n�ʒu x,y,z���W


	logoTexture2 = new Texture("assets/textures/TotalResult/�������ʔ��\���S2.png", "�������ʔ��\���S2");//"��"
	totalresultLogo2 = new Sprite(logoTexture2);
	titleObject->AddComponent(totalresultLogo2);
	totalresultLogo2->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// �摜�̉��A���̑傫��
	totalresultLogo2->SetPosition(new Vector3(SCREEN_WIDTH *0.255, SCREEN_HEIGHT*-0.2, 0));// �J�n�ʒu x,y,z���W


	logoTexture3 = new Texture("assets/textures/TotalResult/�������ʔ��\���S3.png", "�������ʔ��\���S3");//"��"
	totalresultLogo3 = new Sprite(logoTexture3);
	titleObject->AddComponent(totalresultLogo3);
	totalresultLogo3->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// �摜�̉��A���̑傫��
	totalresultLogo3->SetPosition(new Vector3(SCREEN_WIDTH *0.42, SCREEN_HEIGHT *-0.2, 0));// �J�n�ʒu x,y,z���W


	logoTexture4 = new Texture("assets/textures/TotalResult/�������ʔ��\���S4.png", "�������ʔ��\���S4");//"��"
	totalresultLogo4 = new Sprite(logoTexture4);
	titleObject->AddComponent(totalresultLogo4);
	totalresultLogo4->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// �摜�̉��A���̑傫��
	totalresultLogo4->SetPosition(new Vector3(SCREEN_WIDTH *0.58, SCREEN_HEIGHT *-0.2, 0));// �J�n�ʒu x,y,z���W


	logoTexture5 = new Texture("assets/textures/TotalResult/�������ʔ��\���S5.png", "�������ʔ��\���S5");//"��"
	totalresultLogo5 = new Sprite(logoTexture5);
	titleObject->AddComponent(totalresultLogo5);
	totalresultLogo5->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// �摜�̉��A���̑傫��
	totalresultLogo5->SetPosition(new Vector3(SCREEN_WIDTH *0.74, SCREEN_HEIGHT *-0.2, 0));// �J�n�ʒu x,y,z���W


	logoTexture6 = new Texture("assets/textures/TotalResult/�������ʔ��\���S6.png", "�������ʔ��\���S6");//"�\"
	totalresultLogo6 = new Sprite(logoTexture6);
	titleObject->AddComponent(totalresultLogo6);
	totalresultLogo6->SetScale(new Vector2(SD_WIDTH *2.0f, SD_WIDTH *2.0f));// �摜�̉��A���̑傫��
	totalresultLogo6->SetPosition(new Vector3(SCREEN_WIDTH *0.91, SCREEN_HEIGHT *-0.2, 0));// �J�n�ʒu x,y,z���W


	//----------------------------------------------------------------------------------------------�������ʔ��\��
}

void TotalResult::Start() {
	ObjectManager::GetInstance().Instantiate(titleObject);
}

void TotalResult::UnLoad() {
	ObjectManager::GetInstance().Destroy(titleObject);// �I�u�W�F�N�g�������Ă���(�������Ȃ��Ɖ�ʂɎc���đJ�ڂ����Ⴄ����)
	ObjectManager::GetInstance().Destroy(backgroundObject);
}

void TotalResult::Update() {

	timer += Time::GetInstance().GetDeltaTime();

	//�����N�\�f�J���S�ؑ։��o--------------------
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
	
	//������[�������ʔ��\]���S���o---------------------------------------------------------------------------------------------------------------------------
	//1.5�b����

	//��
	if (totalresultLogo1->GetPosition()->GetY() < SCREEN_HEIGHT /2 && timer > 2.5f) {//�͂�߂ɏォ�牺
		//                                                              �������Ń^�C�~���O�̒���
		totalresultLogo1->SetPosition(new Vector3(SCREEN_WIDTH *0.09, totalresultLogo1->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        �����S�̏o�鑬��
		if (totalresultLogo1->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo1->SetPosition(new Vector3(SCREEN_WIDTH *0.09, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}

	//��
	if (totalresultLogo2->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 2.8f) {//�͂�߂ɏォ�牺
		//                                                              �������Ń^�C�~���O�̒���
		totalresultLogo2->SetPosition(new Vector3(SCREEN_WIDTH *0.255, totalresultLogo2->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        �����S�̏o�鑬��
		if (totalresultLogo2->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo2->SetPosition(new Vector3(SCREEN_WIDTH *0.255, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}

	//��
	if (totalresultLogo3->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 3.1f) {//�͂�߂ɏォ�牺
		//                                                              �������Ń^�C�~���O�̒���
		totalresultLogo3->SetPosition(new Vector3(SCREEN_WIDTH *0.42, totalresultLogo3->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        �����S�̏o�鑬��
		if (totalresultLogo3->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo3->SetPosition(new Vector3(SCREEN_WIDTH *0.42, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}

	//��
	if (totalresultLogo4->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 3.4f) {//�͂�߂ɏォ�牺
		//                                                              �������Ń^�C�~���O�̒���
		totalresultLogo4->SetPosition(new Vector3(SCREEN_WIDTH *0.58, totalresultLogo4->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        �����S�̏o�鑬��
		if (totalresultLogo4->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo4->SetPosition(new Vector3(SCREEN_WIDTH *0.58, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}

	//��
	if (totalresultLogo5->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 3.7f) {//�͂�߂ɏォ�牺
		//                                                              �������Ń^�C�~���O�̒���
		totalresultLogo5->SetPosition(new Vector3(SCREEN_WIDTH *0.74, totalresultLogo5->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        �����S�̏o�鑬��
		if (totalresultLogo5->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo5->SetPosition(new Vector3(SCREEN_WIDTH *0.74, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}

	//�\
	if (totalresultLogo6->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 4.0f) {//�͂�߂ɏォ�牺
		//                                                              �������Ń^�C�~���O�̒���
		totalresultLogo6->SetPosition(new Vector3(SCREEN_WIDTH *0.91, totalresultLogo6->GetPosition()->GetY() + 4000 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        �����S�̏o�鑬��
		if (totalresultLogo6->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			totalresultLogo6->SetPosition(new Vector3(SCREEN_WIDTH *0.91, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}

	//------------------------------------------------------------------------------------------------------------------------------------------------------

}