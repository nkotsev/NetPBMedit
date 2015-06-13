#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cstring>

#include "Pixel.h"
#include "Image.h"
#include "ImageFactory.h"
#include "ImageTransformator.h"

#pragma optimize("", off)
int main(){
  // Monochrome
  try{
    std::ifstream inputStream("test.pbm", std::ios::in);
    ImageFactory fact(inputStream);
    Image* pImage = fact.initializeImage();
    std::ofstream outputStream("testMonoPrint.pbm", std::ios::out);
    pImage->printImage(outputStream);
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

  // Pixmap
  Image* pImage = NULL;
  try{
    std::ifstream inputStream("testRGB.ppm", std::ios::in);
    ImageFactory fact(inputStream);
    pImage = fact.initializeImage();
    for (int i = 0; i < pImage->getHeight() * pImage->getWidth(); i++){
      std::cout << pImage->getPixel(i).getRed() << " "
        << pImage->getPixel(i).getGreen() << " "
        << pImage->getPixel(i).getBlue() << std::endl;
    }
    std::ofstream outputStream("testRGBprint.ppm", std::ios::out);
    pImage->printImage(outputStream);
    outputStream.close();
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
  try{
    std::ifstream inputStream("testGrayscale.pgm", std::ios::in);
    ImageFactory fact(inputStream);
    Image* pImage = fact.initializeImage();
    for (int i = 0; i < pImage->getHeight() * pImage->getWidth(); i++){
      std::cout << pImage->getPixel(i).getGrayscale() << std::endl;
    }
    std::ofstream outputStream("testGrayscaleprint.pgm", std::ios::out);
    pImage->printImage(outputStream);
    outputStream.close();
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
  /*
  str.seekg(std::ios::beg);
  std::ifstream stream2("C:\\Users\\Nikolay\\Desktop\\Primo_Victoria.pbm", std::ios::in);
  char string[1024];
  while (str >> string){
  std::cout << string << std::endl;
  }
  while (stream2 >> string){
  std::cout << string << std::endl;
  }*/
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
  //Test Image Transformator
  char* path = "transformator_mono_result.ppm";
  char* path2 = "transformator_grayscale_result.pgm";
  std::ofstream output(path);
  ImageTransformator it2(pImage);
  Image* transformedMono = NULL;
  Image* tranformedGrayscale = NULL;
  if (it2.canTransform()){
    transformedMono = it2.transformToPlainMonochrome();
    tranformedGrayscale = it2.tranformToPlainGrayscale();
  }
  transformedMono->printImage(output);
  output.close();
  output.open(path2);
  tranformedGrayscale->printImage(output);
  output.close();
  system("PAUSE");
  return 0;
}