#pragma once
#include "Image.h"
class PlainImage :
	public Image
{
public:
	PlainImage();
	PlainImage(int, int, int, int, std::ifstream&);
	~PlainImage();
	void readImage(std::ifstream& stream);
	void readMonochrome(std::ifstream& stream, int index);
	void readGrayscale(std::ifstream& stream, int index);
	void readRGB(std::ifstream& stream, int index);
};

