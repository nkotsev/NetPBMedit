#include "PlainGrayscaleImage.h"


PlainGrayscaleImage::PlainGrayscaleImage() : Image()
{
}

PlainGrayscaleImage::PlainGrayscaleImage(int width, int height, int maxVal, int type, std::ifstream& stream)
  : Image(width, height, maxVal, type, stream)
{
  if (type != 1){
    throw "Wrong type given. The magic number for plain monochrone image is P2";
  }
  readImage(stream);
}

void PlainGrayscaleImage::readImage(std::ifstream& stream)
{
  for (int index = 0; index < getWidth() * getHeight(); index++){
    int value;
    if (!stream){
      throw "Error while reading from file.";
    }
    stream >> value;
    if (value != 1 && value != 0){
      throw "Found invalid value for monochrome image. File is corrupted.";
    }
    getPixel(index).setGrayscale(value, getMaxVal());
  }
}

PlainGrayscaleImage::~PlainGrayscaleImage()
{
}
