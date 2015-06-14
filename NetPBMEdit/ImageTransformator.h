#pragma once
#include "Image.h"
#include "PlainGrayscaleImage.h"
#include "PlainMonochromeImage.h"
class ImageTransformator
{
  Image* source;
public:
  ImageTransformator();
  ImageTransformator(Image*);
  ~ImageTransformator();
  const Image* getSource() const ;
  void setSource(Image*);
  bool canTransform();
  PlainMonochromeImage* transformToPlainMonochrome();
  PlainGrayscaleImage*  tranformToPlainGrayscale();
  bool checkIfSourceIsRealPixmap();
private:
  bool checkSourceTypeValidity();
  bool checkSourceContentValidity();
};

