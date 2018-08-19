#include <stdio.h>
#define ARRSIZE 24

void main()
{
	int get(char*, int);
	void set(char*, int);
	void reset(char*, int);

	unsigned char my_bitvec[ARRSIZE / 8] = { 0 }, auswahl = 0;

	while (1)
	{
		system("cls");
		printf("Was wollen Sie tun?\n");
		printf("[0] Beenden\n");
		printf("[1] Get\n");
		printf("[2] Set\n");
		printf("[3] Reset\n");
		scanf_s("%d", &auswahl);

			switch(auswahl)
			{
				case 1:	
					printf("Welches Byte wollen Sie?\n");
					scanf_s("%d", &auswahl);
					printf("Wert: %d\n\n", get(my_bitvec, auswahl));
					system("pause");
					break;
				case 2:
					printf("Welches Feld wollen sie setzen?\n");
					scanf_s("%d", &auswahl);
					set(my_bitvec, auswahl);
					printf("Das Feld %d wurde gesetzt!\n\n", auswahl);
					system("pause");
					break;
				case 3:
					printf("Welches Feld wollen sie zuruecksetzen?\n");
					scanf_s("%d", &auswahl);
					reset(my_bitvec, auswahl);
					printf("Das Feld %d wurde zurueckgesetzt!\n\n", auswahl);
					system("pause");
					break;
				default:
					system("pause");
					exit(0);
					break;
			}
	}
}

int get(unsigned char* bitvec, int index)
{
	return bitvec[index];
}

void set(unsigned char* bitvec, int index)
{
	unsigned char help = 128;
	bitvec[(index / 8)] |= (help >> ((((index / 8) + 1) * 8) - index) - 1);
}

void reset(unsigned char* bitvec, int index)
{
	unsigned char help = 0;
	bitvec[(index / 8)] &= (help >> ((((index / 8) + 1) * 8) - index) - 1);
}