#include "HR.h"
#include<iostream>
using namespace std;


class Employee {
private:
	int id;
	int age;
	bool status;
	double salary;
	int casual_leaves_total;
	int casual_leaves_availed;
	int earned_leaves;
	static int empCount;
public:
	Employee();

	Employee(int, bool);

	Employee(int, bool, double, int, int, int);

	Employee(const Employee& obj);

	Employee* setSalary(double _salary);

	Employee* setStatus(bool _status);

	Employee* setCasualLeaves(int _casual_leaves);

	bool getStatus();

	double getSalary();

	int getId();

	int getCasualLeaves();

	int getEarnedLeaves();

	bool AvailCasualLeave();

	bool AvailEarnedLeave();

	Employee CompareEmployee(Employee& obj);

	~Employee();
};

int Employee::empCount = 1;

Employee::Employee()
{
	id = 0;
	age = 0;
	status = false;
	salary = 0;
	casual_leaves_total = 0;
	casual_leaves_availed = 0;
	earned_leaves = 0;
}

Employee::Employee(int _age, bool _status)
{
	id = empCount++;
	age = _age;
	status = _status;
	salary = 0;
	casual_leaves_total = 0;
	casual_leaves_availed = 0;
	earned_leaves = 0;
}

Employee::Employee(int _age, bool _status, double _salary, int _casual_leaves_total, int _casual_leaves_availed, int _earned_leaves)
{
	id = empCount++;
	age = _age;
	status = _status;
	salary = _salary;
	casual_leaves_total = _casual_leaves_total;
	casual_leaves_availed = _casual_leaves_availed;
	earned_leaves = _earned_leaves;
}

Employee::Employee(const Employee& obj)
{
	this->id = obj.id;
	this->age = obj.age;
	this->status = obj.status;
	this->salary = obj.salary;
	this->casual_leaves_total = obj.casual_leaves_total;
	this->casual_leaves_availed = obj.casual_leaves_availed;
	this->earned_leaves = obj.earned_leaves;
}

bool Employee::getStatus()
{
	return status;
}

int Employee::getCasualLeaves()
{
	return (casual_leaves_total - casual_leaves_availed);
}


int Employee::getEarnedLeaves()
{
	return earned_leaves;
}

double Employee::getSalary()
{
	return salary;
}

int Employee::getId()
{
	return id;
}

Employee* Employee::setSalary(double _salary)
{
	salary = _salary;
	return this;
}

Employee* Employee::setStatus(bool _status)
{
	status = _status;
	return this;
}

Employee* Employee::setCasualLeaves(int _casual_leaves)
{
	casual_leaves_total = _casual_leaves;
	return this;
}

bool Employee::AvailCasualLeave()
{
	if (casual_leaves_availed > 0)
	{
		casual_leaves_availed--;
		return true;
	}
	else
	{
		return false;
	}
}
bool Employee::AvailEarnedLeave()
{
	if (earned_leaves > 0)
	{
		earned_leaves--;
		return true;
	}
	else
	{
		return false;
	}
}
Employee Employee::CompareEmployee(Employee& obj)
{
	if (salary >= obj.salary)
	{
		return *this;
	}
	else
	{
		return obj;
	}
}

Employee :: ~Employee()
{
	cout << "Destructor called" << endl;
}


class HRManager
{
private:
	int size = 0;
	Employee* employees;
	static bool check;
	HRManager()
	{
		size = 0;
		employees = NULL;
	}
	HRManager(int _size)
	{
		size = _size;
		employees = new Employee[size];
	}
public:
	static HRManager getHR_Instance(int = 5);
	Employee* getEmployee(int);
	bool employeeStatus(int);
	void printLeaveBalance(int);
	void printSalaryReport(int);
	~HRManager();
};

bool HRManager::check = false;
HRManager HRManager::getHR_Instance(int number_of_employees)
{
	if (!check)
	{
		HRManager H(5);
		check = true;
		return H;
	}
}
Employee* HRManager::getEmployee(int _id)
{
	if (_id <= size)
	{
		return &employees[_id - 1];
	}
	else
	{
		return NULL;
	}
}
bool HRManager::employeeStatus(int _id)
{
	Employee* employee = getEmployee(_id);
	if (employee != NULL)
	{
		return employee->getStatus();
	}
}
void HRManager::printLeaveBalance(int _id)
{
	Employee* employee = getEmployee(_id);
	if (employee != NULL)
	{
		cout << "Employee id: " << employee->getId() << endl;
		cout << "Casual Leaves: " << employee->getCasualLeaves() << endl;
		cout << "Earned Leaves: " << employee->getEarnedLeaves() << endl;
	}
}
void HRManager::printSalaryReport(int _id)
{
	Employee* employee = getEmployee(_id);
	if (employee != NULL)
	{
		cout << "Employee id: " << employee->getId() << endl;
		cout << "Salary: " << employee->getSalary() << endl;
	}
}

HRManager :: ~HRManager()
{
	delete[] employees;
}


int main()
{
	HRManager manager = HRManager::getHR_Instance();

	return 0;
}