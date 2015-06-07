#pragma once
#include <stdexcept>
class ArgumentManagerException :
	public std::runtime_error
{
	char* message;
public:
	ArgumentManagerException();
	ArgumentManagerException(char* message);
	ArgumentManagerException& operator=(const ArgumentManagerException&);
	~ArgumentManagerException();
	/*DivideByZeroException(int x, int y)
		: runtime_error("division by zero"), numerator(x), denominator(y)
	{}*/
	virtual const char* what() const throw();
};

