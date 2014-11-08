//
//  Esercizio3.c
//
//  Creato da Alberto Giunta il 17/10/13.
//  Matricola 0000691428

/*Scrivere un programma C che, preso in input un numero inserito da tastiera, 
 stampi tutti i suoi divisori. Gestire opportunamente l’errore dell’ input. 
 Corredare il programma degli opportuni commenti.*/

#include <stdio.h>

int main ()
{
    int a,i,j=0,lettera;
    printf("CALCOLO DEI DIVISORI DI UN NUMERO\n\n");
    do {
        fpurge(stdin);
        printf("Inserire un numero: ");
        
        if (scanf("%d", &a)==1) { //prendo in input un numero
        lettera = 0;
            if (a !=0) {
                if (a>0){ //a maggiore di 0
                    printf("I divisori di %d sono: ",a);
                    a*=-1;
                    for (i=a; i<0; i++) {
                        if (a%i==0){ //se la divisione non ha resto
                            printf("%d ",i); //stampa il divisore
                            j++; //postincremento j (numero di divisori)
                        }
                    }
                    
                    a*=-1;
                    for (i=1; i<=a; i++) {
                        if (a%i==0){ //se la divisione non ha resto
                            printf("%d ",i); //stampa il divisore
                            j++; //postincremento j (numero di divisori)
                        }
                    }
                }
                if (a<0){ //a minore di 0
                    printf("I divisori di %d sono: ",a);
                    for (i=a; i<0; i++) { //stampo i divisori dal maggiore al minore
                        if (a%i==0){ //se la divisione non ha resto
                            printf("%d ",i); //stampa il divisore
                            j++; //postincremento j (numero di divisori)
                        }
                    }
                    
                    a*=-1;
                    for (i=1; i<=a; i++) { //stampo i divisori dal minore al maggiore
                        if (a%i==0){ //se la divisione non ha resto
                            printf("%d ",i); //stampa il divisore
                            j++; //postincremento j (numero di divisori)
                        }
                    }
                }
                
                printf("\nIl numero di divisori di %d è %d", a, j);
            } else {
                printf("La divisione per 0 è impossibile"); // a == 0
            }
            
            
            
            printf("\n");
            
            //controllo se il numero è pari o dispari e se è primo
            
            if (a<0) {
                
            }
            else if (a%2==0 && a!=2) { //deve essere PARI E DIVERSO DA 2
                printf("%d è pari quindi non può essere primo",a);
            } else if (j==2 || a==1 || j==4) {
                printf("%d è dispari ed è primo", a);
            } else if (a==2) {
                printf("%d è pari ed è primo",a);
            }else if (a==0) {
                printf("%d è pari e non ha divisori",a);
            } else {
                printf("%d è dispari e non è primo",a);
            }
        } else { //se è stata inserita una lettera
            printf("Non hai inserito un numero, riprova.\n\n");
            lettera = 1; //variabile di controllo inizialiazzata a "vero"
        }
        
    } while (lettera ==1);

    
    printf("\n\n");
    return 0;
}