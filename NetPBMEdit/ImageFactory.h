#pragma once
#include <iostream>
#include <fstream>
#include "Image.h"
class ImageFactory
{
	std::ifstream* stream;
public:
	ImageFactory(std::ifstream& stream);
	virtual ~ImageFactory();
	Image* initializeImage();
private:
	ImageFactory();
	
	bool isComment(char*);
	void checkStream();
	void getNextString(char destination[]);
};

