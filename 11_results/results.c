#include <stdio.h>

int main(void)
{
	int n = 3, k = 4, m;
	float a = 0, b = 3.2;

	char c, e = 1;

	m = n % 2 ? -1 + n : n;
	printf("n %% 2 ? -1 + n : n -> %d \n", m);

	//Mit Klammerung wird zuerst die Multiplikation ausgeführt und dann geteilt 1/2b
	//Ohne Klamerung wird erst geteilt und dann die Multiplikation ausgeführt -> 0 * b
	a = 1 / (2 * b);
	printf("1 / (2 * b) -> %f \n", a);

	//Mit Klammerung wird zuerst 4<1 verglichen -> ergibt 0
	//Ohne Klammerung wird erst Bit-Shifted und dann verglichen -> ergibt 1
	c = (4 < 1) << n;
	printf("(4 < 1) << n -> %d \n", c);

	//Ohne Klammerung -> 1/e = 1, (1/3.2) als char abspeichern ergibt 0
	//Mit Klammerung wird erst a+b ausgeführt dann mit e geteilt und dann mit 1 -> ergibt 3
	c = 1 / (e / (b + a));
	printf("c = 1 / (e / (b + a)) -> %d \n", c);

	system("pause");
	return 0;
}