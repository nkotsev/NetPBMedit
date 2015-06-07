#pragma once
#include <iostream>
#include <fstream>
class ImageFactory
{
	std::ifstream* stream;
public:
	ImageFactory(std::ifstream& stream);
	virtual ~ImageFactory();
	void initializeImage();
private:
	ImageFactory();
	
	bool isComment(char*);
	void checkStream();
	void getNextString(char destination[]);
};

