#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define LENGTH 10
int trovato = FALSE;

typedef struct _lis {
	int valore;
	struct _lis *next;
} lis;


int menuIniziale ();

int statica();
int menuSTAT();
int input();
void inserisciInTestaSTAT(int lista[], int testa, int *coda);
void inserisciInCodaSTAT (int lista[], int testa, int *coda);
void inserisciDopoElementoSTAT (int lista[], int testa, int *coda);
void cancellaInTestaSTAT (int lista[], int *testa, int *coda);
void cancellaInCodaSTAT (int lista[], int *coda);
void cancellaPrimaOccorrenzaSTAT (int lista[], int *testa, int *coda);
void cancellaTutteOccorrenzeSTAT (int lista[], int *testa, int *coda);
void lunghezzaListaSTAT (int *testa, int *coda);
void stampaElementiSTAT (int lista[], int *testa, int *coda);
void numeroOccorrenzeElementoSTAT (int lista[], int *testa, int *coda);
void swapSTAT (int lista[], int *testa, int *coda);

void dinamica();
int menu();
void inserisciInTesta (lis **testa);
void inserisciInCoda (lis **testa);
lis cercaElemento (lis **testa);
void inserisciDopoElemento (lis **testa);
void cancellaInTesta (lis **testa);
void cancellaInCoda (lis **testa);
void cancellaPrimaOccorrenza (lis **testa);
void cancellaTutteOccorrenze (lis **testa);
void numeroOccorrenzeElemento (lis **testa);
void lunghezzaLista (lis **testa);
void stampaElementi (lis **testa);
void swap (lis **testa);

void numeroOccorrenzeElementoRICOR (lis **testa, int elem);
void lunghezzaListaRICOR (lis **testa);
void stampaElementiRICOR (lis **testa);

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

	int lista[LENGTH];
	int testa=0;
	int coda=0;
	int esci = FALSE;

	do {
		fpurge(stdin);
		int scelta = menuSTAT();

		switch (scelta) {

            case 1:
                inserisciInTestaSTAT(lista, testa, &coda);
                break;
            case 2:
                inserisciInCodaSTAT ( lista,  testa,  &coda);
                break;
            case 3:
				inserisciDopoElementoSTAT ( lista,  testa,  &coda);
                break;
            case 4:
				cancellaInTestaSTAT ( lista,  &testa,  &coda);
                break;
            case 5:
                cancellaInCodaSTAT ( lista,  &coda);
                break;
            case 6:
                cancellaPrimaOccorrenzaSTAT ( lista,  &testa,  &coda);
                break;
            case 7:
                cancellaTutteOccorrenzeSTAT ( lista,  &testa,  &coda);
                break;
            case 8:
				stampaElementiSTAT ( lista,  &testa,  &coda);
                break;
            case 9:
				swapSTAT ( lista,  &testa,  &coda);
                break;
            case 10:
                numeroOccorrenzeElementoSTAT ( lista,  &testa,  &coda);
                break;
            case 11:
				lunghezzaListaSTAT ( &testa, &coda);
				break;
            case 12:
                esci = TRUE;
				break;
		}
	}while (esci == FALSE);

    printf("\n\n");
    return 0;
}

int menuSTAT () {
	int scelta;

	puts("\n• • • • • M E N U STATICA• • • • •");
	puts("1 » INSERISCI IN TESTA");
	puts("2 » INSERISCI IN CODA");
	puts("3 » INSERISCI DOPO UN ELEMENTO");
	puts("4 » CANCELLA IN TESTA");
	puts("5 » CANCELLA IN CODA");
	puts("6 » CANCELLA LA PRIMA OCCORRENZA DI UN ELEMENTO");
	puts("7 » CANCELLA TUTTE LE OCCORRENZE DI UN ELEMENTO");
	puts("8 » STAMPA GLI ELEMENTI DELLA LISTA");
	puts("9 » SWAP TRA DUE ELEMENTI");
	puts("10» CALCOLA IL NUMERO DI OCCORRENZE DI UN ELEMENTO");
	puts("11» LUNGHEZZA LISTA");
    puts("12» ESCI");

	do {
		fpurge(stdin);
		printf("			» ");
	} while (scanf("%d", &scelta) != 1 || scelta < 0 || scelta > 12);

	return scelta;
}

