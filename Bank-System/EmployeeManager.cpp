#include "EmployeeManager.h"

void EmployeeManager::printEmployeeMenu()
{
	cout << "\nWhat do you want to do today ?" << endl;
	cout << "\n1)Know My Salary"   << "\t2)Add New Client" << endl;
	cout << "\n3)List All Clients" << "\t4)Search For Client" << endl;
	cout << "\n5)Edit Client Info" << "\t6)Display my info" << endl;
	cout << "\n\t\t7)Exit" << endl;
}

void EmployeeManager::newClient(Employee* employee)
{
	string name , password;
	double balance;

setName:
	system("cls");
	cout << "\nPlease enter the new client name : ";
	cin >> name;
	if (!BankDataValidation::validateName(name))
	{
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto setName;
		else return;
	}

setPass:
	system("cls");
	cout << "\nPlease enter the new client password : ";
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

setBalance:
	system("cls");
	cout << "\nPlease enter the new client balance : ";
	cin >> balance;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto setBalance;
		else return;
	}
	if (!BankDataValidation::validateBalance(balance))
	{
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto setBalance;
		else return;
	}

	Client* client = new Client();
	client->setName(name);
	client->setPassword(password);
	client->setBalance(balance);
	employee->addClient(*client);
	delete client;
}

void EmployeeManager::listAllClients(Employee* employee)
{
	employee->listClient();
}

void EmployeeManager::searchForClient(Employee* employee)
{
	// ask for providing the id 
	int id;
enterID:
	system("cls");
	cout << "\n Please enter the Client ID : ";
	cin >> id;
	if (cin.fail())
	{
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
	Client* client = employee->searchClient(id);
	if (client == nullptr) {
		cout << "\nNo Client Found with this Id" << endl;
		delete client;
		Sleep(1500);
		return;
	}
	cout << "\n-------------- Client Data ------------------ \n" << endl;
	cout << "Client Id : " << client->getId() << endl;
	cout << "Client Name : " << client->getName() << endl;
	cout << "Client Password : " << client->getPassword() << endl;
	cout << "Client Balance : " << client->getBalance() << endl;
	
	delete client;
}

void EmployeeManager::editClientInfo(Employee* employee)
{
	int id,choice;
	string name, password;
	double balance = -1;
	Client* client;
	bool endUpdate=false;

enterID:
	system("cls");
	cout << "\n Please enter the Client ID : ";
	cin >> id;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return;
	}
	if (id <= 0 )
	{
		cout << "\nIncorrect Id , the Id should be larger than zero\n" << endl;
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return;
	}
	client = employee->searchClient(id);
	if (client == nullptr)
	{
		cout << "\nNo Client Found with this Id" << endl;
		Sleep(1500);
		delete client;
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return;
	}

	// select data to update (name , password , balance)
	

	while (!endUpdate)
	{
	chooseUpdateOption:
		system("cls");
		cout << "\n Please select the data that you need to update for Client [ "
			<< client->getName() << " , ID : " << client->getId() << " ] : \n";

		cout << "\n1)Update Name" << "\t\t2)Update Password" << endl;
		cout << "\n3)Update Balance" << "\t4)Exit & Confirm" << endl;
		cout << "\n\nYour choice : ";
		cin >> choice;
		if (cin.fail())
		{
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
		case 2 :
			setPass:
			system("cls");
			cout << "\nPlease enter the new password : ";
			cin >> password;
			if (cin.fail())
			{
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
			setBalance:
			system("cls");
			cout << "\nPlease enter the new balance : ";
			cin >> balance;
			if (cin.fail())
			{
				FlowManager::unexpectedInput();
				balance = -1;
				if (FlowManager::doYouWantToTryAgain()) goto setBalance;
				else break;
			}
			if (!BankDataValidation::validateBalance(balance))
			{
				Sleep(1500);
				balance = -1;
				if (FlowManager::doYouWantToTryAgain()) goto setBalance;
				else break;
			}
			cout << "\Balance is updated locally, after finshing updates please choose [ Exit & Confirm ]\n";
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

	if (name == "" && password == "" && balance < 0) {
		cout << "\nNo Updates !!\n";
		return;
	}


	employee->editClient(id,
		name == "" ? client->getName() : name,
		password == "" ? client->getPassword() : password,
		balance < 0 ? client->getBalance() : balance);

	delete client;
}

Employee* EmployeeManager::login()
{
	int empId;
	string empPassword;
enterID:
	system("cls");
	cout << "\nPlease enter your ID: ";
	cin >> empId;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return nullptr;
	}

	if (empId <= 0 ) {
		cout << "\nIncorrect Id , the Id should be larger than zero\n" << endl;
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return nullptr;
	}

	Employee* emp;
	emp = FileManager::employeeExists(empId);

	if (emp == nullptr)
	{
		cout << "\nThis Id doesn't exist!!";
		delete emp;
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return nullptr;
	}

enterPass:
	system("cls");
	cout << "\nPlease enter your Password: ";
	cin >> empPassword;
	
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto enterPass;
		else return nullptr;
	}

	if (!(emp->getPassword() == empPassword))
	{
		cout << "\n\nIncorrect password!!";
		if (FlowManager::doYouWantToTryAgain()) goto enterPass;
		else return nullptr;
	}
	cout << "\n\n\t\tWelcome  " << emp->getName() << endl;
	Sleep(1500);
	return emp;
}

bool EmployeeManager::employeeOptions(Employee* employee)
{

	bool dontExit = true;

	while (dontExit) {
	selectOption:
		system("cls");
		printEmployeeMenu();
		int menuChoice;
		cout << "\nYour choice : ";
		cin >> menuChoice;
		if (cin.fail())
		{
			FlowManager::unexpectedInput();
			goto selectOption;
		}
		switch (menuChoice)
		{
		case 1:
			system("cls");
			cout << "\nYour Salary is : " << employee->getSalary() << " EGP." << endl;
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 2:
			system("cls");
			newClient(employee);
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 3:
			system("cls");
			listAllClients(employee);
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 4:
			system("cls");
			searchForClient(employee);
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 5:
			system("cls");
			editClientInfo(employee);
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 6:
			system("cls");
			employee->displayInfo();
			dontExit = FlowManager::doYouWantToContinue();
			break;
		case 7:
			dontExit = false; break;
		default:
			system("cls");
			cout << "The selected option is not available in the menu, please try again !!";
			break;
		}
	}
	delete employee;
	return true; // exit from employee
}
