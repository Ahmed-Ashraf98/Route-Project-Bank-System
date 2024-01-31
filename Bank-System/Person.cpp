#include "Person.h"
Person::Person() :id(0) {};
Person::Person(int id, string name, string password)
{
	setName(name);
	setPassword(password);
	this->id = id;
}

void Person::setId(int id)
{
	this->id = id;
}

void Person::setName(string name)
{
	if (BankDataValidation::validateName(name)) {
		this->name = name;
	}
}

void Person::setPassword(string password)
{
	if (BankDataValidation::validatePassword(password)) {
		this->password = password;
	}
}

int Person::getId()
{
	return id;
}

string Person::getName()
{
	return name;
}

string Person::getPassword()
{
	return password;
}

void Person::displayInfo()
{
	//system("cls");
	cout << "ID : " << this->id << endl;
	cout << "Name : " << this->name << endl;
	cout << "Password : " << this->password << endl;
}