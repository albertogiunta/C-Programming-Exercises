#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define DIM 10


int primo = -1;
int ultimo = -1;
int codaSTATIC[DIM];

typedef struct _coda {
    int valore;
    struct _coda *next;
}coda;

/*prototipi funzioni*/
int menuIniziale ();

int statica();
int menuSTATIC();
void pushSTATIC();
void popSTATIC();
int fullSTATIC();
int emptySTATIC();
void stampaSTATIC();

int dinamica();
int menu();
void push();
void pop(coda **primo, coda** ultimo);
int full(coda **primo, coda** ultimo);
int empty(coda **primo, coda** ultimo);
void stampa(coda **primo, coda** ultimo);



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


int statica () {

	int scelta, esci = FALSE;

	do {
		scelta = menuSTATIC();
		fpurge(stdin);
		switch (scelta) {
			case 1:
				pushSTATIC();
				break;
			case 2:
				popSTATIC();
				break;
			case 3:
				stampaSTATIC();
				break;
			case 4:
				esci = TRUE;
				break;
		}
	} while (esci == FALSE);

    printf("\n\n");
    return 0;
}

int menuSTATIC () {
	int scelta;
	puts("\n• • • • M E N U STATICA• • • •");
	puts("1 » INSERISCI ELEMENTO NELLA CODA");
	puts("2 » ELIMINA ELEMENTO DALLA DALLA");
	puts("3 » STAMPA ELEMENTI");
	puts("4 » ESCI");

	do {
		fpurge(stdin);
		printf("          » ");
	} while (scanf("%d", &scelta) != 1 || scelta < 1 || scelta > 4);

	return scelta;
}

void pushSTATIC () {
	int nuovo;

	if (fullSTATIC() == TRUE) {
		printf("Spazio esaurito, impossibile inserire.\n");
		return;
	}

	if (primo == ultimo && ultimo == -1) {
		primo = 0;
		ultimo = 0;
	}

	printf("Inserire un valore:");
	do {
		printf("            » ");
	} while (scanf("%d", &nuovo) != 1 || nuovo < 0);
	printf("Elemento correttamente inserito.\n");

	codaSTATIC[ultimo] = nuovo;
	ultimo = (ultimo + 1) % DIM;
}

void popSTATIC () {
	if (emptySTATIC() == TRUE) {
		printf("La pila è vuota, impossibile eliminare.\n");
		return;
	}
	printf("Elimino %d, ovvero l'elemento inserito meno di recente.\n", codaSTATIC[primo]);
	primo = (primo + 1) % DIM;
}

int fullSTATIC () {
	if (primo == ((ultimo + 1) % DIM)) {
		return 1;
	} else {
		return 0;
	}
}

int emptySTATIC () {
	if (primo == ultimo) {
		return 1;
	} else {
		return 0;
	}
}

void stampaSTATIC() {
	if (emptySTATIC() == TRUE) {
		printf("La pila è vuota.\n");
		return;
	}
	int i = primo;
	while (i != ultimo) {
		printf("%d ", codaSTATIC[i]);
		if (i == DIM - 1) {
			i = 0;
		} else {
			i++;
		}
	}
	puts("");
}


/*dinamica----------------------------------------------------------*/


int dinamica () {

	int scelta, esci = FALSE;

    coda *primo = NULL;
    coda *ultimo = NULL;

	do {
		scelta = menu();
		fpurge(stdin);
		switch (scelta) {
			case 1:
				push(&primo, &ultimo);
				break;
			case 2:
				pop(&primo, &ultimo);
				break;
			case 3:
				stampa(&primo, &ultimo);
				break;
			case 4:
				esci = TRUE;
				break;
		}
	} while (esci == FALSE);

    printf("\n\n");
    free(primo);
    free(ultimo);
    return 0;
}



int menu () {
	int scelta;
	puts("\n• • • • M E N U DINAMICA• • • •");
	puts("1 » INSERISCI ELEMENTO NELLA CODA");
	puts("2 » ELIMINA ELEMENTO DALLA DALLA");
	puts("3 » STAMPA ELEMENTI");
	puts("4 » ESCI");

	do {
		fpurge(stdin);
		printf("          » ");
	} while (scanf("%d", &scelta) != 1 || scelta < 1 || scelta > 4);

	return scelta;
}

void push (coda **primo, coda **ultimo) {
	int nuovo;

	if (full(primo, ultimo) == TRUE) {
		printf("Spazio esaurito, impossibile inserire.\n");
		return;
	}


    coda *temp;
    temp = (coda*)malloc(sizeof(coda));

    //INPUT
	printf("Inserire un valore:");
	do {
		printf("            » ");
	} while (scanf("%d", &nuovo) != 1 || nuovo < 0);
	printf("Elemento correttamente inserito.\n");

    temp->valore = nuovo;
    temp->next = *ultimo;
    if (*primo == *ultimo && *primo == NULL) {
        *primo = temp;
        *ultimo = temp;
        temp->next = NULL;
    } else {
        (*ultimo)->next = temp;
        *ultimo = temp;
        temp->next = NULL;
    }
}

void pop (coda **primo, coda **ultimo) {
	if (empty(primo, ultimo) == TRUE) {
		printf("La pila è vuota, impossibile eliminare.\n");
		return;
	}
	printf("Elimino %d, ovvero l'elemento inserito meno di recente.\n", (*primo)->valore);
	(*primo) = (*primo)->next;
}

int full (coda **primo, coda **ultimo) {
	if (primo == ultimo) {
		return 1;
	} else {
		return 0;
	}
}

int empty (coda **primo, coda** ultimo) {
	if (*primo == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void stampa(coda **primo, coda** ultimo) {
	if (empty(primo, ultimo) == TRUE) {
		printf("La pila è vuota.\n");
		return;
	}
	coda *temp;
    temp = *primo;
	while (temp != NULL) {
		printf("%d ",temp->valore);
        temp = temp->next;
	}
    puts("");
}