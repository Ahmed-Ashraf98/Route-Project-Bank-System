#include "BankDataValidation.h"

bool BankDataValidation::validateName(string name, bool throwExcepWhenError)
{
	bool validationResult = Validation::isAlphabetic(name) && Validation::isStrSizeWithinRange(name, 5, 20);
	const char* errorMsg = "\nError :( !!, Please check if the name is alphabetic and the Number of characters between 5 - 20 \n";

	if (!throwExcepWhenError) {
		return validationResult;
	}

	return ValidationHandler::validateDataWithException(validationResult, errorMsg);

}

bool BankDataValidation::validatePassword(string password, bool throwExcepWhenError)
{
	bool validationResult = Validation::isStrSizeWithinRange(password, 8, 20) && !Validation::isContainsSpace(password);
	const char* errorMsg = "\nError :( !!, the password length should between 8 - 20 and doesn't conatin spaces \n";

	if (!throwExcepWhenError) {
		return validationResult;
	}

	return ValidationHandler::validateDataWithException(validationResult, errorMsg);
}

bool BankDataValidation::validateBalance(double balance, bool throwExcepWhenError)
{
	bool validationResult = Validation::isNumberMoreThanOrEqualN(balance, 1500);
	const char* errorMsg = "\nError(X) = > The minimum balance is 1500 EGP !!\n";

	if (!throwExcepWhenError) {
		return validationResult;
	}

	return ValidationHandler::validateDataWithException(validationResult, errorMsg);
}

bool BankDataValidation::validateSalary(double salary, bool throwExcepWhenError)
{
	bool validationResult = Validation::isNumberMoreThanOrEqualN(salary, 5000);
	const char* errorMsg = "\nError(X) = > The minimum Salary is 5000 EGP !!\n";

	if (!throwExcepWhenError) {
		return validationResult;
	}

	return ValidationHandler::validateDataWithException(validationResult, errorMsg);
}
