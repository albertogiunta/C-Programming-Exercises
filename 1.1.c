//  Esercizio1.c
//
//  Creato da Alberto Giunta il 26/09/13.
//  Matricola : 0000601428

/* Creo un programma in linguaggio C che stampi a 
 video i nomi dei 10 cantanti preferiti utilizzando 
 prima la funzione printf e poi la funzione puts */

/* con la direttiva al preprocessore #include includo 
la libreira <stdio.h> permette di operare tramite 
predeterminate funzioni con i dati in input/output
(ad es printf) */
#include <stdio.h>

//richiamo la funzione main che è al principio di ogni programma in C
int main ()
{
    //stampo la lista tramite l'utilizzo della funzione printf
    //printf NON VA a capo in automatico e per farlo utilizzo la sequenza di escape \n
    
    printf("STAMPA CON UTILIZZO DELLA FUNZIONE PRINTF\n\n");
    printf("1.  Arctic Monkeys\n");
    printf("2.  The Strokes\n");
    printf("3.  Pearl Jam\n");
    printf("4.  Raphael Gualazzi\n");
    printf("5.  Norah Jones\n");
    printf("6.  Ray Charles\n");
    printf("7.  Elvis Presley\n");
    printf("8.  Chuck Berry\n");
    printf("9.  Chet Atkins\n");
    printf("10. Oasis\n\n");
    
    //ora stampo la lista tramite l'utilizzo della funzione puts
    //puts VA a capo in automatico quindi a meno che non voglio un ulteriore a capo non
    //necessito di \n a fine stringa
    
    puts("STAMPA A VIDEO CON UTILIZZO DELLA FUNZIONE PUTS\n");
    puts("1.  Arctic Monkeys");
    puts("2.  The Strokes");
    puts("3.  Pearl Jam");
    puts("4.  Raphael Gualazzi");
    puts("5.  Norah Jones");
    puts("6.  Ray Charles");
    puts("7.  Elvis Presley");
    puts("8.  Chuck Berry");
    puts("9.  Chet Atkins");
    puts("10. Oasis");
    
    //termino il programma uscendo dalla funzione
    return 0;
}