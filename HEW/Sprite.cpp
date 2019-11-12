#include "Sprite.h"
#include "MyDirect3D.h"
#include "LogWriter.h"
#include "GameObject.h"

void Sprite::Init() {
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();
	if (!pDevice) {
		return;
	}

	nullTexture = new Texture("assets/textures/System/null.png", "null");

	//バーテックスバッファを作成する
	pDevice->CreateVertexBuffer(sizeof(Vertex2D) * 4,//4頂点を作る
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX2D,
		D3DPOOL_DEFAULT,
		&g_pVertexBuffer,
		NULL);

	//インデックスバッファを使う
	pDevice->CreateIndexBuffer(sizeof(WORD) * 6,//インデックス6こぶん
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_DEFAULT,
		&g_pIndexBuffer,
		NULL);

	//インデックスに書き込んでおく
	LPWORD pIndex = NULL;
	g_pIndexBuffer->Lock(0, 0, (void**)&pIndex, 0);//インデックス配列のポインタをもらう
	pIndex[0] = 0;
	pIndex[1] = 1;
	pIndex[2] = 2;
	pIndex[3] = 1;
	pIndex[4] = 3;
	pIndex[5] = 2;
	g_pIndexBuffer->Unlock();//描き込み終了
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
	if (texture == nullptr) {
		nullTexture;
	}
}

Sprite::~Sprite() {
	delete position;
	delete scale;
}

void Sprite::SetTexture(Texture * _texture) {
	texture = _texture;
}

void Sprite::SetScale(Vector2* _scale) {
	delete scale;
	scale = _scale;
}

void Sprite::SetCriterion(Criterion _criterion) {
	criterion = _criterion;
}

void Sprite::SetPosition(Vector3* _position) {
	position = _position;
}

void Sprite::SetColor(Color* _color) {
	delete color;
	color = _color;
	int r = _color->GetR(), g = _color->GetB(), b = _color->GetB(), a = _color->GetA();
	g_Color = D3DCOLOR_RGBA(r,g,b,a);
}

void Sprite::SetColor(D3DCOLOR _color) {
	g_Color = _color;
	color->Destroy();
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
	if (texture != nullptr) {

		LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();

		if (!pDevice) {
			return;
		}

		Vector3* pos = nullptr;
		if (GetGameObject() == nullptr) {
			LogWriter::GetInstance().Log("スプライトがGameObjectにアタッチされずに使用されました。GameObjectにアタッチしたうえで使用してください");
			pos = new Vector3(0, 0, 0);
		} else {
			pos = GetGameObject()->GetPosition();
		}

		float positionX = pos->GetX() + position->GetX();
		float positionY = pos->GetY() + position->GetY();
		float positionZ = pos->GetZ() + position->GetZ();

		float left = -scale->GetX() / 2;
		float right = scale->GetX() / 2;

		float up = -scale->GetY() / 2;
		float down = scale->GetY() / 2;

		if (criterion & 1) {
			left = 0;
			right = scale->GetX();
		}
		if (criterion & 2) {
			left = -scale->GetX();
			right = 0;
		}

		if (criterion & 4) {
			up = 0;
			down = scale->GetY();
		}
		if (criterion & 8) {
			up = -scale->GetY();
			down = 0;
		}

		Vertex2D vertex[] = {
			{D3DXVECTOR4(positionX + left, positionY + up, positionZ, 1.0f), g_Color, D3DXVECTOR2(0, 0)},
			{D3DXVECTOR4(positionX + right, positionY + up, positionZ, 1.0f), g_Color, D3DXVECTOR2(1, 0)},
			{D3DXVECTOR4(positionX + left, positionY + down, positionZ, 1.0f), g_Color, D3DXVECTOR2(0, 1)},
			{D3DXVECTOR4(positionX + right, positionY + down, positionZ, 1.0f), g_Color, D3DXVECTOR2(1, 1)}
		};

		//テクスチャ座標計算
		float u[2], v[2];
		u[0] = (float)tx / tw;
		v[0] = (float)ty / th;
		u[1] = (float)(tx + tw) / tw;
		v[1] = (float)(ty + th) / th;    //ピクセル座標をテクスチャ座標に変換

		float	lx = tw / 2.0f;
		float	ly = th / 2.0f;

		//g_pVertexBuffer->Lock(0, 0, (void**)&pv, 0);    //配列のポインタを受け取る

		for (int i = 0; i < 4; i++) {
			vertex[i].color = g_Color;
		}
		vertex[0].texcoord = D3DXVECTOR2(u[0], v[0]);
		vertex[1].texcoord = D3DXVECTOR2(u[1], v[0]);
		vertex[2].texcoord = D3DXVECTOR2(u[0], v[1]);
		vertex[3].texcoord = D3DXVECTOR2(u[1], v[1]);

		//g_pVertexBuffer->Unlock();//バーテックスバッファへの書き込み終了


		pDevice->SetFVF(FVF_VERTEX2D);
		pDevice->SetTexture(0, texture->GetTexture());

		pDevice->DrawPrimitiveUP(
			D3DPT_TRIANGLESTRIP,//プリミティブタイプ
			2,				   //表示ポリゴン数
			vertex,				  //頂点データのポインター
			sizeof(Vertex2D));//頂点1つのサイズ

		//LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();

		//if (!pDevice) {
		//	return;
		//}

		//Vector3* pos = nullptr;
		//if (GetGameObject() == nullptr) {
		//	LogWriter::GetInstance().Log("スプライトがGameObjectにアタッチされずに使用されました。GameObjectにアタッチしたうえで使用してください");
		//	pos = new Vector3(0,0,0);
		//} else {
		//	pos = gameObject->GetPosition();
		//}

		//float positionX = (float)(pos->GetX() + position->GetX());
		//float positionY = (float)(pos->GetY() + position->GetY());
		//float positionZ = (float)(pos->GetZ() + position->GetZ());

		//float left = -scale->GetX()/2;
		//float right = scale->GetX()/2;

		//float up = -scale->GetY() / 2;
		//float down = scale->GetY() / 2;

		//if (criterion & 1) {
		//	left = 0;
		//	right = scale->GetX();
		//}
		//if (criterion & 2) {
		//	left = -scale->GetX();
		//	right = 0;
		//}

		//if (criterion & 4) {
		//	up = 0;
		//	down = scale->GetY();
		//}
		//if (criterion & 8) {
		//	up = -scale->GetY();
		//	down = 0;
		//}

		//Vertex2D v[] = {
		//	{D3DXVECTOR4(positionX + left, positionY + up, positionZ, 1.0f), g_Color, D3DXVECTOR2(0, 0)},
		//	{D3DXVECTOR4(positionX + right, positionY + up, positionZ, 1.0f), g_Color, D3DXVECTOR2(1, 0)},
		//	{D3DXVECTOR4(positionX + left, positionY + down, positionZ, 1.0f), g_Color, D3DXVECTOR2(0, 1)},
		//	{D3DXVECTOR4(positionX + right, positionY + down, positionZ, 1.0f), g_Color, D3DXVECTOR2(1, 1)}
		//};

		//pDevice->DrawPrimitiveUP(
		//	D3DPT_TRIANGLESTRIP,//プリミティブタイプ
		//	2,				   //表示ポリゴン数
		//	v,				  //頂点データのポインター
		//	sizeof(Vertex2D));//頂点1つのサイズ

	} else {
		//Draw(texture);
		LogWriter::GetInstance().Log("テクスチャがnullです");
		texture = nullTexture;
	}
}

