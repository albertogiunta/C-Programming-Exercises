//
//  Esercizio1.c
//
//  Creato da Alberto Giunta il 05/11/13.
//  Matricola: 0000691428


/*Scrivere un programma che chieda all'utente un numero n e quindi
 - allochi n vettori di interi di lunghezza rispettivamente da 2 a n+1;
 - riempa i vettori
 - cerchi fra gli interi quello di valore massimo e quello ripetuto più volte*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAX 10 //grandezza vettore numeriPiuRipetuti

int main (void) {
    
    
    int **arrayDiVettori; //puntatore di puntatori
	int i, riprova, n;
	srand((unsigned)time(NULL));
	
	do {
		fpurge(stdin);
		riprova = 0;
		do {
			fpurge(stdin);
			printf("Inserire un numero maggiore di 1:");
		}while (scanf("%d", &n) == 0 || n <= 1);

		arrayDiVettori = (int**)malloc(n * sizeof(int*)); //riservo lo spazio per il vettore di puntatori
		
		/*CONTROLLO VARLORE MALLOC*/
		if (arrayDiVettori == NULL) {
			printf("Memoria non sufficiente!!!!!!!!!!!!");
			riprova = 1;
		}
		
	}while (riprova == 1);
	
	/*riservo lo spazio per ogni vettore di interi (ognuno di dimensioni diverse)*/
	for (i = 2; i <= n + 1; i++) {
		*(arrayDiVettori + i - 2) = (int*)malloc(i * sizeof(int)); 	}
	printf("\n\n");
	
	/*inizializzo casualmente e stampo la matrice*/
	printf("Stampo la matrice\n");
	for (i = 0; i < n; i++) {
		for (int j = 0; j < i + 2; j++) {
			*(*(arrayDiVettori + i) + j) = rand()%MAX;
			printf("%d ", *(*(arrayDiVettori + i) + j)); //stampa matrice
		}
		printf("\n");
	}
	
	/*RICERCA MASSIMO*/
	int max = -1;
	
	for (i = 0; i < n; i++) {
		for (int j = 0; j < i + 2; j++) {
			if (*(*(arrayDiVettori + i) + j) > max) {
				max = *(*(arrayDiVettori + i) + j);
			}
		}
	}
	printf("\nIl valore massimo è: %d", max);
	
	/*RIPETUTO PIÙ VOLTE*/
	printf("\n\n");
	max = -1;
	int j;
	int ripetutiPiuVolte[MAX] = {0}; //vettore con contatori, gli indici corrispondono ai numeri
	
	
	/*INCREMENTO CONTEGGIO NUMERO*/
	for (i = 0; i < n; i++) {
		for ( j = 0; j < i + 2; j++) {
			ripetutiPiuVolte[*(*(arrayDiVettori + i) + j)]++; //incremento il valore della cella di riferimento
		}
	}

	j = 0;
	for (i = 0; i < MAX; i++) {
		if (ripetutiPiuVolte[i] > max) {
			max = ripetutiPiuVolte[i]; //trovo il valore massimo
		}
	}
	printf("INDICI: \t\t");
	for (i = 0; i < MAX; i++) {
		printf("%2d ", i); //stampa indici
	}
	printf("\n-------------------------------------------\n");
	printf("RIPETIZIONI: \t");
	for (i = 0; i < MAX; i++) {
		printf("%2d ",ripetutiPiuVolte[i]); //stampa vettore ripetuti più volte
	}
	
	printf("\n\nNumeri ripetuti più volte: ");
	for (i = 0; i < MAX; i++) {
		if (ripetutiPiuVolte[i] == max) {
			printf("%d ", i); //stampo tutti gli indici con valore = massimo
		}
	}
	
	/*LIBERO LA MEMORIA ALLOCATA DINAMICAMENTE*/
	for (i = 0; i < n; i++) {
			free(*(arrayDiVettori + i));
	}
	free(arrayDiVettori);
	
	printf("\n\n");
	return 0;
}