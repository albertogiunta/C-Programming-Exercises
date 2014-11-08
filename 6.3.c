//
//  Esercizio4.c
//
//  Creato da Alberto Giunta il 28/10/13
//  Matricola: 0000691428

/*Scrivere un programma C che permetta di lavorare con un certo numero di variabili di tipo scelto dal programmatore e altrettante di tipo puntatore. Le seconde dovranno puntare alle prime. Gestire l’inizializzazione delle prime e tramite le seconde stamparne il valore*/

#include <stdio.h>

int main ()
{
    //Dichiaro vari tipi di variabili
    int integer;
    char character;
    float floating;
    double doublePrecision;
    
    //Dichiaro variabili di tipo puntatore a cui assegno i rispettivi tipi di variabili prima dichiarati
    int *ptrIngeger = &integer;
    char *ptrCharacter = &character;
    float *ptrFloating = &floating;
    double *ptrDoublePrecision = &doublePrecision;
    
    //Aseegno un valore alle variabili tramite i rispettivi puntatori
    *ptrIngeger = 3;
    *ptrCharacter = 'h';
    *ptrFloating = 3.123456;
    *ptrDoublePrecision = 3.123456;
    
    //Stampo i valori delle variabili tramite i rispettivi puntatori
    printf("integer: %d\ncharacter: %c\nfloating point: %f\ndouble precision: %lf", *ptrIngeger,*ptrCharacter, *ptrFloating, *ptrDoublePrecision);
    
    
    printf("\n\n");
    return 0;
}
