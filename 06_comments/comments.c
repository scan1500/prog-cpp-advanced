#include <stdio.h>

int main(void)
{
	printf("Kommentare werden in C mit /*..*/ geklammert.\n");
	printf("Beachte jedoch:");
	printf("\n- Kommentare innerhalb von Anfuehrungszeichen\n");
	printf("werden als Text und nicht als Kommentar interpretiert\n");
	/* printf("Ende\n"); */
	system("pause");
	return(0);
}