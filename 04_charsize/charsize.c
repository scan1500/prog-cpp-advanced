#include <stdio.h>

int main()
{
	char c = 'x';

	printf("Stringziffer: %d Bytes \n", sizeof("\0"));
	printf("Charziffer: %d Bytes \n", sizeof('0')); 

	printf("char-Konstante: %d Bytes \n", sizeof('x')); //Wird zunächst als int-Wert gesehen ('120')
	printf("char-Variable: %d Byte \n", sizeof(c));
	printf("int-Wert: %d Bytes \n", sizeof(10));
	printf("Inhalt der char-Var.: %c, int-Konstante: %i\n", c, 10);

	printf("\n");
	system("pause");
	return 0;
}