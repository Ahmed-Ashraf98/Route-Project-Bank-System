#include "Client.h"

Client::Client() :balance(0) {};
Client::Client(int id, string name, string password, double balance) :Person(id, name, password)
{
	setBalance(balance);
}

void Client::setBalance(double balance)
{
	this->balance = balance;
}

double Client::getBalance()
{
	return this->balance;
}

void Client::deposit(double amount)
{
	this->balance += amount;
}

void Client::withdraw(double amount)
{
	this->balance -= amount;
}

void Client::transferTo(double amount, Client& recipient)
{
	this->balance -= amount;
	recipient.deposit(amount);
}

void Client::checkBalance()
{
	system("cls");
	cout << "------------------[balance Info]--------------------" << endl;
	cout << "\nYour current balance is : " << this->balance << endl;
	cout << "----------------------------------------------------" << endl;
}

void Client::displayInfo()
{
	cout << "---------------------[ Client Data ]------------------------" << endl;
	Person::displayInfo();
	cout << "Balance :" << this->balance << endl;
	cout << "----------------------------------------------------------" << endl;
}
