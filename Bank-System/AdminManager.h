#pragma once
#include "Admin.h"
#include "FileManager.h"
#include "EmployeeManager.h"
class AdminManager
{
public:
	static void printAdminMenu();
	static Admin* createAdminForTheFirstTime();
	static void newUser(Admin* admin ,  bool objIsAdmin);
	static void searchForUser(Admin* admin,bool objIsAdmin);
	static void editUserInfo(Admin* admin , bool objIsAdmin);
	static void listAllUsers(Admin* admin , bool objIsAdmin);
	static Admin* login();
	static bool AdminOptions(Admin* admin);
};

