//
//  Esecizio3.c
//
//  Creato da Alberto Giunta il 30/11/13.
//  Maticola: 0000691428

/*La segreteria del nostro Corso di Laurea ci chiede di sviluppare un programma per la gestione degli studenti. 
 Di ogni studente si vogliono mantenere tutte le informazioni anagrafiche e quelle relative al curriculum. 
 Il programma deve permettere di eseguire le principali operazioni di gestione dell’archivio, quali l’aggiunta di un nuovo studente, la cancellazione di uno studente, la visualizzazione di tutti gli studenti. 
 Il programma deve inoltre permettere la ricerca di uno studente e la conseguente stampa di tutti i suoi voti e la ricerca degli studenti che ancora non hanno sostenuto uno specifico esame.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
#define FALSE 0


typedef struct studente {
	int matricola;
	char nome[20];
	char cognome[20];
	int prog;
	int ana;
	struct studente *next; /*puntatore al prossimo nodo*/
} stud;



stud *testa = NULL; //puntatore al primo elemento

/*prototipi funzioni*/
int menu();
void inserStud();
void elimStud();
void stampaStud ();
void stampaVotiStud ();
int menu2();
void stampaBocciati ();
void nonDatoProg();
void nonDatoAna();

/*variabili globali*/
int esci = FALSE;
int numeroMat = 0;
int vettBocciati[2] = {0};

int main() {

	int scelta;
	do {
		fpurge(stdin);
		scelta = menu();
		esci = FALSE;
		switch (scelta) {
			case 1:
				/*Aggiungi nuovo studente*/
				printf("\n\n");
				inserStud();
				break;
			case 2:
				/*Rimuovi studente*/
				elimStud();
				break;
			case 3:
				/*Stampa studenti*/
				stampaStud();
				break;
			case 4:
				/*Ricerca studente per report voti"*/
				stampaVotiStud ();
				break;
			case 5:
				/*Ricerca studente che non ha dato un esame"*/
				stampaBocciati ();
				break;
			case 6:
				/*Esci*/
				esci = TRUE;
				break;
		}
	}while (esci == FALSE);

	printf("\n\n");

	return 0;
}

int menu() {
	int scelta;
	puts("\n\n                   M E N U                  ");
	puts("1 » Aggiungi nuovo studente");
	puts("2 » Rimuovi studente");
	puts("3 » Stampa studenti");
	puts("4 » Ricerca studente per report voti");
	puts("5 » Ricerca studente che non ha dato un esame");
	puts("6 » Esci");
	do {
		fpurge(stdin);
		printf("				» ");
	}while (scanf("%d", &scelta) != 1 || scelta < 1 || scelta > 6);
	return scelta;
} //menu OK

void inserStud () {

	struct studente *nuovo;
	nuovo = (stud*)malloc(sizeof(stud)); //nuovo puntatore a un elemento stud come lo è testa
	if (nuovo == NULL) {
		printf("Memoria non sufficiente!");
	}
	nuovo->next = testa; //faccio seguire all'elemento inserito il vecchio primo elemento
	testa = nuovo; //ora testa punta all'elemento appena inserito, che è il primo nuovo elemento

	printf("MATRICOLA\n");
	numeroMat++;
	printf("				» %d", numeroMat);
	nuovo->matricola = numeroMat; //incrementa sempre, perchè come le targhe, anche quando una macchina viene demolita, il suo numero di targa non viene dato ad altri.

	printf("\nNOME\n");
	printf("				» ");
	scanf("%s", nuovo->nome);

	printf("\nCOGNOME\n");
	printf("				» ");
	scanf("%s", nuovo->cognome);


	printf("\nVOTO ESAMI       -1 -> Esame non dato\n");
	printf("PROGRAMMAZIONE\n");
	do {
		fpurge(stdin);
		printf("				» ");
	} while (scanf("%d", &nuovo->prog) != 1 || nuovo->prog < -1 || nuovo->prog > 31);
	if (nuovo->prog < 18) {
		vettBocciati[0]++;
	}

	printf("ANALISI\n");
	do {
		fpurge(stdin);
		printf("				» ");
	} while (scanf("%d", &nuovo->ana) != 1 || nuovo->ana < -1 || nuovo->ana > 31);
	if (nuovo->ana < 18) {
		vettBocciati[1]++;
	}


} //inserisci studente OK

