

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define DIM 10

/*statico*/
int top = -1;
int pilaSTAT[DIM];

/*dinamico*/
typedef int tipoPila;

typedef struct _pila {
    int valore;
    struct _pila *next;
} pila;

/*prototipi funzioni*/
int menuIniziale ();

/*statico*/
int statica();
int menuSTAT();
void pushSTAT ();
void popSTAT();
int fullSTAT();
int emptySTAT();
void stampaSTAT();

/*dinamico*/
int dinamica();
int menu();
void initPila (pila *top);
void push (pila **top);
void pop(pila **top);
int empty(pila **top);
void stampa(pila **top);

int main () {

	int scelta;
	int esci = FALSE;

	do {
		scelta = menuIniziale();
		fpurge(stdin);
		switch (scelta) {
			case 1:
                statica();
				break;
			case 2:
                dinamica();
				break;
			case 3:
				esci = TRUE;
				break;
		}
	} while (esci == FALSE);

    printf("\n\n");
    return 0;
}

int menuIniziale () {
    int scelta;

    puts("Scegli come svolgere le operazioni!");
    puts("1 » Allocazione statica");
    puts("2 » Allocazione dinamica");
    puts("3 » Esci");

    do {
        fpurge(stdin);
        printf("         »");
    }while (scanf("%d", &scelta) != 1 || scelta < 1 || scelta > 3);
    return scelta;
}

/*statico-----------------------------------------------------------------------*/
int statica () {

	int scelta, esci = FALSE;
	do {
		scelta = menuSTAT();
		fpurge(stdin);
		switch (scelta) {
			case 1:
				pushSTAT();
				break;
			case 2:
				popSTAT();
				break;
			case 3:
				stampaSTAT();
				break;
			case 4:
				esci = TRUE;
				break;
		}
	} while (esci == FALSE);

    printf("\n\n");
    return 0;
}

int menuSTAT () {
	int scelta;
	puts("\n• • • • M E N U STATICA• • • •");
	puts("1 » INSERISCI ELEMENTO NELLA PILA");
	puts("2 » ELIMINA ELEMENTO DALLA PILA");
	puts("3 » STAMPA ELEMENTI");
	puts("4 » ESCI");

	do {
		fpurge(stdin);
		printf("          » ");
	} while (scanf("%d", &scelta) != 1 || scelta < 1 || scelta > 4);

	return scelta;
}

void pushSTAT () {
	int nuovo;
	if (fullSTAT() == TRUE) {
		printf("Spazio esaurito, impossibile inserire.\n");
		return;
	}
	printf("Inserire un valore:");
	do {
		printf("            » ");
	} while (scanf("%d", &nuovo) != 1 || nuovo < 0);
	printf("Elemento correttamente inserito.\n");
	pilaSTAT[++top] = nuovo;
}

void popSTAT () {
	if (emptySTAT() == TRUE) {
		printf("La pila è vuota, impossibile eliminare.\n");
		return;
	}
	printf("Elimino %d, ovvero l'ultimo elemento inserito.\n", pilaSTAT[top--]);
}

int fullSTAT () {
	if (top == DIM - 1) {
		return 1;
	} else {
		return 0;
	}
}

int emptySTAT () {
	if (top == -1) {
		return 1;
	} else {
		return 0;
	}
}

void stampaSTAT() {
	if (emptySTAT() == TRUE) {
		printf("La pila è vuota.\n");
		return;
	}
	for (int i = top; i >= 0; i--) {
		printf("%d ", pilaSTAT[i]);
	}
	puts("");
}


/*dinamico-----------------------------------------------------------------------*/
int dinamica () {

    pila *top = NULL;


	int scelta, esci = FALSE;
	do {
		scelta = menu();
		fpurge(stdin);
		switch (scelta) {
			case 1:
				push(&top);
				break;
			case 2:
				pop(&top);
				break;
			case 3:
				stampa(&top);
				break;
			case 4:
				esci = TRUE;
				break;
		}
	} while (esci == FALSE);

    printf("\n\n");
    free(top);
    return 0;
}

int menu () {
	int scelta;
	puts("\n• • • • M E N U DINAMICA• • • •");
	puts("1 » INSERISCI ELEMENTO NELLA PILA");
	puts("2 » ELIMINA ELEMENTO DALLA PILA");
	puts("3 » STAMPA ELEMENTI");
	puts("4 » ESCI");

	do {
		fpurge(stdin);
		printf("          » ");
	} while (scanf("%d", &scelta) != 1);

	return scelta;
}

void push (pila **top) {
	int nuovo;
	printf("Inserire un valore:");
	do {
		printf("            » ");
	} while (scanf("%d", &nuovo) != 1 || nuovo < 0);

    pila *temp;
    temp = (pila*)malloc(sizeof(pila));
    temp->valore = nuovo;
    temp->next = *top;
    *top = temp;

	printf("Elemento correttamente inserito.\n");
}

void pop (pila **top) {
	if (empty(top) == TRUE) {
		printf("La pila è vuota, impossibile eliminare.\n");
		return;
	}

    pila *temp;
    temp = *top;
    int pop = temp->valore;

    temp = (*top)->next;
    free(*top);
    *top = temp;
    printf("Elimino %d, ovvero l'ultimo elemento inserito.\n", pop);
}

int empty (pila **top) {
	if (*top == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void stampa(pila **top) {
	if (empty(top) == TRUE) {
		printf("La pila è vuota.\n");
		return;
	}

    pila *temp;
    temp = *top;
    while (temp != NULL) {
        printf("%d ", temp->valore);
        temp = temp->next;
    }
    
   	puts("\n");
}




