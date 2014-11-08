//
//  Esercizio1.c
//
//  Creato da Alberto Giunta il 02/10/13.
//  Matricola: 000691428

/*Scrivere un programma C che dichiari una variabile per ogni tipo studiato, ne stampi il valore
 l’occupazione di memoria usando gli argomenti della funzione printf() studiati e le diverse varianti
 (modificatore, campoMinimo, precisione, modificatoreLunghezza) e aggiungendo la stampa del numero di
 caratteri stampati per ogni istruzione printf().*/


#include <stdio.h>

int main ()
{

	printf("STAMPO I TIPI DI DATI CONOSCIUTI\n\n");
	//CHARACTER
	char A = 'a'; //dichiaro la variabile e le assegno un valore
	int lengthA = printf("CHARACTER\n\
	   Valore: %c \n\
	   Byte occupati: %lu\n\
	   N° caratteri stampati: ", A, (sizeof(char)));
	//stampo il valore della variabilecon il comando di conversione adatto al tipo di dato
	//stampo la quantità di memoria occupata tramite uso della funzione (sizeof(tipoDato))
	printf("%d\n\n", lengthA+2);
	//stampo il numero di caratteri aggiungendo i caratteri della stampa della variabile length (lo spazio più le due cifre)
	//NB dà un risultato corretto soltanto per stringhe < 100 caratteri
	
	//ripeto la procedura per tutti i tipi di caratteri
	
	unsigned char B = 'b';
	int lengthB = printf("UNSIGNED CHARACTER\n\
	   Valore: %c\n\
	   Byte occupati: %lu\n\
	   N° caratteri stampati: ", B, (sizeof(unsigned char)));
	   printf("%d\n\n", lengthB+2);


	//INTEGER
	short int C = 1;
	int lengthC = printf("INTEGER\n\
	    Valore: %d \n\
		Byte occupati: %lu\n\
		N° caratteri stampati: ", C, (sizeof(int)));
		printf("%d\n\n", lengthC+2);
	
	unsigned short int D = 2;
	int lengthD = printf("UNSIGNED SHORT INTEGER\n\
	   Valore: %d \n\
	   Byte occupati: %lu\n\
	   N° caratteri stampati: ", D, (sizeof(unsigned short int)));
	   printf("%d\n\n", lengthD+2);
	
	int E = -3;
	int lengthE = printf("INTEGER\n\
	   Valore: %d \n\
	   Byte occupati: %lu\n\
	   N° caratteri stampati: ", E, (sizeof(int)));
	   printf("%d\n\n", lengthE+2);
	
	unsigned int F = 4;
	int lengthF = printf("UNSIGNED INTEGER\n\
		Valore: %d \n\
		Byte occupati: %lu\n\
		N° caratteri stampati: ", F, (sizeof(unsigned int)));
		printf("%d\n\n", lengthF+2);

	long int G = 5;
	int lengthG = printf("LONG INTEGER\n\
	   Valore: %ld \n\
	   Byte occupati: %ld\n\
	   N° caratteri stampati: ", G, (sizeof(long int)));
	   printf("%d\n\n", lengthG+2);
	
	unsigned long int H = 6;
	int lengthH = printf("UNSIGNED LONG INTEGER\n\
	   Valore: %lu \n\
	   Byte occupati: %lu\n\
	   N° caratteri stampati: ", H, (sizeof(unsigned long int)));
	   printf("%d\n\n", lengthH+2);
	
	//FLOATING POINT
	float I = 1.2;
	int lengthI = printf("FLOAT\n\
	   Valore: %f \n\
	   Byte occupati: %lu\n\
	   N° caratteri stampati: ", I, (sizeof(float)));
	   printf("%d\n\n", lengthI+2);
	
	//DOUBLE PRECISION
	double L = 2.3;
	int lengthL = printf("DOUBLE\n\
	   Valore: %f \n\
	   Byte occupati: %lu\n\
	   N° caratteri stampati: ", L, (sizeof(double)));
	   printf("%d\n\n", lengthL+2);
	
	long double M = 3.4;
	int lengthM = printf("LONG DOUBLE\n\
		   Valore: %Lf \n\
		   Byte occupati: %lu\n\
		   N° caratteri stampati: ", M, (sizeof(long double)));
		   printf("%d\n\n", lengthM+2);
	/*NB per comodità non ho utilizzato nomi delle variabili significativi 
	 poichè il loro utilizzo era puramente dimostrativo e non avrebbe dovuto ripetersi*/
	
	printf("\n");
	
	
	//VARIANTI MODIFICATORI
	
	//modificatore
	puts("VARIANTI DEI MODIFICATORI\n");
	printf("Stampa del carattere senza modificatori (neutro): %d\n", 1);
	printf("Allineamento a sinistra: %-d\n", 1);
	printf("Stampa del segno: %+d\n", 1);
	printf("Spazio davanti al valore (se non ha segno): % d\n", 1);
	printf("Formato alternativo (ottale e esadecimale): %#o, %#x\n", 12, 12);
	
	//campo minimo
	printf("\nCampo minimo: ..%5d\n\n", 1234);
	//comincia a spaziare dal momento in cui il valore nel carattere di conversione è superiore al numero di caratteri del valore da stampare
	
	
	//precisione
	printf("Minimo numero cifre (5) %.5d\n", 12345);
	printf("Numero cifre decimali prefissato (3) %.3f\n\n", 12.123456789);
	
	//modificatoreLunghezza
	printf("Determina il tipo di dato (ad es. long double): %ld\n\n", 12345678901);

	return 0;
}