void elimStud () {

	stud *prec;
	prec = NULL;


	stud *temp;
	temp = testa;

	int elimMat;
	printf("MATRICOLA DA ELIMINARE\n");
	do {
		fpurge(stdin);
		printf("				» ");
	} while (scanf("%d", &elimMat) != 1 || elimMat < 1);

	while (temp != NULL) {
		if (temp->matricola == elimMat) {
			if (prec == NULL) {
				testa = testa->next;
			} else {
				prec->next = temp->next;
			}
			free(temp);
			break;
		}
		prec = temp;
		temp = temp->next;
	}
} //elimina studente OK

void stampaStud () {
	stud *temp;
	temp = testa;

	while (temp != NULL) {
		printf("» %s %s\n", temp->nome, temp->cognome);
		printf("  MATRICOLA	     » %d", temp->matricola);
		printf("\n  ANALISI:        » ");
		if (temp->ana == -1) {
			printf("Esame non dato");
		}else {
			printf("%d", temp->ana);
		}
		printf("\n  PROGRAMMAZIONE: » ");
		if (temp->prog == -1) {
			printf("Esame non dato");
		}else {
			printf("%d", temp->prog);
		}
		printf("\n\n");
		temp = temp->next;

	}

} //stampa tutti studenti OK (ordine cronologico o crescente di matricola? fai la scelta?

void stampaVotiStud () {

	stud *temp;
	temp = testa;

	int cercaMat;
	printf("MATRICOLA DA CERCARE\n");
	do {
		fpurge(stdin);
		printf("				» ");
	} while (scanf("%d", &cercaMat) != 1 || cercaMat < 1);

	//finchè non viene raggiunta la fine della lista
	while (temp != NULL) {
		if (temp->matricola == cercaMat) { //se la matricola della cella corrisponde a quella ricercata
			printf("» %s %s\n", temp->nome, temp->cognome);
			printf("  MATRICOLA	     » %d", temp->matricola);
			printf("\n  ANALISI:        » ");
			if (temp->ana == -1) {
				printf("Esame non dato");
			}else {
				printf("%d", temp->ana);
			}
			printf("\n  PROGRAMMAZIONE: » ");
			if (temp->prog == -1) {
				printf("Esame non dato");
			}else {
				printf("%d", temp->prog);
			}
		}
		temp = temp->next;
	}
} //stampa voti studente OK

int menu2() {
	int scelta;
	puts("\n\n                   M E N U                  ");
	puts("1 » Alunni che non hanno dato PROGRAMMAZIONE");
	puts("2 » Alunni che non hanno dato ANALISI");
	puts("3 » Esci");
	do {
		fpurge(stdin);
		printf("				» ");
	}while (scanf("%d", &scelta) != 1 || scelta < 1 || scelta > 3);
	return scelta;
} //menu2 OK

void stampaBocciati () {

	int scelta;

	do {
		esci = FALSE;
		fpurge(stdin);
		scelta = menu2();
		esci = FALSE;
		switch (scelta) {
			case 1:
				/*PROGRAMMAZIONE*/
				nonDatoProg();
				break;
			case 2:
				/*ANALISI*/
				nonDatoAna();
				break;
			case 3:
				/*Esci*/
				esci = TRUE;
				break;
		}
	}while (esci == FALSE);
}//stampa voti studente OK

void nonDatoProg () {
	//programmazione non dato
	stud *temp;
	temp = testa;

	while (temp != NULL) {
		if (temp->prog == -1) {
			printf("» %s %s\n", temp->nome, temp->cognome);
			printf("  MATRICOLA	     » %d\n\n", temp->matricola);
		}
		temp = temp->next;
	}
}

void nonDatoAna () {
	//analisi non dato
	stud *temp;
	temp = testa;

	while (temp != NULL) {
		if (temp->ana == -1) {
			printf("» %s %s\n", temp->nome, temp->cognome);
			printf("  MATRICOLA	     » %d\n\n", temp->matricola);
		}
		temp = temp->next;
	}
}