int input() {
	int valore;
	printf("Inserisci il valore: ");
	do {
		fpurge(stdin);
		printf("			» ");
	} while (scanf("%d", &valore) != 1);

	return valore;
}

/*inserisci un elemento in TESTA alla lista*/
void inserisciInTestaSTAT (int lista[], int testa, int *coda){

	int nuovo = input(), i;
	if (testa == *coda) { //se la lista non contiene elementi
		lista[testa] = nuovo;
	} else {
		for (i = *coda + 1; i >= testa; i--) { //sposto verso destra tutti gli elementi
			lista[i] = lista[i - 1]; //mi posiziono una cella oltre la fine e sposto tutti gli elementi di una cella a destra
		}
		lista[testa] = nuovo;
	}
	*coda += 1;
    printf("Elemento correttamente inserito.");
}

/*inserisci un elemento in CODA alla lista*/
void inserisciInCodaSTAT (int lista[], int testa, int *coda) {
	int nuovo = input();

	lista[*coda] = nuovo;
	*coda += 1;
    printf("Elemento correttamente inserito.");
}

/*inserisci dopo un certo elemento*/
void inserisciDopoElementoSTAT (int lista[], int testa, int *coda) {


	printf("Inserire il numero da ricercare nella lista:");
	int cerca = input();
	printf("Inserire il valore da immettere nella lista:");
	int nuovo = input(), i = 0, j;
	trovato = FALSE;
	while (i < *coda) {
		if (lista[i] == cerca) {
			trovato = TRUE;
			break;
		}
		i++;
	}
	if (trovato == TRUE) {
		for (j = *coda + 1; j > i; j--) { //forse solo >
			lista[j] = lista[j - 1];
		}
		lista[i + 1] = nuovo;
		printf("Il numero è stato correttamente inserito");
	} else {
		printf("Il numero ricercato non è stato trovato all'interno della lista");
	}
	*coda += 1;
}

/*cancella l'elemento in testa alla lista*/
void cancellaInTestaSTAT (int lista[], int *testa, int *coda) {

	if (*testa == *coda) {
		printf("La lista è vuota");
		return;
	}
	int i;
	for (i = *testa; i <= *coda; i++) {
		lista [i] = lista[i + 1];
	}
	*coda -= 1;
    printf("Elemento cancellato correttamente");
}

/*cancella l'elemento in coda alla lista*/
void cancellaInCodaSTAT (int lista[], int *coda) {
	lista[*coda] = 0;
	*coda -= 1;
    printf("Elemento cancellato correttamente");
}

/*cancella la prima occorrenza dell'elemento inserito in input*/
void cancellaPrimaOccorrenzaSTAT (int lista[], int *testa, int *coda) {

	int elem = input(), i = 0, j;
	trovato = FALSE;

	if (*testa == *coda) {
		printf("La lista è vuota");
		return;
	}

	int mid = (*coda - *testa)/2;
	while (i < *coda) {
		if (lista[i] == elem) {
			trovato = TRUE;
			break;
		}
		i++;
	}
	if (trovato == TRUE) {											//non ho idea se funzioni
		if (i < mid) { //se
			for (j = i; j >= *testa; j--) {
				lista[j] = lista[j - 1];
			}
			*testa += 1;
		} else if (i >= mid) {
			for (j = i; j < *coda; j++) {
				lista[j] = lista[j + 1];
			}
			*coda -= 1;
		}
	}

	if (trovato == TRUE) {
		printf("La prima occorrenza dell'elemento di valore %d è stata cancellata correttamente •  •\n", elem);
	} else {
		printf("L'elemento di valore %d non è stato trovato all'interno della lista, impossibile cancellare la sua prima occorenza •  •\n", elem);
	}
}

