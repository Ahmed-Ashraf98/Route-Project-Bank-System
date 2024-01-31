#include "Screens.h"


void Screens::bankName()
{
    cout << " CIB ";
}

void Screens::welcome()
{
    cout << "Welcome in ";
    bankName();
    cout << " Application" << endl;
}

void Screens::loginOptions()
{
    system("cls");
    cout << "\nPlease choose the login type: " << endl;
    cout << "1) Client "<<endl;
    cout << "2) Employee "<<endl;
    cout << "3) Admin "<<endl;
    cout << "*******************************" << endl;
    cout << "Type 'x' to Exist from the App " << endl;
    cout << "*******************************" << endl;
    loginScreen(loginAs());
}

int Screens::loginAs()
{
    char choice;
    cout << "\nYour choise : ";
    cin >> choice;
    cin.clear();
    cin.ignore(INT_MAX,'\n');
    switch (tolower(choice))
    {
    case '1': return 1;
    case '2': return 2;
    case '3': return 3;
    case 'x': return 4;
    default:
        return 0;
    }
    
}

void Screens::invalid(int c)
{
    system("cls");
    cout << "\nInvalid choice :( , please try again!!" << endl;
    Sleep(1000);
}

void Screens::logout()
{
    cout << "\nThank you for using CIB application, have a nice day ;) " << endl;
    Sleep(1000);
}

void Screens::loginScreen(int c)
{
    bool exit = false;

    Client* client;
    Employee* emp;
    Admin* admin;

    switch (c)
    {
    case 1:
        system("cls");
        cout << "\nPlease enter your ID & Password to login" << endl;
        client = ClientManger::login();
        exit = client == nullptr ? true : ClientManger::clientOptions(client);
        if (exit) { logout(); loginOptions(); };
        break;
    case 2:
        system("cls");
        cout << "\nPlease enter your ID & Password to login" << endl;
        emp= EmployeeManager::login();
        exit = emp ==nullptr ? true : EmployeeManager::employeeOptions(emp);
        if (exit) { logout(); loginOptions(); };
        break;
    case 3:
        system("cls");
        cout << "\nPlease enter your ID & Password to login" << endl;
        admin = AdminManager::login();
        exit = admin == nullptr ? true: AdminManager::AdminOptions(admin);
        if (exit) {  logout(); loginOptions(); };
        break;
    case 4:
        logout();
        break;
    default:
     system("cls");
     invalid(c);
     loginOptions();
     break;
    }
}

void Screens::runApp()
{
    welcome();
    loginOptions();
}
