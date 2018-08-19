#include <iostream>
#include "friend.h"
using namespace std;

void main()
{
	Rational a(1, 6);
	Rational b(2, 9);
	Rational c;

	c = add(a, b);
	c.ausgabe();
	

	cin.peek();
}