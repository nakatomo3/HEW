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
		sprite->SetColor(new Color(0, 0, 0, 255));
	}

	else if (archery->timer >= 14) { // �I���̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 6, SD_HEIGHT * 6));
		sprite->SetTexture(textures[7]);
	}

	else if (archery->timer >= 13) { //�c��1s
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[6]);
	}

	else if (archery->timer >= 12) { //�c��2s
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[5]);
	}

	else if (archery->timer >= 11) { //�c��3s
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[4]);
		sprite->SetColor(new Color(255, 255, 255, 255));
	}

	else if (archery->timer >= 6) { //�\���������܂�
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetColor(new Color(0, 0, 0, 255));
	}

	else if (archery->timer >= 5.95) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 5.9) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 5.85) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 5.8) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 5.75) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 5.7) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 5.65) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 5.6) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 5.55) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 5.5) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 5.45) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 5.4) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 5.35) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 5.3) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 5.25) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 5.2) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 5.15) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 5.1) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 5.05) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 5) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 4.95) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 4.9) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 4.85) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 4.8) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 4.75) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 4.7) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 4.65) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 4.6) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 4.55) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 4.5) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 4.45) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 4.4) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 4.35) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 4.3) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 4.25) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 4.2) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 4.15) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
	}

	else if (archery->timer >= 4.1) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[2]);
	}

	else if (archery->timer >= 4.05) { //A�A�ł̕\��
		sprite->SetScale(new Vector2(SD_HEIGHT * 5, SD_HEIGHT * 5));
		sprite->SetTexture(textures[3]);
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
