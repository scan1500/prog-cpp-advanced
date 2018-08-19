#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(0));
	int zufallszahl = (int)(10.0*rand() / (RAND_MAX + 1.0));
	int eingabe="0";

	printf("Erraten Sie eine Zahl von 0 bis 9.\n");
	printf("-------------------------------------\n");
	for (int i = 1; i <= 3; i++)
	{
		printf("%d.Versuch: ", i);
		scanf_s("%d", &eingabe); //Tastatureingabe, Speichert Wert direkt in die Adresse der Variable -> &

		if (zufallszahl == eingabe)
		{
			printf("\n Richtige Zahl!\n\n");
			break;
		}
		else
			printf("\n Falsche Zahl!\n\n");
	}
	printf("-------------------------------------\n");
	printf("Die Zufallszahl ist: %d \n\n", zufallszahl);
	system("pause");
	return 0;
}