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

	//�^�C�g���̏���������͂��̉���

	// �w�i
	titleSprite->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// �w�i�̑傫��
	titleSprite->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �w�i�̈ʒu
	titleSprite->SetColor(new Color(0, 0, 0, 0));// ���F�w�i

	//�^�C�g�����S
	logoTexture5 = new Texture("assets/textures/Title/Title5.png", "Title5");// ���t�O�p�@�ォ�牺
	titleLogo5 = new Sprite(logoTexture5);
	titleObject->AddComponent(titleLogo5);
	titleLogo5->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// �摜�̉��A���̑傫��
	titleLogo5->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 15, 0));// �J�n�ʒu x,y,z���W /2, /15, 0


	logoTexture1 = new Texture("assets/textures/Title/Title1.png", "Title1");// ����  ������E
	titleLogo1 = new Sprite(logoTexture1);
	titleObject->AddComponent(titleLogo1);
	titleLogo1->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// �摜�̉��A���̑傫��
	titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 18, SCREEN_HEIGHT / 2, 0));// �J�n�ʒu x,y,z���W /18, /2, 0


	logoTexture2 = new Texture("assets/textures/Title/Title2.png", "Title2");// ���l�@�E���獶
	titleLogo2 = new Sprite(logoTexture2);
	titleObject->AddComponent(titleLogo2);
	titleLogo2->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// �摜�̉��A���̑傫��
	titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 1, SCREEN_HEIGHT / 2, 0));// �J�n�ʒu x,y,z���W /1, /2, 0


	logoTexture3 = new Texture("assets/textures/Title/Title3.png", "Title3");// �I�����@�������
	titleLogo3 = new Sprite(logoTexture3);
	titleObject->AddComponent(titleLogo3);
	titleLogo3->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// �摜�̉��A���̑傫��
	titleLogo3->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT /0.8, 0));// �J�n�ʒu x,y,z���W /2, /0.8, 0


	logoTexture4 = new Texture("assets/textures/Title/Title4.png", "Title4");// �s�b�N�@�������
	titleLogo4 = new Sprite(logoTexture4);
	titleObject->AddComponent(titleLogo4);
	titleLogo4->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// �摜�̉��A���̑傫��
	titleLogo4->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 0.8, 0));// �J�n�ʒu x,y,z���W /2, /0.8, 0


	logoTexture6 = new Texture("assets/textures/Title/Title6.png", "Title6");// ���}�b�`���@�ォ�牺
	titleLogo6 = new Sprite(logoTexture6);
	titleObject->AddComponent(titleLogo6);
	titleLogo6->SetScale(new Vector2(SCREEN_WIDTH, SCREEN_WIDTH));// �摜�̉��A���̑傫��
	titleLogo6->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 5, 0));// �J�n�ʒu x,y,z���W /2, /5, 0

	//�Q�[���I�u�W�F1�@�X�v���C�g5�@�X�N���v�g1

}

void Title::Update() {

	

	timer += Time::GetInstance().GetDeltaTime();


	if (titleLogo1->GetPosition()->GetX() < SCREEN_WIDTH / 2 && timer > 3) {// ���� ������E
		//                                                             �������Ń^�C�~���O�̒���
		titleLogo1->SetPosition(new Vector3(titleLogo1->GetPosition()->GetX() + logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 2, 0));
		//                                                                      �����S�̏o�鑬��
		if (titleLogo1->GetPosition()->GetX() > SCREEN_WIDTH / 2) {
			titleLogo1->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}


	if (titleLogo2->GetPosition()->GetX() > SCREEN_WIDTH / 2 && timer > 4) {// ���l �E���獶
		//                                                             �������Ń^�C�~���O�̒���
		titleLogo2->SetPosition(new Vector3(titleLogo2->GetPosition()->GetX() - logoSpeed * Time::GetInstance().GetDeltaTime(), SCREEN_HEIGHT / 2, 0));
		//                                                                      �����S�̏o�鑬��
		if (titleLogo2->GetPosition()->GetX() < SCREEN_WIDTH / 2) {
			titleLogo2->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}


	if (titleLogo3->GetPosition()->GetY() > SCREEN_HEIGHT / 2 && timer > 5) {// �I���� �������
		//                                                              �������Ń^�C�~���O�̒���
		titleLogo3->SetPosition(new Vector3( SCREEN_WIDTH/2,titleLogo3->GetPosition()->GetY() - logoSpeed * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                      �����S�̏o�鑬��
		if (titleLogo3->GetPosition()->GetY() < SCREEN_HEIGHT / 2) {
			titleLogo3->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}


	if (titleLogo4->GetPosition()->GetY() > SCREEN_HEIGHT / 2 && timer > 6) {// �s�b�N �������
		//                                                              �������Ń^�C�~���O�̒���
		titleLogo4->SetPosition(new Vector3( SCREEN_WIDTH / 2,titleLogo4->GetPosition()->GetY() - logoSpeed * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        �����S�̏o�鑬��
		if (titleLogo4->GetPosition()->GetY() < SCREEN_HEIGHT / 2) {
			titleLogo4->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}

	if (titleLogo5->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 1) {// ���t�O�p �ォ�牺
		//                                                              �������Ń^�C�~���O�̒���
		titleLogo5->SetPosition(new Vector3(SCREEN_WIDTH / 2, titleLogo5->GetPosition()->GetY() + logoSpeed * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        �����S�̏o�鑬��
		if (titleLogo5->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			titleLogo5->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}

	if (titleLogo6->GetPosition()->GetY() < SCREEN_HEIGHT / 2 && timer > 1) {// ���}�b�`�� �ォ�牺
		//                                                              �������Ń^�C�~���O�̒���
		titleLogo6->SetPosition(new Vector3(SCREEN_WIDTH / 2, titleLogo6->GetPosition()->GetY() + 200 * Time::GetInstance().GetDeltaTime(), 0));
		//                                                                                        �����S�̏o�鑬��
		if (titleLogo6->GetPosition()->GetY() > SCREEN_HEIGHT / 2) {
			titleLogo6->SetPosition(new Vector3(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0));// �������ʒu
		}
	}

	if (Input::GetInstance().GetKey(DIK_Q)) {
		SceneManager::GetInstance().LoadScene("runTitle");
	}

}

void Title::UnLoad() {
	ObjectManager::GetInstance().Destroy(titleObject);
}
