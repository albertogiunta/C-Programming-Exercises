//  Esercizio2
//
//  Creato da Alberto Giunta il 26/09/2013
//  Matricola: 0000691428

#include <stdio.h>

int main ()
{
	/* solitamente non è richiesto, ma in questo esercizio lascio uno spazio tra
	la sequenza di escape e il resto della stringa per migliorare la
	leggibilità del codice */
	
    puts("Stampo stringhe a video utilizzando le sequenze di escape conosciute\n");
	
    puts("\" stampo i doppi apici");
    puts("\' stampo l'apice singolo");
	puts("\\ stampo il backslash");
	puts("\? stampo il punto interrogativo");
	//le funzioni di escape fin'ora usate vengono utilizzate per stampare caratteri
	//che altrimenti verrebbero confusi con caratteri "di servizio" del linguaggio C
	
	printf("vado a capo\n\n");
    puts("\a il computer emette un suono");
	puts("cancello l'ultimo carattere\b");
	puts("\t tabulazione orizzontale");
	puts("\v tabulazione verticale");
	puts("carattere nullo o fine strin\0ga");
	
	return 0;
}