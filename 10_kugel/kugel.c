#include <stdio.h>
#define PI 3.1415927
#define zweite_pot(x) ((x)*(x))
#define dritte_pot(x) ((x)*(x)*(x))

int main(void)
{
	double radius = 0;
	//const double pi = 3.1415927;

	printf("Radius einer Kugel eingeben (cm): ");
	scanf_s("%lf", &radius);

	printf("Oberflaeche: %lfcm^2 \n", 4*PI*zweite_pot(radius));
	printf("Volumen: %lfcm^3 \n", 4*PI*dritte_pot(radius)/3);

	system("pause");
	return 0;
}