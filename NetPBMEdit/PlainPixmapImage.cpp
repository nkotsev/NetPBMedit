#include "PlainPixmapImage.h"
#include <fstream>
#include <iomanip> // setw

const int PlainPixmapImage::defaultMaxVal = 255;

// Find a better place for this function
template <class T>
inline int GetNumberOfDigits(T i)
{
  return i > 0 ? (int)log10((double)i) + 1 : 1;
}


PlainPixmapImage::PlainPixmapImage()
{
}


PlainPixmapImage::PlainPixmapImage(int width, int height, int maxVal, int type, std::ifstream& stream) 
  : Image(width, height, maxVal, type, stream)
{
  if (type != 3){
    throw "Wrong type given. The magic number for plain pixmap image is P3";
  }
  readImage(stream);
}

void PlainPixmapImage::readImage(std::ifstream& stream){
  for (int index = 0; index < getWidth() * getHeight(); index++)
  {
    int r,g,b;
    if (!stream){
      throw "Eror while reading from file.";
    }
    stream >> r >> g >> b;
    if (r < 0 || r > getMaxVal() ||
        g < 0 || g > getMaxVal() ||
        b < 0 || b > getMaxVal() )
    {
      throw "Found invalid value for monochrome image. File is corrupted.";
    }
    getPixel(index).setColor(r, g, b, getMaxVal());
  }
}

PlainPixmapImage::~PlainPixmapImage()
{
}

void PlainPixmapImage::printImage(std::ofstream& stream)
{
  if (!stream){
    throw "Bad file state. Terminating the process";
  }
  printHeader(stream);
  printBody(stream);
}

void PlainPixmapImage::printBody(std::ofstream& stream)
{
  if (!stream){
    throw "Bad file state. Terminating the process";
  }
  int printWidth = GetNumberOfDigits(getMaxVal());
  for (int row = 0; row < getHeight(); row++){
    for (int col = 0; col < getWidth(); col++){
      stream << std::setw(printWidth) << getPixel(row * getWidth() + col).getRed() << ' '
             << std::setw(printWidth) << getPixel(row * getWidth() + col).getGreen() << ' '
             << std::setw(printWidth) << getPixel(row * getWidth() + col).getBlue() << '\t';
    }
    stream << "\n";
  }
  stream.flush();
}
