#pragma once
#include "Admin.h"
#include <vector>
#include <fstream>
#include <string>
class DataSourceInterface
{
public:

	virtual void addClient(Client client) = 0;
	virtual void addEmployee(Employee employee) = 0;
	virtual void addAdmin(Admin admin) = 0;
	virtual vector<Client> getAllClients() = 0;
	virtual vector<Employee>getAllEmployees() = 0;
	virtual vector<Employee>getAllAdmins() = 0;
	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;
};

