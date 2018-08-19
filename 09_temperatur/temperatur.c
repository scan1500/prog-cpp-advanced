#include <stdio.h>

//5 * (Fahrenheit - 32) = 9 * Celsius
int main(void)
{
	float fahrenheit=0;
	float celsius=0;

	printf("Fahrenheit: ");
	scanf_s("%f", &fahrenheit);

	printf("\n%.1f Fahrenheit entsprechen %.1f Celsius \n\n", fahrenheit, (5 * (fahrenheit - 32) / 9));

	printf("Celsius: ");
	scanf_s("%f", &celsius);

	printf("\n%.1f Celsius entsprechen %.1f Fahrenheit \n\n", celsius, ((9*celsius)/5)+32);


	system("pause");
	return 0;
}