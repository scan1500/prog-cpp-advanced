#include <iostream>
#include "rational.h"
using namespace std;

Rational::Rational() : zaehler(0), nenner(0) 
{ 
	cout << "Standardkonstruktor" << endl; 
}
Rational::Rational(long _zaehler, long _nenner) : zaehler(_zaehler), nenner(_nenner) 
{ 
	cout << "Konstruktor mit Zähler u. Nenner" << endl; 
}
Rational::Rational(long gz) : zaehler(gz), nenner(1) 
{
	cout << "Konstruktor für ganze Zahlen" << endl;
}
Rational::Rational(const Rational &_rat)
{
	cout << "Kopierkonstruktor" << endl;
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

void Rational::set(long z, long n)
{
	zaehler = z;
	nenner = n;
}

void Rational::add(const Rational &a, const Rational &b)
{
	zaehler = (a.zaehler * b.nenner) + (b.zaehler * a.nenner);
	nenner = (a.nenner * b.nenner);
}

void Rational::sub(const Rational &a, const Rational &b)
{
	zaehler = (a.zaehler * b.nenner) - (b.zaehler * a.nenner);
	nenner = (a.nenner * b.nenner);
}

void Rational::mult(const Rational &a, const Rational &b)
{
	zaehler = (a.zaehler * b.zaehler);
	nenner = (a.nenner * b.nenner);
}

void Rational::div(const Rational &a, const Rational &b)
{
	zaehler = (a.zaehler *  b.nenner);
	nenner = (a.nenner * b.zaehler);
}




