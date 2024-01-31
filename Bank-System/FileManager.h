#pragma once
#include "DataSourceInterface.h"
#include "FilesHelper.h"
class FileManager : public DataSourceInterface
{

public:
	static Client* clientExists(int id);
	static Employee* employeeExists(int id);
	static Admin* adminExists(int id);
	static void addClient(Client client);
	static void editClient(Client client);
	static void addEmployee(Employee employee);
	static void editEmployee(Employee employee);
	static void addAdmin(Admin admin);
	static void editAdmin(Admin admin);
	static vector<Client> getAllClients();
	static vector<Employee>getAllEmployees();
	static vector<Employee>getAllAdmins();
	static void removeAllClients();
	static void removeAllEmployees();
	static void removeAllAdmins();
};

