//
//  Esercizio3.c
//
//  Creato da Alberto Giunta il 24/10/13
//  Matricola: 0000691428

/*Scrivere un programma C che presa una matrice quadrata contenente valori interi
 determini se si tratta di una matrice magica. 
 Una matrice si dice magica quando la somma degli elementi di ogni riga è uguale alla somma di quelli di ogni colonna 
 e questo valore è anche uguale alla somma degli elementi della diagonale principale 
 e alla somma degli elementi della diagonale secondaria*/

#include <stdio.h>
#define R 5
#define C 5

int main ()
{
	int mat[R][C] = { {17, 23, 4, 10, 11}, {24,	5, 6, 12, 18}, {1, 7, 13, 19, 25}, {8, 14, 20, 21, 2}, {15, 16, 22, 3, 9} };
	
	int sum = 0, r = 0, c = 0, d1 = 0, d2 = 0, j = 0, i = 0, sumR = 0, sumC = 0;
	
	/*STAMPA*/
	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			printf("%4d ", mat[i][j]);
		}
		printf("\n");
	}
	
	
	/*SOMMA RIGHE*/
	for (j = 0; j < 5; j++) {
		sum += mat[0][j]; // riga di test
	}
//	printf("\nsum = %d\n",sum);
	
	/*ANALIZZO RIGHE*/
	for (i = 1; i < 5; i++) { //parto dalla seconda riga in poi
		r = 0;
		for (j = 0; j < 5; j++) { //scorro le colonne
			r += mat[i][j]; //incremento la somma
		}
		if (sum != r) break;
		sumR++;
	}
//	printf("\nsumR = %d\n",sumR);

	
	/*ANALIZZO COLONNE*/
	for (i = 0; i < 5; i++) { //parto dalla seconda riga in poi
		c = 0;
		for (j = 0; j < 5; j++) { //scorro le colonne
			c += mat[j][i]; //incremento la somma
		}
		if (sum != c) break;
		sumC++;
	}
//	printf("\nsumC = %d\n",sumC);

	
	/*ANALIZZO DIAGONALE 1 */
	for (i = 0, j = 0; i<5 && j<5; i++, j++) {
		d1 += mat[i][j];
	}
//	printf("\nd1 = %d\n",d1);

	/*ANALIZZO DIAGONALE 2 */
	for (i = 4, j = 0; i >= 0 && j < 5; i--, j++) {
		d2 += mat[i][j];
	}
//	printf("\nd2 = %d\n",d2);

	
	/*STAMPA*/
	if (sumR == 4 && sumC == 5  && d1 == sum && d2 == sum) {
		printf("\nLa matrice è magica.");
	} else {
		printf("\nTanto lavoro per nulla, la matrice non è magica :(");
	}
		
		
	printf("\n\n");
	return 0;
}
