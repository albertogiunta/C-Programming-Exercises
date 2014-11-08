//
//  Esercizio3.c
//
//  Creato da Alberto Giunta il 02/10/13.
//  Matricola: 0000691428


/*Scrivere un programma C che, dato un numero reale D immesso da tastiera, 
 calcoli e stampi: a. l’area del quadrato di lato D b. l’area del cerchio di 
 diametro D c. l’area del triangolo equilatero di lato D*/

#include <stdio.h>
#include <math.h> //includo la libreria che contiene le funzioni matematiche (servirà per il pigreco)

int main ()
{
    
    
    float D;
    printf("Inserire un numero: ");
    scanf("%f", &D);
    printf("\n");
    //dichiaro e prendo in input la lunghezza del lato

    //QUADRATO
    float areaQ = D * D; //AREA
    printf("L'area del quadrato di lato %.2f è %.2f\n", D, areaQ);
    float perimQ = D * 4; //PERIMETRO
    printf("Il perimetro del quadrato di lato %.2f è %.2f\n", D, perimQ);
    float diagQ = D * sqrt(2); //DIAGONALE
    printf("La diagonale del quadrato di lato %.2f è %.2f\n\n", D, diagQ);
    
    //CERCHIO
    float areaC = (D/2) * (D/2) * M_PI; //AREA
    //M_PI è la funzione pigreco contenuta nella libreria <math.h>
    printf("L'area del cerchio di raggio %.2f è %.2f\n", D/2, areaC);
    float circC = 2 * (D/2) * M_PI; //CIRCONFERENZA
    printf("La lunghezza della circonferenza di raggio %.2f è %.2f\n\n", D/2, circC);
    
    //TRIANGOLO EQUILATERO
    float areaTE = (D*D)*(sqrt(3)/4);//AREA
    printf("L'area del triangolo equilatero di lato %.2f è %.2f\n\n",D,areaTE);
    
    
    //TRIANGOLO QUALSIASI
    char decision;
    printf("Si vuole trovare l'area di un triangolo qualsiasi? (s/n): ");
    scanf("%s", &decision);
    if (decision == 's'){
        float base, alt, areaT;
        printf("Inserire la lunghezza della base del triangolo: ");
        scanf("%f", &base);
        printf("Inserire la lunghezza dell'altezza del triangolo: ");
        scanf("%f", &alt);
        areaT = base * alt / 2; //calcolo area
        printf("L'area del triangolo è di %.2f\n\n", areaT);
    }else if (decision == 'n') {
        printf("Come non detto\n\n");
    }
    else {
        printf("Hai inserito un carattere errato, pazienza, passiamo oltre!\n\n");
    }
    
    //TEOREMA PITAGORA + PERIMETRO
    char scelta1, scelta2;
    float cateto1,cateto2, ipotenusa;
    printf("Vuoi usare il teorema di pitagora con un triangolo rettangolo? (s/n): ");
    scanf("%s", &scelta1);
    if (scelta1 == 's'){
        printf("Vuoi trovare la lunghezza dell'ipotenusa o di un cateto? (i/c): ");
        scanf("%s", &scelta2);
        if (scelta2 == 'c') { //calcolo di un cateto
            printf("Inserisci la lunghezza del cateto 1: ");
            scanf("%f", &cateto1);
            printf("Inserisci la lunghezza dell'ipotenusa: ");
            scanf("%f", &ipotenusa);
            cateto2 = sqrt((ipotenusa*ipotenusa)-(cateto1*cateto1));
            printf("La lunghezza del cateto 2 è di %.2f e il perimetro del triangolo è di %.2f", cateto2, cateto2+cateto1+ipotenusa);
        }else if (scelta2 == 'i') { //calcolo dell'ipotenusa
            printf("Inserisci la lunghezza del cateto 1: ");
            scanf("%f", &cateto1);
            printf("Inserisci la lunghezza del cateto 2: ");
            scanf("%f", &cateto2);
            ipotenusa = sqrt((cateto1*cateto1)+(cateto2*cateto2));
            printf("La lunghezza dell'ipotenusa è di %.2f e il perimetro del triangolo è di %.2f", ipotenusa, cateto2+cateto1+ipotenusa);
        }else{
            printf("Hai inserito un carattere errato, pazienza, passiamo oltre!\n\n");
        }
    }else if (scelta1 =='n') {
        printf("Come non detto\n\n");
    }else{
        printf("Hai inserito un carattere errato, riprova, avrai più fortuna!\n\n");
    }
    

    printf("\n\n");
    return 0;
}