#pragma once

class Color {
public:
	unsigned char r, g, b, a;

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

};