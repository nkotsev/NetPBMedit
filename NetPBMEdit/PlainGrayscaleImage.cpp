#include "PlainGrayscaleImage.h"
#include <iomanip> // setw

#include "ApplicationHelpers.cpp"

PlainGrayscaleImage::PlainGrayscaleImage() : Image()
{
}

PlainGrayscaleImage::PlainGrayscaleImage(int width, int height, int maxVal, int type, std::ifstream& stream)
  : Image(width, height, maxVal, type, stream)
{
  if (type != 2){
    throw "Wrong type given. The magic number for plain monochrone image is P2";
  }
  readImage(stream);
}

PlainGrayscaleImage::PlainGrayscaleImage(int width, int height, int maxVal, int type)
  : Image(width, height, maxVal, type)
{
  if (type != 2){
    throw "Wrong type given. The magic number for plain monochrone image is P2";
  }
}

void PlainGrayscaleImage::readImage(std::ifstream& stream)
{
  for (int index = 0; index < getWidth() * getHeight(); index++){
    int value;
    if (!stream){
      throw "Error while reading from file.";
    }
    stream >> value;
    if (value < 0 || value > getMaxVal()){
      throw "Found invalid value for this grayscale image. File is corrupted.";
    }
    getPixel(index).setGrayscale(value, getMaxVal());
  }
}

PlainGrayscaleImage::~PlainGrayscaleImage()
{
}

void PlainGrayscaleImage::printImage(std::ofstream& stream)
{
  if (!stream){
    throw "Bad file state. Terminating the process";
  }
  printHeader(stream);
  printBody(stream);
}

void PlainGrayscaleImage::printBody(std::ofstream& stream)
{
  if (!stream){
    throw "Bad file state. Terminating the process";
  }
  int printWidth = GetNumberOfDigits(getMaxVal());
  for (int row = 0; row < getHeight(); row++){
    for (int col = 0; col < getWidth(); col++){
      stream << std::setw(printWidth) << getPixel(row * getWidth() + col).getGrayscale() << " ";
    }
    stream << "\n";
  }
  stream.flush();
}