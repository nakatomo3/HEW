#include "Sprite.h"
#include "MyDirect3D.h"
#include "LogWriter.h"
#include "GameObject.h"

void Sprite::Init() {
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();
	if (!pDevice) {
		return;
	}
	//�o�[�e�b�N�X�o�b�t�@���쐬����
	pDevice->CreateVertexBuffer(sizeof(Vertex2D) * 4,//4���_�����
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX2D,
		D3DPOOL_DEFAULT,
		&g_pVertexBuffer,
		NULL);

	//�C���f�b�N�X�o�b�t�@���g��
	pDevice->CreateIndexBuffer(sizeof(WORD) * 6,//�C���f�b�N�X6���Ԃ�
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_DEFAULT,
		&g_pIndexBuffer,
		NULL);

	//�C���f�b�N�X�ɏ�������ł���
	LPWORD pIndex = NULL;
	g_pIndexBuffer->Lock(0, 0, (void**)&pIndex, 0);//�C���f�b�N�X�z��̃|�C���^�����炤
	pIndex[0] = 0;
	pIndex[1] = 1;
	pIndex[2] = 2;
	pIndex[3] = 1;
	pIndex[4] = 3;
	pIndex[5] = 2;
	g_pIndexBuffer->Unlock();//�`�����ݏI��
}

Sprite::Sprite() {
	position = new Vector3(0,0,0);
	scale = new Vector2(100,100);
}

Sprite::Sprite(Texture * _texture, Vector2 * _scale, Vector2 * uv, Vector2 * textureScale, Vector3 * _position, Criterion _criterion) {
	texture = _texture;
	scale = _scale;
	position = _position;
	criterion = _criterion;
	tx = uv->GetX();
	ty = uv->GetY();
	tw = textureScale->GetX();
	th = textureScale->GetY();
}

Sprite::~Sprite() {
	delete position;
	delete scale;
}

void Sprite::SetTexture(Texture * _texture) {
	texture = _texture;
}

void Sprite::SetScale(Vector2* _scale) {
	scale = _scale;
}

void Sprite::SetCriterion(Criterion _criterion) {
	criterion = _criterion;
}

void Sprite::SetPosition(Vector3* _position) {
	position = _position;
}

void Sprite::SetColor(Color* _color) {
	color = _color;
	int r = _color->GetR(), g = _color->GetB(), b = _color->GetB(), a = _color->GetA();
	g_Color = D3DCOLOR_RGBA(r,g,b,a);
}

void Sprite::SetColor(D3DCOLOR _color) {
	g_Color = _color;
	delete color;
	color = new Color((_color&0xff)<<16, (_color & 0xff) << 8, (_color & 0xff), (_color & 0xff) << 24);
}

Texture * Sprite::GetTexture() {
	return texture;
}

Vector2 * Sprite::GetScale() {
	return scale;
}

Criterion Sprite::GetCriterion() {
	return criterion;
}

Vector3 * Sprite::GetPosition() {
	return position;
}

Color * Sprite::GetColor() {
	return color;
}

void Sprite::Draw() {
	if (texture == nullptr) {
		LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();

		if (!pDevice) {
			return;
		}

		Vector3* pos = nullptr;
		if (GetGameObject() == nullptr) {
			LogWriter::GetInstance().Log("�X�v���C�g��GameObject�ɃA�^�b�`���ꂸ�Ɏg�p����܂����BGameObject�ɃA�^�b�`���������Ŏg�p���Ă�������");
			pos = new Vector3(0,0,0);
		} else {
			pos = GetGameObject()->GetPosition();
		}

		int positionX = pos->GetX() + position->GetX();
		int positionY = pos->GetY() + position->GetY();
		int positionZ = pos->GetZ() + position->GetZ();

		int left = (int)-scale->GetX()/2;
		int right = (int)scale->GetX()/2;

		int up = (int)-scale->GetY() / 2;
		int down = (int)scale->GetY() / 2;

		if (criterion & 1) {
			left = 0;
			right = (int)scale->GetX();
		}
		if (criterion & 2) {
			left = (int)-scale->GetX();
			right = 0;
		}

		if (criterion & 4) {
			up = 0;
			down = (int)scale->GetY();
		}
		if (criterion & 8) {
			up = (int)-scale->GetY();
			down = 0;
		}

		Vertex2D v[] = {
			{D3DXVECTOR4(positionX + left, positionY + up, positionZ, 1.0f), g_Color, D3DXVECTOR2(0, 0)},
			{D3DXVECTOR4(positionX + right, positionY + up, positionZ, 1.0f), g_Color, D3DXVECTOR2(1, 0)},
			{D3DXVECTOR4(positionX + left, positionY + down, positionZ, 1.0f), g_Color, D3DXVECTOR2(0, 1)},
			{D3DXVECTOR4(positionX + right, positionY + down, positionZ, 1.0f), g_Color, D3DXVECTOR2(1, 1)}
		};

		pDevice->DrawPrimitiveUP(
			D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�^�C�v
			2,				   //�\���|���S����
			v,				  //���_�f�[�^�̃|�C���^�[
			sizeof(Vertex2D));//���_1�̃T�C�Y
	} else {
		Draw(texture);
	}
}

