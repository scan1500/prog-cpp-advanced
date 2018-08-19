#include <stdio.h>

char *c[] = { "he dast ga", "lllt dumm", "C i", "dar nich"};
//			|  dar nich  |    C i   | lllt dumm | he dast ga
char **cp[] = { c + 3, c + 2, c + 1, c };
char ***cpp = cp;

int main(void)
{
	printf("%s", **++cpp);			
	printf("%s", *--*++cpp + 5);	
	printf("%s", cpp[-2][0] + 2);		
	printf("%s\n", *(cpp[1] + 1) + 3);
	getchar();
}