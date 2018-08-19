#ifndef VEKTOR_H
#define VEKTOR_H
#include <cassert>

class Vektor
{
private:
	unsigned int size;
	double *v;

public:
	Vektor() : size(0), v(0) {}
	Vektor(unsigned int _size);
	Vektor(const Vektor &_vek);
	~Vektor() { if (v) delete[] v; }
	void resize(unsigned int _size);
	unsigned int getSize() const { return size; }
	double get( unsigned int _i) const;
	void set(unsigned int _i, double val);
};

inline Vektor::Vektor(unsigned int _size) : size(_size)
{
	v = new double[size];
}

inline Vektor::Vektor(const Vektor& _vek) : size(0)
{
	v = new double[_vek.size];
	if (v == 0)
		return;
	size = _vek.size;

	for (unsigned int i = 0; i < size; i++)
		v[i] = _vek.v[i];
}

inline void Vektor::resize(unsigned int _size)
{
	if (v)
		delete[] v;

	size = _size;
	v = new double[size];
}

inline double Vektor::get(unsigned int _i) const
{
	assert(_i < size && v != 0);
	return v[_i];
}

inline void Vektor::set(unsigned int _i, double _val)
{
	assert(_i < size && v != 0);
	v[_i] = _val;
}


#endif