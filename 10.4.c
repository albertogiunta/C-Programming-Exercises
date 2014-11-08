//alberto giunta
//matr. 0000691428

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0
#define TOTESAMI 10
#define MAXSTUDENTITOT 1000

/*strutture*/


/*struttura esame*/
typedef struct _Es{
    int idEsame;
    char nomeEsame[40];
    int voto;
	struct _Es *next;
}Esame;

/*struttura studente*/
typedef struct _Stud {
	int matricola;
	char nome[20];
	char cognome[20];
    Esame *testaEsame;
	int annoIscritto;
	int sommaVoti;
	int numEsamiDati;
	struct _Stud *next;
} Stud;

/*struttura anno accademico*/
typedef struct _AA {
	int idAnno;
    int annoPartenza;
	int annoFine;
    int numeroProgrammato;
    int iscritti;
	Stud *testaStud;
	struct _AA *next;
}AnnoAccademico;

int numMatricola = 0, contaAnni = 0, contaStudenti = 0;

/*prototipi funzioni*/
int menu ();
void initEsami(Esame listaEsami[]);
int menuStud (int maxScelta);
int mainStud (AnnoAccademico **testaAA, Stud **testaStud, Esame **testaEsame, Esame listaEsami[]);
int inputScelta (int minScelta, int maxScelta);
int inputMatrStud ();
int inputAnnoStud ();
Stud* ricercaStudente (AnnoAccademico **testaAA, int cercaAnno, int cercaMatr);
int nuovoAA (AnnoAccademico **testaAA);
int iscriviStudenteInLista (AnnoAccademico **testaAA, Stud *nuovoStud);
int inserisciStudente (AnnoAccademico *testaAA, Esame listaEsami[]);
void stampaEsami ();
int modificaCurriculum(AnnoAccademico **testaAA, Esame listaEsami[], int cercaAnno, int cercaMatr);
void stampaInfoEdEsami (Stud *studCercato);
int esameNonDato (AnnoAccademico **testaAA);
int annoMediaMaggiore (AnnoAccademico **testaAA);

/*corpo*/

int main () {
    int esci, scelta, esito;

    /*puntatori a strutture (x liste)*/
    Stud *testaStud = NULL;
    AnnoAccademico *testaAA = NULL;
	Esame *testaEsame = NULL;


    Esame listaEsami[10];
    initEsami(listaEsami);

	do {
		fpurge(stdin);
		scelta = menu();
		esci = FALSE;
		switch (scelta) {
			case 1:
				/*Aggiungi nuovo anno accademico*/
				esito = nuovoAA(&testaAA);
				if (esito == 1) {
					puts("Nuovo anno accademico inserito con successo!");
				} else if (esito == 0){
					puts("Errore nell'inserimento dell'anno accademico!");
				}
				printf("\n\n");
				break;
			case 2:
				if (testaAA == NULL) {
					printf("Non è stato inserito alcun anno accademico!\n");
					break;
				}
				/*operazioni con voce studente*/
				esito = mainStud(&testaAA, &testaStud , &testaEsame, listaEsami);
				break;
			case 3:
				/*Esci*/
				esci = TRUE;
				break;
		}
	}while (esci == FALSE);

    printf("\n\n");
	free(testaStud);
	free(testaAA);
	free(testaEsame);
	free(listaEsami);
    return 0;
}

int menu () {
    int scelta;
	puts("\n\n                   M E N U                  ");
	puts("1 » Inserisci anno accademico");
	puts("2 » Opera con studente");
	puts("3 » ESCI");

	do {
		fpurge(stdin);
		printf("				» ");
	}while (scanf("%d", &scelta) != 1 || scelta < 1);
	return scelta;
}


/*----------------------------------------------------------------------------------------*/

