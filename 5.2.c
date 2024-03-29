//
//  Esercizio2.c
//
//  Creato da Alberto Giunta il 24/10/13
//  Matricola: 0000691428

/*Due colleghi intendono fissare una riunione,  pertanto devono identificare i giorni nei quali sono entrambi liberi da impegni.
 A tale scopo, si realizzi un programma C che permetta a ciascuno di immettere le proprie disponibilità, 
 e che identifichi i giorni nei quali entrambi sono liberi. 
 In particolare, in una prima fase il programma deve acquisire un elenco di numeri interi che indicano i giorni del mese in cui essi sono disponibili 
 e nella seconda fase il programma deve identificare e stampare i giorni in cui entrambi i colleghi sono disponibili.*/

#include <stdio.h>
#include <ctype.h>
int main ()
{
	int user1[31] = {0}, user2[31] = {0}, monthLen, month, monthCorrect, dayCorrect=0, i, j = 0;
	char bisest;
	int day = 0;
	
	do {
		fpurge(stdin); //pulisco il buffer
		printf("Inserire il numero del mese desiderato: ");
		if (scanf("%d", &month) == 0 || month < 1 || month >12) { //controllo correttezza mese
			printf("Non hai inserito un numero di mese corretto. Riprova\n");
			monthCorrect = 0;
		} else {
			monthCorrect = 1;
		}
	} while (monthCorrect == 0);
	
	 switch (month) { //controllo lunghezza mese
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			 monthLen = 31;
			 break;
		case 4:
		case 6:
		case 9:
		case 11:
			 monthLen = 30;
			 break;
		 case 2:
			 printf("L'anno è bisestile? s/n __ ");
			 scanf("%s", &bisest);
			 if (bisest == 's')	{
				 monthLen = 29;
			 } else {
				 monthLen = 28;
			 }
			 break;
	 }
	
	const int constMonthLen = monthLen; //rendo costante la lunghezza del mese
	
	for (i = 1; i <= 2; i++) { //per ogni utente faccio inserire i giorni di disponibilità
		printf("\nUtente %d: inserire i giorni di disponibilità, compresi tra 1 e %d. 0 per terminare.\n",i, monthLen);
		
		do {
			do {
				fpurge(stdin);
				printf("-> ");
				
				if ((scanf("%d", &day) == 1) && day >= 0 && day <= constMonthLen) {
					if (i == 1) {
						user1[day - 1] = 1;
					} else if (i == 2) {
						user2[day - 1] = 1;
					}
					dayCorrect = 1;
				} else {
					printf("Non è estato inserito un numero corretto, riprova.\n");
					dayCorrect = 0;
				}
			} while (dayCorrect == 0);
		} while (day != 0);
		
	}
			
//		/* STAMPA  DEL VETTORE */
//		int x;
//		if (i == 1) {
//			for (x = 0; x < constMonthLen; x++) {
//				printf("%d", user1[x]);
//			}
//		}
//		if (i == 2) {
//			for (x = 0; x < constMonthLen; x++) {
//				printf("%d", user2[x]);
//			}
//		}
//		printf("\n\n");
//	}
	
	printf("\nI giorni liberi in comune del %d° mese dell'anno sono i seguenti: ", month);
	for (i = 1; i <= constMonthLen; i++) {
		if (user1[i] == user2[i] && user1[i] == 1) {
			printf("%d ", i+1);
			j++;
		}
	}
	if (j == 0) { //se non ci sono giorni in comune
		printf("/// \n\n\t\t\t\t\t\t*ATTENZIONE*\nPurtroppo non potrete proprio incontrarvi, non ci sono giorni liberi in comune.");
	}
	puts("\n\n");
	return 0;
}