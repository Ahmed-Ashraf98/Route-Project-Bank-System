#pragma once
#include "Employee.h"
#include "FileManager.h"
#include "FlowManager.h"
class EmployeeManager
{
public:
	static void printEmployeeMenu();
	static void newClient(Employee* employee);
	static void listAllClients(Employee* employee);
	static void searchForClient(Employee* employee);
	static void editClientInfo(Employee* employee);
	static Employee* login();
	static bool employeeOptions(Employee* employee);
};

