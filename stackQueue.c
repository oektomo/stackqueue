/*
 * stackQueue.c
 *
 *  Created on: May 3, 2017
 *      Author: otm
 */

// directive preprocessor
#include <stdio.h>

#define INPUT_STACK		1
#define OUTPUT_STACK	2
#define INPUT_QUEUE		3
#define OUTPUT_QUEUE	4
#define PRINT_STACK		5
#define PRINT_QUEUE		6
#define QUIT			7
#define PANJANG_ANTRIAN 20
#define PANJANG_TUMPUKAN 20

void printArray(int* ArrayInt, int length);

void printQueue(int* ArrayInt, int length, int start, int end);
void inputQueue(int* ArrayInt, int data, int length, int* readP, int* writeP);
int outputQueue(int* ArrayInt, int length, int* readP, int* writeP);

/**
 * @brief inputStack
 * @input ArrayInt pointer ke Array Stack
 * @input data data yang akan dimasukkan ke dalam stack
 * @input int length panjang Array Stack
 * @input int* writeP berfungsi sebagai stack pointer
 *
 */
void inputStack(int* ArrayInt, int data, int length, int* writeP);

/**
 * @brief outputStack
 * @input int*ArrayInt
 * @input int* writeP
 */
int outputStack(int*ArrayInt, int* writeP);

int main()
{
int pilihan = 0;
int dataTumpukan[PANJANG_TUMPUKAN], dataAntrian[PANJANG_ANTRIAN];
int penunjukTumpukan = 0, bacaAntrian = 0, tulisAntrian = 0;

while(pilihan != QUIT)
{
	printf("        Menu :\n");
	printf("=====================\n");
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
		printf("memasukkan %d ke Tumpukkan\n", bilBulat);
		inputStack(dataTumpukan, bilBulat, PANJANG_TUMPUKAN, &penunjukTumpukan);
		break;
	case OUTPUT_STACK :
		bilBulat = outputStack(dataTumpukan, &penunjukTumpukan);
		printf("Data Tumpukan teratas: %d\n", bilBulat);
		break;
	case INPUT_QUEUE :
		printf("Masukkan bilangan bulat ke Antrian: ");
		scanf("%d",&bilBulat);
		printf("memasukkan %d ke Antrian\n", bilBulat);
		inputQueue(dataAntrian, bilBulat, PANJANG_ANTRIAN, &bacaAntrian, &tulisAntrian);
		break;
	case OUTPUT_QUEUE :
		bilBulat = outputQueue(dataAntrian, PANJANG_TUMPUKAN, &bacaAntrian, &tulisAntrian);
		printf("Data Antrian Terdepan: %d\n", bilBulat);
		break;
	case PRINT_STACK :
		printf("Data Tumpukan:\n");
		printArray(dataTumpukan, penunjukTumpukan);
		printf("Data array Tumpukan:\n");
		printArray(dataTumpukan, PANJANG_TUMPUKAN);
		break;
	case PRINT_QUEUE :
		printf("Data Antrian:\n");
		printQueue(dataAntrian, PANJANG_ANTRIAN, bacaAntrian, tulisAntrian);
		printf("Data array Tumpukan:\n");
		printArray(dataAntrian, PANJANG_ANTRIAN);
		break;
	}
	printf("\n \n \n");
	getchar();

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

void printQueue(int* ArrayInt, int length, int start, int end)
{
	for (int i = start; i != end; i++) {
		i = i % length;
		printf("%d ", ArrayInt[i]);
	}
	printf("\n");
}

void inputQueue(int* ArrayInt, int data, int length, int* readP, int* writeP)
{
	// check buffer overwrite
	ArrayInt[*writeP] = data;
	(*writeP)++;
	*writeP = *writeP % length;
}

int outputQueue(int* ArrayInt, int length, int* readP, int* writeP)
{
	// check buffer underrun
	int temp = ArrayInt[*readP];
	(*readP)++;
	*readP = *readP % length;
	return temp;
}

void inputStack(int* ArrayInt, int data, int length, int* writeP)
{
	// check stack overflow
	ArrayInt[*writeP] = data;
	(*writeP)++;
}

int outputStack(int*ArrayInt, int* writeP)
{
	(*writeP)--;
	// check stack empty
	return ArrayInt[*writeP];
}
