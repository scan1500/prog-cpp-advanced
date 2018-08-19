#include <stdio.h>

int zeller(int, int, int);

void main()
{
	int day=0, month=0, year=0;
	printf("<<<Calculating Weekday>>>\n\n");
	printf("Day: ");
	scanf_s("%d",  &day);
	printf("Month: ");
	scanf_s("%d", &month);
	printf("Year: ");
	scanf_s("%d", &year);

	switch(zeller(day, month, (month == 1 | month == 2) ? year-- : year))
	{
		case 0: printf("\n > Sunday\n\n");
			break;
		case 1: printf("\n > Monday\n\n");
			break;
		case 2: printf("\n > Tuesday\n\n");
			break;
		case 3: printf("\n > Wednesday\n\n");
			break;
		case 4: printf("\n > Thursday\n\n");
			break;
		case 5: printf("\n > Friday\n\n");
			break;
		case 6: printf("\n > Saturday\n\n");
			break;
	}
	system("pause");
}

int zeller(int d, int m, int y)
{
	if (m == 1)
		m = 13;

	if (m == 2)
		m = 14;

	int weekday = ((d + ((m + 1) * 26 / 10) + ((5 * (y % 100)) / 4) + ((y / 100) / 4) - (2 * (y / 100)) - 1) % 7);
	
	while(weekday < 0)
		weekday += 7;

	return weekday;
}