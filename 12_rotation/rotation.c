#include <stdio.h>

unsigned char rotate_bits(unsigned char, int);

int main(void)
{
	unsigned char unrotated_char = 154;
	unsigned char rotated_char = 0;

	rotated_char = rotate_bits(unrotated_char, 1);

	printf("Unrotated Char: %d \n", unrotated_char);
	printf("Rotated Char: %d \n", rotated_char);

	printf("%d\n", rotate_bits(154, 3));

	system("pause");
	return 0;
}

unsigned char rotate_bits(unsigned char c, int n)
{
	return ((c << n) | c >> (8 - n));
}
