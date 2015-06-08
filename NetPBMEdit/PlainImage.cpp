#include "PlainImage.h"
#include <fstream>

PlainImage::PlainImage() : Image()
{
}


PlainImage::PlainImage(int width, int height, int maxVal, int type, std::ifstream& stream) : Image(width, height, maxVal, type, stream)
{
	if (type > 3){
		throw "Types P4, P5 and P6 are for binary files. Please use BinaryImage class";
	}
	readImage(stream);
}

PlainImage::~PlainImage()
{
}

void PlainImage::readImage(std::ifstream& stream){
	for (int i = 0; i < getWidth() * getHeight(); i++){
		switch (getType()){
		case (1) :
			readMonochrome(stream, i);
			break;
		case (2) :
			readGrayscale(stream, i);
			break;
		case (3) :
			readRGB(stream, i);
		}
	}
}

void PlainImage::readMonochrome(std::ifstream& stream, int index)
{
  int value = -1;
  if (!stream){
    throw "Unable to read from file";
  }
  stream >> value;
  if (value != 1 && value != 0){
    throw "Found invalid value for monochrome image. File is corrupted.";
  }
  getPixel(index).setMonochrome(value);
}

void PlainImage::readGrayscale(std::ifstream& stream, int index)
{

}

void PlainImage::readRGB(std::ifstream& stream, int index)
{

}
