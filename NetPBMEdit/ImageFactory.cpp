#include "ImageFactory.h"
#include <cstddef>
#include <stdexcept>
#include <cstring>
#include <cstdlib>

#include "Image.h"
#include "PlainImage.h"
#include "PlainMonochromeImage.h"
#include "PlainPixmapImage.h"
#include "PlainGrayscaleImage.h"

ImageFactory::ImageFactory(): stream(NULL)
{
}

ImageFactory::ImageFactory(std::ifstream& stream):stream(NULL) {
	if (!stream){
		throw new std::invalid_argument("Problem with the stream");
	}
	this->stream = &stream;
}

void ImageFactory::getNextString(char destination[]){
	do{
		checkStream();
		*stream >> destination;
	} while (isComment(destination) || !strcmp(destination, ""));
}

Image* ImageFactory::initializeImage(){
	int type;
	int width;
	int height;
	int maxVal = 1;
	char string[128];
	getNextString(string);
	// Checks type
	type = string[1] - '0';
	if (string[0] != 'P' || type < 1 || type > 6){
		throw "Invalid image format. The file should begin with \'P\' and the value after that should be between 1 and 6.";
	}
	// Get width
	getNextString(string);
	width = (int) std::strtoul(string, NULL, 0);
	if (width <= 0){
		throw "Invalid image size. Width should be greater than 0.";
	}
	// Get height
	getNextString(string);
	height = (int)std::strtoul(string, NULL, 0);
	if (height <= 0){
		throw "Invalid image size. Height should be greater than 0.";
	}
	// Get maxVal if needed
	if (type != 1 && type != 4){
		getNextString(string);
		maxVal = (int)std::strtoul(string, NULL, 0);
		if (maxVal <= 0 || maxVal > Image::MAX_VAL_MAX){
			throw "Invalid maxVal value. It should be between 1 and 65536";
		}
	}
  Image * pImage = NULL;
  // Construct Image:
  try
  {
    switch (type){
    case(1):
      pImage = new PlainMonochromeImage(width, height, PlainMonochromeImage::defaultMaxVal, type, *stream);
      break;
    case(2) :
      pImage = new PlainGrayscaleImage(width, height, maxVal, type, *stream);
      break;
    case(3) :
      pImage = new PlainPixmapImage(width, height, maxVal, type, *stream);
      break;
    case(4):
      //TODO : Binary monochrome
    case(5):
      //TODO : Binary grayscale
    case(6):
      //TODO : Binary pixmap
    default:
      throw "Invalid image type.";
    }
  }
  catch (std::exception e)//TODO: make more cases
  {
    std::cerr << e.what() << std::endl;
    throw e;
  }
  catch (char* e)
  {
    std::cerr << e << std::endl;
    throw e;
  }
  return pImage;
}

bool ImageFactory::isComment(char* str){
	if (str[0] == '#'){
    char c = 0;
    stream->get(c);
    while (c != '\n' && !stream->eof() && !stream->fail())
    {
      stream->get(c);
    }
		return true;
	}
	return false;
}

ImageFactory::~ImageFactory()
{
}

void ImageFactory::checkStream(){
	if (!*stream){
		throw "Find better object to throw";
	}
}
