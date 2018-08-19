#ifndef _KUNDE_
#define _KUNDE_

using namespace std;
static int obj_counter = 0;

class Kunde
{
	int m_nummer;
	string m_name;

public:

	Kunde();
	Kunde(int, string&);
	~Kunde();
	int getNummer();
	const string& getName();
	void ausgeben();
	static const int getCounter();
};

#endif // !_KUNDE_

