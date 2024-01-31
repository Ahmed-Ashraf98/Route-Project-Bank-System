#pragma once
#include <iostream>
#include "BankDataValidation.h"
#include "ClientManger.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "Admin.h"
using namespace std;
class Screens
{
public:
	static void bankName();
	static void welcome();
	static void loginOptions();
	static int loginAs();
	static void invalid(int c);
	static void logout();
	static void loginScreen(int c);
	static void runApp();
};

