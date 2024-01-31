#include "Validation.h"

bool Validation::isStrSizeWithinRange(string str, int minNum, int maxNum)
{
	if (str.size() >= minNum && str.size() <= maxNum) {
		return true;
	}
	return false;
}

bool Validation::isAlphabetic(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (!isalpha(str[i])) {
			return false;
		}
	}
	return true;
}

bool Validation::isContainsSpace(string str)
{
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') {
			return true;
		}
	}
	return false;
}

bool Validation::isNumberMoreThanOrEqualN(double number, double minNum)
{
	if (number >= minNum) {
		return true;
	}
	return false;
}


