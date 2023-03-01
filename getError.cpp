#include "getError.h"
#include <iostream>

getError::getError(std::string error)
{
	errorMessage = error;
}

std::string getError::getErrorMsg()
{
	return errorMessage;
}
