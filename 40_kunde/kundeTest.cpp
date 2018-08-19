#include <iostream>
#include "kunde.h"
using namespace std;

void main()
{
	cout << "Anzahl Objekte: " << Kunde::getCounter() << endl;

	Kunde *a = new Kunde;
	Kunde *b = new Kunde;

	cout << "Anzahl Objekte: " << Kunde::getCounter() << endl;

	Kunde *c = new Kunde;
	Kunde *d = new Kunde;

	cout << "Anzahl Objekte: " << Kunde::getCounter() << endl;

	delete c;
	delete d;

	cout << "Anzahl Objekte: " << Kunde::getCounter() << endl;

	delete a;
	delete b;

	cout << "Anzahl Objekte: " << Kunde::getCounter() << endl;




	cin.peek();
}