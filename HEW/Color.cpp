#include "Color.h"
#include "LogWriter.h"
#define COLOR_INT_MAX 255
#define COLOR_FLOAT_MAX 1.0f
#define COLOR_MIN 0

unsigned int Color::GetR() {
	return r;
}

unsigned int Color::GetG() {
	return g;
}

unsigned int Color::GetB() {
	return b;
}

unsigned int Color::GetA() {
	return a;
}

void Color::SetR(unsigned int _r) {
	r = _r;
}

void Color::SetG(unsigned int _g) {
	g = _g;
}

void Color::SetB(unsigned int _b) {
	b = _b;
}

void Color::SetA(unsigned int _a) {
	a = _a;
}

Color::Color(unsigned int R, unsigned int G, unsigned int B) {
	if (R > COLOR_INT_MAX || G > COLOR_INT_MAX || B > COLOR_INT_MAX) {
		LogWriter::GetInstance().LogWorning("Color‚ðintŒ^‚Å‰Šú‰»‚·‚éê‡‚Í0`255‚Ì”ÍˆÍ‚ÅŽw’è‚µ‚Ä‚­‚¾‚³‚¢B@Žw’è‚µ‚½RGB=(%d,%d,%d)", R, G, B);
	}

	if (R > COLOR_INT_MAX) {
		r = COLOR_INT_MAX;
	} else {
		r = R;
	}

	if (G > COLOR_INT_MAX) {
		g = COLOR_INT_MAX;
	} else {
		g = G;
	}

	if (B > COLOR_INT_MAX) {
		b = COLOR_INT_MAX;
	} else {
		b = B;
	}
	a = COLOR_INT_MAX;
}

Color::Color(unsigned int R, unsigned int G, unsigned int B, unsigned int A) {
	if (R > COLOR_INT_MAX || G > COLOR_INT_MAX || B > COLOR_INT_MAX || A > COLOR_INT_MAX) {
		LogWriter::GetInstance().LogWorning("Color‚ðintŒ^‚Å‰Šú‰»‚·‚éê‡‚Í0`255‚Ì”ÍˆÍ‚ÅŽw’è‚µ‚Ä‚­‚¾‚³‚¢B@Žw’è‚µ‚½RGBA=(%d,%d,%d,%d)", R, G, B, A);
	}

	if (R > COLOR_INT_MAX) {
		r = COLOR_INT_MAX;
	} else {
		r = R;
	}

	if (G > COLOR_INT_MAX) {
		g = COLOR_INT_MAX;
	} else {
		g = G;
	}

	if (B > COLOR_INT_MAX) {
		b = COLOR_INT_MAX;
	} else {
		b = B;
	}

	if (A > COLOR_INT_MAX) {
		a = COLOR_INT_MAX;
	} else {
		a = A;
	}
}

Color Color::Nega() {
	return Color(255-r, 255-g, 255-b);
}


Color::~Color() {

}
