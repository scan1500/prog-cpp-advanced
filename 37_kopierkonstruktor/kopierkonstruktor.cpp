#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

void main()
{
}

class Employee
{
private:
	int salary;
	char* name;

public:
	Employee() : salary(20000), name(nullptr) {}
	Employee(const Employee &_emp);
	~Employee() { if (name) delete[] name; };

	int getSalary();
	char* getName();
};
	
Employee::Employee(const Employee &_emp)
{
	salary = _emp.salary;
	strncpy(name = new char[80] , _emp.name, 80);
}

int Employee::getSalary()
{
	return salary;
}

char* Employee::getName()
{
	return name;
}

#endif