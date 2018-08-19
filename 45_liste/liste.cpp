#include <iostream>
using namespace std;

struct LE
{
	float      value;        /* Daten im Element       */
	LE*        next;         /* Zeiger auf nächstes    */
	LE() : value(0.0f), next(nullptr) {}
};

class List
{
private:
	LE*       first;       /* erstes Listenelement   */
	LE*       last;        /* letztes Listenelement  */
	LE*       leArray;     /* Array mit Listenelementen */
	unsigned  leArraySize; /* Größe des Arrays */
	LE*       firstEmpty;
	LE*       newLE();

public:
	List(unsigned size = 0);
	List(const List& source);
	List(List&& source);
	virtual ~List();

	int append(float value);
	void deleteLE(LE* old);
	List& operator=(const List& source);
	List& operator=(List&& source);

	// *** Zeiger für Listeneintrag mit gewünschtem Float-Wert suchen ***
	LE* getPointer(float value);

	using ItemFunction = int(List::*)(LE&);
	int forall(ItemFunction exec);
	int printItem(LE& element);
	void printList() { forall(&List::printItem); }
};

LE* List::newLE()
{
	LE* freeLE = nullptr;

	// *** Wenn erstes Element auf nullptr zeigt dann ist die Liste voll! ***
	if (firstEmpty == nullptr)
		return nullptr;

	// *** Noch Speicher frei - gleich den ersten verfügbaren nehmen ***
	freeLE = firstEmpty;
	firstEmpty = firstEmpty->next;		// FirstEmpty auf nächsten freien Speicher oder nullptr zeigen lassen

	return freeLE;					// Freien Listeintrag zurückgeben
}

// -----------------------------------------------------------
// Konstruktor
// -----------------------------------------------------------
List::List(unsigned size) : first(0), last(0), leArray(0), leArraySize(size), firstEmpty(0)
{
	if (size <= 0)
		return;

	leArray = new LE[size];
	if (leArray == 0)
		return;

	// Leerliste aufbauen 
	firstEmpty = leArray;

	for (unsigned i = 0; i < size - 1; i++)
	{
		LE* current = &leArray[i];
		current->next = &leArray[i + 1];
	}

	// *** Letzter Eintrag hat keinen Nachfolger! ***
	leArray[size - 1].next = nullptr;
}

// -----------------------------------------------------------
// Destruktor
// -----------------------------------------------------------
List::~List()
{
	if (leArray)
		delete[] leArray;
}

// -----------------------------------------------------------
// Zuweisungsoperator
// -----------------------------------------------------------
List& List::operator=(const List& source)
{
	// 1. Test auf Gleichheit
	if (this == &source)
		return *this;

	// 2. Freigabe des belegten Speichers
	delete[] leArray;

	// 3. Neues Array anlegen 
	leArray = new LE[source.leArraySize];
	leArraySize = source.leArraySize;

	// Leere Liste? 
	if (source.first == nullptr) {
		first = last = nullptr;
	}

	// Ab jetzt die Zeigeroffsets mittels Zeigerarithmetik berechnen. 
	else {
		first = &leArray[source.first - source.leArray];
		last = &leArray[source.last - source.leArray];
	}

	if (source.firstEmpty != 0) {
		firstEmpty = &leArray[source.firstEmpty - source.leArray];
	}
	else {
		firstEmpty = 0;
	}

	for (unsigned int i = 0; i < source.leArraySize; i++) {
		leArray[i].value = source.leArray[i].value;
		leArray[i].next = source.leArray[i].next != nullptr ?
			&leArray[source.leArray[i].next - source.leArray] :
			nullptr;
	}

	return *this;
}

// -----------------------------------------------------------
// Moveoperator
// -----------------------------------------------------------
List& List::operator=(List&& source)
{
	// 1. Test auf Gleichheit
	if (this == &source)
		return *this;

	// 2. Zeiger für Array umsetzen
	leArray = source.leArray;
	leArraySize = source.leArraySize;
	source.leArray = nullptr;

	// Leere Liste? 
	if (source.first == nullptr) {
		first = last = nullptr;
	}
	else
	{
		first = source.first;
		last = source.last;
		firstEmpty = source.firstEmpty;

		source.first = nullptr;
		source.last = nullptr;
		source.firstEmpty = nullptr;
		source.leArraySize = 0;
	}

	return *this;
}

// -----------------------------------------------------------
// Kopierkonstruktor
// -----------------------------------------------------------
List::List(const List& source) : first(0), last(0),
leArray(0), leArraySize(0), firstEmpty(0)
{
	*this = source;
}

// -----------------------------------------------------------
// Movekonstruktor
// -----------------------------------------------------------
List::List(List&& source) : first(0), last(0),
leArray(0), leArraySize(0), firstEmpty(0)
{
	*this = (std::move(source));
	// *this = source;  // reicht allein nicht!
}

