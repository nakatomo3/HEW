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

//�ő�\��������
#define TEXT_BUFFER_MAX (256)
//�f�t�H���g�̃t�H���g�T�C�Y
#define DEFAULT_TEXT_SIZE (24)

//�t�H���g�̎�ނ𑫂������ꍇ�ALAST�̏�ɏ�������
typedef enum {
	POP,
	GOTHIC,
	MINCHO,
	LAST
}FONT;

static LPD3DXFONT fonts[LAST];

//C:\Windows\Fonts�ɏ����Ă��閼�O�������Ă���
static const char* fontName[]{
	"HGP�n�p�p�߯�ߑ�",
	"HGP�޼��E",
	"HGP����E"
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

	//���t���[���g�p����ꍇ�AFPS�̒ቺ���\�z����܂��B
	//���̂悤�Ȏg�p���������ꍇ�A�摜���Ȃǂ��Ă�������
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