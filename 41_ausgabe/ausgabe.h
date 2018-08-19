#include <iostream>
#ifndef _HEADER
#define _HEADER_

using namespace std;

class A
{
public:
	A() { cout << "Initialisierung" << endl; }
	~A() 
	{ 
		cout << "Aufraeumen" << endl; 
		cin.peek();
	}
};

#endif	
