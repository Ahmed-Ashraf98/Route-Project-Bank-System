#include "InvalidDataException.h"

InvalidDataException::InvalidDataException(const char* errorMessage)
{
    col = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col, 4);
    this->errorMessage = errorMessage;
}

char const* InvalidDataException::what() const
{
    return errorMessage;
}

InvalidDataException::~InvalidDataException()
{
    SetConsoleTextAttribute(col, 7);
}



/*
 string className = typeid(*this).name();
 className = className.replace(0, 6,"");
*/