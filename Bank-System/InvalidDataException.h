#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;
class InvalidDataException : public exception
{
private:
    HANDLE col;
    const char* errorMessage;
public:
    InvalidDataException(const char* errorMessage);
    char const* what() const;
    ~InvalidDataException();
};

