#include <stdio.h>

/*
o const int *zgr_auf_konstante = &variable;
	Der Zeiger darf verändert werden, der Inhalt der Speicherstelle
	nicht.

o int *const konstanter_zgr = &variable;
	Hier ist es umgekehrt: Der Zeiger darf nicht verändert werden,
	der Inhalt der Speicherstelle schon.

o const int *const konst_zgr_auf_konst = &variable;
	Hier darf überhaupt nichts verändert werden.
*/

const char* strChar(char *s, char c);
//char* strChar(const char *s, int c);
//char* strChar(char const *s, int c);

void main()
{
	char value[] = "Digitaltechnik";
	char* p = value;

	printf("%c\n", *(strChar(p, 'c')));
	system("pause");
}

const char* strChar(char *s, char c)
{
	 const char* char_pointer = s;

	while (*s++ != c)
		char_pointer = s;

	return char_pointer;
}