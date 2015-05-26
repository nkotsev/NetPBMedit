#include "Pixel.h"

#include <exception>
#include <stdexcept>

Pixel::Pixel() : r(0), g(0), b(0)
{
}
Pixel::Pixel(int r, int g, int b) 
{
	setColor(r, g, b);
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
	if (value < 0 || value > 255){
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

void Pixel::setGrayscale(int value, int maxColor){
	int grayTone = (int) value * (255.0/maxColor);
	if (checkValueValidity(grayTone)){
		this->r = this->b = this->g = grayTone;
	}
	else{
		throw std::invalid_argument(INVALID_COLOR_ARGUMENT);
	}
}

int Pixel::getMonochrome(){
	return getGrayscale(2);
}

void Pixel::setMonochrome(char color){
	setGrayscale(color, 2);
}