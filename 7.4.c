//
//  Esercizio4.c
//
//  Creato da Alberto Giunta il 05/11/13.
//  Matricola: 0000691428


/*Si vuole gestire una sequenza (frase) di stringhe (parole) la cui dimensione non è nota a priori. 
 Le parole devono poter essere di lunghezza differente. 
 Scrivere un programma C che allochi dinamicamente le informazioni descritte e che costruisca una nuova frase in cui l'ordine delle parole sia invertito (ad esempio, la frase “Che bella giornata” diviene “giornata bella Che”) lavorando con i puntatori a parola.
 Il programma deve visualizzare la frase prima e dopo la trasformazione.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN_PHRASE 200

int main () {
	
	char *frase; //contiene tutta la frase
	char **parola; //contiene puntatori a parole
	char c;
	int i = 0, j = 0, k, contaPar = 0, length = 0, x = 0, start = 0;

	/*alloco dinamicamente il vettore per la frase*/
	frase = (char*)malloc(MAX_LEN_PHRASE * sizeof(char));
	printf("Inserire una frase (RETURN per terminare):\n");
	/*riempio la frase*/
	while((c = getchar())!='\n' && length < MAX_LEN_PHRASE) {
		*(frase + length) = c;
		length++;
	}
	
	if (length > MAX_LEN_PHRASE) {
		printf("\nHai inserito una stringa troppo lunga, perciò è stata tagliata a %d caratteri.\n", MAX_LEN_PHRASE);
	}
	*(frase + length) = '\0'; //inserisco il carattere terminatore alla fine della frase
	
	for (i = 0 ; i < length+1; i++) { //faccio funzionare il programma e il conteggio delle parole anche se ci sono spazi iniziali
		if (*(frase + i) == ' ') { //partendo dall'inizio della frase, finchè incontro spazi incremento di 1 il punto di partenza
			start++;
		} else break; //quando finalmente incontro un carattere esco dal ciclo
	}
	
	/*conto quante parole contiene la stringa, il numero di parole sarà uguale al numero di puntatori a parola*/
	for (i = start; i < length+1; i++) { //scorro tutta la frase
		 if ((*(frase + i) == ' ' || *(frase + i) == '\0') && *(frase + i + 1) != ' ') { //quando trovo il termine di una parola
			 contaPar++; //incremento il numero di parole
		}
	}
	parola = (char**)malloc(contaPar * sizeof(char*)); //alloco il vettore di puntatori a parola
	printf("\nSono state inserite %d parole.\n", contaPar);
	
	contaPar = 0; //reinizializzo il conteggio delle parole
	printf("\nLe parole che sono state memorizzate sono:\n");
	for (i = start; i < length+1; i++) { //scorro tutta la frase
		if ((*(frase + i) == ' ' || *(frase + i) == '\0') && *(frase + i + 1) != ' ') { //quando trovo il termine di una parola
			*(parola + contaPar) = (char*)malloc((i-j + 1) * sizeof(char)); //alloco la riga della matrice per la lunghezza della parola
			//i - j è la lunghezza della parola, +1 per riservare lo spazio anche per il '\0'
			
			//j scorre le righe della matrice (parte da 0 ogni volta e conta fino alla lunghezza della parola
			//x cresce sempre allo scorrere dei caratteri
			//k cresce dal termine della prima parola, e sottratto a i restituisce lo scarto corrispondente alla parola corrente
			printf("Parola %2d > ", contaPar + 1);
			k  = x;
			j = 0;
			while (j < (i  - k)) { //scorro la riga contaPar della matrice e ci memorizzo la parola
				*(*(parola + contaPar)+ j) = *(frase + x); //inizializzo la riga della matrice con la rispettiva parola
				printf("%c", *(*(parola + contaPar)+ j)); //stampo il contenuto della cella in questione
				j++;
				x++;
			}
			*(*(parola + contaPar)+ j) = '\0'; //inserisco il carattere terminatore al termine della parola, e della riga della matrice
			contaPar++; //incremento il numero di parole
			j++;
			x++; //salto la lettura dello spazio nella frase
			i++;
			if (*(frase + i) == '\0') break; //se si è arrivati alla fine del vettore frase interrompo il ciclo
			printf("\n"); //vado a capo
		}
	}
	

	printf("\n\nLa frase letta al contrario diventa:\n\"");
	for (i = contaPar - 1; i >= 0; i--) {
		printf("%s ", *(parola + i)); //stampo al contrario la matrice risalendo le righe dall'ultima alla prima
	}
	printf("\"");
	
	
	printf("\n\nLibero la memoria allocata dinamicamente... ");
	
	for (i = 0; i < contaPar; i++) { //libero lo spazio in memoria allocato dinamicamente
		free (*(parola + i));
	}
	free(parola);
	free(frase);
	
	printf("Memoria deallocata con successo.\n");
	
	printf ("\n\n");
	return 0;
}