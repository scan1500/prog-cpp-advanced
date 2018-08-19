#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char **pp, *z;
	if (argc >1)
	{
		pp = argv + 1;
		z = *pp + strlen(*pp);

		while (*pp - --z) //Adresse wird dekrementiert
			printf("%c", --*z); //Inhalt der Adresse wird dekrementiert, (vorheriger Buchstabe)

		printf("%c\n", *z);
	}

	system("pause");
	return 0;
}