/*cancella tutte le occorrenze dell'elemento inserito in input*/
void cancellaTutteOccorrenzeSTAT (int lista[], int *testa, int *coda) {


	int elem = input(), i = 0, j, conta = 0;
	trovato = FALSE;

	if (*testa == *coda) {
		printf("La lista è vuota");
		return;
	}

	for (i = *testa; i < *coda; i++) {
		if (lista[i] == elem) {
            conta++;
			trovato = TRUE;
			for (j = i; j < *coda; j++) {
				lista[j] = lista[j + 1];
			}
            i--;
		}
	}

    *coda -= conta;

	if (trovato == TRUE) {
		printf("Le occorrenze dell'elemento di valore %d sono state cancellate correttamente •  •\n", elem);
	} else {
		printf("L'elemento di valore %d non è stato trovato all'interno della lista, impossibile cancellare le occorrenze •  •\n", elem);
	}

}

/*restituisce la lunghezza della lista*/
void lunghezzaListaSTAT (int *testa, int *coda) {
	printf("La lista ha %d element", (*coda - *testa));
    if ((*coda - *testa) == 1) {
        printf("o");
    } else {
        printf("i");
    }
}

/*stampa di tutti gli elementi della lista*/
void stampaElementiSTAT (int lista[], int *testa, int *coda) {

	if (*testa == *coda) {
		printf("La lista è vuota");
		return;
	}

	for (int i = *testa; i < *coda; i++) {
		printf("%d ", lista[i]);
	}

	printf("\n");
}

/*stampa del numero di occorrenze di un elemento nella lista*/
void numeroOccorrenzeElementoSTAT (int lista[], int *testa, int *coda) {
	int elem = input();
	int i = 0, conta = 0;
	trovato = FALSE;

	if (*testa == *coda) {
		printf("La lista è vuota");
		return;
	}

	for (i = *testa; i < *coda; i++) {
		if (lista[i] == elem) {
			trovato = TRUE;
			conta++;
		}
	}
	printf("Sono state trovate %d occorrenze dell'elemento %d", conta, elem);
}

/*swap tra due elementi a scelta della lista*/
void swapSTAT (int lista[], int *testa, int *coda) {
	int trovato1 = FALSE, trovato2 = FALSE, i, j, temp;

	printf("Primo elemento:");
	int elem1 = input();

	printf("Secondo elemento:");
	int elem2 = input();

	if (*testa == *coda) {
		printf("La lista è vuota");
		return;
	}

	for (i = *testa; i < *coda; i++) {
		if (lista[i] == elem1) {
			trovato1 = TRUE;
			break;
		}
	}

	for (j = *testa; j < *coda; j++) {
		if (lista[j] == elem2) {
			trovato2 = TRUE;
			break;
		}
	}

	if (trovato1 == TRUE && trovato2 == TRUE) {
		temp = lista[i];
		lista[i] = lista[j];
		lista[j] = temp;
        printf("Swap tra gli elementi correttamente effettuato");
	} else {
		printf("Elementi non trovati nella lista, impossibile eseguire lo swap");
	}
    
}



/*DINAMICO ----------------------------------------------------------------*/


void dinamica () {

	lis *testa = NULL;
	int *trovato = NULL;
	int esitoRicerca = FALSE;
	trovato = &esitoRicerca;
	int esci = FALSE;
    int elem;
	do {
		fpurge(stdin);
		int scelta = menu();

		switch (scelta) {
            case 1:
                inserisciInTesta(&testa);
                break;
            case 2:
                inserisciInCoda(&testa);
                break;
            case 3:
                inserisciDopoElemento(&testa);
                break;
            case 4:
                cancellaInTesta(&testa);
                break;
            case 5:
                cancellaInCoda(&testa);
                break;
            case 6:
                cancellaPrimaOccorrenza(&testa);
                break;
            case 7:
                cancellaTutteOccorrenze(&testa);
                break;
            case 8:
                lunghezzaLista(&testa);
                break;
            case 9:
                lunghezzaListaRICOR(&testa);
                break;
            case 10:
                stampaElementi(&testa);
                break;
            case 11:
                stampaElementiRICOR(&testa);
                break;
            case 12:
                numeroOccorrenzeElemento(&testa);
                break;
            case 13:
                elem = input();
                numeroOccorrenzeElementoRICOR(&testa, elem);
                break;
            case 14:
                swap(&testa);
                break;
            case 15:
                esci = TRUE;
                break;
		}
	}while (esci == FALSE);

    free(testa);
    printf("\n\n");
}

