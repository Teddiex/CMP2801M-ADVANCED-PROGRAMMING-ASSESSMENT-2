#pragma once
#include <iostream>


class getError
{
private:
	std::string errorMessage;
public:
	getError(std::string error);
	std::string getErrorMsg();
};
