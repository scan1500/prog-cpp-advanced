//IFNDEF STATT IFDEF
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

void main()
{
}

//KEIN PUBLIC
class Employee
{
	//PUBLIC OHNE ; -> :
	//PUBLIC VOR KONSTRUKTOR KEINEN SINN
public:
	int salary = 20000;
	char* name;

	//KEIN VOID -> KONSTR. HAT KEINEN RÜCKGABEWERT
	Employee(int newSalary)
	{
		salary = newSalary;
		name = new char[80];
	}

	int getSalary()
	{
		return salary;
	}

	//SCHREIBFEHLER nane -> name
	//FALSCHER RÜCKGABEWERT int -> char*
	char* getName()
	{
		return name;
	}
};
#endif //Kein Argument