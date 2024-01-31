#include "ValidationHandler.h"

bool ValidationHandler::validateDataWithException(bool validationResult, const char* errorMessage)
{

	try
	{
		if (validationResult) {
			return true;
		}
		throw InvalidDataException(errorMessage);
	}
	catch (exception& excep)
	{
		cout << excep.what() << endl;
		return false;
	}

}
