//
//  Esercizio2.c
//
//  Creato da Alberto Giunta il 07/10/13.
//  Matricola: 0000691428

/*Scrivere un programma C che, preso in ingresso un valore n,
 calcoli il valore di fattoriale(n) utilizzando sia il costrutto 
 for che il costrutto while (all’interno dello stesso main ripetere 
 il calcolo con i due costrutti)*/


#include <stdio.h>

int main ()
{
    double n,fatt1,fatt2,i; // double permette di calcolare il fatt. dei numeri fino a 170 compreso
    printf("Scrivere un numero intero maggiore o uguale a 0: ");
    scanf("%lf", &n);
  
    if (n>0 && n <= 170) { //170 è il numero massimo di cui si può calcolare il fattoriale con double
        
        fatt1 = n;
        //FATTORIALE CON CICLO FOR
        for (i=1;i<n;i++) {
            fatt1 *=(n-i);
        }
        printf("\n(FOR)\nIl fattoriale di %.0lf è %.0lf\n\n",n, fatt1);
        
        
        fatt2 = n; //inizializzo una nuova variabile fattoriale
        i = 1; //reinizializzo i
        //FATTORIALE CON CICLO WHILE
        while (i<n ) {
            fatt2 *=(n-i);
            i++; //postincremento i
        }
        printf("(WHILE)\nIl fattoriale di %.0lf è %.0lf\n\n",n, fatt2);
    } else if (n<0){ //se n è minore di 0
        printf("Il fattoriale di un numero negativo è indefinito! Non lo sapevi?\n\n");
    } else if (n==0) { //se n è = a 0
        printf("Il fattoriale di 0 è 1\n\n");
    } else if (n>170) { //per evitare l'overflow
        printf("Hai inserito un numero troppo grande\n\n");
    }
    
    return 0;
}