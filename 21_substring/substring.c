#include <stdio.h>

void main()
{
	int substr(const char* str1, const char* str2);
	int strlaenge(const char* str);

	char str1[] = "Kleiderschrank";
	char str2[] = "der";

	printf("String 1: %s\n", str1);
	printf("Length: %d\n", strlaenge(str1));
	printf("String 2: %s\n", str2);
	printf("Length: %d\n", strlaenge(str2));
	printf("------------------------------\n");
	printf("String 2 begins @: %d\n\n", substr(str1, str2));

	system("pause");
}

int substr(const char* str1, const char* str2)
{
	for (int i = 0; i <= strlaenge(str1) - strlaenge(str2); i++)
		if (str1[i] == *str2)
			for (int j = i; str1[j] == str2[j-i]; j++)
				if (j == (i + strlaenge(str2)-1))
					return i;
	return -1;
}

int strlaenge(const char* str)
{
	int length = 0;
	while (*str++)
		length++;
	return length;
}