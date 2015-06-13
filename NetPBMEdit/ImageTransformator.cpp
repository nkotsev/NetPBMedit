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
  PlainMonochromeImage* pMono = new PlainMonochromeImage(source->getWidth(),
    source->getHeight(), PlainMonochromeImage::defaultMaxVal, 1);
  for (int i = 0; i < pMono->pixelCount(); i++){
    pMono->getPixel(i).setMonochrome(source->getPixel(i).getMonochrome());
  }
  return pMono;
}
PlainGrayscaleImage* ImageTransformator::tranformToPlainGrayscale(){
  PlainGrayscaleImage* pGrayscale = new PlainGrayscaleImage(source->getWidth(),
    source->getHeight(), source->getMaxVal(), 2);
  for (int i = 0; i < pGrayscale->pixelCount(); i++){
    Pixel* p = &source->getPixel(i);
    pGrayscale->getPixel(i).setGrayscale(p->getGrayscale(), source->getMaxVal());
  }
  return pGrayscale;
}