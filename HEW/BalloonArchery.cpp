#include "BalloonArchery.h"
#include "Archery.h"

BalloonArchery::BalloonArchery() {
}


BalloonArchery::~BalloonArchery() {
}

void BalloonArchery::Start() {

}

void BalloonArchery::Update() {
	
	if (archery == NULL) {
		archery = dynamic_cast<Archery*>(SceneManager::GetInstance().GetNowScene());
	}

	if (archery->timer >= 19) {
		SceneManager::GetInstance().LoadScene("ArcheryResult");
	}
	else if (archery->timer >= 17) {	//�\���������܂�
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[6]);
		sprite->SetColor(new Color(0, 0, 0, 255));
	}

	else if (archery->timer >= 14) { // �I���̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 6, SD_HEIGHT * 6));
		sprite->SetTexture(textures[5]);
	}

	else if (archery->timer >= 13) { //�c��1s
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[5]);
	}

	else if (archery->timer >= 12) { //�c��2s
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[4]);
	}

	else if (archery->timer >= 11) { //�c��3s
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
		sprite->SetColor(new Color(255, 255, 255, 255));
	}

	else if (archery->timer >= 7) { //�\���������܂�
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetColor(new Color(0, 0, 0, 255));
	}

	else if (archery->timer >= 4) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 3) { //Go�̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 6, SD_HEIGHT * 6));
		sprite->SetTexture(textures[1]);
	}

	else if (archery->timer >= 0) { //Ready�̕\��
		sprite->SetTexture(textures[0]);
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
	}
	
}

void BalloonArchery::SetSprite(Sprite * _sprite) {
	sprite = _sprite;
}


void BalloonArchery::SetTexture(Texture * texture) {
	textures.emplace_back(texture);
}
