//
//  Esercizio5.c
//
//  Creato da Alberto Giunta il 07/10/13.
//  Matricola: 0000691428

/*Scrivere un programma C che, preso in ingresso un 
 carattere, indichi il suo tipo (lettera maiuscola, 
 lettera minuscola, vocale, consonante, numero, …) , 
 il codice ASCII corrispondente e la trasformi in maiuscola 
 se minuscola o viceversa.*/

#include <stdio.h>

int main ()
{
    printf("Inserire un qualunque carattere da tastiera: ");
    char ch = getchar(); //prendo in input il carattere che viene inserito
    int i=0; //inizializzo un contatore come espediente di discriminazione tra numero, consonante o vocale

    
    if (ch >= 65 && ch <= 90) {
        printf("\n\"%c\" è una lettera maiuscola, e per la precisione è una ",ch);
        i=1; //1 = maiuscola
    } else if (ch >= 97 && ch <= 122) {
        printf("\n\"%c\" è una lettera minuscola, e per la precisione è una ",ch);
        i=2; //2 = minuscola
    } else if (ch >= 48 && ch <= 57) {
        printf("\n\"%c\" è un numero\n\n",ch);
        i=0; //2 = minuscola
    } else {
        printf("\n\"%c\" è un simbolo\n\n",ch); //se non è niente dei precedenti è un simbolo sintattico
    }


    
    if (i==1 || i==2) { //se la variabile contiene una lettera
        switch((int)ch) {
            case 65:
            case 69:
            case 73:
            case 79:
            case 85:
            case 97:
            case 101:
            case 105:
            case 111:
            case 117:
                printf("vocale");
                printf("\n\n");
                break;
            default: //nel caso non sia nessuno dei precedenti
                printf("consonante");
                printf("\n\n");
                break;
        }
    }
    
    if (i==1) {
        printf("La lettera \"%c\" in minuscolo si scrive \"%c\"\n\n", ch, ch+32); //la distanza in ASCII tra maiuscole e minuscole è costante (32)
    } else if (i==2) {
         printf("La lettera \"%c\" in maiuscolo si scrive \"%c\"\n\n", ch, ch-32);
    }

    
    printf("Il codice ASCII corrispondente è: \"%d\"",ch); //ch nonostante di tipo char contiene un carattere ascii che viene poi semplicemente interpretato come lettera
    
    printf("\n\n");
    return 0;
}