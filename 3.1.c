//
//  Esercizio1.c
//
//  Creato da Alberto Giunta il 07/10/13.
//  Matricola: 0000691428

/*scrivere un programma C che, preso in input un valore riga e
 un valore colonna stampi a video la tavola pitagorica della 
 moltiplicazione e quella dell’addizione, utilizzando una volta
 il costrutto for e una volta il costrutto while*/


#include <stdio.h>

int main ()
{
    int riga=0, colonna=0,i,j;
    do {
        printf("Inserire un numero maggiore o uguale a 1\n");
        printf("Inserire numero di colonne: ");
        scanf("%d", &riga);
        printf("Inserire numero di righe: ");
        scanf("%d", &colonna);
        printf("\n\n");
    } while (riga<1 || colonna<1);

    
    //MOLT. FOR
        printf("TAVOLA PITAGORICA DELLA MOLTIPLICAZIONE CON CICLO FOR\n");
    
        for (i=1; i<=colonna; i++) {
            for (j=1; j<=riga; j++) { //annidamento del ciclo for
                printf("%d\t",i*j); //stampo il prodotto dell'attuale valore di i per j
            }
            printf("\n"); //chiudo la riga e vado a capo
        }
    
        printf("\n\n");
    
    
        //MOLT. WHILE
        printf("TAVOLA PITAGORICA DELLA MOLTIPLICAZIONE CON CICLO WHILE\n");
        i = 1; //inizializzo il contatore
        while (i<=colonna) {
            j = 1; //inizializzo il secondo contatore
            while (j<=riga) { //annidamento del ciclo while
                printf("%d\t",i*j); //stampo il prodotto dell'attuale valore di i per j
                j++; //postincremento j
            }
            i++; //postincremento i
            printf("\n"); //chiudo la riga e vado a capo
        }
        printf("\n\n");
    
    
        //ADD. FOR

        printf("TAVOLA PITAGORICA DELL'ADDIZIONE CON CICLO FOR\n");
        for (i=0; i<colonna; i++) {
            for (j=0; j<riga; j++) { //annidamento del ciclo for
                printf("%d\t",i+j); //stampo la somma dell'attuale valore di i per j
            }
            printf("\n"); //chiudo la riga e vado a capo
        }
        printf("\n\n");
    
    
        //ADD. WHILE
        printf("TAVOLA PITAGORICA DELL'ADDIZIONE CON CICLO WHILE\n");
        i = 0;
        while (i<colonna) {
            j = 0;
            while (j<riga) { //annidamento del ciclo while
                printf("%d\t",i+j); //stampo la somma dell'attuale valore di i per j
                j++;
            }
            i++;
            printf("\n"); //chiudo la riga e vado a capo
        }
    printf("\n\n");

    return 0;
}
