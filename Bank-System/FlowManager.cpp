#include "FlowManager.h"

bool FlowManager::doYouWantToContinue()
{
	char doYouWantToCont;
	cout << "\nDo you want to do other operations ? (Y/N) : ";
	cin >> doYouWantToCont;
	return tolower(doYouWantToCont) == 'y' ? true : false;
}

bool FlowManager::doYouWantToTryAgain()
{
	char doYouWantToTermP;
	cout << "\nDo you want to try again ? (Y/N) : ";
	cin >> doYouWantToTermP;
	return tolower(doYouWantToTermP) == 'y' ? true : false;
}

void FlowManager::unexpectedInput()
{
	system("cls");
	cout << "\nUnexpected input  (O_O) !!!\n";
	Sleep(1000);
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}
