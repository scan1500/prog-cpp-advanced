#include <stdio.h>
#define SWAP(a, b, help) { help = b; b = a; a = help; }

int main()
{
	int values[5], help = 0;

	printf("Insert 5 values to calc. the median: \n");
	for (int i = 0; i < 5; i++)
		scanf_s("%d", &values[i]);


	printf("Unsorted Array:\n");
	for (int i = 0; i < 5; i++)
		printf("%d ", values[i]);

	for (int j = 4; j > 0; j--)
		for (int i = 0; i < j; i++)
			if (values[i] > values[i + 1])
				SWAP(values[i], values[i + 1], help);

	printf("\n\nSorted Array:\n");
	for (int i = 0; i < 5; i++)
		printf("%d ", values[i]);

	printf("\n\nMedian: %d \n\n", values[2]);

	system("pause");
	return 0;
}