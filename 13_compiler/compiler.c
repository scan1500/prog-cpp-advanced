#include<stdio.h>

int main(void)
{
	int a = 4;
	double b = 8;
	int c = b;
	char z;
	printf("%lf\n", a*b / c);
	printf("%lf\n", a / c*b);
	printf("%lf\n", a / b*c);
	printf("%lf\n", 1 / (c / a*b));
	z = getch();

	return 0;
}