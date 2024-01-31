#pragma once
#include "Client.h"
class Employee : public Person
{
protected:
	double salary;
public:
	Employee();
	Employee(int id, string name, string password, double salary);
	void setSalary(double salary);
	double getSalary();
	void addClient(Client& client);
	Client* searchClient(int id);
	void listClient();
	void editClient(int id, string name, string password, double balance);
	void displayInfo();
};
