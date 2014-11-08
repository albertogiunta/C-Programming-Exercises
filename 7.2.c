//
//  Esercizio2.c
//
//  Creato da Alberto Giunta il 05/11/13.
//  Matricola: 0000691428



/*Scrivere un programma C che presenti i seguenti requisiti: 
 •dichiari un array contenente i voti di 200 studenti 
 •dichiari un puntatore ptr che punti al primo elemento del vettore
 •inizializzi il vettore con almeno due modalità differenti
 •stampi i voti usando tutte le possibili modalità di accesso al vettore*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define STUD 200 //grandezza massima del vettore (costante)


int main () {
    
    int voti[STUD]; //vettore per n studenti
    int *ptrVoti = voti; //ptrVoti punta voti[0]
	int i, scelta, riprova;
		
	do {
		riprova = 0;
		fpurge(stdin);
		
		/*MENU*/
		printf("Scegliere come inserire i dati:\n");
		printf("1 -> ORDINE CASUALE\n");
		printf("2 -> MANUALMENTE\n");
		scanf("%d", &scelta);
		
		switch (scelta) {
			case 1:
				/*INIZIALIZZAZIONE CASUALE*/
				
				srand((unsigned)time(NULL));
				
				/*Inizializzo usando nome del vettore e indice*/
				for (i = 0; i < STUD; i++) {
					voti[i] = rand()%10+1;
				}
				
				/*Inizializzo usando nome del vettore e offset*/
				for (i =0; i < STUD; i++) {
					*(voti + i) = rand()%10+1;
				}
				
				/*Inizializzo usando puntatore e indice*/
				ptrVoti = voti; //reinizializzo ptrVoti
				for (i = 0; i < STUD; i++) {
					ptrVoti[i] = rand()%10+1;
				}
				
				/*Inzializzo usando puntatore e offset*/
				ptrVoti = voti; //reinizializzo ptrVoti
				for (i = 0; i < STUD; i++) {
					*(ptrVoti + i) = rand()%10+1;
				}
				
				break;
			
			case 2:
				/*INIZIALIZZAZIONE MANUALE*/
				
				/*Inizializzo usando nome del vettore e indice*/
				for (i = 0; i < STUD; i++) {
					voti[i] = 0;
				}
				
				i = 0;
				
				/*Inserimento manuale*/
				for (i = 0; i < STUD; i++) {
					do {
						fpurge(stdin);
						do {
							riprova = 0;
							fpurge(stdin);
							printf("Inserire il voto del %d° studente - 0 per terminare:", i+1);
							
							if (scanf("%d", (voti + i)) != 1) { //se l'input non è un numero
								riprova = 1;
							}
		
						} while (riprova == 1);
						
					} while ((voti[i] < 0 || *(voti + i) > 10));
					
					if (voti[i] == 0) {
						printf("\n\tINSERIMENTO TERMINATO.\n\tSTAMPO IL REPORT DEI VOTI...\n");
						break;
					}
				}
				break;
			
			default:
				printf("Non hai inserito una scelta corretta. Riprova.\n");
				riprova = 1;
				break;
		}
	}while (riprova == 1);

	
	printf("\nSTAMPA USANDO nome del vettore e indice\n");
	for (i = 0; i < STUD; i++) {
		printf("%d ", voti[i]);
	}

	printf("\n\nSTAMPA USANDO vettore e offset\n");
	ptrVoti = voti;
	for (i = 0; i < STUD; i++) {
		printf("%d ", *(voti + i));
	}
	
	printf("\n\nSTAMPA USANDO puntatore e indice\n");
	ptrVoti = voti;
	for (i = 0; i < STUD; i++) {
		printf("%d ", ptrVoti[i]);
	}
	
	printf("\n\nSTAMPA USANDO puntatore e offset\n");
	ptrVoti = voti;
	for (i = 0; i < STUD; i++) {
		printf("%d ", *(ptrVoti + i));
	}

	printf("\n\n");
	return 0;
}