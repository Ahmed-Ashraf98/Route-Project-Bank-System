#include "FilesHelper.h"


bool FilesHelper::clientExists(Client client)
{

    if (client.getId() > 0) {  // client added to the file with Id
        vector<Client> clientsList = getClients();
        int clientsListSize = clientsList.size();
        for (int i = 0; i < clientsListSize; i++)
        {
            if (clientsList[i].getId() == client.getId()) {
                return true;
            }
        }
    }
    return false;
}

bool FilesHelper::employeeExists(Employee employee)
{
    if (employee.getId() > 0) {  // employee added to the file with Id
        vector<Employee> employeesList = getEmployees();
        int employeesListSize = employeesList.size();
        for (int i = 0; i < employeesListSize; i++)
        {
            if (employeesList[i].getId() == employee.getId()) {
                return true;
            }
        }
    }
    return false;
}

bool FilesHelper::adminExists(Employee admin)
{
    if (admin.getId() > 0) {  // admin added to the file with Id
        vector<Employee> adminsList = getAdmins();
        int adminsListSize = adminsList.size();
        for (int i = 0; i < adminsListSize; i++)
        {
            if (adminsList[i].getId() == admin.getId()) {
                return true;
            }
        }
    }
    return false;
}

Client* FilesHelper::clientExists(int id)
{
    Client* c = nullptr;

    if (id > 0) {  // client added to the file with Id
        vector<Client> clientsList = getClients();
        int clientsListSize = clientsList.size();
        for (int i = 0; i < clientsListSize; i++)
        {
            if (clientsList[i].getId() == id ) {
                c = new Client(clientsList[i]);
            }
        }
    }
    return c;
}

Employee* FilesHelper::employeeExists(int id)
{
    Employee* e = nullptr;

    if (id > 0) {  // employee added to the file with Id
        vector<Employee> employeesList = getEmployees();
        int employeesListSize = employeesList.size();
        for (int i = 0; i < employeesListSize; i++)
        {
           if (employeesList[i].getId() == id ) {
                e =new Employee(employeesList[i]);
           }
        }
    }
    return e;
}

Admin* FilesHelper::adminExists(int id)
{
    Admin* ad = nullptr;

    if (id > 0) {  // admin added to the file with Id
        vector<Employee> adminsList = getAdmins();
        int adminsListSize = adminsList.size();
        for (int i = 0; i < adminsListSize; i++)
        {
            if (adminsList[i].getId() == id ) {
                ad =new Admin(adminsList[i].getId(), adminsList[i].getName(), adminsList[i].getPassword(), adminsList[i].getSalary());
            }
        }
    }
    return ad;
}

void FilesHelper::saveLast(string fileName, int id)
{
    fstream file;
    file.open(fileName, ios::out);

    if (file.is_open()) {
        id = (id == 0) ? 1 : id + 1;
        file << to_string(id);
        file.clear();
        file.close();
    }

    else if (file.fail()) {
        cout << "\nCouldn't Open the " << fileName << " File" << endl;
    }
    else {
        cout << "\nSomething went wrong!!" << endl;
    }
}

int FilesHelper::getLast(string fileName)
{
    int lastId = 0;
    string lastIdInStr;
    fstream file;
    file.open(fileName, ios::in | ios::out | ios::app);


    if (file.is_open()) {

        file.seekg(0, ios::end);
        if (file.tellg() == 0) {
            file.clear();
            file.close();
            return lastId;
        }
        file.seekg(0, ios::beg);
        getline(file, lastIdInStr);
        lastId = stoi(lastIdInStr);
        //cout << "Found an ID --> " << lastId;
        file.close();
        return lastId;
    }
    else if (file.fail()) {
        cout << "\nCouldn't Open the " << fileName << " File" << endl;
    }
    else {
        cout << "\nSomething went wrong!!" << endl;
    }
}

void FilesHelper::saveClient(Client c , bool addNew)
{
    // get all clients
    // update only the client with the specific ID
    // Re-write the file with the updated data 

     // chech if client exist or not , if not then add new one , otherwise update the existing


    //if (!(BankDataValidation::validateName(c.getName(), false) && BankDataValidation::validatePassword(c.getPassword(), false) && BankDataValidation::validateBalance(c.getBalance(), false))) {
    //    cout << "Can't Add/Update this client because the data is not valid!!" << endl;
    //    return;
    //}

    fstream file;
    vector<Client> clientsList = getClients();
    int clientsListSize = clientsList.size();


    if (!addNew) { // Means update action

        if (clientExists(c)) { // update the existing one    
            file.open("Clients.txt", ios::out);
            if (file.is_open()) {
                for (int i = 0; i < clientsListSize; i++)
                {
                    if (c.getId() == clientsList[i].getId()) {
                        file << Parser::parseClientToStr(c) << "\n";
                        continue;
                    }
                    file << Parser::parseClientToStr(clientsList[i]) << "\n";
                }
                cout << "\n --->>> Client Updated Successfully :) \n" << endl;
                file.close();
                return;
            }
            else if (file.fail()) {
                cout << "\nCouldn't Open the Client File" << endl;
            }
            else {
                cout << "\nSomething went wrong!!" << endl;
            }
        }
        else {
            cout << "\n No Client found with specified ID, Please check the Id and try again!\n";
        }
    }
    
    else { // add a new client
        file.open("Clients.txt", ios::app);
        if (file.is_open()) {
            int lastId = FilesHelper::getLast("ClientsLastID.txt"); // get Last Id
            FilesHelper::saveLast("ClientsLastID.txt", lastId); // Last ID updated
            lastId = FilesHelper::getLast("ClientsLastID.txt"); // get Updated Last Id
            c.setId(lastId);
            file << Parser::parseClientToStr(c) << "\n";
            cout << "\n--->>> Client Created Successfully :)\n" << endl;
            file.close();
            return;
        }
        else if (file.fail()) {
            cout << "\nCouldn't Open the Client File" << endl;
        }
        else {
            cout << "\nSomething went wrong!!" << endl;
        }

    }

}

