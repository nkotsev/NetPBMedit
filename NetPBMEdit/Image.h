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
  static const int defaultMaxVal;
public:
	Image();
	Image(int width, int height, int maxVal, int type, std::ifstream& steam);
  Image(int width, int height, int maxVal, int type);
	virtual ~Image();
	
	void setWidth(int width);
	int  getWidth();
	void setHeight(int height);
	int  getHeight();
	void setMaxVal(int maxVal);
	int  getMaxVal();
	void setType(int type);
	int  getType();
	Pixel& getPixel(int index);
  int pixelCount();
  virtual void printImage(std::ofstream& stream) = 0;
protected:
  virtual void printHeader(std::ofstream&);
  virtual void printBody(std::ofstream&) = 0;
	bool checkSizeValidity(int width, int height);
  virtual void readImage(std::ifstream& stream) = 0;
};

