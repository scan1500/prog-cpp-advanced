#include <stdio.h>
#include <stdlib.h>

int matches = 0;

void main()
{
	int* selectMask(int*, int, int);

	int values[] = { 1,2,3,4,5 };
	int *pointer = values, *result=NULL;

	result = selectMask(pointer, (sizeof(values) /sizeof(int)), 1); // 1 = Mask

	for (int i = 0; i < matches; i++)
		printf("%d\n", result[i]);

	system("pause");
}

int* selectMask(int *pointer, int size, int mask)
{
	int *r = NULL;

	for (int i = 0; i < size; i++)
		if ((mask & pointer[i]) == mask)
		{
			r = realloc(r, ++matches * sizeof(int));
			r[matches - 1] = (pointer[i] - mask);
		}

	return r;
}