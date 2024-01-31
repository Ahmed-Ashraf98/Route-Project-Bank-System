#pragma once

#include "Admin.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
class Parser
{
public:
	static vector<string> split(string line);
	static Client parseToClient(string line);
	static Employee parseToEmployee(string line);
	static Admin parseToAdmin(string line);
	static string parseClientToStr(Client client);
	static string parseEmployeeToStr(Employee employee);
	static string parseAdminToStr(Employee admin);
};

