#include <stdio.h>

void main()
{
	char text[100];
	char* char_pointer=NULL;
	char_pointer = text;

	printf("Insert text: ");
	fgets(text, 100, stdin);

	printf("Insert char: ");

	printf("%d\n", charcount(char_pointer, getchar()));
	system("pause");
}

int charcount(char* char_pointer, char c)
{
	int count = 0;

	while (*char_pointer)
		if (*char_pointer++ == c)
			count++;

	return count;
}