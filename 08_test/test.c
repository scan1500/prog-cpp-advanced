#include <stdio.h>

int main() {

	int x = 2;
	double y = 4.0;
	int z = y;
	
	printf("%lf %lf %lf\n", x*y / z, x / z*y, 1 / (z/x*y));
	system("pause");
	return 0;

}