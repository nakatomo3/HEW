#pragma once

#include <d3dx9.h>
#include <stdio.h>

#include <string.h>
using namespace std;

#include "mydirect3d.h"
#include "Setting.h"
#include "Color.h"
#include "Vector2.h"
#include "Vector3.h"
#include "VisualComponent.h"

//最大表示文字数
#define TEXT_BUFFER_MAX (256)
//デフォルトのフォントサイズ
#define DEFAULT_TEXT_SIZE (24)

//フォントの種類を足したい場合、LASTの上に書くこと
typedef enum {
	POP,
	GOTHIC,
	MINCHO,
	LAST
}FONT;

static LPD3DXFONT fonts[LAST];

//C:\Windows\Fontsに書いてある名前を持ってくる
static const char* fontName[]{
	"HGP創英角ﾎﾟｯﾌﾟ体",
	"HGPｺﾞｼｯｸE",
	"HGP明朝E"
};

class Text : public VisualComponent {

public :
	Text();
	Text(int size, FONT type = POP);

	string text;

	static void Init();
	static void Uninit();

	void SetCriterion(Criterion _criterion);
	void SetPosition(Vector3* _position);
	void SetColor(Color* _color);
	void SetColor(D3DCOLOR _color);

	Color* GetColor();

	void LateDraw() override;

	//毎フレーム使用する場合、FPSの低下が予想されます。
	//そのような使用をしたい場合、画像化などしてください
	void SetSize(int _size);
	int GetSize();

private:

	FONT type;
	int size = DEFAULT_TEXT_SIZE;
	LPD3DXFONT font;

	Criterion criterion = CENTER;
	Vector3* position;

	D3DCOLOR g_Color;
	Color* color;

	~Text();
};