// -----------------------------------------------------------
// Listenelement freigeben 
// -----------------------------------------------------------
void List::deleteLE(LE* old)
{
	// *** Beim ersten Zeiger anfangen und dann durchgehen bis Zeiger vor old gefunden wurde ***
	if (first == nullptr)
		return;

	// *** Iterator und vorheriges Element ***
	LE* it = first;
	LE* pre = nullptr;

	while (it != nullptr)
	{
		if (it == old)	// Element gefunden
		{
			if (it == first)
			{
				// *** Anfang der Liste jetzt umbiegen ***
				first = old->next;
				if (it == last)		// Einzigstes Element
					last = nullptr;
			}
			else
			{
				// *** Eintrag gefunden -> Jetzt umbiegen ***
				pre->next = old->next;
				if (it == last)		// Letztes Element?
					last = pre;
			}

			// *** old als ganz neues erstes Element der freien Einträge umbiegen ***
			old->next = firstEmpty;
			firstEmpty = old;
			break;
		}
		else
		{	// *** Pre-Element auf Iterator setzen und dann Iterator erhöhen ***
			pre = it;
			it = it->next;
		}
	}
}

// -----------------------------------------------------------
int List::append(float value)
{
	LE* le = newLE();

	// Kein Speicher mehr frei 
	if (le == nullptr)
	{
		return 0;
	}

	// Neues LE anhaengen 
	if (last == nullptr)
	{
		last = first = le;
	}
	else
	{
		last->next = le;
		last = le;
	}

	le->value = value;
	le->next = nullptr;
	return 1;
}

int List::forall(List::ItemFunction exec)
{
	LE* current;
	int no_of_execs = 0;

	/* Bei leerer Liste kann nichts aufgerufen werden */
	if (!first)
		return 0;

	/* Durchlaufe die Liste */
	for (current = first; current != NULL; current = current->next)
		no_of_execs += (this->*exec)(*current);

	return no_of_execs;
}

/*  ------------------------------------------
Name      : printItem
Zweck     : Druckt ein Listenelement aus
Parameter : Zeiger auf ein Element
Rückgabe  : Anzahl der erfolgreichen Aufrufe dieser Funktion
------------------------------------------*/
int List::printItem(LE& element)
{
	cout << element.value << endl;
	return 1;
}

// *** Zeiger auf gewünschten Wert zurückgeben **
LE* List::getPointer(float value)
{
	if (first == nullptr)
		return nullptr;

	// *** Mit Iterator (it) über Liste iterieren ***
	for (LE* it = first; it != nullptr; it = it->next)
	{
		// *** ersten gefundenen Zeiger zurückgeben ***
		if (it->value == value)
			return it;
	}
}

int main(void)
{
	const int SIZE = 10;
	List list(SIZE);
	// *** Zahlen einfügen ***
	for (int i = 0; i < SIZE; i++)
	{
		if (list.append((i + 1)*1.5f))
			cout << "Element " << ((i + 1)*1.5f) << " eingefuegt." << endl;
		else
			cout << "Element " << ((i + 1)*1.5f) << " konnte nicht eingefuegt werden!" << endl;
	}

	// *** In List 2 Einträge mit bestimmten Werten löschen und danach neue hinzufügen und ausgeben ***
	List list2;
	list2 = list;
	cout << "Ausgabe list2:" << endl;
	cout << "Element mit Wert 6 loeschen..." << endl;
	list2.deleteLE(list2.getPointer(6));
	cout << "Element mit Wert 15 loeschen..." << endl;
	list2.deleteLE(list2.getPointer(15));
	cout << "Element mit Wert 12 loeschen..." << endl;
	list2.deleteLE(list2.getPointer(12));
	cout << "Element mit Wert 4.5 loeschen..." << endl;
	list2.deleteLE(list2.getPointer(4.5));
	if (list2.append(77.7f))
		cout << "Element " << (77.7f) << " eingefuegt." << endl;
	else
		cout << "Element " << (77.7f) << " konnte nicht eingefuegt werden!" << endl;
	if (list2.append(88.8f))
		cout << "Element " << (88.8f) << " eingefuegt." << endl;
	else
		cout << "Element " << (88.8f) << " konnte nicht eingefuegt werden!" << endl;
	if (list2.append(99.9f))
		cout << "Element " << (99.9f) << " eingefuegt." << endl;
	else
		cout << "Element " << (99.9f) << " konnte nicht eingefuegt werden!" << endl;
	if (list2.append(66.0f))
		cout << "Element " << (66.0f) << " eingefuegt." << endl;
	else
		cout << "Element " << (66.0f) << " konnte nicht eingefuegt werden!" << endl;
	if (list2.append(55.0f))
		cout << "Element " << (55.0f) << " eingefuegt." << endl;
	else
		cout << "Element " << (55.0f) << " konnte nicht eingefuegt werden!" << endl;
	list2.printList();

	// *** list3 erhält wieder list1 ***
	List list3(move(list));
	cout << "Ausgabe list3:" << endl;
	list3.printList();

	system("pause");
	return 0;
}





