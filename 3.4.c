//
//  Esercizio4.c
//
//  Creato da Alberto Giunta il 07/10/13.
//  Matricola: 0000691428

/*Scrivere un programma C che, dato il valore dello stipendio
 lordo, calcoli lo stipendio netto mensile considerando una sola 
 tassazione pari al 20% per stipendi lordi compresi fra 10.001 euro 
 e 30.000 euro, pari al 30% oltre ai 30.000 euro e esentasse per gli 
 stipendi lordi inferiori a 10.000 euro.*/

#include <stdio.h>

int main()
{
    double stipLordo;
    do {
    printf("Inserisci il corretto stipendio lordo annuale: € ");
    scanf("%lf", &stipLordo); //prendo in input lo stipendio lordo
    } while (stipLordo<0);
    
    
        if (stipLordo<=10000){ //fascia <10000
            printf("Sei nella fascia di reddito inferiore o uguale a 10.000 euro e sei esentato dalla tassazione sugli stipendi.\nIl tuo stipendio mensile netto è di €%.2lf\n", stipLordo/12); //non ci sono tasse da scorporare
            
        } else {
            if (stipLordo>=10001 && stipLordo<=30000) //compreso tra 10000 e 30000
                printf("Sei nella fascia di reddito compresa tra 10.001 e 30.000 euro e subisci una tassazione pari al 20%% dello stipendio.\nIl tuo stipendio mensile netto è di €%.2lf\n", (stipLordo*.8)/12); //scorporo la tassa e lo rendo mensile
            
            else
                printf("Sei nella fascia di reddito superiore a 30.000 euro e subisci una tassazione pari al 30%% dello stipendio.\nIl tuo reddito mensile netto è di €%.2lf\n", (stipLordo*.7)/12); //superiore a 30000, scorporo la tassa e lo rendo mensile
        }
    return 0;
}