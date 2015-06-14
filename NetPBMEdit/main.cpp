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
  Image* pImageMonochrome;
  try{
    std::ifstream inputStream("test.pbm", std::ios::in);
    ImageFactory fact(inputStream);
    pImageMonochrome = fact.initializeImage();
    std::ofstream outputStream("testMonoPrint.pbm", std::ios::out);
    pImageMonochrome->printImage(outputStream);
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
  Image* pImagePixmap = NULL;
  try{
    std::ifstream inputStream("testRGB.ppm", std::ios::in);
    ImageFactory fact(inputStream);
    pImagePixmap = fact.initializeImage();
    std::ofstream outputStream("testRGBprint.ppm", std::ios::out);
    pImagePixmap->printImage(outputStream);
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
  //Grayscale
  Image* pImageGrayscale;
  try{
    std::ifstream inputStream("testGrayscale.pgm", std::ios::in);
    ImageFactory fact(inputStream);
    pImageGrayscale = fact.initializeImage();
    std::ofstream outputStream("testGrayscaleprint.pgm", std::ios::out);
    pImageGrayscale->printImage(outputStream);
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
  //Test Image Transformator
  char* path  = "transformator_mono_result.ppm";
  char* path2 = "transformator_grayscale_result.pgm";
  char* path3 = "testGrayscaleToMonochrome.pbm";
  char* path4 = "testMonochromeToGrayscale.pbm";
  
  ImageTransformator it2(pImagePixmap);
  Image* transformedMono = NULL;
  Image* tranformedGrayscale = NULL;
  Image* grayscaleTransofrmedtoMonochrome = NULL;
  Image* monochromeToGrayscale = NULL;
  if (it2.canTransform()){
    transformedMono = it2.transformToPlainMonochrome();
    tranformedGrayscale = it2.tranformToPlainGrayscale();
    it2.setSource(pImageGrayscale);
    grayscaleTransofrmedtoMonochrome = it2.transformToPlainMonochrome();
    it2.setSource(pImageMonochrome);
    monochromeToGrayscale = it2.transformToPlainMonochrome();
  }
  std::ofstream output;
  if (transformedMono){
    output.open(path);
    transformedMono->printImage(output);
    output.close();
  }
  if (tranformedGrayscale){
    output.open(path2);
    tranformedGrayscale->printImage(output);
    output.close();
  }
  if (grayscaleTransofrmedtoMonochrome){
    output.open(path3);
    grayscaleTransofrmedtoMonochrome->printImage(output);
    output.close();
  }
  if (monochromeToGrayscale){
    output.open(path4);
    monochromeToGrayscale->printImage(output);
    output.close();
  }
  system("PAUSE");
  return 0;
}