/*
 Si desidera sviluppare un programma in linguaggio C per gestire un registro di esame memorizzato in un file di testo con nome registro.txt che contiene i dati di N studenti, ove N è il numero intero scritto nella prima riga del file.
 Dopo questa prima riga, ogni riga successiva contiene il dato relativo ad un singolo studente, individuato dal suo numero di matricola (numero intero compreso 1 e 999999) e il voto conseguito in una specifica materia (numero intero con valore tra 18 e 30, oppure zero per indicare che l’esame non è ancora stato sostenuto). 
 Il programma deve gestire una modalità statistica e una modalità inserimento. 
 La prima modalità deve fornire le seguenti statistiche: numero di studenti promossi (e relativa percentuale sul totale) e voto medio degli studenti promossi. 
 La seconda modalità riceve come parametro il numero di matricola di uno studente e il voto conseguito dallo studente nell’ esame. 
 Il programma deve inserire nel file il voto dello studente, segnalando però errore nel caso che lo studente non sia iscritto all’esame (ossia il suo numero di matricola non compaia nel file) oppure abbia già superato l’esame (ossia voto diverso da zero nella riga contenente la sua matricola).
*/

/* cartella del file:
/Users/albertogiunta/
*/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0


/*protitipi funzioni*/
int menu();
FILE* open(FILE *fileOpen);
int inputNum (int max, int min);
int numeroStudenti (FILE *file, int numStud);
void stat(FILE *file, int numStud);
void modifica(FILE *file);
void salvaFile(int trovato);


/*corpo*/
int main () {
	FILE *file = NULL;
	file = open(file);

	int numStud = 0, esci = FALSE, scelta;

	/*prendo il numero di studenti iscritti all'esame*/
	numStud = numeroStudenti(file, numStud);
	fclose(file);

	do {
		scelta = menu();
		switch (scelta) {
			case 1:
				/*cerca matricola e modifica voto*/
				modifica(file);
				break;
			case 2:
				/*richiamo la funzione stampare la statistica sui voti*/
				stat(file, numStud);
				break;
			case 3:
				esci = TRUE;
				break;
		}
	} while (esci == FALSE);

	printf("\n\n");
	return 0;
}

int menu () {
	int scelta;
	printf("· · · M E N U · · ·\n");
	puts("1 » Inserisci voto cercando per matricola");
	puts("2 » Stampa statistiche sui voti delle matricole");
	puts("3 » ESCI");
	do {
		fpurge(stdin);
		printf("     » ");
	} while (scanf("%d", &scelta) != 1 || scelta < 1 || scelta > 3);
	printf("\n");
	return scelta;
}

FILE* open (FILE *fileOpen) {
	fileOpen = fopen("/Users/albertogiunta/registro.txt", "r");
	if (fileOpen == NULL) {
		printf("Erarore in lettura del file");
		exit(1);
	}
	return fileOpen;
}

int inputNum (int min, int max) {
	int val;
	do {
		fpurge(stdin);
		printf("          » ");
	} while (scanf("%d", &val) != 1 || val < min || val > max);
	return val;
}

int numeroStudenti (FILE *file, int numStud) {
	/*leggo una riga (la prima)*/
	fscanf(file, "%d", &numStud);
	return numStud;
}

void stat(FILE *file, int numStud) {
	file = open(file);

	int voto;
	int sommaVoti = 0, contaPromossi = 0;

	fscanf(file, "%d", &voto);
	/*incremento la sommatoria dei voti, e il conteggio dei promossi*/
	while (fscanf(file, "%d", &voto) > 0) {
		fscanf(file, "%d", &voto);
		if (voto > 17 && voto < 31) {
			sommaVoti += voto;
			contaPromossi++;
		}
	}

	fclose(file);
	printf("STUDENTI PROMOSSI » %d su %d (%d%c del totale)\n", contaPromossi, numStud, (contaPromossi * 100) / numStud, 37);
	printf("MEDIA » %d\n\n", sommaVoti/contaPromossi);

	fclose(file);
}

void modifica (FILE *file) {
	int cercaVoto, cercaMatr, trovato, numStud;

	/*prendo l'input di matricola e voto dello studente*/
	printf("\nInserisci matricola\n");
	int inputMatr = inputNum(1, 999999);

	printf("\nInserisci voto\n");
	int inputVoto = inputNum(18, 30);

	/*riapro il file contenente matricole e voti*/
	file = open(file);

	/*creo il file di appoggio temporaneo*/
	FILE *modFile = fopen("/Users/albertogiunta/registroMod.txt", "w");

	/*scrivo il numero di studenti nel file temporaneo*/
	fscanf(file, "%d", &numStud);
	fprintf(modFile, "%d\n", numStud);

	/*scorro tutto il file registro.txt*/
	while (fscanf(file, "%d", &cercaMatr) > 0) {

		/*stampo nel file temporano ogni matricola*/
		fprintf(modFile, "%d ", cercaMatr);

		/*faccio seguire la matricola dal voto*/
		/*se la matricola in questione è la stessa che è stata richiesta*/
		if (cercaMatr == inputMatr) {
			trovato = TRUE;
			fscanf(file, "%d", &cercaVoto);

			if (cercaVoto == 0) {

				/*e se l'esame non è ancora stato dato*/
				fprintf(modFile, "%d\n", inputVoto);
			} else {

				/*altrimenti ricopio il vecchio voto*/
				fprintf(modFile, "%d\n", cercaVoto);
				trovato = FALSE;
			}

		} else {

			/*prendo e ristampo il voto della matricola*/
			fscanf(file, "%d", &cercaVoto);
			fprintf(modFile, "%d\n", cercaVoto);
		}
	}
	salvaFile(trovato);

	fclose(file);
	fclose(modFile);
}

void salvaFile (int trovato) {
	if (trovato == FALSE) {
		/*se non è stata trovata la matricola, il lavoro fatto è inutile, quindi cancello il file temporaneo*/
		printf("\nLa matricola cercata non è iscritta all'esame o l'aveva già sostenuto!\n");
		remove("/Users/albertogiunta/registroMod.txt");
	} else {
		/*altrimenti cancello il file originale,  e rinomino il file temporaneo come il file originale*/
		remove("/Users/albertogiunta/registro.txt");
		rename("/Users/albertogiunta/registroMod.txt", "/Users/albertogiunta/registro.txt");
		printf("\nVoto correttamente modificato!\n");
	}
}


