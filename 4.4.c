
//
//  Esercizio5.c
//
//  Creato da Alberto Giunta il 17/10/13.
//  Matricola 0000691428

/*Scrivere un programma C che stampi a video i primi n numeri primi, con n inserito da tastiera. 
 Se si decide di effettuare limitazioni al valore di ingresso n, assicurarsi che le stesse siano 
 gestite a livello di programma. Corredare il programma degli opportuni commenti.*/

#include <stdio.h>

int main ()
{
	int i=0,j,k,x=0,n,m,lettera,menu;
		
	
	
	do {
		fpurge(stdin);
		
		printf("MENU\n");
		printf("1. Inserisci un numero n e ti dico i primi n numeri primi\n");
		printf("2. Inserisci un numero e ti dico i numeri primi minori o uguali ad esso\n");
		scanf("%d",&menu);
		
		if (menu==1) {

			puts("ELENCO DEI PRIMI N NUMERI PRIMI");
			do { //per permettere il reinserimento in caso di m==0
				fpurge(stdin);
				printf("Inserire un numero: ");
				
				if (scanf("%d", &m)==1) { //prendo in input il numero m e controllo che sia un numero
					
					lettera = 0;
					if (m<0) { //prendo il valore assoluto di m
						m*=-1;
						printf("Hai immesso un numero negativo, probabilmente hai commesso un errore e intendevi %d.\n\n", m);
						printf("In ogni caso: ");
					}
					
					if(m>0) {
						//controllo grammaticale
						if (m==1) {
							printf("Il primo numero primo è: ");
						} else {
							printf("I primi %d numeri primi sono: ",m);
						}
						//inizializzo i contatori
						j=2;
						i=0;
						
						while (i<m) { //trovo e stampo i numeri primi
							k=0; //inizializzo il contatore dei divisori
							for (x=1; x<=j; x++) {
								if (j%x==0) {
									k++;
								}
							}
							
							if (k==2) {
								printf("%d ", j); //stampo il numero primo
								i++; //i incrementa a ogni numero primo trovato
							}
							j++; //j incrementa a ogni iterazione
						}
						
					} else if (m==0) { //controllo che m debba essere diverso da 0
						printf("Inserire un numero diverso da 0\n\n");
						lettera = 1;
					}
					
				} else { //se è stata inserita una lettera
					printf("Non hai inserito un numero, riprova.\n\n");
					lettera = 1; //variabile di controllo inizialiazzata a "vero"
				}
				
			} while (lettera == 1 || m==0);
			

		} else if (menu==2) {
	
		
			puts("ELENCO DEI NUMERI PRIMI MINORI O UGUALI A UN NUMERO");
			do { //permetto il reinserimento del numero se uguale a 0
				fpurge(stdin);
				printf("Inserire un numero: ");
				if (scanf("%d", &n)==1) { //prendo in input il numero n
			
					if (n!=0) { //con n diverso da 0
						printf("I numeri primi minori o uguali a %d sono: ",n);
						if (n>0) { //n maggiore di 0
							for (i=1; i<=n; i++) {
								k=0;
								for (j=1; j<=i; j++) {
									if (i%j==0) {
										k++;
									}
								}
								if (k==2) {
									printf("%d ",i);
								}
							}
						} else if (n<0) { //n minore di 0
							n*=-1; //prendo il valore assoluto di n
							for (i=1; i<=n; i++) {
								k=0;
								for (j=1; j<=i; j++) { //inverto il ciclo for rispetto a n>0
									
									if (i%j==0) {
										k++;
									}
								}
								if (k==2) {
									printf("-%d ",i);
								}
							}
						}
					} else {
						printf("Inserire un numero diverso da 0\n\n");
					}
				} else { //se è stata inserita una lettera
					printf("Non hai inserito un numero, riprova.\n\n");
					lettera = 1; //variabile di controllo inizialiazzata a "vero"
				}

			} while (lettera ==1 || n==0);
		
		} else {
			printf("Inserire 1 oppure 2\n\n");
		
		}
	} while (menu !=1 && menu != 2);
	
	printf("\n\n");
	return 0;
}