#include "ImageTransformator.h"


ImageTransformator::ImageTransformator() : source(NULL)
{
}

ImageTransformator::ImageTransformator(Image* source)
{
  setSource(source);
}

void ImageTransformator::setSource(Image* source)
{
  this->source = source;
}

const Image* ImageTransformator::getSource() const {
  return source;
}

bool ImageTransformator::canTransform(){
  return source != NULL;
}

ImageTransformator::~ImageTransformator()
{
}

PlainMonochromeImage* ImageTransformator::transformToPlainMonochrome(){
  if (!checkIfSourceIsRealPixmap()){
    return NULL;
  }
  PlainMonochromeImage* pMono = new PlainMonochromeImage(source->getWidth(),
    source->getHeight(), PlainMonochromeImage::defaultMaxVal, 1);
  for (int i = 0; i < pMono->pixelCount(); i++){
    pMono->getPixel(i).setMonochrome(source->getPixel(i).getMonochrome());
  }
  return pMono;
}
PlainGrayscaleImage* ImageTransformator::tranformToPlainGrayscale(){
  if (!checkIfSourceIsRealPixmap()){
    return NULL;
  }
  PlainGrayscaleImage* pGrayscale = new PlainGrayscaleImage(source->getWidth(),
    source->getHeight(), source->getMaxVal(), 2);
  for (int i = 0; i < pGrayscale->pixelCount(); i++){
    Pixel* p = &source->getPixel(i);
    pGrayscale->getPixel(i).setGrayscale(p->getGrayscale(), source->getMaxVal());
  }
  return pGrayscale;
}

bool ImageTransformator::checkIfSourceIsRealPixmap(){
  bool result = checkSourceTypeValidity() && checkSourceContentValidity();
  if (!result){
    std::cerr << "You can't convert image that is not real pixmap" << std::endl;
  }
  return result;
}

bool ImageTransformator::checkSourceTypeValidity(){
  if (source->getType() != 3 && source->getType() != 6){
    return false;
  }
  return true;
}

bool ImageTransformator::checkSourceContentValidity(){
  bool isGrayscale = true;
  for (int i = 0; i < source->pixelCount(); i++){
    if (!(source->getPixel(i).getRed() == source->getPixel(i).getGreen() ==
      source->getPixel(i).getBlue())){
      isGrayscale = false;
      break;
    }
  }
  return !isGrayscale;
}