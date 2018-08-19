#include <stdio.h>
#define BITSIZE 32

void printBitvec(unsigned char*);
void setBitvec(unsigned char*, int);
void convIEEE754(unsigned char*, float);

unsigned char help = 128;
int exponent = 0;

void main()
{
	union ieee754 
	{
		float float_input;
	}u1;

	unsigned char bitvec[BITSIZE / 8] = { 0 };

	printf("Insert float value: ");
	scanf_s("%f", &u1.float_input);

	printf("\nHex: %x\n", *(unsigned int*)&u1.float_input);

	convIEEE754(bitvec, u1.float_input);
	printBitvec(bitvec);


	printf("\n\n");
	system("pause");
}

void convIEEE754(unsigned char *bitvec, float float_input)
{
	//Vorzeichenbit hinzufügen und Minuszeichen abfangen falls negativ
	if (float_input < 0)
	{
		setBitvec(bitvec, 31);
		float_input *= -1;
	}

	int pre_point = float_input;
	float post_point = float_input - pre_point;

	//Berechnen wie viele Mantissestellen für die Vorkommaziffern minus die erste 1 benötigt werden (Exponent)
	for (int pre_help = pre_point; pre_help > 1; pre_help /= 2)
			exponent++;

	//Vorkommastellen ohne die Vorderste 1 hinzufügen, ab Mantissenstelle 22 abwärts bis Mant.stelle - (Exponent-1) 
	for (int i = 23-exponent; i < 23; i++, pre_point /= 2)
		if (pre_point % 2)
			setBitvec(bitvec, i);

	//Nachkommastellen der Mantisse hinzufügen, ab der Stelle, an der die Vorkommastellen aufhören
	for(int i = (23-exponent)-1; i>=0; i--)// (post_point >= 1 ? post_point-- : post_point))
		if ((post_point *= 2) >= 1)
		{
			setBitvec(bitvec, i);
			post_point = post_point-1;
		}

	//Charakteristik hinzufügen
	char characteristic = exponent + 127;
	for (int i = 30; i >= 23; i--)
		if ((characteristic & (help >> (30 - i))) == (help >> (30 - i)))
			setBitvec(bitvec, i);

}

void setBitvec(unsigned char *bitvec, int index)
{
	bitvec[(index / 8)] |= (help >> ((((index / 8) + 1) * 8) - index) - 1);
}

void printBitvec(unsigned char *bitvec)
{
	//Ausgabe Vorzeichen
	if ((bitvec[3] & help) == help)
		printf("\nBinary: 1 | ");
	else
		printf("\nBinary: 0 | ");

	//Ausgabe Charakteristik 7 Stellen in Byte 3 
	for (int i = 30; i >= 24; i--)
		if ((bitvec[3] & (help >> (31 - i))) == (help >> (31 - i)))
			printf("1 ");
		else
			printf("0 ");

	//Ausgabe Charakteristik letzte Stelle in Byte 2
	if (bitvec[2] & help == help)
		printf("1 | ");
	else
		printf("0 | ");

	//Ausgabe Mantisse 7 Stellen in Byte 2 
	for (int i = 22; i >= 16; i--)
		if ((bitvec[2] & (help >> (23 - i))) == (help >> (23 - i)))
			printf("1 ");
		else
			printf("0 ");

	//Ausgabe Mantisse 8 Stellen in Byte 1
	for (int i = 15; i >= 8; i--)
		if ((bitvec[1] & (help >> (15 - i))) == (help >> (15 - i)))
			printf("1 ");
		else
			printf("0 ");

	//Ausgabe Mantisse 8 Stellen in Byte 0
	for (int i = 7; i >= 0; i--)
		if ((bitvec[0] & (help >> (7 - i))) == (help >> (7 - i)))
			printf("1 ");
		else
			printf("0 ");

}