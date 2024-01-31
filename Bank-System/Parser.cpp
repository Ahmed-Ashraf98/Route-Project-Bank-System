#include "Parser.h"

vector<string> Parser::split(string line)
{
    vector<string> stringWords;
    istringstream str(line);
    string word;
    while (getline(str, word, '-'))
    {
        stringWords.push_back(word);
    }
    return stringWords;
}

Client Parser::parseToClient(string line)
{
    vector<string> clientData = split(line);
    return Client(stoi(clientData[0]), clientData[1], clientData[2], stod(clientData[3]));
}

Employee Parser::parseToEmployee(string line)
{
    vector<string> employeeData = split(line);
    return Employee(stoi(employeeData[0]), employeeData[1], employeeData[2], stod(employeeData[3]));
}

Admin Parser::parseToAdmin(string line)
{
    vector<string> adminData = split(line);
    return Admin(stoi(adminData[0]), adminData[1], adminData[2], stod(adminData[3]));
}

string Parser::parseClientToStr(Client client)
{
    string clientDataInStrFormat = to_string(client.getId()) + "-" + client.getName() + "-" + client.getPassword() + "-" + to_string(client.getBalance());
    return clientDataInStrFormat;
}

string Parser::parseEmployeeToStr(Employee employee)
{
    string employeeDataInStrFormat = to_string(employee.getId()) + "-" + employee.getName() + "-" + employee.getPassword() + "-" + to_string(employee.getSalary());
    return employeeDataInStrFormat;
}

string Parser::parseAdminToStr(Employee admin)
{
    string adminDataInStrFormat = to_string(admin.getId()) + "-" + admin.getName() + "-" + admin.getPassword() + "-" + to_string(admin.getSalary());
    return adminDataInStrFormat;
}
