#pragma once
#include <fstream>
class Pixel
{
	int r;
	int	g;
	int b;
  int maxVal;
  static const char* INVALID_COLOR_ARGUMENT;
public:
	Pixel();
	Pixel(int r, int g, int b, int maxVal);
	void setColor(int r, int g, int b);
	int getRed();
	int getGreen();
	int getBlue();
  int getMaxVal();
  void setMaxVal(int val);
	int getGrayscale(int maxColor);
	void setGrayscale(int value);
	int getMonochrome();
	// 0 for white character and 1 for black
	void setMonochrome(char color);

private:
	bool checkValueValidity(int value);
	bool checkRGBValidity(int r, int g, int b);
};

