#pragma once
#include <fstream>
class Pixel
{
	int r;
	int	g;
	int b;
	const char* INVALID_COLOR_ARGUMENT = "The value of each color should be\
								   between 0 and 255";
public:
	Pixel();
	Pixel(int r, int g, int b);
	void setColor(int r, int g, int b);
	int getRed();
	int getGreen();
	int getBlue();
	int getGrayscale(int maxColor);
	void setGrayscale(int value, int maxColor);
	int getMonochrome();
	// 0 for white character and 1 for black
	void setMonochrome(char color);

private:
	bool checkValueValidity(int value);
	bool checkRGBValidity(int r, int g, int b);
};

