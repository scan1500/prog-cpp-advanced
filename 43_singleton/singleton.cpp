#include <iostream>
using namespace std;

class Soundcard
{
private:
	static Soundcard *card; //Muss private sein! Zugriff von au�en soll verhindert werden.
	Soundcard() {} //Konstruktor private oder protected
	Soundcard(const Soundcard&) {}

public:
	static Soundcard* getInstance() 
	{
		if (card == nullptr) { card = new Soundcard(); }
		return card;
	}

	static void cleanup()
	{
		if (card) { delete card; }
		card = nullptr;
	}
};

Soundcard *Soundcard::card = 0; //statische Elemente einer Klasse m�ssen initialisiert werden. 

int main()
{
	// Soundcard* sc2 = new Soundcard();   // nicht m�glich!!
	Soundcard* sc = Soundcard::getInstance();

	// *sc2 = *sc;   // zurzeit m�glich

	sc->cleanup();
	cin.peek();
	return 0;
}
