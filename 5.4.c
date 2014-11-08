//
//  Esercizio4.c
//
//  Creato da Alberto Giunta il 24/10/13
//  Matricola: 0000691428

/*Scrivere un programma C che legga una frase introdotta da tastiera. 
 La frase è terminata dall’introduzione del carattere di invio. 
 La frase contiene sia caratteri maiuscoli che caratteri minuscoli e complessivamente al più 100 caratteri.
 Il programma dovrà stampare su schermo le seguenti informazioni: 
 •per ognuna delle lettere dell’alfabeto, il numero di volte che la lettera compare nella stringa
 •il numero di consonanti presenti nella stringa  
 •il numero di vocali presenti nella stringa.*/

#include <stdio.h>
#include <ctype.h>
#define MAX 100




int main () {
	
	char string[MAX+1], c;
	int i,len = 0, ascii, vocals = 0, cons = 0;
	int count[27] = {0};
	
	printf("Insert some text: ");
	
	while ((c = getchar()) != '\n' && len < MAX) { //finchè non è premuto INVIO o si raggiunge il limite di lunghezza
		c = tolower(c); //rendo la stringa tutta minuscola
		string[len] = c; //assegno il carattere inserito in una nuova cella del vettore
		len++; //seleziono una nuova cella del vettore
		 
		if ( c != 32 && c >= 97 && c <= 122) { //controllo ascii per conteggi di vocali e consonanti
			switch (c) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					vocals++;
					break;
				default:
					cons++;
					break;
			}
		}
	}
    string[len] = '\0'; //termino la stringa col carattere terminatore
	
	for (i = 0; i < len; i++) { //incremento il conteggio del carattere nella cella corrispondente al suo posto nell'alfabeto
		ascii = string[i];
		ascii -= 96;
		count[ascii]++;
	}
    
	for (i = 1; i <= 26; i++) {
		printf("La lettera %c è stata scritta %d ", i + 96, count[i]);
		if (count[i] == 1) { //controllo grammaticale volte-volta
			printf("volta.\n");
		} else {
			printf("volte.\n");
		}
	}
	printf("\nSono state scritte %d vocali e %d consonanti.", vocals, cons);
	
    puts("\n\n");
    return 0;
}