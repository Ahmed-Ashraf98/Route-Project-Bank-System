#pragma once
#include "ValidationHandler.h";
#include "Validation.h";
class BankDataValidation
{
private:
	// This method will prevent you from creating an Object from this class,
	// This method is not accessable from anywhere, just inside this class,
	// Don't modify this method!!
	virtual void NotForObjectCreation() = 0;
public:
	static bool validateName(string name, bool throwExcepWhenError = true);
	static bool validatePassword(string password, bool throwExcepWhenError = true);
	static bool validateBalance(double balance, bool throwExcepWhenError = true);
	static bool validateSalary(double salary, bool throwExcepWhenError = true);
};

