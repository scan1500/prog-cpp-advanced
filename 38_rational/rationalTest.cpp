#include <iostream>
#include "rational.h"
using namespace std;

void main()
{
	Rational a(1, 6);
	Rational b(2, 9);
	Rational c;

	Rational d(4, 6);

	c.add(a, b);
	c.ausgabe();

	c.sub(a, b);
	c.ausgabe();

	c.div(a, b);
	c.ausgabe();

	d.ausgabe();

	cin.peek();
}