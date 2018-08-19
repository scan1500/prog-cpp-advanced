#ifndef _RATIONAL_
#define _RATIONAL_

using namespace std;

class Rational
{
private:
	long zaehler;
	long nenner;

public:

	long ggT(long a, long b);
	Rational();
	Rational(long _zaehler, long _nenner);
	Rational(long gz);
	Rational(const Rational &_rat);

	friend Rational set(long z, long n);
	friend Rational add(const Rational &a, const Rational &b);
	friend Rational sub(const Rational &a, const Rational &b);
	friend Rational mult(const Rational &a, const Rational &b);
	friend Rational div(const Rational &a, const Rational &b);

	void kehrwert();
	void kuerzen();
	void ausgabe();
};

Rational set(long z, long n);
Rational add(const Rational &a, const Rational &b);
Rational sub(const Rational &a, const Rational &b);
Rational mult(const Rational &a, const Rational &b);
Rational div(const Rational &a, const Rational &b);

#endif
