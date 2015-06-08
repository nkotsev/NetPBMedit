#pragma once
#include "Image.h"
class PlainGrayscaleImage :
  public Image
{
public:
  static const int defaultMaxVal;
public:
  PlainGrayscaleImage();
  PlainGrayscaleImage(int width, int height, int maxVal, int type, std::ifstream& stream);
  virtual void readImage(std::ifstream& stream);
  virtual void printImage(std::ofstream&);
  ~PlainGrayscaleImage();
protected:
  virtual void printHeader(std::ofstream&);
  virtual void printBody(std::ofstream&);
};