int menu () {
	int scelta;

	puts("\n• • • • • M E N U  DINAMICA• • • • •");
	puts("1 » INSERISCI IN TESTA");
	puts("2 » INSERISCI IN CODA");
	puts("3 » INSERISCI DOPO UN ELEMENTO");
	puts("4 » CANCELLA IN TESTA");
	puts("5 » CANCELLA IN CODA");
	puts("6 » CANCELLA LA PRIMA OCCORRENZA DI UN ELEMENTO");
    puts("7 » CANCELLA TUTTE LE OCCORRENZE DI UN ELEMENTO");
    puts("8 » CALCOLA LUNGHEZZA LISTA");
    puts("9 » CALCOLA LUNGHEZZA LISTA (RICORSIVA");
	puts("10» STAMPA GLI ELEMENTI DELLA LISTA");
    puts("11» STAMPA GLI ELEMENTI DELLA LISTA (RICORSIVA");
	puts("12» CALCOLA IL NUMERO DI OCCORRENZE DI UN ELEMENTO");
    puts("13» CALCOLA IL NUMERO DI OCCORRENZE DI UN ELEMENTO (RICORSIVA)");
    puts("14 » SWAP TRA DUE ELEMENTI");
    puts("15» ESCI");

	do {
		fpurge(stdin);
		printf("			» ");
	} while (scanf("%d", &scelta) != 1 || scelta < 0 || scelta > 15);

	return scelta;
}

/*1 inserisci un elemento in TESTA alla lista*/
void inserisciInTesta (lis **testa){
	/*[pag.4]*/

	lis *nuovo = NULL;

	//l'ordine di queste istruzioni va rispettato alla lettera
	//questo procedimento funziona anche per le liste vuote
	nuovo = (lis*)malloc(sizeof(lis));
	nuovo->valore = input();
	nuovo->next = *testa;
	*testa = nuovo;
    printf("Elemento correttamente inserito.");
}

/*2 inserisci un elemento in CODA alla lista*/
void inserisciInCoda (lis **testa) {
	/*[pag.13]*/

	lis *temp = NULL, *nuovo = NULL;

	nuovo = (lis*)malloc(sizeof(lis));

	nuovo->valore = input();

	/*controllo se la lista è vuota*/
	if (*testa == NULL) {				/*se è vuota, ovvero testa punta a null*/
		*testa = nuovo;					/*allora testa punta subito a nuovo*/

	} else {							/*se non è vuota*/

		temp = *testa;					/*inizializzo una variabile temporanea che a partire da testa scorre la lista (così non perdo testa)*/

		while (temp->next != NULL) {	/*finchè non raggiungo la fine della lista*/
			temp = temp->next;			/*temp punta sempre al suo successivo*/
		}
        
        nuovo->next = temp->next;
		temp->next = nuovo;				/*quando trovo l'ultima cella della lista, faccio puntare il successivo a nuovo*/
	}
    printf("Elemento correttamente inserito.");
}

/*3 inserisci dopo un certo elemento*/
void inserisciDopoElemento (lis **testa) {
	lis *temp = NULL, *nuovo = NULL;
	temp = *testa;
	trovato = FALSE;

	if (*testa == NULL) {
		printf("Impossibile inserire, la lista è vuota •  •\n");
	} else {
		nuovo = (lis*)malloc(sizeof(lis));
		printf("Nuovo elemento •  •");
		nuovo->valore = input();
		printf("Cerca elemento dopo il quale inserire •  •\n");
		int cerca = input();
		while (temp != NULL) {
			if (temp->valore == cerca) {
				trovato = TRUE;
				break;
			}
			temp = temp->next;
		}
		if (trovato == TRUE) {
			nuovo->next = temp->next;
			temp->next = nuovo;
			printf("L'elemento di valore %d è stato correttamente inserito •  •\n", nuovo->valore);
		} else if (trovato == FALSE) {
			printf("Elemento non trovato all'interno della lista, impossibile inserire •  •\n");
		}
	}
}

