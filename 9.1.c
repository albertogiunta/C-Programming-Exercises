//
//  Esecizio1.c
//
//  Creato da Alberto Giunta il 30/11/13.
//  Maticola: 0000691428

/*Implementare tramite una funzione ricorsiva che risolva il problema delle torri di Hanoi.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*prototipi funzioni*/
void hanoi (int n, int a, int b, int c);
void muovi (int n, int a, int b);

/*main*/
int main () {
    int n;
    do {
        printf("Con quanti dischi si vuole giocare?     »");
	}while (scanf("%d", &n) != 1 && n <= 0); /*inserimento numero di dischi*/
	printf("Saranno necessarie %.0f mosse.\n\n",(pow(2, n) - 1)); /*calcolo il numero di mosse minimo*/
	hanoi(n, 1, 2, 3);

	printf("\n\n      F I N E      ");
    printf("\n\n");
    return 0;
}

/*funzione hanoi, ricorsiva, quando si richiama si occupa anche di 
 passare le variabili nell'ordine relativo alla mossa necessaria*/
void hanoi (int n, int a, int b, int c) {

	if (n == 1) { /*passo base*/
		muovi(n, a, c); /*stampo l'operazione*/
	} else {
		hanoi(n - 1, a, c, b); /*sposto n-1 dischi dal primo piolo al secondo*/
		muovi(n, a, c); /*stampo l'operazione*/
		hanoi(n - 1, b, a, c); /*ripeto lo spostamento di nuovo per n-1 dal secondo al terzo piolo*/
	}
}

/*funzione muovi, stampa il numero della mossa e la mossa fatta*/
void muovi (int n, int a, int c) {
	static int conta = 0; /*static così posso usarla come contatore locale alla funzione senza che si riazzeri ogni volta*/
	conta++; /*incremento la mossa*/
	printf("%d » Muovo dal palo %d al palo %d\n",conta, a, c); /*stampo il tipo di mossa*/
}