void initEsami (Esame listaEsami[]) {
	/*inizializzo l'id di ogni esame*/
	for (int i = 0; i < TOTESAMI; i++) {
		listaEsami[i].idEsame = i;
	}
	/*inizializzo il nome di ogni esame*/
	strcpy(listaEsami[0].nomeEsame, "Analisi");
	strcpy(listaEsami[1].nomeEsame, "Programmazione");
	strcpy(listaEsami[2].nomeEsame, "Algoritmi e strutture dati");
	strcpy(listaEsami[3].nomeEsame, "Algebra e geometria");
	strcpy(listaEsami[4].nomeEsame, "Architettura degli elaboratori");
	strcpy(listaEsami[5].nomeEsame, "Programmazione a oggetti");
	strcpy(listaEsami[6].nomeEsame, "Algoritmi numerici");
	strcpy(listaEsami[7].nomeEsame, "Sistemi automatici");
	strcpy(listaEsami[8].nomeEsame, "Basi di dati");
	strcpy(listaEsami[9].nomeEsame, "Statistica e probabilità");

	/*in caso di variazione del numero di esami, ricordarsi di aggiungere manualmente gli esami nello switch.*/
}


/*----------------------------------------------------------------------------------------*/

int inputScelta (int minScelta, int maxScelta) {
	int scelta;

	do {
		fpurge(stdin);
		printf("          » ");
	} while (scanf("%d", &scelta) != 1 || scelta < minScelta || scelta > maxScelta);

	return scelta;
} //OK


/*----------------------------------------------------------------------------------------*/

Stud* ricercaStudente (AnnoAccademico **testaAA, int cercaAnno, int cercaMatr) {
	int trovato = FALSE;


	AnnoAccademico *tempAA = NULL;
	tempAA = *testaAA;

	//scorro la lista anni e trovo l'anno cercato
	while (tempAA != NULL) {
		if (tempAA->annoPartenza == cercaAnno) {
			trovato = TRUE;
			break;
		}
		tempAA = tempAA->next;
	}
	if (trovato == FALSE) {
		puts("L'anno selezionato non è stato trovato all'interno della lista");
		return NULL;
	}

	//faccio lo stesso con gli studenti
	Stud *tempStud = NULL;
	tempStud = tempAA->testaStud;

	trovato = FALSE;
	while (tempStud != NULL) {
		if (tempStud->matricola == cercaMatr) {
			trovato = TRUE;
			break;
		}
		tempStud = tempStud->next;
	}

	if (trovato == FALSE) {
		puts("Lo studente ricercato non è stato trovato all'interno degli iscritti all'anno selezionato.");
		return NULL;
	}
	//se trovo lo studente lo restituisco
	return tempStud;

} // OK

int inputMatrStud () {
	//funzione per l'inserimento della matrice
	puts("Inserisci la matricola dello studente");
	int cercaMatr = inputScelta(0, numMatricola);
	return cercaMatr;
}

int inputAnnoStud () {
	//funzione per l'inserimento dell'anno
	puts("Inserisci l'anno di corso nel quale vuoi cercare lo studente (ES: se 2013/2014, inserisci 2013)");
	int cercaAnno = inputScelta(2013, 3000);
	return cercaAnno;
}

/*----------------------------------------------------------------------------------------*/

void stampaInfoEdEsami (Stud *studCercato) {

	Esame *tempEsame = NULL;
	tempEsame = studCercato->testaEsame;
	printf("Matricola: %d\n", studCercato->matricola);
	printf("Studente: %s %s\n", studCercato->nome, studCercato->cognome);
	printf("Iscritto al corso %d / %d\n", studCercato->annoIscritto, (studCercato->annoIscritto + 1));
	if (tempEsame == NULL) {
		printf("Lo studente non ha ancora dato esami");
	} else {
		while (tempEsame != NULL) {
			printf("Esame: %s (%d)  VOTO: %d\n", tempEsame->nomeEsame, tempEsame->idEsame, tempEsame->voto);
			tempEsame = tempEsame->next;
		}
		printf("Esami dati: %d - Media: %d", studCercato->numEsamiDati, (studCercato->sommaVoti/studCercato->numEsamiDati));
	}
}

