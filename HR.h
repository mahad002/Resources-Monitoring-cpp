#pragma once
#include <iostream>

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


class HRManager{
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
	HRManager getHR_Instance(int);
	Employee* getEmployee(int);
	bool employeeStatus(int);
	void printLeaveBalance(int);
	void printSalaryReport(int);
	~HRManager();
};


};