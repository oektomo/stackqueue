/*
 * stack.c
 *
 *  Created on: May 3, 2017
 *      Author: otm
 */

#include <stdio.h>

#define INPUT_STACK	1
#define OUTPUT_STACK	2
#define PRINT_STACK 5
#define QUIT	7
#define PANJANG_TUMPUKAN 20

void printArray(int* ArrayInt, int length);

void inputStack(int* ArrayInt, int data, int length, int* writeP);
int outputStack(int*ArrayInt, int* writeP);

int main()
{
int pilihan = 0;
int dataTumpukan[PANJANG_TUMPUKAN];
int penunjukTumpukan = 0, bacaAntrian = 0, tulisAntrian = 0;

while(pilihan != QUIT)
{
	printf("Menu:\n");
	printf("1. Masukkan data ke Tumpukan\n");
	printf("2. Keluarkan data Tumpukan Teratas\n");
	printf("3. Masukkan data ke Antrian\n");
	printf("4. Keluarkan data Antrian Terdepan\n");
	printf("5. Tampilkan data Tumpukan\n");
	printf("6. Tampilkan data Antrian\n");
	printf("7. Keluar\n");
	printf("Masukan pilihan: ");
	scanf("%d",&pilihan);
	int bilBulat = 0;

	switch (pilihan) {

	case INPUT_STACK :
		printf("Masukkan bilangan bulat ke Tumpukkan: ");
		scanf("%d",&bilBulat);
		printf("memasukkan %d ke Tumpukkan", bilBulat);
		inputStack(dataTumpukan, bilBulat, PANJANG_TUMPUKAN, &penunjukTumpukan);
		break;
	case OUTPUT_STACK :
		bilBulat = outputStack(dataTumpukan, &penunjukTumpukan);
		printf("Data Tumpukan teratas: %d\n", bilBulat);
		break;
	case PRINT_STACK :
		printf("Data Tumpukan:\n");
		printArray(dataTumpukan, penunjukTumpukan);
		printf("Data array Tumpukan:\n");
		printArray(dataTumpukan, PANJANG_TUMPUKAN);
		break;

	}

}
return 0;
}

void printArray(int* ArrayInt, int length)
{
	for (int i = 0; i < length; i++) {
		printf("%d ", ArrayInt[i]);
	}
	printf("\n");
}

void inputStack(int* ArrayInt, int data, int length, int* writeP)
{
	ArrayInt[*writeP] = data;
	(*writeP)++;
}

int outputStack(int*ArrayInt, int* writeP)
{
	(*writeP)--;
	return ArrayInt[*writeP];
}
