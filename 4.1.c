//
//  Esercizio2
//
//  Creato da Alberto Giunta il 18/10/13.
//  Matricola: 0000691428

/*Scrivere un programma C che, preso in ingresso un valore intero n, 
 ne effettui la conversione nel corrispondente numero binario e lo 
 memorizzi in un vettore. Se si decide di effettuare limitazioni al 
 valore di ingresso n, assicurarsi che le stesse siano gestite a livello 
 di programma. Corredare il programma degli opportuni commenti.*/


#include <stdio.h>

int main ()
{
    int lettera=0,n,resto,i;
    
    do {
        fpurge(stdin); //pulisco il buffer
        printf("Inserire un numero da convertire: ");
        if (scanf("%d",&n)==0) { //se non è stato inserito un numero
            printf("Non hai inserito un numero. Riprova.\n\n");
            lettera = 1; //variabile di controllo = vero
        } else {
            
            if (n>0) {
                int vBin[8]; //dichiaro il vettore di 8 elementi
                for (i = 7; i>=0; i--) { //assegno i valori dall'ultimo al primo
                    resto = n%2; //prendo la cifra binaria del resto
                    n/=2; //diminuisco n
                    vBin[i] = resto; //assegno la cifra binaria alla locazione i del vettore
                }
                for (i=0; i<=7; i++) {
                    printf("%d", vBin[i]); //leggo il vettore al contrario e stampo il numero
                }
                
            } else if (n<0) {
                n*=-1; //prendo il valore assouluto di n
                int vBin[8];
                for (i = 7; i>=0; i--) {
                    resto = n%2;
                    n/=2;
                    vBin[i] = resto;
                }
                for (i=0; i<=7; i++) {
                    if (i==0) { //uso la codifica modulo e segno per i numeri negativi
                        if (vBin[i]==0) { //inverto il MSB
                            vBin[i]=1;
                        } else {
                            vBin[i]=0;
                        }
                    }
                    printf("%d", vBin[i]);
                }
            } else if (n==0) {
                int vBin[8];
                for (i=0; i<=7; i++) {
                    vBin[i]=0; //0 in binario è composto di soli zeri
                    printf("%d", vBin[i]);
                }
            }
            lettera = 0; //inizializzo variabile di contrllo a farlo (non era necessario, è per correttezza)
        }
    } while (lettera==1);
    
    printf("\n\n");
    return 0;
}