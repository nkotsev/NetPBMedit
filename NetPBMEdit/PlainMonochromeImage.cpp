#include "PlainMonochromeImage.h"
#include <fstream>

const int PlainMonochromeImage::defaultMaxVal = 1;

PlainMonochromeImage::PlainMonochromeImage() : Image()
{
}

PlainMonochromeImage::PlainMonochromeImage(int width, int height, int maxVal, int type, std::ifstream& stream): Image(width, height, maxVal, type, stream)
{
  if (type != 1){
    throw "Wrong type given. The magic number for plain monochrone image is P1";
  }
  readImage(stream);
}

void PlainMonochromeImage::readImage(std::ifstream& stream)
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
    getPixel(index).setMonochrome(value);
  }
}

PlainMonochromeImage::~PlainMonochromeImage()
{
}

void PlainMonochromeImage::printImage(std::ofstream& stream){
  if (!stream){
    throw "Bad file state. Terminating the process";
  }
  printHeader(stream);
  printBody(stream);
}

void PlainMonochromeImage::printHeader(std::ofstream& stream){
  if (!stream){
    throw "Bad file state. Terminating the process";
  }
  stream << "P1" << '\n'
    << getWidth() << ' ' << getHeight() << '\n';
}

void PlainMonochromeImage::printBody(std::ofstream& stream){

}