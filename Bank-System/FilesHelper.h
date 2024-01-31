#pragma once
#include "Parser.h"
using namespace std;

class FilesHelper
{

private:
	static bool clientExists(Client client);
	static bool employeeExists(Employee employee);
	static bool adminExists(Employee admin);

public:
	static Client* clientExists(int id);
	static Employee* employeeExists(int id);
	static Admin* adminExists(int id);
	static void saveLast(string fileName, int id);
	static int getLast(string fileName);
	static void saveClient(Client c , bool addNew);
	//static void removeClient(int id);
	static void saveEmployee(string fileName, string lastIdFile, Employee e , bool addNew);
	//static void removeEmployee(string fileName, int id);
	static vector<Client> getClients();
	static vector<Employee> getEmployees();
	static vector<Employee> getAdmins();
	static void clearFile(string fileName, string lastIdFile);
};