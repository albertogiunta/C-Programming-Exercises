//
//  Esecizio4.c
//
//  Creato da Alberto Giunta il 19/11/13.
//  Maticola: 0000691428
/*Realizzare un programma per il calcolo del fattoriale in modo da visualizzare le sue variabili locali e i parametri delle chiamate ricorsive. 
 Per ogni chiamata ricorsiva, visualizzare l’output su una riga separata e aggiungere un livello di rientro. 
 Fate del vostro meglio per rendere l’output chiaro, interessante e significativo.
 L’obiettivo è quello di disegnare e implementare un formato dell’output che aiuti una persona a capire meglio la ricorsione.*/

#include <stdio.h>

int input();
long double fatt(long double);


int main () {
	
	int i;
	long double n = input(); //prendo il numero di cui fare il fattoriale in input
	for (i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			printf(" "); //stampo il rientro relazionato al passo in cui ci si trova
		}
		printf("\nPasso base: n = 1. Ora n vale %d\n", i);

		printf("Il fattoriale di %d è: %.0Lf\n\n", i, fatt(i));
	}
	return 0;
}

/* FUNZIONE INPUT + CONTROLLO INPUT*/
int input() {
	int n;
	do {
		printf("Inserire il numero n di cui si vuole calcolare il fattoriale: ");
	}while (scanf("%d", &n)!= 1);
	printf("\n");
	(n < 1 && n != 0) ? n *= -1 : n ; //prendo il valore assoluto dell'input
	return n;
}

/* FUNZIONE FATTORIALE */
long double fatt(long double n) {
	if (n <= 1) {
		return 1;
	} else {
		return n * fatt(n - 1); //richiamo la funzione stessa finchè non raggiungo un passo base di cui conosco il risultato che mi permette di tornare al punto iniziale
	}
}