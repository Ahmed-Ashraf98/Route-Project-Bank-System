#pragma once
#include "BankDataValidation.h"
#include <iostream>
using namespace std;


class Person
{
protected:
	int id;
	string name, password;
public:
	Person();
	Person(int id, string name, string password);
	void setId(int id);
	void setName(string name);
	void setPassword(string password);
	int getId();
	string getName();
	string getPassword();
	virtual void displayInfo();
};

