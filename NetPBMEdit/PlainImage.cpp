#include "PlainImage.h"
#include <fstream>

PlainImage::PlainImage() : Image()
{
}


PlainImage::PlainImage(int width, int height, int maxVal = 1, int type, std::ifstream& stream) : Image(width, height, maxVal, type, stream)
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
