#define _CRT_SECURE_NO_WARNINGS
#include "Text.h"
#include "LogWriter.h"
#include "GameObject.h"

void Text::Init() {
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();

	D3DXCreateFont(pDevice,
		DEFAULT_TEXT_SIZE, 0, 0, 0,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		fontName[POP],
		&fonts[POP]);

	if (fonts[POP] == NULL) {
		LogWriter::GetInstance().LogError("ポップ体のロードに失敗しました");
	} else {
		LogWriter::GetInstance().Log("ポップ体のロードに成功しました");
	}

	D3DXCreateFont(pDevice,
		DEFAULT_TEXT_SIZE, 0, 0, 0,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		fontName[GOTHIC],
		&fonts[GOTHIC]);

	if (fonts[GOTHIC] == NULL) {
		LogWriter::GetInstance().LogError("ゴシック体のロードに失敗しました");
	} else {
		LogWriter::GetInstance().Log("ゴシック体のロードに成功しました");
	}

	D3DXCreateFont(pDevice,
		DEFAULT_TEXT_SIZE, 0, 0, 0,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		fontName[MINCHO],
		&fonts[MINCHO]);

	if (fonts[MINCHO] == NULL) {
		LogWriter::GetInstance().LogError("明朝体のロードに失敗しました");
	} else {
		LogWriter::GetInstance().Log("明朝体のロードに成功しました");
	}
}

void Text::Uninit() {
	for (int i = 1; i < LAST; i++) {
		fonts[i]->Release();
		fonts[i] = NULL;
	}
}


void Text::SetCriterion(Criterion _criterion) {
	criterion = _criterion;
}

void Text::SetPosition(Vector3 * _position) {
	delete position;
	position = _position;
}

void Text::SetColor(Color * _color) {
	delete color;
	color = _color;
	int r = _color->GetR(), g = _color->GetB(), b = _color->GetB(), a = _color->GetA();
	g_Color = D3DCOLOR_RGBA(r, g, b, a);
}

void Text::SetColor(D3DCOLOR _color) {
	g_Color = _color;
	delete color;
	color = new Color((_color & 0xff) << 16, (_color & 0xff) << 8, (_color & 0xff), (_color & 0xff) << 24);
}

Color * Text::GetColor() {
	return color;
}

void Text::LateDraw() {
	LONG defaultPosX = (LONG)(position->GetX() + gameObject->GetPosition()->GetX());
	LONG defaultPosY = (LONG)(position->GetY() + gameObject->GetPosition()->GetY());
	if (isOutline == true) {
		TextDraw(defaultPosX + outlineDistance, defaultPosY, g_outlineColor);
		TextDraw(defaultPosX - outlineDistance, defaultPosY, g_outlineColor);
		TextDraw(defaultPosX, defaultPosY + outlineDistance, g_outlineColor);
		TextDraw(defaultPosX, defaultPosY - outlineDistance, g_outlineColor);
		if (isBeautifulOutline == true) {
			TextDraw(defaultPosX + outlineDistance, defaultPosY + outlineDistance, g_outlineColor);
			TextDraw(defaultPosX - outlineDistance, defaultPosY + outlineDistance, g_outlineColor);
			TextDraw(defaultPosX - outlineDistance, defaultPosY - outlineDistance, g_outlineColor);
			TextDraw(defaultPosX + outlineDistance, defaultPosY - outlineDistance, g_outlineColor);
		}
	}
	TextDraw(defaultPosX, defaultPosY, g_Color);
}

void Text::SetSize(int _size) {
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();
	if(size == _size){
		return;
	}
	if (size != DEFAULT_TEXT_SIZE) {
		font->Release();
	}
	if (_size != DEFAULT_TEXT_SIZE) {
		D3DXCreateFont(pDevice,
			_size, 0, 0, 0,
			FALSE,
			SHIFTJIS_CHARSET,
			OUT_DEFAULT_PRECIS,
			DEFAULT_QUALITY,
			DEFAULT_PITCH,
			fontName[type],
			&font);
	} else {
		font = fonts[type];
	}
	size = _size;
}

int Text::GetSize() {
	return size;
}

void Text::SetOutlineColor(Color * _color) {
	delete outlineColor;
	outlineColor = _color;
	int r = _color->GetR(), g = _color->GetB(), b = _color->GetB(), a = _color->GetA();
	g_outlineColor = D3DCOLOR_RGBA(r, g, b, a);
}

void Text::SetOutlineColor(D3DCOLOR _color) {
	g_outlineColor = _color;
	delete outlineColor;
	color = new Color((_color & 0xff) << 16, (_color & 0xff) << 8, (_color & 0xff), (_color & 0xff) << 24);
}

Text::Text() {
	position = new Vector3();
	color = new Color(255,255,255,255);
	g_Color = D3DCOLOR_RGBA(255,255,255,255);
	font = fonts[POP];
	size = 24;
	criterion = LEFT;
}

Text::Text(int _size, FONT type) {
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D::GetInstance().GetDevice();

	if (_size != DEFAULT_TEXT_SIZE) {
	D3DXCreateFont(pDevice,
		_size, 0, 0, 0,
		FALSE,
		SHIFTJIS_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH,
		fontName[type],
		&font);
	} else {
		font = fonts[type];
	}
	size = _size;
}


void Text::TextDraw(LONG x, LONG y, D3DCOLOR _color) {
	RECT rect = { (LONG)x, (LONG)y, (int)SCREEN_WIDTH, (int)SCREEN_HEIGHT };

	char buf[TEXT_BUFFER_MAX];
	strcpy(buf, text.c_str());

	font->DrawText(NULL, buf, -1, &rect, DT_LEFT, _color);
}

Text::~Text() {
	font->Release();
}

