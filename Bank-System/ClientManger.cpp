#include "ClientManger.h"

void ClientManger::printClientMenu()
{
	cout << "\nHow we can help you today ?" << endl;
	cout << "\n1)Know my balance" << "\t2)Update my password" << endl;
	cout << "\n3)Deposite"        << "\t\t4)Withdraw" << endl;
	cout << "\n5)Transfer Money"  << "\t6)Display my info" << endl;
	cout << "\n\t\t7)Exit" << endl;
}

void ClientManger::updatePassword(Person* person)
{
	string newPass;
setPass:
	system("cls");
	cout << "\nPlease enter the new password: ";
	cin >> newPass;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto setPass;
		else return;
	}
	if(!BankDataValidation::validatePassword(newPass)){
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto setPass;
		else return;
	}
	person->setPassword(newPass);
}

void ClientManger::depositeAmount(Client* client)
{
	double amount;
setAmount:
	system("cls");
	cout << "\nPlease enter the amount that you want to deposite : ";
	cin >> amount;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto setAmount;
		else return;
	}
	bool validationResult = Validation::isNumberMoreThanOrEqualN(amount, 1);
	const char* errorMsg = "\nError (X) => you can't deposit negative or zero amounts!!\n";

	if (!ValidationHandler::validateDataWithException(validationResult, errorMsg)) {
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto setAmount;
		else return;
	}
	
	client->deposit(amount);
	FileManager::editClient(*client);
}

void ClientManger::withdrawAmount(Client* client)
{
	double amount;
setAmount:
	system("cls");
	cout << "\nPlease enter tha amount that you want to withdraw : ";
	cin >> amount;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto setAmount;
		else return;
	}

	bool validateAmount = Validation::isNumberMoreThanOrEqualN(amount, 1),
	validateAmountBalance = Validation::isNumberMoreThanOrEqualN(client->getBalance(), amount);

	const char* amountErrorMsg = "\nError (X) => you can't withdraw negative or zero amounts!!\n",
		* amountBalanceErrorMsg = "\nError (X) => Fund insufficient!!\n";

	if (!(ValidationHandler::validateDataWithException(validateAmount, amountErrorMsg) ) || !(ValidationHandler::validateDataWithException(validateAmountBalance, amountBalanceErrorMsg)) ) {
		Sleep(1000);
		if (FlowManager::doYouWantToTryAgain()) goto setAmount;
		else return;
	}
	client->withdraw(amount);
	FileManager::editClient(*client);
}

void ClientManger::transferAmount(Client* client)
{
	// ask the user to provide the client that he want to tranfer to
	// ask the user to provide the amount
	// update the both accounts info
	int cId;
enterID:
	system("cls");
	cout << "\nPlease enter the Account ID that you want to transfer to: ";
	cin >> cId;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return;
	}

	if (cId == client->getId())
	{
		cout << "\nYou can't transfer monye to your account!!";
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return;
	}

	Client* recipient;
	recipient = FilesHelper::clientExists(cId);

	if (recipient == nullptr)
	{
		cout << "\nThis Id doesn't exist!!";
		Sleep(1500);
		delete recipient;
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return;
	}

	double amount;
setAmount:
	system("cls");
	cout << "\nPlease enter tha amount that you want to transfer to Account [ " << recipient->getId() << " - "<< recipient->getName()<< " ] : ";
	cin >> amount;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto setAmount;
		else return;
	}

	bool validateAmount = Validation::isNumberMoreThanOrEqualN(amount, 1),
		validateAmountBalance = Validation::isNumberMoreThanOrEqualN(client->getBalance(), amount);
	const char* amountErrorMsg = "\nError (X) => you can't transfer negative or zero amounts!!\n",
		* amountBalanceErrorMsg = "\nError (X) => Fund insufficient!!\n";

	if (!(ValidationHandler::validateDataWithException(validateAmount, amountErrorMsg)) || !(ValidationHandler::validateDataWithException(validateAmountBalance, amountBalanceErrorMsg))) {
		Sleep(1500);
		if (FlowManager::doYouWantToTryAgain()) goto setAmount;
		else return;
	}

	client->transferTo(amount, *recipient);
	cout << "Client " << recipient->getId() << " - " << recipient->getName();
	FileManager::editClient(*recipient);// update the recipient data here
	cout << "Client " << client->getId() << " - " << client->getName();
	FileManager::editClient(*client);
	delete recipient;
}

Client* ClientManger::login()
{
	int cId;
	string cPassword;
enterID:
	system("cls");
	cout << "\nPlease enter your ID: ";
	cin >> cId;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return nullptr;
	}

	Client* c;
	c = FileManager::clientExists(cId);
	
	if (c == nullptr)
	{
		cout << "\nThis Id doesn't exist!!";
		Sleep(1000);
		delete c;
		if (FlowManager::doYouWantToTryAgain()) goto enterID;
		else return nullptr;
	}

enterPass:
	system("cls");
	cout << "\nPlease enter your Password: ";
	cin >> cPassword;
	if (cin.fail())
	{
		FlowManager::unexpectedInput();
		if (FlowManager::doYouWantToTryAgain()) goto enterPass;
		else return nullptr;
	}
	if (!(c->getPassword() == cPassword))
	{
		cout << "\n\nIncorrect password!!\n";
		Sleep(1000);
		if (FlowManager::doYouWantToTryAgain()) goto enterPass;
		else return nullptr;
	}
	cout << "\n\n\t\tWelcome  " << c->getName() <<endl;
	Sleep(1500);
	return c;
}

bool ClientManger::clientOptions(Client* client)
{
	Person* person = client;

	bool dontExit = true;
	
while (dontExit){
selectOption:
    system("cls");
	printClientMenu();
	string oldPass;
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
		cout << "\nYour Balance is : " << client->getBalance() << " EGP." << endl; 
		dontExit = FlowManager::doYouWantToContinue();
		break;
	case 2:
		system("cls");
		oldPass = person->getPassword();
		updatePassword(person);
		if (oldPass != person->getPassword())  FileManager::editClient(*client);
		else cout << "\nSame Password :D !!!\n";
		dontExit = FlowManager::doYouWantToContinue();
		break;
	case 3:
		system("cls");
		depositeAmount(client);
		dontExit = FlowManager::doYouWantToContinue();
		break;
	case 4:
		system("cls");
		withdrawAmount(client);
		dontExit = FlowManager::doYouWantToContinue();
		break;
	case 5:
		system("cls");
		transferAmount(client);
		dontExit = FlowManager::doYouWantToContinue();
		break;
	case 6:
		system("cls");
		client->displayInfo();
		dontExit = FlowManager::doYouWantToContinue();
		break;
	case 7:
		dontExit = false; break;
	default:
		system("cls");
		cout << "The selected option is not available in the menu, please try again !!";
		Sleep(1000);
		break;
	  }
    }
	delete person;
	return true; // exit from client
}
