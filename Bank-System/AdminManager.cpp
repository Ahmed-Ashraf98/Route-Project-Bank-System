#include "AdminManager.h"

void AdminManager::printAdminMenu()
{
	cout << "\nWhat do you want to do today ?" << endl;
	cout << "\n1)Know My Salary"     << "\t2)Add New Client" << endl;
	cout << "\n3)List All Clients"   << "\t4)Search For Client" << endl;
	cout << "\n5)Edit Client Info"   << "\t6)Add New Employee" << endl;
	cout << "\n7)List All Employees" << "\t8)Search For Employee" << endl;
	cout << "\n9)Edit Employee Info" << "\t10)Add New Admin " << endl;
	cout << "\n11)List All Admins"   << "\t12)Search For Admin " << endl;
	cout << "\n13)Edit Admin Info"   << "\t14)Display my info" << endl;
	cout << "\n\t\t15)Exit" << endl;
}

Admin* AdminManager::createAdminForTheFirstTime()
{

	string name, password;
	double salary;
setName:
	system("cls");
	cout << "\nHello, since this is the first time to run the app, you will need to create a new admin!" << endl;
	cout << "\nAfter creating the admin you will be logged in automatically :) \n" << endl;
	cout << "\nPlease enter the Admin name : ";
	cin >> name;
	if (!BankDataValidation::validateName(name))
	{
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto setName;
		else return nullptr;
	}

setPass:
	system("cls");
	cout << "\nPlease enter the new Admin password : ";
	cin >> password;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto setPass;
		else return nullptr;
	}
	if (!BankDataValidation::validatePassword(password))
	{
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto setPass;
		else return nullptr;
	}

setSalary:
	system("cls");
	cout << "\nPlease enter the new Admin salary : ";
	cin >> salary;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto setSalary;
		else return nullptr;
	}
	if (!BankDataValidation::validateSalary(salary))
	{
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto setSalary;
		else return nullptr;
	}
	
	Admin* ad = new Admin();
	ad->setName(name);
	ad->setPassword(password);
	ad->setSalary(salary);
	FileManager::addAdmin(*ad);
	delete ad;
	ad = FileManager::adminExists(1);
	return ad;
}

void AdminManager::newUser(Admin* admin, bool objIsAdmin)
{
	string name, password , objName= objIsAdmin ? "Admin" : "Employee";
	double salary;

setName:
	system("cls");
	cout << "\nPlease enter the new "<< objName << " name : ";
	cin >> name;
	if (!BankDataValidation::validateName(name))
	{
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto setName;
		else return;
	}

setPass:
	system("cls");
	cout << "\nPlease enter the new " << objName << " password : ";
	cin >> password;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto setPass;
		else return;
	}
	if (!BankDataValidation::validatePassword(password))
	{
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto setPass;
		else return;
	}

setSalary:
	system("cls");
	cout << "\nPlease enter the new " << objName << " salary : ";
	cin >> salary;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto setSalary;
		else return;
	}
	if (!BankDataValidation::validateSalary(salary))
	{
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto setSalary;
		else return;
	}

	if (objIsAdmin) {
		Admin* ad = new Admin();
		ad->setName(name);
		ad->setPassword(password);
		ad->setSalary(salary);
		admin->addAdmin(*ad);
		delete ad;
	}
	if (!objIsAdmin) {
		Employee* emp = new Employee();
		emp->setName(name);
		emp->setPassword(password);
		emp->setSalary(salary);
		admin->addEmployee(*emp);
		delete emp;
	}

}

void AdminManager::searchForUser(Admin* admin, bool objIsAdmin)
{
	// ask for providing the id 
	int id;
	string objName = objIsAdmin ? "Admin" : "Employee";
enterID:
	system("cls");
	cout << "\n Please enter the "<< objName <<" ID : ";
	cin >> id;
	if (cin.fail()) {
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return;
	}
	if (id <= 0)
	{
		cout << "\nIncorrect Id , the Id should be larger than zero\n" << endl;
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return;
	}

	Employee* user = objIsAdmin ? admin->searchAdmin(id) : admin->searchEmployee(id);
	if (user == nullptr) {
		cout << "\nNo " << objName << " Found with this Id" << endl;
		Sleep(1500);
		return;
	}
	cout << "\n-------------- " << objName << " Data ------------------ \n" << endl;
	cout << objName << " Id : " << user->getId() << endl;
	cout << objName << " Name : " << user->getName() << endl;
	cout << objName << " Password : " << user->getPassword() << endl;
	cout << objName << " Balance : " << user->getSalary() << endl;

	delete user;
}

