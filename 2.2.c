//
//  Esercizio2
//
//  Creato da Alberto Giunta il 02/10/13.
//  Matricola: 000691428

/*Scrivere un programma C che usi tutti gli operatori studiati 
 almeno quattro volte ciascuno e stampi i valori delle variabili 
 usate prima e dopo l’applicazione degli stessi.*/

#include <stdio.h>

int main ()
{
    int a,b,c=0;

    printf("Inserire il 1° numero (a): ");
    scanf("%d", &a);
    
	printf("Inserire il 2° numero (b): ");
	scanf("%d", &b);
	//prendo in input il valore delle variabili
	
	printf("\n\n");
	
	//ADDIZIONE
	puts("ADDIZIONE SEMPLICE +");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("c = a + b --> %d = %d + %d\n",c=a+b,a,b);
	printf("a = %d\tb = %d\tc = %d\n\n",a,b,c);
	
	puts("OPERATORE DI INCREMENTO PREFISSO ++a");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("b = ++c --> %d = ++%d\n",b,c);
	printf("a = %d\tb = %d\tc = ",a,b=++c); //per evitare effetti collaterali non posso usare la variabile c in modi diversi nella stessa espressione
	printf("%d\n\n",c);
	
	puts("OPERATORE DI DECREMENTO POSTFISSO a++");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("a = b++ --> %d = %d++\n",a,b);
	printf("a = %d\tb = ",a=b++); //stesse motivazioni e procedimento dell'operatore di incremento prefisso
	printf("%d\tc = %d\n\n",b,c);

	puts("OPERATORE DI ASSEGNAMENTO COMPATTO +=");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("a = a + b UGUALE A a += b --> %d += %d\n",a,b); //funziona con tutti gli operatori, es. +=, -=, *=, /= ecc.
	printf("a = %d\tb = %d\tc = %d\n\n",a+=b,b,c);
	
	//SOTTRAZIONE
	puts("SOTTRAZIONE SEMPLICE -");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("c = a - b --> %d = %d - %d\n",c=a-b,a,b);
	printf("a = %d\tb = %d\tc = %d\n\n",a,b,c);
	
	puts("OPERATORE DI INCREMENTO PREFISSO --a");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("b = --c --> %d = --%d\n",b,c);
	printf("a = %d\tb = %d\tc = ",a,b=--c);
	printf("%d\n\n",c);
	
	puts("OPERATORE DI DECREMENTO POSTFISSO a--");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("a = b-- --> %d = %d--\n",a,b);
	printf("a = %d\tb = ",a=b--);
	printf("%d\tc = %d\n\n",b,c);
	
	puts("OPERATORE DI ASSEGNAMENTO COMPATTO -=");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("a = a - b UGUALE A a -= b --> %d -= %d\n",a,b);
	printf("a = %d\tb = %d\tc= %d\n\n",a-=b,b,c);
	
	//MOLTIPLICAZIONE (non esiste elevamento a potenza)
	puts("MOLTIPLICAZIONE *");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("c = a * b --> %d = %d * %d\n", c=a*b,a,b);
	printf("a = %d\tb = %d\tc = %d\n\n",a,b,c);
	
	puts("OPERATORE DI ASSEGNAMENTO COMPATTO *=");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("a = a * b UGUALE A a *= b --> %d *= %d\n",a,b);
	printf("a = %d\tb = %d\tc = %d\n\n",a*=b,b,c);

	
	//DIVISIONE E RESTO (modulo, a%b)
	puts("DIVISIONE E RESTO / %");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("c = a * b --> %d = %d / %d, RESTO: %d\n", c=a/b,a,b,a%b);
	printf("a = %d\tb = %d\tc = %d\n\n",a,b,c);
	
	puts("OPERATORE DI ASSEGNAMENTO COMPATTO /=");
	printf("a = %d\tb = %d\tc = %d\n",a,b,c);
	printf("a = a / b UGUALE A a /= b --> %d /= %d\n",a,b);
	printf("a = %d\tb = %d\tc = %d\n\n",a/=b,b,c);
	
	//OPERATORI LOGICI
	puts("RISULTATO DELLA COMPARAZIONE CON OPERATORI LOGICI");
	if (a>=b){
		if (a>b){
			puts("a > b");
		} else {
			puts("a = b");
		}
	}else if (a<=b){
		if (a<b){
			puts("a < b");
		}else{
			puts("a = b");
		}
	}
	
	printf("\n\n\n");
		
	//OPERAZIONI DI DIVISIONE E RESTO CON OPERATORI LOGICI
	
	//FATTORI DI UNA MOLTIPLICAZIONE
	int ris, f1,f2;
	printf("INSERIRE IL RISULTATO INTERO DI UNA MOLTIPLICAZIONE: ");
	scanf("%d",&ris);
	printf("INSERIRE UN ALTRO QUALSIASI NUMERO INTERO: ");
	scanf("%d", &f1);
	
	f2 = ris/f1;
	
	printf("\nIl numero %d è contenuto %d volt", f1, f2);
	
	char sing='a', plur='e'; //ottimizzo il lessico in "volte" o "volta" a seconda che il secondo fattore sia != o == a 1
	if (f2!=1){
		printf("%c",plur);
	}else {
		printf("%c",sing);
	}
	
	printf(" con resto %d nel numero %d\n\n",ris%f1, ris);
	
	
	
	//NUMERO PARI O DISPARI
	int val;
	float resto;
	printf("Inserire un numero intero: ");
	scanf("%d", &val);
	resto = val%2; //se è divisibile per due e quindi il resto è zero il numero è pari
	if (resto == 0) {
		printf("Il numero %d è pari", val);
	} else {
		printf("Il numero %d è dispari", val);
	}
	
	printf("\n\n");
	
	
	//SCOMPOSIZIONE E SPAZIAMENTO DELLE CIFRE DI UN NUMERO
	int num;
	printf("Inserire un numero intero di 3 cifre: ");
	scanf("%d", &num);
	float cent = num/100; //trasformo le centinaia in unità
	num %= 100; //riduco il numero alle decine
	float dec = num/10; //trasformo le decine in unità
	num %= 10; //riduco il numero alle unità
	float uni = num;

	printf("%.0f %.0f %.0f", cent, dec, uni);
	
	printf("\n\n");
	
	
	//STAMPA TABELLA QUADRATI E CUBI DA 0 A 10
	int i;
	puts("\nCalcolo di quadrati e cubi dei numeri da 0 a 10\n");
	printf("Numero\t\tQuadrato\t\tCubo\n");
	for (i=0; i<=10; i++)
		printf("%d\t\t\t%d\t\t\t\t%d\n",i,i*i,i*i*i);
		i = i+1;
	
	
	
	printf("\n\n");
	return 0;
}