#include <iostream>
#include "friend.h"
using namespace std;

Rational::Rational() : zaehler(0), nenner(0) {}
Rational::Rational(long _zaehler, long _nenner) : zaehler(_zaehler), nenner(_nenner) {}
Rational::Rational(long gz) : zaehler(gz), nenner(1) {}
Rational::Rational(const Rational &_rat)
{
	zaehler = _rat.zaehler;
	nenner = _rat.nenner;
}

long Rational::ggT(long a, long b)
{
	long help;
	while (1)
	{
		if (!(a % b) || b == 1) //Wenn Teiler gefunden -> Rest = 0 
			return b;
		else
		{
			help = a % b;
			a = b;
			b = help;
		}
	}
	return a;
}

void Rational::kuerzen()
{
	long teiler = ggT(zaehler, nenner);;
	zaehler /= teiler;
	nenner /= teiler;
}

void Rational::kehrwert()
{
	long help = zaehler;
	zaehler = nenner;
	nenner = help;
}

void Rational::ausgabe()
{
	Rational::kuerzen();
	cout << zaehler << "/" << nenner << endl;
}

Rational set(long z, long n)
{
	Rational result;
	result.zaehler = z;
	result.nenner = n;
	return result;
}

Rational add(const Rational &a, const Rational &b)
{
	return set((a.zaehler * b.nenner) + (b.zaehler * a.nenner), (a.nenner * b.nenner));
}

Rational sub(const Rational &a, const Rational &b)
{
	return set((a.zaehler * b.nenner) - (b.zaehler * a.nenner), (a.nenner * b.nenner));
}

Rational mult(const Rational &a, const Rational &b)
{
	return set((a.zaehler * b.zaehler), (a.nenner * b.nenner));
}

Rational div(const Rational &a, const Rational &b)
{
	return set((a.zaehler *  b.nenner), (a.nenner * b.zaehler));
}




