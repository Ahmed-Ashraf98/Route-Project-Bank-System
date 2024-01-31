#include "FileManager.h"

Client* FileManager::clientExists(int id)
{
    return FilesHelper::clientExists(id);
}

Employee* FileManager::employeeExists(int id)
{
    return FilesHelper::employeeExists(id);
}

Admin* FileManager::adminExists(int id)
{
    return FilesHelper::adminExists(id);
}

void FileManager::addClient(Client client)
{
    FilesHelper::saveClient(client,true);
}

void FileManager::editClient(Client client)
{
    FilesHelper::saveClient(client,false);
}

void FileManager::addEmployee(Employee employee)
{
    FilesHelper::saveEmployee("Employees.txt", "EmployeesLastID.txt", employee , true);
}

void FileManager::editEmployee(Employee employee)
{
    FilesHelper::saveEmployee("Employees.txt", "EmployeesLastID.txt", employee , false);
}

void FileManager::addAdmin(Admin admin)
{
    FilesHelper::saveEmployee("Admins.txt", "AdminsLastID.txt", admin , true);
}

void FileManager::editAdmin(Admin admin)
{
    FilesHelper::saveEmployee("Admins.txt", "AdminsLastID.txt", admin , false);
}

vector<Client> FileManager::getAllClients()
{
    return FilesHelper::getClients();
}

vector<Employee> FileManager::getAllEmployees()
{
    return FilesHelper::getEmployees();
}

vector<Employee> FileManager::getAllAdmins()
{
    return FilesHelper::getAdmins();
}

void FileManager::removeAllClients()
{
    FilesHelper::clearFile("Clients.txt", "ClientsLastID.txt");
}

void FileManager::removeAllEmployees()
{
    FilesHelper::clearFile("Employees.txt", "EmployeesLastID.txt");
}

void FileManager::removeAllAdmins()
{
    FilesHelper::clearFile("Admins.txt", "AdminsLastID.txt");
}
