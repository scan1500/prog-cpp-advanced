#include <iostream>
#include <string>
#include "kunde.h"
using namespace std;

Kunde::Kunde() : m_nummer(0), m_name("") 
{ 
	obj_counter++; 
}

Kunde::Kunde(int _nummer, string &_name) : m_nummer(_nummer), m_name(_name)
{
	obj_counter++;
}

Kunde::~Kunde()
{
	obj_counter--;
}

const int Kunde::getCounter()
{
	return obj_counter;
}

void Kunde::ausgeben() 
{ 
	std::cout << Kunde::m_nummer << ": " << m_name << std::endl; 
}

int Kunde::getNummer()
{
	return Kunde::m_nummer;
}

const string& Kunde::getName()
{
	return Kunde::m_name;
}