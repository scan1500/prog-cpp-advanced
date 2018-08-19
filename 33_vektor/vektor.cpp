#include "vektor.h"
#include <iostream>
using namespace std;

void main()
{
	Vektor v(15);

	for (unsigned int i = 0; i<15; i++)
		v.set(i, i / 4.0);

	for (unsigned int i = 0; i<15; i++)
		cout << v.get(i) << " ";

	cout << endl;
	//v.set(20, -1.0);


	system("pause");
}

