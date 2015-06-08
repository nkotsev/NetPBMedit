#pragma once
#include "Image.h"
class PlainPixmapImage :
  public Image
{
public:
  static const int defaultMaxVal;
public:
  PlainPixmapImage();
  PlainPixmapImage(int width, int height, int maxVal, int type, std::ifstream& stream);
  ~PlainPixmapImage();
  virtual void readImage(std::ifstream& stream);
  virtual void printImage(std::ofstream&);
protected:
  virtual void printBody(std::ofstream&);
};

