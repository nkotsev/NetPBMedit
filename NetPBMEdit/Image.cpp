#include "Image.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>

const char* const Image::INVALID_IMAGE_SIZE = "The size of the image is invalid";

Image::Image() : width(0), height(0), maxVal(0), type(0), image(NULL)
{
}

Image::Image(int width, int height, int maxVal = 1, int type, std::ifstream& stream) : image(NULL)
{
	setWidth(width);
	setHeight(height);
	setMaxVal(maxVal);
	setType(type);
	image = new Pixel[width*height];
}

Image::~Image()
{
	delete[] image;
}

bool Image::checkSizeValidity(int width, int height)
{
	if (width <= 0 || height <= 0){
		return false;
	}
	return true;
}

void Image::setWidth(int width)
{
	if (checkSizeValidity(width, width)){
		this->width = width;
	}
	else{
		throw "Invalid image size. Width should be greater than 0.";
	}
}

int Image::getWidth()
{
	return width;
}

void Image::setHeight(int height)
{
	if (checkSizeValidity(height, height))
	{
		this->height = height;
	}
	else
	{
		throw "Invalid image size. Height should be greater than 0.";
	}
}

int Image::getHeight()
{
	return height;
}

void Image::setMaxVal(int maxVal)
{
	if (maxVal > 0 && maxVal < Image::MAX_VAL_MAX)
	{
		this->maxVal = maxVal;
	}
	else
	{
		throw "Invalid maxVal value. It should be between 1 and 65536";
	}
}

int Image::getMaxVal()
{
	return maxVal;
}

void Image::setType(int type)
{
	if (type >= 1 && type <= 6){
		this->type = type;
	}
	else
	{
		throw "Invalid image format. The file should begin with \'P\' and the value after that should be between 1 and 6.";
	}
}

int Image::getType(){
	return type;
}

Pixel Image::getPixel(int index){
	return image[index];
}