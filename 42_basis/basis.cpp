#include <iostream>
using namespace std;

class Basis
{
public:
	//Konstruktor
	Basis() {}
	Basis(int _arraysize) : arraysize(_arraysize) { p = new int[_arraysize]; }
	//Kopierkonstruktor
	Basis(Basis &_other) : arraysize(_other.arraysize), p(new int[_other.arraysize])
	{
		for (int i = 0; i < arraysize; i++)
			p[i] = _other.p[i];
	}
	//Zuweisungsoperator
	Basis& operator=(Basis &_other)
	{
		if (this != &_other) //1. Test auf Identität von THIS & OTHER
		{
			if (p) { delete[] p; } //2. Freigabe des belegten Speichers

			arraysize = _other.arraysize;
			p = new int[arraysize];	//3. Reservieren der neuen Speichergröße

			for (int i = 0; i < arraysize; i++) //4. Inhalt von OTHER nach THIS kopieren
				p[i] = _other.p[i];
		}
		return (*this); //5. Rückgabe einer Referenz auf sich selbst
	}

	//Destruktor
	virtual ~Basis() { delete[] p; }

private:
	int *p;
	int arraysize;

};


void main()
{
	Basis *b[5];

	cin.peek();
}

/*
Welche Methoden oder Operatoren müssen Sie auf jeden Fall implementieren? Begründen Sie Ihre Angaben.
- Destruktor, der den Speicher wieder freigibt.
- Zuweisungsoperator, damit ein zugewiesenes Objekt eine Kopie des angeforderten Speichers erhält.
- Kopierkonstruktor, damit ein neu erzeugtes Objekt eine Kopie des angeforderten Speichers erhält.

Ihre neue Klasse soll als Basisklasse für andere Klassen dienen, die ebenfalls Speicher dynamisch anfordern. Müssen Sie dieses beim Entwurf der Klasse Basis beachten? Wenn ja, was müssen Sie dazu machen? Begründen Sie Ihre Aussagen.
- Ja: Mindestens der Destruktor muss virtuell werden, da sonst beim Löschen eines Objektes der abgeleiteten Klasse mit Hilfe eines Basisklassenzeigers der Destruktor der abgeleiteten Klasse nicht aufgerufen wird.

Sie wollen Objekte der Klasse Basis auch direkt in einem Array ablegen. Wie werden die Objekte im Array erzeugt, wenn das Array erzeugt wird?
- Durch Aufruf des Defaultkonstruktors der Klasse Basis.

Wie können Sie erreichen, dass die Objekte der Klasse Basis in einem Array mit einem allgemeinen Konstruktor initialisiert werden?
- Basis* array[1000];
- und individuelles Erzeugen und Initialisieren jedes Zeigers.
*/