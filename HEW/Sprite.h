#pragma once
#include "Texture.h"
#include "Vector3.h"
#include "Vector2.h"
#include "VisualComponent.h"
#include "Color.h"
#include <d3d9.h>

//ポリゴンの頂点構造体
typedef struct Vertex2D_tag {
	D3DXVECTOR4 position; // 頂点座標（座標変換済み頂点）
	D3DCOLOR color;       // 頂点カラー(32Bit ARGB指定)
	D3DXVECTOR2 texcoord; // テクスチャ座標
}Vertex2D;

#define FVF_VERTEX2D (D3DFVF_XYZRHW|D3DFVF_DIFFUSE|D3DFVF_TEX1) // ２Dポリゴン頂点フォーマット

static LPDIRECT3DVERTEXBUFFER9 g_pVertexBuffer;
static LPDIRECT3DINDEXBUFFER9 g_pIndexBuffer;

static Texture* nullTexture;

class Sprite : public VisualComponent{
public:
	static void Init();

	Sprite(Texture* _texture = nullTexture, Vector2* _scale = new Vector2(1,1), Vector2* uv = new Vector2(0,0), Vector2* _textureScale = new Vector2(1,1), Vector3* _position = new Vector3(0,0,0),Criterion _criterion = CENTER);

	void SetTexture(Texture* _texture);
	void SetScale(Vector2* _scale);
	void SetCriterion(Criterion _criterion);
	void SetPosition(Vector3* _position);
	void SetColor(Color* _color);
	void SetColor(D3DCOLOR _color);

	Texture* GetTexture();
	Vector2* GetScale();
	Criterion GetCriterion();
	Vector3* GetPosition();
	Color* GetColor();

	void Draw() override;

protected :
	Texture* texture;

	Vector2* scale;

	Criterion criterion = CENTER;
	Vector3* position;

	D3DCOLOR g_Color = D3DCOLOR_RGBA(255,255,255,255);
	Color* color = new Color(255,255,255,255);

	void Draw(Texture* _texture);

	float tx, ty, tw, th;
	~Sprite();

};