#include <stdio.h>

int main(void)
{
	printf("Hauptmenue \n");
	printf("== == == == == \n\n");

	printf("(A)endern \n");
	printf("(B)eenden \n");
	printf("(D)rucken \n");
	printf("(E)ingeben \n");
	printf("(L)oeschen \n\n\n");


	printf("Was wuenschen Sie zu tun ? \n");

	switch (getchar())
	{
		case 'A': printf("A wurde gedrueckt! \n");
			break;
		case 'B': printf("B wurde gedrueckt! \n");
			break;
		case 'D': printf("D wurde gedrueckt! \n");
			break;
		case 'E': printf("E wurde gedrueckt! \n");
			break;
		case 'L': printf("L wurde gedrueckt! \n");
			break;
		default: printf("Eingabe unbekannt! \n");
			break;
	}

	system("pause");
	return 0;
}