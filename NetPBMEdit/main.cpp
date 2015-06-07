#include <fstream>
#include <iostream>
#include <stdexcept>
#include "Pixel.h"
#include "ImageFactory.h"

#include <cstring>
#pragma optimize("", off)
int main(){
	std::ifstream str("C:\\Users\\Nikolay\\Desktop\\test.pbm", std::ios::in);
	try{
		ImageFactory fact(str);
	}
	catch (std::exception e){
		std::cout << e.what() << std::endl;
		system("PAUSE");
		throw e;
	}
	catch (char* string){
		std::cout << string << std::endl;
		system("PAUSE");
		throw string;
	}
	str.seekg(std::ios::beg);
	std::ifstream stream2("C:\\Users\\Nikolay\\Desktop\\Primo_Victoria.pbm", std::ios::in);
	char string[1024];
	while (str >> string){
		std::cout << string << std::endl;
	}
	while (stream2 >> string){
		std::cout << string << std::endl;
	}
	/*char string[1024];
	while (str >> string){
		std::cout << string << std::endl;
	}*/

	// Basic pixel tests
	/*Pixel p(13, 10, 33);
	std::cout << p.getGrayscale(2) << std::endl;
	Pixel p2;
	p2.setGrayscale(p.getGrayscale(2), 2);
	std::cout << p2.getRed() << " " << p2.getGreen() << " " << p2.getBlue() << std::endl;*/
	system("PAUSE");
	return 0;
}

//TODO:
// See a logical way to parse the headers
// Fix throws;