#pragma once

#include "Pixel.h"
#include <iostream>

class Image
{
	int width;
	int height;
	int maxVal;
	int type;
	Pixel* image;
protected:
	static const char* const INVALID_IMAGE_SIZE;
public:
	static const long MAX_VAL_MAX = 65536;
public:
	Image();
	Image(int width, int height, int maxVal, int type, std::ifstream& steam);
	virtual ~Image();
	
	void setWidth(int width);
	int  getWidth();
	void setHeight(int height);
	int  getHeight();
	void setMaxVal(int maxVal);
	int  getMaxVal();
	void setType(int type);
	int  getType();
	Pixel getPixel(int index);

protected:
	bool checkSizeValidity(int width, int height);
	virtual void readImage(int image_size, std::ifstream& stream) = 0;
};

