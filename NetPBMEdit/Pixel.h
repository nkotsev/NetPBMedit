#pragma once
class Pixel
{
	int r;
	int	g;
	int b;
public:
	Pixel();
	Pixel(int r, int g, int b);
	void setColor(int r, int g, int b);
	int getRed();
	int getGreen();
	int getBlue();
	int getGrayscale(int maxColor);
	int setGrayscale(int color, int maxColor);
	int getMonochrome();
	// 0 for white character and 1 for black
	int setMonochrome(char color);
	~Pixel();
};

