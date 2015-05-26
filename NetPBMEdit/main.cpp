#include <iostream>
#include "Pixel.h"

int main(){
	Pixel p(13, 10, 33);
	std::cout << p.getGrayscale(2) << std::endl;
	Pixel p2;
	p2.setGrayscale(p.getGrayscale(2), 2);
	std::cout << p2.getRed() << " " << p2.getGreen() << " " << p2.getBlue() << std::endl;
	system("PAUSE");
	return 0;
}