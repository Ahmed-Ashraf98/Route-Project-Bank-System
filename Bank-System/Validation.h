#pragma once
#include <iostream>
using namespace std;
/// <remarks>
/// This class made just for input validation, hince that, you can't create a new object from this class.
/// </remarks>
class Validation
{

private:
	// This method will prevent you from creating an Object from this class,
	// This method is not accessable from anywhere, just inside this class,
	// Don't modify this method!!
	virtual void NotForObjectCreation() = 0;

public:

	/// <summary>
	/// This method to check the string length size is in the Range.
	/// </summary>
	/// <param name="str"> : The word or the string that you need to check </param>
	/// <param name="minNum"> : The min size of the string length</param>
	/// <param name="maxNum"> : The max size of the string length</param>
	/// <returns> boolean => true - if the string size is within the range</returns>
	static bool isStrSizeWithinRange(string str, int minNum, int maxNum);

	/// <summary>
	/// This method to check if the string is Alphabetic.
	/// </summary>
	/// <param name="name"> : The string that you need to check </param>
	/// <returns> boolean => true - if the string is Alphabetic </returns>
	static bool isAlphabetic(string str);

	/// <summary>
	/// This method to check if the string is containing spaces.
	/// </summary>
	/// <param name="name"> : The string that you need to check </param>
	/// <returns> boolean => true - if the string is containing spaces </returns>
	static bool isContainsSpace(string str);

	/// <summary>
	/// This method to check if Number is not smallerthan the min number.
	/// In this project , it can be used in checking the minimum balance and minimum salary
	/// </summary>
	/// <param name="number"> : The number that will be checked </param>
	/// <param name="minNum"> : The minimum number that will be used in the comparison</param>
	/// <returns> boolean => true - if the number is more than or equal the minimum number </returns>
	static bool isNumberMoreThanOrEqualN(double number, double minNum);

};