void AdminManager::editUserInfo(Admin* admin, bool objIsAdmin)
{
	string objName = objIsAdmin ? "Admin" : "Employee";
	int id, choice;
	string name, password;
	double salary =-1;
	Employee* user;
	bool endUpdate = false;

enterID:
	system("cls");
	cout << "\n Please enter the " << objName << " ID : ";
	cin >> id;
	if (cin.fail()) {
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return;
	}
	if (id <= 0)
	{
		cout << "\nIncorrect Id , the Id should be larger than zero\n" << endl;
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return;
	}
	user = objIsAdmin? admin->searchAdmin(id) : admin->searchEmployee(id);
	if (user == nullptr)
	{
		cout << "\nNo "<<objName<< " Found with this Id" << endl;
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return;
	}

	// select data to update (name , password , balance)


	while (!endUpdate)
	{
		chooseUpdateOption:
		system("cls");
		cout << "\nPlease select the data that you need to update for " << objName << " [ "
			<< user->getName() << " , ID : " << user->getId() << " ] : \n";
		cout << "\n1)Update Name"   << "\t2)Update Password" << endl;
		cout << "\n3)Update Salary" << "\t4)Exit & Confirm" << endl;

		cout << "\n\nYour choice : ";
		cin >> choice;
		if (cin.fail()) {
			FlowManager::unexpectedInput();
			goto chooseUpdateOption;
		}
		switch (choice)
		{
		case 1:
			setName:
			system("cls");
			cout << "\nPlease Enter the new name : ";
			cin >> name;
			if (!BankDataValidation::validateName(name))
			{
				Sleep(1500);
				name = "";
				if (FlowManager::doYouWantToTryAgain()) goto setName;
				else break;
			}
			cout << "\nName is updated locally, after finshing updates please choose [ Exit & Confirm ]\n";
			Sleep(2500);
			break;
		case 2:
			setPass:
			system("cls");
			cout << "\nPlease enter the new password : ";
			cin >> password;
			if (cin.fail()) {
				FlowManager::unexpectedInput();
				password = "";
				if (FlowManager::doYouWantToTryAgain()) goto setPass;
				else break;
			}
			if (!BankDataValidation::validatePassword(password))
			{
				Sleep(1500);
				password = "";
				if (FlowManager::doYouWantToTryAgain()) goto setPass;
				else break;
			}
			cout << "\Password is updated locally, after finshing updates please choose [ Exit & Confirm ]\n";
			Sleep(2500);
			break;
		case 3:
			setSalary:
			system("cls");
			cout << "\nPlease enter the new salary : ";
			cin >> salary;
			if (cin.fail()) {
				FlowManager::unexpectedInput();
				salary = -1;
				if (FlowManager::doYouWantToTryAgain()) goto setSalary;
				else break;
			}
			if (!BankDataValidation::validateSalary(salary))
			{
				Sleep(1500);
				salary = -1;
				if (FlowManager::doYouWantToTryAgain()) goto setSalary;
				else break;
			}
			cout << "\Salary is updated locally, after finshing updates please choose [ Exit & Confirm ]\n";
			Sleep(2500);
			break;

		case 4:
			endUpdate = true; break;
		default:
			cout << "\nUnknown option :( , please try again" << endl;
			Sleep(2500);
			break;
		}
	}

	if (name == "" && password == "" && salary < 0) {
		cout << "\nNo Updates !!\n"; 
		return;
	}

	objIsAdmin ? 
		
	admin->editAdmin(id,
		name == "" ? user->getName() : name,
		password == "" ? user->getPassword() : password,
		salary < 0 ? user->getSalary() : salary) :
	
	admin->editEmployee(id,
		name == "" ? user->getName() : name,
		password == "" ? user->getPassword() : password,
		salary < 0 ? user->getSalary() : salary);

	delete user;
}

void AdminManager::listAllUsers(Admin* admin, bool objIsAdmin)
{
	objIsAdmin ? admin->listAdmin() : admin->listEmployee();
}

Admin* AdminManager::login()
{
	int adminId;
	string adminPassword;
	int adminsListSize = FileManager::getAllAdmins().size();

	if (adminsListSize == 0) { // if no admin created before, then enforce admin creation
		return createAdminForTheFirstTime();
	}

enterID:	
	system("cls");
	cout << "\nPlease enter your ID: ";
	cin >> adminId;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return nullptr;
	}

	if (adminId <= 0)
	{
		cout << "\nIncorrect Id , the Id should be larger than zero\n" << endl;
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return nullptr;
	}

	Admin* admin;

	admin = FileManager::adminExists(adminId);

	if (admin == nullptr)
	{
		cout << "\nThis Id doesn't exist!!";
		Sleep(1500);
		delete admin;
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return nullptr;
	}

enterPass:
	system("cls");
	cout << "\nPlease enter your Password: ";
	cin >> adminPassword;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto enterPass;
		else return nullptr;
	}
	if (!(admin->getPassword() == adminPassword))
	{
		cout << "\n\nIncorrect password!!,";
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto enterPass;
		else return nullptr;
	}
	cout << "\n\n\t\tWelcome  " << admin->getName() << endl;
	Sleep(1500);
	return admin;
}

bool AdminManager::AdminOptions(Admin* admin)
{
	bool dontExit = true;

	while (dontExit) {
	selectOption:
		system("cls");
		printAdminMenu();
		int menuChoice;
		cout << "\nYour choice : ";
		cin >> menuChoice;
		
		if(cin.fail())
		{
			FlowManager::unexpectedInput();
			goto selectOption;
		}

		switch (menuChoice)
		{
		case 1:
			system("cls");
			cout << "\nYour Salary is : " << admin->getSalary() << " EGP." << endl;
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 2:
			system("cls");
			EmployeeManager::newClient(admin);
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 3:
			system("cls");
			EmployeeManager::listAllClients(admin);
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 4:
			system("cls");
			EmployeeManager::searchForClient(admin);
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 5:
			system("cls");
			EmployeeManager::editClientInfo(admin);
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 6:
			system("cls");
			newUser(admin, false); // flase = create employee
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 7:
			system("cls");
			listAllUsers(admin, false);// flase = get all employees
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 8:
			system("cls");
			searchForUser(admin,false); // flase = search for  employee
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 9:
			system("cls");
			editUserInfo(admin, false);// flase = update employee
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 10:
			system("cls");
			newUser(admin, true); // true = create admin
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 11:
			system("cls");
			listAllUsers(admin,true); // true = get all admins
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 12:
			system("cls");
			searchForUser(admin, true); // true = search for admin
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 13:
			system("cls");
			editUserInfo(admin,true); // true = edit admin
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 14:
			system("cls");
			admin->displayInfo();
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 15:
			dontExit = false; break;
		default:
			system("cls");
			cout << "The selected option is not available in the menu, please try again !!";
			break;
		}
	}
	delete admin;
	return true; // exit from admin
}
