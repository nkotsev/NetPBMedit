#include "Pixel.h"
#include "Image.h" // For Image::MAX_VAL_MAX;
#include <exception>
#include <stdexcept>

const char* Pixel::INVALID_COLOR_ARGUMENT = "The value of each color should be\
                                  								   between 0 and 255";

Pixel::Pixel() : r(0), g(0), b(0), maxVal(0)
{
}
Pixel::Pixel(int r, int g, int b, int maxVal) 
{
	setColor(r, g, b);
  setMaxVal(maxVal);
}

void Pixel::setColor(int r, int g, int b){
	if (!checkRGBValidity(r, g, b)){
		throw new std::invalid_argument(INVALID_COLOR_ARGUMENT);
	}
	this->r = r;
	this->g = g;
	this->b = b;
}

bool Pixel::checkValueValidity(int value){
	if (value < 0 || value > maxVal){
		return false;
	}
	return true;
}

bool Pixel::checkRGBValidity(int r, int g, int b){
	return checkValueValidity(r) &&
		   checkValueValidity(g) &&
		   checkValueValidity(b);
}

int Pixel::getRed(){
	return r;
}

int Pixel::getGreen(){
	return g;
}

int Pixel::getBlue(){
	return b;
}

int Pixel::getGrayscale(int maxColor){
	return (int)((((r + b + g) / 3) / 255.0) *maxColor);
}

void Pixel::setGrayscale(int value){
	int grayTone = (int) value * (255.0/maxVal);
	if (checkValueValidity(grayTone)){
		r = g = b = grayTone;
	}
	else{
		throw std::invalid_argument(INVALID_COLOR_ARGUMENT);
	}
}

int Pixel::getMonochrome(){
	return r ? 0 : 1; // if r > 0 (should be 255) return 0 else (r == 0) return 1
}

void Pixel::setMonochrome(char color){
  setMaxVal(1);
  if (color == 0){
    setColor(0,0,0);
  }
  else if (color == 1){
    setColor(1,1,1);
  }
  else
  {
    throw "Invalid value for monochrome.";
  }
}

void Pixel::setMaxVal(int val){
  if (val <= 0 || val > Image::MAX_VAL_MAX){
    throw "The maximum value should be between 1 and 65535";
  }
  maxVal = val;
}