void Sprite::Draw(Texture * _texture) {
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();

	if (!pDevice) {
		return;
	}

	Vector3* pos = nullptr;
	if (GetGameObject() == nullptr) {
		LogWriter::GetInstance().Log("�X�v���C�g��GameObject�ɃA�^�b�`���ꂸ�Ɏg�p����܂����BGameObject�ɃA�^�b�`���������Ŏg�p���Ă�������");
		pos = new Vector3(0, 0, 0);
	} else {
		pos = GetGameObject()->GetPosition();
	}

	int positionX = pos->GetX() + position->GetX();
	int positionY = pos->GetY() + position->GetY();
	int positionZ = pos->GetZ() + position->GetZ();

	int left = (int)-scale->GetX() / 2;
	int right = (int)scale->GetX() / 2;

	int up = (int)-scale->GetY() / 2;
	int down = (int)scale->GetY() / 2;

	if (criterion & 1) {
		left = 0;
		right = (int)scale->GetX();
	}
	if (criterion & 2) {
		left = (int)-scale->GetX();
		right = 0;
	}

	if (criterion & 4) {
		up = 0;
		down = (int)scale->GetY();
	}
	if (criterion & 8) {
		up = (int)-scale->GetY();
		down = 0;
	}

	Vertex2D vertex[] = {
		{D3DXVECTOR4(positionX + left, positionY + up, positionZ, 1.0f), g_Color, D3DXVECTOR2(0, 0)},
		{D3DXVECTOR4(positionX + right, positionY + up, positionZ, 1.0f), g_Color, D3DXVECTOR2(1, 0)},
		{D3DXVECTOR4(positionX + left, positionY + down, positionZ, 1.0f), g_Color, D3DXVECTOR2(0, 1)},
		{D3DXVECTOR4(positionX + right, positionY + down, positionZ, 1.0f), g_Color, D3DXVECTOR2(1, 1)}
	};

	pDevice->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,//�v���~�e�B�u�^�C�v
		2,				   //�\���|���S����
		vertex,				  //���_�f�[�^�̃|�C���^�[
		sizeof(Vertex2D));//���_1�̃T�C�Y

	//�e�N�X�`�����W�v�Z
	float u[2], v[2];
	u[0] = (float)tx / tw;
	v[0] = (float)ty / th;
	u[1] = (float)(tx + tw) / tw;
	v[1] = (float)(ty + th) / th;    //�s�N�Z�����W���e�N�X�`�����W�ɕϊ�

	float	lx = tw / 2.0f;
	float	ly = th / 2.0f;

	//g_pVertexBuffer->Lock(0, 0, (void**)&pv, 0);    //�z��̃|�C���^���󂯎��

	for (int i = 0; i < 4; i++) {
		vertex[i].color = g_Color;
	}
	vertex[0].texcoord = D3DXVECTOR2(u[0], v[0]);
	vertex[1].texcoord = D3DXVECTOR2(u[1], v[0]);
	vertex[2].texcoord = D3DXVECTOR2(u[0], v[1]);
	vertex[3].texcoord = D3DXVECTOR2(u[1], v[1]);

	//g_pVertexBuffer->Unlock();//�o�[�e�b�N�X�o�b�t�@�ւ̏������ݏI��


	pDevice->SetFVF(FVF_VERTEX2D);
	pDevice->SetTexture(0, texture->GetTexture());
	//pDevice->SetStreamSource(0,
	//	g_pVertexBuffer,//�`�悵�����|���S���̃o�[�e�b�N�X�o�b�t�@
	//	0,
	//	sizeof(Vertex2D));//���_1���̃T�C�Y

	//pDevice->SetIndices(g_pIndexBuffer);//�`�悵�����|���S���̃C���f�b�N�X
	//
	//pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,
	//	0, 0,
	//	4,//���_��
	//	0, 2);//2���|���S���̐�

	//pDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 0, &vertex[0], sizeof(Vertex2D));

}