void stampaInfoEdEsamiPerAnno (AnnoAccademico **testaAA, int cercaAnno) {

	if ((*testaAA)->testaStud == NULL) {
		printf("Non è stato inserito alcuno studente!");
		return;
	}

	AnnoAccademico *tempAA;
	tempAA = *testaAA;
	Stud *tempStud;
	int trovato = FALSE;
	//trovo l'anno e quando lo trovo stampo ogni studente
	while (tempAA != NULL) {
		if (tempAA->annoPartenza == cercaAnno) {
			trovato = TRUE;
			tempStud = tempAA->testaStud;
			while (tempStud != NULL) {
				stampaInfoEdEsami(tempStud);
				printf("\n");
				tempStud = tempStud->next;
			}
			break;
		}
		tempAA = tempAA->next;
	}
	if (trovato == FALSE) {
		printf("L'anno di corso inserito non è presente in lista!");
	}
}

/*----------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------*/
//ANNO ACCADEMICO
/*----------------------------------------------------------------------------------------*/

int nuovoAA(AnnoAccademico **testaAA) {

	/*dichiaro e alloco una nuova cella di tipo AnnoAccademico*/
	AnnoAccademico *nuovoAA = NULL;
	nuovoAA = (AnnoAccademico*)malloc(sizeof(AnnoAccademico));
	if (nuovoAA == NULL) {
		printf("Memoria insufficiente");
		return 0;
	}

	/*inserisco il nuovo anno in testa alla lista principale (degli anni)*/
	nuovoAA->testaStud = NULL;
	nuovoAA->next = *testaAA;
	*testaAA = nuovoAA;

	int tempAnnoPartenza;
	int tempAnnoFine;

	int annoMinimo = 0;
	AnnoAccademico *tempAnno;
	tempAnno = *testaAA;


	/*prendo in input l'anno di inizio del corso*/
	printf("Inserire anno di inizio (a partire dal 2013)\n");

	/*ciclo per far inserire solo anni che sono di volta in volta successivi (se si inserisce il 2013, poi non si può inserire il 2012*/
	if (tempAnno->next != NULL) {
		tempAnno = tempAnno->next;
	}
	if (tempAnno->annoPartenza == 0) {
		annoMinimo = 2013;
	} else if (annoMinimo <=  tempAnno->annoPartenza) {
		annoMinimo = tempAnno->annoPartenza + 1;
	}

	/*input anno*/
	tempAnnoPartenza = inputScelta(annoMinimo, 3000);
	tempAnnoFine = tempAnnoPartenza + 1; /*il corso finisce ovviamente l'anno successivo. ad es 2013/2014*/
	nuovoAA->annoPartenza = tempAnnoPartenza;
	nuovoAA->annoFine = tempAnnoFine;
	printf("ANNO ACCADEMICO: %d / %d\n",tempAnnoPartenza, tempAnnoFine);

	/*faccio scegliere all'utente se c'è il numero chiuso o no, e se si di quanti studenti è*/
	printf("È presente il numero chiuso? *c'è comunque un tetto massimo di %d studenti*\n", MAXSTUDENTITOT);
	puts("1 » Si");
	puts("2 » No");
	int scelta = inputScelta(1, 2);
	int maxStud;
	switch (scelta) {
		case 1:
			puts("Qual è il tetto massimo?\n");
			maxStud = inputScelta(1, 1000);
			nuovoAA->numeroProgrammato = maxStud;
			break;
		case 2:
			puts("Non c'è un tetto massimo di studenti");
			nuovoAA->numeroProgrammato = FALSE; /*se numero programmato è = 0 vuol dire che non c'è un tetto*/
			break;
	}

	/*faccio inserire il numero di iscritti al corso*/
	printf("Quanti studenti si sono scritti all'anno accademico %d / %d\n", tempAnnoPartenza, tempAnnoFine);
	int numIscritti = 0;
	if (nuovoAA->numeroProgrammato == 0) {
		numIscritti = inputScelta(1, MAXSTUDENTITOT);
	} else {
		numIscritti = inputScelta(1, maxStud);
	}
	nuovoAA->idAnno = contaAnni;
	contaAnni++;
	return 1;
} //OK OK


