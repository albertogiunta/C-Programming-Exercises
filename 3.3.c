//
//  Esercizio3.c
//
//  Creato da Alberto Giunta il 07/10/13.
//  Matricola: 0000691428

/*Scrivere un programma C che, preso in input un valore 
 numero_studenti permetta l’inserimento da tastiera del voto 
 di ciascuno degli studenti e ne calcoli la media utilizzando 
 sia il costrutto for che il costrutto while (all’interno dello 
 stesso main ripetere il calcolo con i due costrutti)*/


#include <stdio.h>

int main () 
{
    int numStud,i;
    float vIta,sumIta=0, vIng, sumIng=0,mediaIta, mediaIng;
    do {
    printf("Inserire il corretto numero degli studenti: "); //prendo in input il numero di studenti
    scanf("%d", &numStud);
    printf("\n");
    } while (numStud<1); //controllo che il numero degli studenti sia positivo
    
    //CICLO FOR
    printf("Svolgimento esercizio con il costrutto FOR\n");
    for (i=1;i<=numStud;i++) {
        printf("Studente n°%d\n",i);//Intestazione col numero dello studente
        
        do {
            printf("Inserire il voto in Italiano: ");
            scanf("%f", &vIta);
        } while (vIta<18 || vIta>30);
        sumIta += vIta; //incremento la somma parziale
        
        do {
            printf("Inserire il voto in Inglese: ");
            scanf("%f", &vIng);
        } while (vIng<18 || vIng>30);
        sumIng += vIng;
        printf("\n");
    }
    
    mediaIta = sumIta/numStud; //trovo la media nella materia
    mediaIng = sumIng/numStud;
    
    printf("La media dei voti in italiano della classe (di %d studenti) è di %.2f\n", numStud, mediaIta);
    printf("La media dei voti in inglese della classe (di %d studenti) è di %.2f\n", numStud, mediaIng);
    
    
    
    i = 1, vIta=0, vIng=0, sumIta=0, sumIng=0, mediaIta=0, mediaIng=0; //resetto le variabili
    
    //CICLO WHILE
    printf("\n\nSvolgimento esercizio con il costrutto WHILE\n");
    while (i<=numStud) {
        printf("Studente n°%d\n",i);//Intestazione col numero dello studente
        do {
            printf("Inserire il voto in Italiano: ");
            scanf("%f", &vIta);
        } while (vIta<18 || vIta>30);
        sumIta += vIta; //incremento la somma parziale
        do {
            printf("Inserire il voto in Inglese: ");
            scanf("%f", &vIng);
        } while (vIng<18 || vIng>30);
        sumIng += vIng;
        printf("\n");
        i++; //postincremento i
    }
    
    mediaIta = sumIta/numStud; //trovo la media nella materia
    mediaIng = sumIng/numStud;
    
    printf("La media dei voti in italiano della classe (di %d studenti) è di %.2f\n", numStud, mediaIta);
    printf("La media dei voti in inglese della classe (di %d studenti) è di %.2f\n", numStud, mediaIng);

    printf("\n\n");
    return 0;
    
}