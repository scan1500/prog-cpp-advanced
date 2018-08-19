#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void main()
{
	char input_buffer[100];
	FILE *file_pointer = NULL;
	const char * const filename = "memo.txt";

	time_t current_time;
	struct tm *time_info;
	char timeString[9];  // space for "HH:MM:SS\0"

	//WRITING
	if ((file_pointer = fopen(filename, "a")) == NULL)
	{
		fprintf(stderr, "Fehler: Datei %s konnte nicht geöffnet werden!", filename);
		exit(0);
	}
	while (1)
		if (fgets(input_buffer, 100, stdin)[0] != '.')
		{
			time(&current_time);
			strftime(timeString, sizeof(timeString), "%H:%M:%S", localtime(&current_time));

			fprintf(file_pointer, timeString);
			fprintf(file_pointer, ": ");
			fprintf(file_pointer, input_buffer);
		}
		else
			break;
	fclose(file_pointer);

	//READING
	if ((file_pointer = fopen(filename, "r")) == NULL)
	{
		fprintf(stderr, "Fehler: Datei %s konnte nicht geöffnet werden!", filename);
		exit(0);
	}
	for (int i = 1; fgets(input_buffer, 100, file_pointer); i++)
		printf("%d. %s", i, input_buffer);

	fclose(file_pointer);

	printf("\n");
	system("pause");
}