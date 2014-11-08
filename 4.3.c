//
//  Esercizio3.c
//
//  Creato da Alberto Giunta il 17/10/13.
//  Matricola 0000691428

/*Scrivere un programma C che, preso in input un numero 
 inserito da tastiera, stampi le migliaia, le centinaia, 
 le decine e le unità dalle quali il numero è composto. 
 Se si decide di effettuare limitazioni al valore di ingresso, 
 assicurarsi che le stesse siano gestite a livello di programma. 
 Corredare il programma degli opportuni commenti.*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int n,i,j=1000, lettera;
    float parz;
   
	printf("SCOMPOSIZIONE DI UN NUMERO NEI FATTORI CHE LO COMPONGONO\n");

	do {
        
		fpurge(stdin); //pulisco il buffer (mac)
        fflush(stdin); //pulisco il buffer (windows)

		printf("Inserire un numero naturale: ");

		if (scanf("%d", &n)==1) { //se lo scanf restituisce un valore "vero" è stato inserito un numero
			
			lettera = 0; //variabile di controllo inizialiazzata a "falso"
			
            //ALGORITMO FUNZIONANTE MA NON EFFICIENTE
            
            /*float migliaia = n/1000;
             printf("(%.0f * 1000) + ",migliaia);
    
             n%=1000;
    
             float centinaia = n/100;
             printf("(%.0f * 100) + ",centinaia);
			 
			 n%=100;
			 
			 float decine = n/10;
			 printf("(%.0f * 10) + ", decine);
    
			 n%=10;
    
			 float unità = n;
			 printf("(%.0f)", unità);*/
    
			//utilizzo meno righe di codice per fare lo stesso lavoro dell'algoritmo sopra scritto
			for (i=1; i<=4; i++) {
				parz = n/j; //numero da stampare
				printf("(%.0f * %d)",parz,j); //printf("(%.0f * %d) + ",parz, j);
				if (i!=4) {             // se \b funzionasse non ce ne sarebbe bisogno
					printf(" + ");      // e si potrebbe fare come scritto sopra
				}                       //
				n%=j; //elimino il fattore maggiore e prendo solo il resto della divisione
				j/=10; //diminuisco il divisore
			}
			//printf("\b\b");
			/*grazie a qesta sequenza di escape non ci sarebbe bisogno del ciclo if dentro il for
			 e si potrebbe aggiungere il + direttamente nel printf del for,
			 ma su mac \b non è riconosciuto rendendo il programma non completamente portabile*/
			
		} else { //se è stata inserita una lettera
			printf("Non hai inserito un numero, riprova.\n\n");
			lettera = 1; //variabile di controllo inizialiazzata a "vero"
		}
	} while (lettera==1);
	
    printf("\n\n");
    return 0;
}