#include "Admin.h"
#include "FileManager.h"

Admin::Admin() {}

Admin::Admin(int id, string name, string password, double salary) :Employee(id, name, password, salary) {}

void Admin::addEmployee(Employee& employee)
{
	FileManager::addEmployee(employee);
}

Employee* Admin::searchEmployee(int id)
{
	Employee* emp = nullptr;
	vector<Employee> getAllEmployees = FileManager::getAllEmployees();
	int empListSize = getAllEmployees.size();
	for (int i = 0; i < empListSize; i++)
	{
		if (getAllEmployees[i].getId() == id)
		{
			emp = new Employee(getAllEmployees[i]);
			return emp;
		}
	}
	return emp;
}

void Admin::editEmployee(int id, string name, string password, double salary)
{
	FileManager::editEmployee(Employee(id, name, password, salary));
}

void Admin::listEmployee()
{
	vector<Employee> getAllEmployees = FileManager::getAllEmployees();
	int empListSize = getAllEmployees.size();
	cout << "\n################################### [ All Employess in the Bank ] ########################### : \n" << endl;
	
	for (int i = 0; i < empListSize; i++)
	{
		cout << "\n---------------------------- " << i + 1 << " -------------------------- " << endl;
		
		cout << "Id : " << getAllEmployees[i].getId() << endl;
		cout << "Name : " << getAllEmployees[i].getName() << endl;
		cout << "Password : " << getAllEmployees[i].getPassword() << endl;
		cout << "Salary : " << getAllEmployees[i].getSalary() << endl;
	}

	cout << "\n#############################################################################################\n" << endl;

}

void Admin::addAdmin(Admin& employee)
{
	FileManager::addAdmin(employee);
}

Employee* Admin::searchAdmin(int id)
{
	Employee* admin = nullptr;
	vector<Employee> getAllAdmins = FileManager::getAllAdmins();
	int adminListSize = getAllAdmins.size();
	for (int i = 0; i < adminListSize ; i++)
	{
		if (getAllAdmins[i].getId() == id)
		{
			admin = new Employee(getAllAdmins[i]);
			return admin;
		}
	}
	return admin;
}

void Admin::editAdmin(int id, string name, string password, double salary)
{
	FileManager::editAdmin(Admin(id, name, password, salary));
}

void Admin::listAdmin()
{
	vector<Employee> getAllAdmins = FileManager::getAllAdmins();
	int adminListSize = getAllAdmins.size();

	cout << "\n################################### [ All Admins in the Bank ] ########################### : \n" << endl;

	for (int i = 0; i < adminListSize; i++)
	{
		cout << "\n---------------------------- " << i + 1 << " -------------------------- " << endl;

		cout << "Id : " << getAllAdmins[i].getId() << endl;
		cout << "Name : " << getAllAdmins[i].getName() << endl;
		cout << "Password : " << getAllAdmins[i].getPassword() << endl;
		cout << "Salary : " << getAllAdmins[i].getSalary() << endl;
	}

	cout << "\n#############################################################################################\n" << endl;

}

void Admin::displayInfo()
{
	cout << "---------------------[ Admin Data ]------------------------" << endl;
	Person::displayInfo();
	cout << "Salary :" << this->salary << endl;
	cout << "----------------------------------------------------------" << endl;
}
