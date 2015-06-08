#pragma once
#include "Image.h"
class PlainMonochromeImage :
  public Image
{
public:
  static const int defaultMaxVal;
public:
  PlainMonochromeImage();
  PlainMonochromeImage(int width, int height, int maxVal, int type, std::ifstream& stream);
  void readImage(std::ifstream& stream);
  virtual void printImage(std::ofstream&);
  ~PlainMonochromeImage();
protected:
  virtual void printHeader(std::ofstream&);
  virtual void printBody(std::ofstream&);
};

