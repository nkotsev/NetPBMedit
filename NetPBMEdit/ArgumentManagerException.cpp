#include "ArgumentManagerException.h"
#include <cstring>
#include <iostream>

ArgumentManagerException::ArgumentManagerException() :runtime_error("Argument list exception"), message(NULL)
{

}

ArgumentManagerException::ArgumentManagerException(char* message):runtime_error(message){
	try{
		this->message = new char[strlen(message) + 1];
	}
	catch (...){ //Exceptions shouldn't throw exceptions.
		std::cerr << "Unable to allocate memory. Terminating." << std::endl;
		exit(1);
	}
	strcpy(this->message, message);
}

ArgumentManagerException::~ArgumentManagerException()
{
	delete[] message;
}

const char* ArgumentManagerException::what() const throw(){
	return (const char*) message;
}

ArgumentManagerException& ArgumentManagerException::operator=(const ArgumentManagerException& other){
	if (this == &other){
		return *this;
	}

}
