//
//  Esercizio3.c
//
//  Creato da Alberto Giunta il 05/11/13.
//  Matricola: 0000691428


/*Si scriva un programma che allochi dinamicamente un vettore di interi e che effettui le operazioni di: 
 - ricerca di un valore all'interno del vettore restituendo la posizione se il valore è presente 
 - ricerca del valore massimo e di quello minimo presenti nel vettore 
 - reverse degli elementi del vettore 
 Il tutto lavorando sui valori del vettore sia tramite notazione vettoriale che tramite l’aritmetica dei puntatori.*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int main () {
	
	int n, i, ricerca, trovato = FALSE, riprova = FALSE, j = 0;
	int *vett;
	
	do {
		fpurge(stdin);
		/*INSERIMENTO NUMERO ELEMENTI NEL VETTORE*/
		riprova = FALSE;
		printf("Inserisci il numero di elementi del vettore (n >= 1): ");
		if (scanf ("%d", &n) != TRUE) {
			riprova = TRUE;
		} else riprova = FALSE;
		if (n < 1) {
			riprova = TRUE;
		}
	} while (riprova == TRUE);
	
	trovato = FALSE;
	
	printf("\n");
	vett = (int*)malloc(n * sizeof(int)); //alloco un vettore grande quanto il numero inserito in input * l'ingombro di ogni cella di tipo char
	
	/*CONTROLLO VARLORE MALLOC*/
	if (vett == NULL) {
		printf("\nMemoria non sufficiente!!!!!!!!!!!!\n");
		riprova = TRUE;
	}
	
	srand((unsigned)time(NULL));
	
	/*INIZIALIZZO CASUALMENTE IL VETTORE*/
	
	//notazione vettoriale
	
	for (i = 0; i < n; i++) {
		vett[i] = rand() %10 + 1;
	}
	
	//aritmetica puntatori
	for (i = 0; i < n; i++) {
		*(vett + i)= rand() %10 + 1;
	}
	
	
	/*STAMPO IL VETTORE*/
	printf("*Il vettore inizializzato casualmente è il seguente*\n\n");
	//notazione vettoriale
	printf("Con notazione vettoriale: ");
	for (i = 0; i < n; i++) {
		printf("%d ", vett[i]);
	}
	
	printf("\n");

	//aritmetica puntatori
	printf("Con l'aritmetica dei puntatori: ");
	for (i = 0; i < n; i++) {
		printf("%d ", *(vett + i));
	}
	
	printf("\n\n");
	
	/*REVERSE DEL VETTORE*/
	printf("*Il vettore visualizzato al contario è il seguente*\n\n");
	//notazione vettoriale
	printf("Con notazione vettoriale: ");
	for (i = n - 1; i >= 0; i--) {
		printf("%d ", vett[i]);
	}
	
	printf("\n");
	
	//aritmetica puntatori
	printf("Con l'aritmetica dei puntatori: ");
	for (i = n - 1; i >= 0; i--) {
		printf("%d ", *(vett + i));
	}
	
	printf("\n\n");
	
	/*RICERCA*/
	do {
		fpurge(stdin);
		printf("\n\nRicerca un valore: ");
	} while (scanf("%d", &ricerca) != 1);
	
	//notazione vettoriale
	printf("Con notazione vettoriale.\n");
	for (i = 0; i < n; i++) {
		trovato = FALSE;
		if (vett[i] == ricerca) {
			trovato = TRUE;
			printf("Il valore %d è stato trovato nella posizione %d dell'array.\n", ricerca, i);
		} else {
			j++;
		}
	}
	j = 0;
	
	//aritmetica puntatori
	printf("\nCon l'aritmetica dei puntatori.\n");
	for (i = 0; i < n; i++) {
		trovato = FALSE;
		if (*(vett + i) == ricerca) {
			trovato = TRUE;
			printf("Il valore %d è stato trovato nella posizione %d dell'array.\n", ricerca, i);
		} else {
			j++;
		}
	}
	
	if (j == n) {
		printf("\nIl valore %d non è stato trovato all'interno dell'array.\n", ricerca);
	}
	
	
	/*STAMPO MASSIMO E MINIMO*/
	int *ptrMin = &vett[0], *ptrMax = &vett[0]; //inizializzo puntatori a massimo e minimo
	
	/*MINIMO*/
	//notazione vettoriale
	for (i = 0; i < n; i++) {
		if (*ptrMin > vett[i]) {
			*ptrMin = vett[i];
		}
	}
	
	//aritmetica puntatori
	for (i = 0; i < n; i++) {
		if (*ptrMin > *(vett + i)) {
			*ptrMin = *(vett + i);
		}
	}
	printf("\nIl minimo è: %d\n", *ptrMin); //stampo minimo
	
	/*MASSIMO*/
	//notazione vettoriale
	for (i = 0; i < n; i++) {
		if (*ptrMax < vett[i]) {
			*ptrMax = vett[i];
		}
	}
	
	//aritmetica puntatori
	for (i = 0; i < n; i++) {
		if (*ptrMax < *(vett + i)) {
			*ptrMax = *(vett + i);
		}
	}
	printf("\nIl massimo è: %d\n", *ptrMax); //stampo massimo

	free(vett); //libero la memoria allocata dinamicamente
	
	printf("\n\n");
	return 0;
}