void FilesHelper::saveEmployee(string fileName, string lastIdFile, Employee e , bool addNew)
{
    // get all employees
       // update only the employee with the specific ID
       // Re-write the file with the updated data 

        // chech if employee exist or not , if not then add new one , otherwise update the existing

    // validating data before storing it
   /* if (!(BankDataValidation::validateName(e.getName(), false) && BankDataValidation::validatePassword(e.getPassword(), false) && BankDataValidation::validateSalary(e.getSalary(), false))) {
        cout << "\nCan't Add/Update this Employee/Admin because the data is not valid!!" << endl;
        return;
    }*/

    fstream file;
    vector<Employee> usersList = (fileName == "Employees.txt") ? getEmployees() : getAdmins();
    int usersListSize = usersList.size();

    bool userExists = (fileName == "Employees.txt") ? employeeExists(e) : adminExists(e);
    string objectTypeName = (fileName == "Employees.txt" ? "Employee" : "Admin");

    if (!addNew) { // means updating action

        if (userExists) { // update the existing one    
            file.open(fileName, ios::out);
            if (file.is_open()) {
                for (int i = 0; i < usersListSize; i++)
                {
                    if (e.getId() == usersList[i].getId()) {
                        file << Parser::parseEmployeeToStr(e) << "\n";
                        continue;
                    }
                    file << Parser::parseEmployeeToStr(usersList[i]) << "\n";
                }
                cout << "\n --->>> " << objectTypeName << " Updated Successfully :) \n" << endl;
                file.close();
                return;
            }
            else if (file.fail()) {
                cout << "\nCouldn't Open the " << fileName << "File" << endl;
            }
            else {
                cout << "\nSomething went wrong!!" << endl;
            }
        }
        else {
            cout << "\nNo " << objectTypeName << " Found with specified ID, please check and try again!\n";
        }
    }
    else { // add a new employee
        file.open(fileName, ios::app);
        if (file.is_open()) {
            int lastId = FilesHelper::getLast(lastIdFile); // get Last Id
            FilesHelper::saveLast(lastIdFile, lastId); // Last ID updated
            lastId = FilesHelper::getLast(lastIdFile); // get Updated Last Id
            e.setId(lastId);
            file << Parser::parseEmployeeToStr(e) << "\n";
            cout << "\n --->>> " << objectTypeName << " Created Successfully :) \n" << endl;
            file.close();
            return;
        }
        else if (file.fail()) {
            cout << "\nCouldn't Open the " << fileName << "File" << endl;
        }
        else {
            cout << "\nSomething went wrong!!" << endl;
        }

    }

}

vector<Client> FilesHelper::getClients()
{
    vector<Client> clientsList;
    string line;
    fstream file;
    file.open("Clients.txt", ios::in);

    if (file.is_open()) {

        while (getline(file, line, '\n'))
        {
            clientsList.push_back(Parser::parseToClient(line));
        }

    }
    else if (file.fail()) {
        //cout << "\nCan't Get Clients, because the file is not exist" << endl;
    }
    else {
        cout << "\nSomething went wrong!!" << endl;
    }

    return clientsList;
}

vector<Employee> FilesHelper::getEmployees()
{
    vector<Employee> employeesList;
    string line;
    fstream file;
    file.open("Employees.txt", ios::in);

    if (file.is_open()) {

        while (getline(file, line, '\n'))
        {
            employeesList.push_back(Parser::parseToEmployee(line));
        }

    }
    else if (file.fail()) {
        //  cout << "\nCouldn't Open the Employees File" << endl;
    }
    else {
        cout << "\nSomething went wrong!!" << endl;
    }

    return employeesList;
}

vector<Employee> FilesHelper::getAdmins()
{
    vector<Employee> adminsList;
    string line;
    fstream file;
    file.open("Admins.txt", ios::in);

    if (file.is_open()) {

        while (getline(file, line, '\n'))
        {
            adminsList.push_back(Parser::parseToAdmin(line));
        }

    }
    else if (file.fail()) {
        //  cout << "\nCouldn't Open the Admins File" << endl;
    }
    else {
        cout << "\nSomething went wrong!!" << endl;
    }

    return adminsList;
}

void FilesHelper::clearFile(string fileName, string lastIdFile)
{
    ofstream dataFile, dataLastIdFile;
    dataFile.open(fileName, ios::trunc);
    dataLastIdFile.open(lastIdFile, ios::trunc);


    if (dataFile.is_open()) {
        cout << "Data Removed in the file[ " << fileName << " ] file" << endl;
    }
    else if (dataFile.fail()) {
        cout << "\nCouldn't Open the " << fileName << " File" << endl;
    }
    else {
        cout << "\nSomething went wrong!!" << endl;
    }


    if (dataLastIdFile.is_open()) {
        cout << "Data Removed in the file[ " << lastIdFile << " ] file" << endl;
    }
    else if (dataLastIdFile.fail()) {
        cout << "\nCouldn't Open the " << lastIdFile << " File" << endl;
    }
    else {
        cout << "\nSomething went wrong!!" << endl;
    }
}