/*----------------------------------------------------------------------------------------*/
//STUDENTE
/*----------------------------------------------------------------------------------------*/

int mainStud (AnnoAccademico **testaAA, Stud **testaStud, Esame **testaEsame, Esame listaEsami[]) {

	int esci, scelta, esito, maxScelta, cercaAnno, cercaMatr;
	Stud *studCercato;
	do {
		fpurge(stdin);
		scelta = menuStud(maxScelta);
		esci = FALSE;
		maxScelta = 6;
		switch (scelta) {
			case 1:
				/*inserisci studente*/
				esito = inserisciStudente (*testaAA, listaEsami);
				if (esito == 1) {
					puts("Nuovo studente inserito con successo!");
				} else if (esito == 0){
					puts("Errore nell'inserimento dello studente!");
				}
				printf("\n\n");
				break;
			case 2:
				printf("Che informazioni si desidera stampare?\n1 » Specifico studente\n2 » Intero anno\n");
				/*stampa informazioni*/
				scelta = inputScelta(1, 2);
				if (scelta == 1) {
					cercaAnno = inputAnnoStud();
					cercaMatr = inputMatrStud();
					studCercato = ricercaStudente(testaAA, cercaAnno, cercaMatr);
					if (studCercato != NULL) {
						stampaInfoEdEsami(studCercato);
					}
				} else {
					cercaAnno = inputAnnoStud();
					stampaInfoEdEsamiPerAnno(testaAA, cercaAnno);
				}

				break;
			case 3:
				/*modifica curriculum*/
				cercaAnno = inputAnnoStud();
				cercaMatr = inputMatrStud();
				esito = modificaCurriculum(testaAA, listaEsami, cercaAnno, cercaMatr);
				if (esito == 1) {
					puts("Update del curriculum effettuato con successo!");
				} else if (esito == 0){
					puts("Errore nell'update del curriculum!");
				}
				printf("\n\n");
				break;
			case 4:
				esito = esameNonDato(testaAA);
				break;
			case 5:
				esito = annoMediaMaggiore(testaAA);
				break;
			case 6:
				/*esci*/
				esci = TRUE;
				break;
		}
	}while (esci == FALSE);
    printf("\n\n");
    return 0;

	
	return 1;
}

int menuStud (int maxScelta) {
    int scelta;
	puts("\n\n• • • M E N U • • •");
	puts("1 » Inserisci studente");
	puts("2 » Stampa informazioni");
	puts("3 » Modifica curriculum");
	puts("4 » Studenti che non hanno dato un esame");
	puts("5 » Anno con media maggiore");
	puts("6 » Esci");

	do {
		fpurge(stdin);
		printf("				» ");
	}while (scanf("%d", &scelta) != 1 || scelta < 1 || scelta > maxScelta);
	return scelta;
}


/*----------------------------------------------------------------------------------------*/

