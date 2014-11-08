/*Si desidera sviluppare un programma in linguaggio C per il calcolo delle statistiche sui caratteri presenti in un file di testo.
 Il programma deve considerare tutti i caratteri tranne quelli di spaziatura e fornire su un file di output le informazioni relative a:
 » il numero di righe di cui è composto il testo
 » il numero totale di caratteri (esclusi quelli di spaziatura) presenti nel testo
 • il numero massimo e medio di caratteri di una riga
 • la riga più lunga incontrata nel file.
 */


#include <stdio.h>
#include <stdlib.h>


/*prototipi funzioni*/
FILE* open (FILE *fileOpen);
void analizzaTesto (FILE* file);
void stampaStatistica (int contaRighe, int contaCarTor, int media, int maxCar, char *ptr);
void copiaStatisticaInFile (int contaRighe, int contaCarTor, int media, int maxCar, char *ptr);

int main () {
	/*dichiaro il file*/
	FILE *file = NULL;

	/*richiamo la funzione di conteggio dei caratteri*/
	analizzaTesto(file);
	printf("\n\n");
    return 0;
}

FILE* open (FILE *fileOpen) {
	/*apro il file*/
	fileOpen = fopen("/Users/albertogiunta/testo.txt", "r");
	/*controllo che si presente*/
	if (fileOpen == NULL) {
		printf("Erarore in lettura del file");
		exit(1);
	}
	/*restituisco il puntatore al file aperto*/
	return fileOpen;
}

void analizzaTesto (FILE* file) {
	/*apro il file*/
	file = open(file);
	int *carattRiga = NULL, media = 0, contaRighe = 0, contaCarTot = 0, maxCar = 0, parziale = 0, indexMaxCar, contaSpazi = 0, spaziMaxCarRiga, start = 0;
	char *maxRiga = NULL, c;

	/*vettore dinamico contente il numero di caratteri di ogni riga*/
	carattRiga = (int*)malloc(sizeof(int));

	do {
		fpurge(stdin);
		do {
			fpurge(stdin);
			/*prendo un carattere dal file*/
			c = fgetc(file);
			/*controllo che non sia l'EOF*/
			if (feof(file)) {
				break;
			}
			/*se è diverso dallo spazio incremento il numero di caratteri, altrimenti il numero di spazi (che mi serve per calcolare
			 la reale lunghezza della riga più lunga*/
			c != 32 ? contaCarTot++ : contaSpazi++;
			/*faccio questo finchè non si raggiunge il punto (ovvero la fine della frase)*/
		} while (c != 10);

		/*quando incontra un invio a capo*/

		/*controllo che non si sia arrivati all'EOF*/
		if (feof(file)) {
			if (contaCarTot == 0) {
				printf("Il file è vuoto!!!\n\n");
				exit(1);
			}
			break;
		}


			contaRighe++;
			/*realloco il vettore contente il numero di caratteri per ogni riga*/
			carattRiga = realloc(carattRiga, sizeof(int) * (contaRighe));
			/*assegno alla cella il valore dei caratteri totali fin'ora trovati diminuito del valore dei caratteri trovati fino al passaggio precedente*/
			carattRiga[contaRighe - 1] = contaCarTot - parziale;

			/*se il numero di caratteri della riga è maggiore del massimo precedente entro nell'if*/
			if (carattRiga[contaRighe - 1] > maxCar) {
				/*assegno al massimo dei caratteri il valore della riga corrente*/
				maxCar = carattRiga[contaRighe - 1];
				/*salvo l'indice della riga di lunghezza massima*/
				indexMaxCar = contaRighe - 1;
				/*salvo il numero di spazi della riga di lunghezza massima*/
				spaziMaxCarRiga = contaSpazi;
			}

			/*azzero il conteggio degli spazi*/
			contaSpazi = 0;
			/*incremento la somma parziale dei caratteri*/
			parziale += carattRiga[contaRighe - 1];


		/*è un ciclo infinito, deve uscire solo quando trova l'EOF*/
	}while (1);

	/*calcolo la media dei caratteri per ogni riga*/
	media = contaCarTot / contaRighe;
	/*chiudo il file*/
	fclose(file);

	/*maxRiga è un vettore dinamico che conterrà la frase di lunghezza maggiore*/
	maxRiga = (char*)malloc(sizeof(char) * maxCar);
	if (maxRiga == NULL) {
		printf("Errore nell'allocazione della memoria!");
		exit(1);
	}
	/*riapro il file*/
	file = open(file);

	/*tramite l'indiche memorizzato prima, ricorro alla frase più lunga e la memorizzo*/
	for (int i = start; i <= indexMaxCar; i++) {
		fgets(maxRiga, maxCar + spaziMaxCarRiga, file);
	}

	fclose(file);

	stampaStatistica(contaRighe, contaCarTot, media, maxCar, maxRiga);
	copiaStatisticaInFile(contaRighe, contaCarTot, media, maxCar, maxRiga);

	free(carattRiga);
}

void stampaStatistica (int contaRighe, int contaCarTor, int media, int maxCar, char *ptr) {
	/*stampo a video le statistiche*/
	printf("%s %d\n", "Numero righe » ", contaRighe);
	printf("%s %d\n", "Numero totale caratteri » ", contaCarTor);
	printf("%s %d\n", "Media caratteri per riga » ", media);
	printf("%s %d\n", "Lunghezza della riga più lunga » ", maxCar);
	printf("\n%s\n%s\n", "Testo della riga di lunghezza maggiore:", ptr);
}

void copiaStatisticaInFile (int contaRighe, int contaCarTor, int media, int maxCar, char *ptr) {
	/*dichiaro e creo un file .txt per memorizzare le statistiche del suddetto testo*/
	FILE *fileValori = NULL;
	fileValori = fopen("/Users/albertogiunta/statisticaTesto.txt", "w");

	fprintf(fileValori, "%s %d\n", "Numero righe » ", contaRighe);
	fprintf(fileValori, "%s %d\n", "Numero totale caratteri » ", contaCarTor);
	fprintf(fileValori, "%s %d\n", "Media caratteri per riga » ", media);
	fprintf(fileValori, "%s %d\n", "Lunghezza della riga più lunga » ", maxCar);
	fprintf(fileValori, "\n%s\n%s\n", "Testo della riga di lunghezza maggiore:", ptr);
    
	fclose(fileValori);
}