/*4 cancella l'elemento in testa alla lista*/
void cancellaInTesta (lis **testa) {
	lis *temp = NULL;
	if (*testa != NULL) {
		temp = *testa;
		*testa = temp->next;
		free(temp);
		printf("Elemento in testa alla lista cancellato correttamente •  •\n");
	} else {
		printf("La lista è attualmente vuota, impossibile cancellare •  •\n");
	}
}

/*5 cancella l'elemento in coda alla lista*/
void cancellaInCoda (lis **testa) {
	lis *temp = NULL, *prec = NULL;
	temp = *testa;

	if (testa != NULL) { //se la lista non è vuota
		while (temp->next != NULL) {
			prec = temp;
			temp = temp->next;
		}
		if (prec == NULL) {
			*testa = NULL;
		} else {
			prec->next = temp->next;
		}
		free(temp);
        printf("Elemento in coda alla lista cancellato correttamente •  •\n");
	} else {
		printf("La lista è attualmente vuota, impossibile cancellare •  •\n");
	}
}

/*6 cancella la prima occorrenza dell'elemento inserito in input*/
void cancellaPrimaOccorrenza (lis **testa) {

	lis *temp = NULL, *prec = NULL;

	int elem = input();
	trovato = FALSE;
	temp = *testa;

	while (temp != NULL) {
		if (temp->valore == elem) {
			trovato = TRUE;
			if (prec == NULL) {
				*testa = temp->next;
			} else {
				prec->next = temp->next;
			}
			free(temp);
			break;
		}
		prec = temp;
		temp = temp->next;
	}

	if (trovato == TRUE) {
		printf("La prima occorrenza dell'elemento di valore %d è stata cancellata correttamente •  •\n", elem);
	} else {
		printf("L'elemento di valore %d non è stato trovato all'interno della lista, impossibile cancellare la sua prima occorenza •  •\n", elem);
	}
}

/*7 cancella tutte le occorrenze dell'elemento inserito in input*/
void cancellaTutteOccorrenze (lis **testa) {
	lis *temp = NULL, *prec = NULL, *elimina = NULL;

	int elem = input();
	trovato = FALSE;
	temp = *testa;

	while (temp != NULL) {
		if (temp->valore == elem) {
			trovato = TRUE;
			if (prec == NULL) {
				*testa = temp->next;
			} else {
				prec->next = temp->next;
			}
			elimina = temp;
			temp = temp->next;
			free(elimina);
		} else {
			prec = temp;
			temp = temp->next;
		}
	}

	if (trovato == TRUE) {
		printf("Le occorrenze dell'elemento di valore %d sono state cancellate correttamente •  •\n", elem);
	} else {
		printf("L'elemento di valore %d non è stato trovato all'interno della lista, impossibile cancellare le occorrenze •  •\n", elem);
	}

}

/*8 restituisce la lunghezza della lista*/
void lunghezzaLista (lis **testa) {
	lis *temp = NULL;
	int conta = 0;
	if (testa == NULL) {
		printf("La lista è vuota, non ci sono elementi • • •\n");
	} else {
		temp = *testa;
		while (temp != NULL) {
			conta++;
			temp = temp->next;
		}
		switch (conta) {
			case 1:
				printf("La lista contiene 1 elemento • • •\n");
				break;
			default:
				printf("La lista conteiene %d elementi • • •\n", conta);
				break;
		}
	}
}

/*9 restituisce la lunghezza della lista*/
void lunghezzaListaRICOR (lis **testa) {
	lis *temp = NULL;
	static int conta = 0;
	temp = *testa;
	if (temp == NULL) {
		switch (conta) {
			case 0:
				printf("La lista è vuota, non ci sono elementi • • •\n");
				break;
			case 1:
				printf("La lista contiene 1 elemento • • •\n");
				break;
			default:
				printf("La lista conteiene %d elementi • • •\n", conta);
				break;
		}
		return;
	} else {
		conta++;
		lunghezzaListaRICOR(&temp->next);
	}
} //RICORSIVA OK

