#ifndef _RATIONAL_
#define _RATIONAL_

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

	void add(const Rational &a, const Rational &b);
	void sub(const Rational &a, const Rational &b);
	void mult(const Rational &a, const Rational &b);
	void div(const Rational &a, const Rational &b);

	void set(long z, long n);
	void kehrwert();
	void kuerzen();
	void ausgabe();
};
#endif
