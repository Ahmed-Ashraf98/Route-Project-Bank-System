#pragma once
#include "InvalidDataException.h"
class ValidationHandler
{
private:
	// This method will prevent you from creating an Object from this class,
	// This method is not accessable from anywhere, just inside this class,
	// Don't modify this method!!
	virtual void NotForObjectCreation() = 0;

public:
	static bool validateDataWithException(bool validationResult, const char* errorMessage);

};