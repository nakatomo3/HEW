#pragma once

class Color {
public:

	unsigned int GetR();
	unsigned int GetG();
	unsigned int GetB();
	unsigned int GetA();

	void SetR(unsigned int _r);
	void SetG(unsigned int _g);
	void SetB(unsigned int _b);
	void SetA(unsigned int _a);

	Color(unsigned int R, unsigned int G, unsigned int B);
	Color(unsigned int R, unsigned int G, unsigned int B, unsigned int A);

	Color Nega();

	Color operator+(Color color) {
		int newR = r + color.r;
		newR = (newR + 256) % 256;
		int newG = g + color.g;
		newG = (newG + 256) % 256;
		int newB = b + color.b;
		newB = (newB + 256) % 256;
		return Color((unsigned int)newR, (unsigned int)newG, (unsigned int)newB);
	}

	Color operator-(Color color) {
		int newR = r - color.r;
		newR = (newR + 256) % 256;
		int newG = g - color.g;
		newG = (newG + 256) % 256;
		int newB = b - color.b;
		newB = (newB + 256) % 256;
		return Color((unsigned int)newR, (unsigned int)newG, (unsigned int)newB);
	}

	~Color();
private :
	unsigned char r, g, b, a;
};