int inserisciStudente (AnnoAccademico *testaAA, Esame listaEsami[]) {
	printf("Inserisci nuovo studente:\n");

	/*alloco spazio per nuovo studente*/
	Stud *nuovoStud = NULL;
	nuovoStud = (Stud*)malloc(sizeof(Stud));
	if (nuovoStud == NULL) {
		printf("Memoria insufficiente!");
		return 0;
	}
	nuovoStud->testaEsame = NULL;

	/*riempio i campi del nuovo studente*/
	nuovoStud->matricola = numMatricola++;
	printf("Matricola » %d\n", nuovoStud->matricola);
	fpurge(stdin);

	char nome[20];
	printf("Nome » ");
	gets(nome);
	strcpy(nuovoStud->nome, nome);
	fpurge(stdin);

	char cognome[20];
	printf("Cognome » ");
	gets(cognome);
	strcpy(nuovoStud->cognome, cognome);
	fpurge(stdin);

	printf("Anno Accademico » ");
	scanf("%d", &nuovoStud->annoIscritto); //modifica funzione input per passare inizio fine input

	//chiedo se si vuole modificare anche il curriculum
	int avvenutaIscrizione = iscriviStudenteInLista(&testaAA, nuovoStud);
	int scelta, modCurriculum;
	if (avvenutaIscrizione == 1) {
		puts("Studente correttamente iscritto");
		contaStudenti++;
		printf("\nVuoi modificare il curriculum dello studente?\n1 » Si\n2 » No\n");
		scelta = inputScelta(1, 2);
		if (scelta == 1) {
			modCurriculum = modificaCurriculum(&testaAA, listaEsami, nuovoStud->annoIscritto, nuovoStud->matricola);
		}
		return 1;
	} else {
		puts("Errore nell'inserimento. Anno scolastico non trovato.");
		numMatricola--;
		free(nuovoStud);
		return 0;
	}
} // OK

int iscriviStudenteInLista(AnnoAccademico **testaAA, Stud *nuovoStud) {
	AnnoAccademico *tempAA;
	tempAA = *testaAA;

	int trovato = FALSE;

	while (tempAA != NULL) {
		if (tempAA->annoPartenza == nuovoStud->annoIscritto) {
			trovato = TRUE;
			break;
		}
		tempAA = tempAA->next;
	}
	static int numIscritti = 0;


	if (trovato == TRUE) {
		if (tempAA->testaStud == NULL) {
			tempAA->testaStud = nuovoStud;
		} else {
			nuovoStud->next = tempAA->testaStud;
			tempAA->testaStud = nuovoStud;

		}
		tempAA->iscritti = numIscritti++;
		return 1;
	} else {
		return 0;
	}
} // OK


/*----------------------------------------------------------------------------------------*/

int modificaCurriculum (AnnoAccademico **testaAA, Esame listaEsami[], int cercaAnno, int cercaMatr) {

	if ((*testaAA)->testaStud == NULL) {
		printf("Non è stato inserito alcuno studente!\n");
		return 0;
	}

	int votazione, sceltaEsame;

	Stud *studCercato = ricercaStudente(testaAA, cercaAnno, cercaMatr);
	if (studCercato == NULL) {
		return 0;
	}

	Esame *nuovoEsame;
	nuovoEsame = (Esame*)malloc(sizeof(Esame));
	if (nuovoEsame == NULL) {
		puts("Memoria insufficiente!");
		return 0;
	}

	nuovoEsame->next = studCercato->testaEsame;
	studCercato->testaEsame = nuovoEsame;

	/*selezione esame*/
	puts("Selezionare un esame e inserirne la votazione");
	stampaEsami();
	sceltaEsame = inputScelta(1, TOTESAMI);

	/*inizializzo il nuovo esame dello studente*/
	nuovoEsame->idEsame = listaEsami[sceltaEsame].idEsame;
	strcpy(nuovoEsame->nomeEsame, listaEsami[sceltaEsame - 1].nomeEsame);

	puts("Inserire votazione (max 31 lode)");
	votazione = inputScelta(0, 31);
	nuovoEsame->voto = votazione;

	studCercato->sommaVoti += votazione;
	studCercato->numEsamiDati += 1;

	printf("Esame correttamente inserito!\n");

	printf("Inserire un altro esame?\n1 » Si\n2 » No\n");
	int modCurriculum;
	int scelta = inputScelta(1, 2);
	if (scelta == 1) {
		modCurriculum = modificaCurriculum(testaAA, listaEsami, cercaAnno, cercaMatr);
	} else {
		return 1;
	}
	return 1;
}