/*10 stampa di tutti gli elementi della lista*/
void stampaElementi (lis **testa) {
	lis *temp = NULL;
	temp = *testa;

	if (testa == NULL) {
		printf("La lista è vuota, impossibile stampare • • •\n");
	} else {
		while (temp != NULL) {
			printf("%d ", temp->valore);
			temp = temp->next;
		}
	}
	printf("\n");
}

/*11 stampa di tutti gli elementi della lista*/
void stampaElementiRICOR (lis **testa) {
	lis *temp = NULL;
	temp = *testa;

	if (temp == NULL) {
		printf("\n");
		return;
	} else {
		printf("%d ", temp->valore);
		stampaElementiRICOR(&temp->next); //temp->next a ogni nuova chiamata si sostituisce alla testa
	}

} //RICORSIVA OK

/*12 stampa del numero di occorrenze di un elemento nella lista*/
void numeroOccorrenzeElemento (lis **testa) {
	lis *temp = NULL;

	printf("Elemento da ricercare	\n");
	int elem = input();
	int conta = 0;

	if (testa == NULL) {
		printf("La lista è vuota, impossibile contare le occorenze dell'elemento di valore %d • • •", elem);
	} else {
		temp = *testa;
		while (temp != NULL) {
			if (temp->valore == elem) {
				conta++;
			}
			temp = temp->next;
		}
		if (conta != 0) {
			printf("Sono state trovate %d occorrenze dell'elemento di valore %d • • •", conta, elem);
		} else {
			printf("L'elemento di valore %d non è stato trovato all'interno della lista, impossibile stampare il numero delle sue occorrenze • • •", elem);
		}
	}
}

/*13 stampa del numero di occorrenze di un elemento nella lista*/
void numeroOccorrenzeElementoRICOR (lis **testa, int elem) {
	lis *temp = NULL;
	temp = *testa;
	static int conta = 0;
	if (temp == NULL) {
		if (conta != 0) {
			printf("Sono state trovate %d occorrenze dell'elemento di valore %d • • •", conta, elem);
		} else if (conta == 0) {
			printf("La lista è vuota, impossibile contare le occorenze dell'elemento di valore %d • • •", elem);
		}else {
			printf("L'elemento di valore %d non è stato trovato all'interno della lista, impossibile stampare il numero delle sue occorrenze • • •", elem);
		}
		return;
	} else {
		if (temp->valore == elem) {
			conta++;
		}
        numeroOccorrenzeElementoRICOR(&temp->next, elem);
	}
} //RICORSIVA OK

/*14 swap tra due elementi a scelta della lista*/
void swap (lis **testa) {
	lis *temp1 = NULL, *temp2 = NULL, *prec1 = NULL, *prec2 = NULL, *temp = NULL;
	int trovato1 = FALSE, trovato2 = FALSE;

	printf("Primo elemento:");
	int elem1 = input();

	printf("Secondo elemento:");
	int elem2 = input();

	if (testa == NULL) {
		printf("La lista è vuota.");
	} else {
		temp1 = *testa;
		while (temp1 != NULL) {
			if (temp1->valore == elem1) {
				trovato1 = TRUE;
				break;
			}
			prec1 = temp1;
			temp1 = temp1->next;
		}

		temp2 = *testa;
		while (temp2 != NULL) {
			if (temp2->valore == elem2) {
				trovato2 = TRUE;
				break;
			}
			prec2 = temp2;
			temp2 = temp2->next;
		}
        
		if (trovato1 == TRUE && trovato2 == TRUE) {
			if (prec1 == NULL) { //se il primo elemento è in testa
				*testa = temp2;
			} else {
				prec1->next = temp2;
			}
            
			if (prec2->next == temp1) { //se sono consecutivi
				temp = temp1;
			} else {
				temp = temp1->next;
				prec2->next = temp1;
			}
			temp1->next = temp2->next;
			temp2->next = temp;
            printf("Swap tra gli elementi correttamente effettuato");
		} else {
            printf("Elementi non trovati, impossibile effettuare lo swap");
        }
	}

} //funziona, ma non ho capito

