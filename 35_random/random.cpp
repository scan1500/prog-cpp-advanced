#include <iostream>
#include <ctime>
#include "random.h"

using namespace std;

unsigned long b = 9757;
unsigned long c = 6925;
unsigned long m = 32768;

void main()
{
	Random randObj1;
	cout << "Pseudozufall zwischen 1 und " << m << endl << endl;

	for (int i = 0; i < 15; i++)
		cout << randObj1.rand() << endl;

	Random randObj2;
	cout << endl << "Pseudozufall zwischen 0 und 1" << endl << endl;

	for (int i = 0; i < 15; i++)
		cout << randObj2.doubleRand() << endl;

	cin.peek();
}

double Random::doubleRand()
{
	return (double)Random::rand() / m;
}

unsigned long Random::rand()
{
	static int a = (int)(time(0) % m);  // KEIM
	return a = (a * b + c) % m;
}