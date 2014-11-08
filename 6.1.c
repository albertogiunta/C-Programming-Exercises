//
//  Esercizio2.c
//
//  Creato da Alberto Giunta il 28/10/13
//  Matricola: 0000691428

/*Si scriva un programma C, adeguatamente commentato, che acquisisca da tastiera un testo libero, composto da più righe (max 1000) di un numero di caratteri non superiore a 100 ciascuna.
 L’inserimento termina quando l’utente inserirà la riga “FINE”. Al termine dell’acquisizione del testo, il programma dovrà stampare le seguenti statistiche:
 • il numero totale di righe inserite (ad eccezione di quella “FINE”); 
 • il numero totale di caratteri inseriti; 
 • il numero totale di caratteri alfanumerici inseriti; 
 • il numero totale di parole inserite.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/types.h>
#include <ctype.h>

//DEFINISCO LE DIMENSIONI DELLA MATRICE

#define ROW 1000
#define LENGTH 100

//INCLUDO LA FUNZIONE GETCH

int getch(void);

int getch(void) {
    char ch;
    int error;
    static struct termios Otty, Ntty;
    
    fflush(stdout);
    tcgetattr(0, &Otty);
    Ntty = Otty;
    
    Ntty.c_iflag  =  0;           /* input mode           */
    Ntty.c_oflag  =  0;           /* output mode          */
    Ntty.c_lflag &= ~ICANON;  /* line settings        */
    
    /* disable echoing the char as it is typed */
    Ntty.c_lflag &= ~ECHO;    /* disable echo         */
    
    Ntty.c_cc[VMIN]  = CMIN;      /* minimum time to wait */
    Ntty.c_cc[VTIME] = CTIME;     /* minimum chars to wait for */
    
    if (0 == (error = tcsetattr(0, 1, &Ntty))) {
        error  = (int)read(0, &ch, 1 );                /* get char from stdin */
        error += tcsetattr(0, 1, &Otty);   /* restore old settings */
    }
    
    return (error == 1 ? (int) ch : -1 );
    
}



int main () {
	
	char car; //variabile input
	int j, i, numCar = 1, carAlpha = 1, numPar = 0, k;
	char frase[ROW][LENGTH] = {0, 0}; //dichiaro la matrice
	
	printf("Inserire del testo. Per terminare -> \"fine\"\n\n");
	for (i = 0; i < ROW; i++) { //scorro le righe
		
		j = 0; //Indice del vettore stringa
		
		while ((car = getch()) != 13 && j + 1 < LENGTH ) { //numero di caratteri alfanumerici
			if (car != 13) {
				numCar++; //vale per qualsiasi carattere digitato
			} else {
				break;
			}
			
			frase[i][j] = car; //salvo l'input nella matrice
			
			j++;
			
			if (isalpha(car) != 0 || (car >= 48 && car <= 57)) { //se è una lettera o un numero
				carAlpha++;
			}
				
		}
		
		frase[i][j] = '\0'; //inserisco carattere terminatore
		
		for (k = 1; k <= j + 1; k++) {
			if (frase[i][k] == 32 ||  frase[i][k] == '\0') {
				numPar++; //incremento conteggio parole se si incontra spazio, invio, o carattere terminatore
			}
		}

		if (strcmp(frase[i], "fine") == 0) break;
		
		printf("\n");
		
	}
	
	printf("\nNumero di righe inserite: %d", i);
	printf("\nNumero di tasti digitati: %d", numCar - 4);
	printf("\nNumero di caratteri alfanumerici: %d", carAlpha - 4);
	printf("\nNumero di parole inserite: %d", numPar - i -1);
	
	
	printf("\n\n");
	return 0;
}