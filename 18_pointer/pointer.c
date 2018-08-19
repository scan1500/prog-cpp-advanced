#include <stdio.h>

void main()
{
	//a ist ein Zeiger auf einen konstanten float - Wert.
	const float PI = 3.14;
	float *a = &PI;

	//b ist ein konstanter Zeiger auf eine float - Variable.
	float value = 1.23;
	float  *const b = &value;

	//c ist ein Zeiger auf einen konstanten Zeiger auf eine float - Variable.
	float **c = b;

	//d ist ein Vektor mit 3 Zeigern auf float - Variablen.
	float f1 = 1.23, f2 = 2.34, f3 = 3.45;
	float *p1 = &f1, *p2 = &f2, *p3 = &f3;
	float *vektor[3] = {p1, p2, p3};

	//e ist ein Zeiger auf einen Vektor mit 3 Zeigern auf float - Variablen.
	float **e = vektor;

	system("pause");
}