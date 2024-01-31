#include "Employee.h"
#include "FileManager.h"

Employee::Employee() :salary(0) {};
Employee::Employee(int id, string name, string password, double salary) :Person(id, name, password)
{
	setSalary(salary);
}


void Employee::setSalary(double salary)
{
	this->salary = salary;
}

double Employee::getSalary()
{
	return this->salary;
}

void Employee::addClient(Client& client)
{
	FileManager::addClient(client);
}

Client* Employee::searchClient(int id)
{
	Client* client = nullptr;
	vector<Client> getAllClients = FileManager::getAllClients();
	int clientsListSize = getAllClients.size();
	for (int i = 0; i < clientsListSize; i++)
	{
		if (getAllClients[i].getId() == id)
		{
			client =new Client(getAllClients[i]);
			return client;
		}
	}
	return client;
}

void Employee::listClient()
{
	vector<Client> getAllClients = FileManager::getAllClients();
	int clientsListSize = getAllClients.size();
	cout << "\n################################### [ All Clients in the Bank ] ########################### : \n" << endl;
	for (int i = 0; i < clientsListSize; i++)
	{
		cout << "---------------------------- "<< i+1 <<" ------------------------" << endl;
		cout << "Id : " << getAllClients[i].getId() << endl;
		cout << "Name : " << getAllClients[i].getName() << endl;
		cout << "Password : " << getAllClients[i].getPassword() << endl;
		cout << "Balance : " << getAllClients[i].getBalance() << endl;
	}

	cout << "\n#############################################################################################\n" << endl;

}

void Employee::editClient(int id, string name, string password, double balance)
{
	FileManager::editClient(Client(id, name, password, balance));
}

void Employee::displayInfo()
{
	cout << "---------------------[ Employee Data ]------------------------" << endl;
	Person::displayInfo();
	cout << "Salary :" << this->salary << endl;
	cout << "----------------------------------------------------------" << endl;
}