void Sprite::Draw(Texture * _texture) {
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();

	if (!pDevice) {
		return;
	}

	Vector3* pos = nullptr;
	if (GetGameObject() == nullptr) {
		LogWriter::GetInstance().Log("スプライトがGameObjectにアタッチされずに使用されました。GameObjectにアタッチしたうえで使用してください");
		pos = new Vector3(0, 0, 0);
	} else {
		pos = GetGameObject()->GetPosition();
	}

	float positionX = pos->GetX() + position->GetX();
	float positionY = pos->GetY() + position->GetY();
	float positionZ = pos->GetZ() + position->GetZ();

	float left = -scale->GetX() / 2;
	float right = scale->GetX() / 2;

	float up = -scale->GetY() / 2;
	float down = scale->GetY() / 2;

	if (criterion & 1) {
		left = 0;
		right = scale->GetX();
	}
	if (criterion & 2) {
		left = -scale->GetX();
		right = 0;
	}

	if (criterion & 4) {
		up = 0;
		down = scale->GetY();
	}
	if (criterion & 8) {
		up = -scale->GetY();
		down = 0;
	}

	Vertex2D vertex[] = {
		{D3DXVECTOR4(positionX + left, positionY + up, positionZ, 1.0f), g_Color, D3DXVECTOR2(0, 0)},
		{D3DXVECTOR4(positionX + right, positionY + up, positionZ, 1.0f), g_Color, D3DXVECTOR2(1, 0)},
		{D3DXVECTOR4(positionX + left, positionY + down, positionZ, 1.0f), g_Color, D3DXVECTOR2(0, 1)},
		{D3DXVECTOR4(positionX + right, positionY + down, positionZ, 1.0f), g_Color, D3DXVECTOR2(1, 1)}
	};

	pDevice->DrawPrimitiveUP(
		D3DPT_TRIANGLESTRIP,//プリミティブタイプ
		2,				   //表示ポリゴン数
		vertex,				  //頂点データのポインター
		sizeof(Vertex2D));//頂点1つのサイズ

	//テクスチャ座標計算
	float u[2], v[2];
	u[0] = (float)tx / tw;
	v[0] = (float)ty / th;
	u[1] = (float)(tx + tw) / tw;
	v[1] = (float)(ty + th) / th;    //ピクセル座標をテクスチャ座標に変換

	float	lx = tw / 2.0f;
	float	ly = th / 2.0f;

	//g_pVertexBuffer->Lock(0, 0, (void**)&pv, 0);    //配列のポインタを受け取る

	for (int i = 0; i < 4; i++) {
		vertex[i].color = g_Color;
	}
	vertex[0].texcoord = D3DXVECTOR2(u[0], v[0]);
	vertex[1].texcoord = D3DXVECTOR2(u[1], v[0]);
	vertex[2].texcoord = D3DXVECTOR2(u[0], v[1]);
	vertex[3].texcoord = D3DXVECTOR2(u[1], v[1]);

	//g_pVertexBuffer->Unlock();//バーテックスバッファへの書き込み終了


	pDevice->SetFVF(FVF_VERTEX2D);
	pDevice->SetTexture(0, texture->GetTexture());
	//pDevice->SetStreamSource(0,
	//	g_pVertexBuffer,//描画したいポリゴンのバーテックスバッファ
	//	0,
	//	sizeof(Vertex2D));//頂点1このサイズ

	//pDevice->SetIndices(g_pIndexBuffer);//描画したいポリゴンのインデックス
	//
	//pDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,
	//	0, 0,
	//	4,//頂点数
	//	0, 2);//2がポリゴンの数

	//pDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 0, &vertex[0], sizeof(Vertex2D));

}
