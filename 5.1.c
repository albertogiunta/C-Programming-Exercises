//
//  Esercizio1.c
//
//  Creato da Alberto Giunta il 24/10/13
//  Matricola: 0000691428

/*Scrivere un programma C che realizzi il gioco della vita, l’automa cellulare di Conway.
 Gestire quindi la mappa di dimensione NxM tramite una matrice i cui valori rappresentino  la presenza o meno di un organismo nel mondo.
 Partendo da una configurazione iniziale degli organismi a vostra scelta, far evolvere la popolazione nel tempo secondo le tre seguenti regole genetiche:
 – un organismo sopravvive fino alla generazione successiva se ha 2 o 3 vicini;
 – un organismo muore, lasciando la cella vuota, se ha più di 3 o meno di 2 vicini;
 – ogni cella vuota con 3 vicini diventa una cella di nascita e alla generazione successiva viene occupata da un organismo.
 Si visualizzi l’evoluzione della popolazione  nel tempo.*/


#include <stdio.h>
#include <ncurses.h>
#include <time.h>
#include <stdlib.h>

#define R 20 //righe
#define C 30 //colonne

int main ()
{
    int i = 0, j =0, k = 0, x = 0;
	char mondo[R][C]; //prima matrice
	char mondo2[R][C]; //matrice di appoggio
	char enter; //variabile per passare a una generazione
	const char alive = 'O'; //modalità vivo
	const char dead = '.'; //modalità morto
	int neighbour = 0, gen = 0, cont = 0, contaGen = 0;
	
	//inizializzo tutta la matrice a dead
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			mondo[i][j] = dead;
		}
	}
	
	/* ESEMPI DI CREATURE PRIMITIVE */
	
	//mondo[5][5] = alive; mondo[4][5] = alive; mondo[4][6] = alive;
	
	/*QUADRATO*/
	//mondo[5][5] = alive; mondo[4][5] = alive; mondo[4][6] = alive; mondo[5][6] = alive;
	
	/*GLINDER*/
	//mondo[5][5] = alive; mondo[5][6] = alive; mondo[5][7] = alive;
	
//	/*ALIANTE 1*/
//	mondo[5][5] = alive; mondo[5][4] = alive; mondo[5][3] = alive;
//	mondo[4][3] = alive;
//	mondo[3][4] = alive;
//	
//	/*ALIANTE 2*/
//	mondo[15][10] = alive; mondo[15][11] = alive; mondo[15][12] = alive;
//	mondo[16][10] = alive;
//	mondo[17][11] = alive;
//
//	/*ALIANTE 3*/
//	mondo[15][5] = alive; mondo[16][5] = alive; mondo[17][5] = alive;
//	mondo[15][6] = alive;
//	mondo[16][7] = alive;

	
	
	/*CONFIGURAZIONE CASUALE*/
	
	srand((unsigned)time(NULL));
	
	for (i = 0;
		 i < R; i++) {
		for (j = 0; j < C; j++) {
			x = rand()%2; //seleziono i valori (0, 1)
			switch(x) {
				case 0:
					mondo[i][j] = dead;
					break;
				case 1:
					mondo[i][j] = alive;
					break;
			}
		}
	}

	
	
	//STAMPO MONDO 1 SOLA VOLTA
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			printf("%2c", mondo[i][j]);
		}
		printf("\n");
	}

	do {
		
		/*SVILUPPO DI UNA GENERAZIONE*/
		
		scanf("%c", &enter); //avvio la procedura
		
		//system("clear"); //non funziona su mac
		
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) { //scorro ogni cella
				gen++; //incremento generazione
				enter = ' ';
				neighbour = 0; //inizializzo il num di vicini
				
				
				/*RIGA SOTTO*/
				for (x = i + 1 , k = j - 1; k <= j + 1; k++) {
					if (mondo[x][k] == alive) {
						neighbour++;
					}
				}
				/*RIGA SOPRA*/
				for (x = i-1, k = j - 1; k <= j + 1; k++) {
					if (mondo[x][k] == alive) {
						neighbour++;
					}
				}
				/*CELLE A DX E SX*/
				for (x = i, k = j - 1; k <= j + 1; k += 2) {
					if (mondo[x][k] == alive) {
						neighbour++;
					}
				}
				
				/*CONTROLLO VICINI*/
				if (mondo[i][j] == alive) {
					switch (neighbour) {
						case 2:
						case 3:
							mondo2[x][j] = alive;
							break;
						default:
							mondo2[x][j] = dead;
							break;
					}
				} else if (mondo[i][j] == dead) {
					switch (neighbour) {
						case 3:
							mondo2[i][j] = alive;
							break;
						default:
							mondo2[i][j] = dead;
							break;
					}
				}
			}
		}
		
		
		/*CONTROLLO UGUALGLIANZA*/
		cont = 0;
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				if (mondo[i][j] == mondo2[i][j]) { //mondo è la generazione n, mondo2 è la generazione n+1. se sono uguali non c'è stato cambiamento e non ce ne sarà più.
					cont++; //conteggi delle celle uguali nelle due generazioni
				}
			}
		}
		
		
		if (cont == R * C) { //se il numero di celle uguali è = al numero di celle totale
			gen = -1; //esco dal ciclo
		} else { // se non sono uguali faccio un'altra generazione
			gen = 0;
			for (i = 0; i < R; i++) {
				for (j = 0; j < C; j++) {
					mondo[i][j] = mondo2[i][j]; //scambio le matrici e rendo mondo2 la generazione attuale
					printf("%2c", mondo2[i][j]); //stampo mondo2
					mondo2[i][j] = '.'; //azzero mondo2
				}
				printf("\n"); //creo nuova riga
			}
		}
		contaGen++; //conteggio generazioni
	} while (gen != -1);
	printf("\n\nCi sono state %d generazioni.",contaGen); //stampo num generazioni (
	printf("\n\n");
	return 0;
}