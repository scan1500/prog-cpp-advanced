#include <stdio.h>

int leapyear(int year)
{
	//Wenn Jahr / 4 Rest 0 ergibt -> Schaltjahr, sprich Februar hat 29 Tage, ergo 1 zurückgeben
	//Wenn Jahr / 4 Rest >= 1 ergibt -> Kein Schaltjahr, sprich Februar hat 28 Tage, ergo 0 zurückgeben
	return ((year % 4) ? 0 : 1);
}

int main(void)
{
	int days = 0, month = 0, year = 0;

	printf("Insert day: ");
	scanf_s("%d", &days);
	printf("\nInsert month: ");
	scanf_s("%d", &month);
	printf("\nInsert year: ");
	scanf_s("%d", &year);

	int months[] = { 31, 28 + leapyear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	for (int i = 0; i < month - 1; i++)
		days += months[i];

	printf("\nNumber of days: %d \n\n", days);

	system("pause");
	return 0;
}