void stampaEsami () {
	puts("• • • Quale esame è stato dato? • • •");
	puts("1 » ANALISI");
	puts("2 » PROGRAMMAZIONE");
	puts("3 » ALGORITMI E STRUTTURE DATI");
	puts("4 » ALGEBRA E GEOMETRIA");
	puts("5 » ARCHITETTURA DEGLI ELABORATORI");
	puts("6 » PROGRAMMAZIONE A OGGETTI");
	puts("7 » ALGORITMI NUMERICI");
	puts("8 » SISTEMI AUTOMATICI");
	puts("9 » BASI DI DATI");
	puts("10» STATISTICA E PROBABILITÀ");
}


/*----------------------------------------------------------------------------------------*/

int esameNonDato (AnnoAccademico **testaAA) {

	if ((*testaAA)->testaStud == NULL) {
		printf("Non è stato inserito alcuno studente!");
		return 0;
	}

	AnnoAccademico *tempAA = NULL;
	tempAA = *testaAA;

	Stud *tempStud = NULL;
	Esame *tempEsame = NULL;

	stampaEsami();
	int idEsameCercato = inputScelta(1, TOTESAMI);
	int trovato = FALSE;
	int contaEsami = 0, contaStud = 0;

	while (tempAA != NULL) {
		tempStud = tempAA->testaStud;
		while (tempStud != NULL) {
			tempEsame = tempStud->testaEsame;
			while (tempEsame != NULL) {
				if (tempEsame->idEsame == idEsameCercato) {
					contaEsami++;
					contaStud++;
					trovato = TRUE;
					break;
				}
				contaStud++;
				tempEsame = tempEsame->next;
			}
			if (trovato == FALSE) {
				stampaInfoEdEsami(tempStud);
				puts("");
			}
			trovato = FALSE;
			printf("\n");
			tempStud = tempStud->next;
		}
		tempAA = tempAA->next;
	}
	if (contaEsami == contaStud) {
		printf("Tutti gli attuali iscritti all'Università hanno dato questo esame!");
	}

	return 1;
}

int annoMediaMaggiore (AnnoAccademico **testaAA) {

	if ((*testaAA)->testaStud == NULL) {
		printf("Non è stato inserito alcuno studente!");
		return 0;
	}

	AnnoAccademico *tempAA = NULL;
	tempAA = *testaAA;

	Stud *tempStud = NULL;

	int *vettVoti;
	vettVoti = (int*)malloc(sizeof(int));
	int tempSommaVoti = 0;
	int max = 0;
	int annoMax = 0;
	int contaEsami = 0;
	int dim = 0;
	//scorro gli anni
	while (tempAA != NULL) {
		tempStud = tempAA->testaStud;
		tempSommaVoti = 0;
		contaEsami = 0;
		//scorro gli studenti dell'anno
		while (tempStud != NULL) {
			tempSommaVoti += tempStud->sommaVoti;
			contaEsami += tempStud->numEsamiDati;
			tempStud = tempStud->next;
		}
		//incremento la media
		if (tempSommaVoti > 0 && contaEsami > 0) {
			vettVoti = realloc(vettVoti, sizeof(int) * dim);
			vettVoti[dim] = (tempSommaVoti / contaEsami);
			dim++;
			tempAA = tempAA->next;
		}
	}

	//trovo la media maggiore
	int k = 0;
	for (int j = dim; j > 0; j--) {
		if (vettVoti[k] > max) {
			max = vettVoti[k];
			annoMax = (j - 1);
		}
		k++;
	}


	tempAA = *testaAA;
	while (tempAA != NULL) {
		if (tempAA->idAnno == annoMax) {
			printf("La media maggiore è stata trovata nel corso %d / %d ed è di un punteggio di %d\n", tempAA->annoPartenza, tempAA->annoFine, max);
			break;
		}
		tempAA = tempAA->next;
	}

	return 1;
}



