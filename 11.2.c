//esercizio 1 - alberto giunta

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// /Users/albertogiunta/

/*prototipi funzioni*/
char inserisciCar();
void read(FILE *fp);
FILE* inputNome (FILE *fp, char mode);
void filecopy (FILE *inFile, FILE *outFile);
char scegliCarattere ();


int main () {
	FILE *fi = NULL;
	FILE *fo = NULL;
	char mode;
	printf("File in lettura\n");
	fpurge(stdin);
	mode = 'r';
	fi = inputNome(fi, mode);
	if  (fi == NULL) {
		printf("Nome errato!\n");
		exit(1);
	}
	printf("File in scrittura\n");
	fpurge(stdin);
	mode = 'w';
	fo = inputNome(fo, mode);

    if  (fi == NULL || fo == NULL) {
		printf("Nome errato!\n");
		exit(1);
	} else {
		filecopy(fi, fo);
	}

	printf("Controlla il file di output!");
	fclose(fi);
	fclose(fo);
    printf("\n\n\n");
    return 0;
}

FILE* inputNome (FILE *fp, char mode) {
    char nome[40];
    printf("Nome file: ");
	scanf("%s", nome);

    if ((fp = fopen(nome, &mode)) == NULL) {
        return NULL;
    }
    return fp;
}

void read(FILE *file) {
    char c;
    while ((fscanf(file, "%c", &c)) > 0) {
        printf("%c", c);
    }
}

void filecopy (FILE *inFile, FILE *outFile) {
	char c;
	printf("Primo carattere » ");
	int car1 = inserisciCar();
	printf("Secondo carattere » ");
	int car2 = inserisciCar();

	while (fscanf(inFile, "%c", &c) > 0) {

		if (c == car1) {
			c = car2;
		} else if (c == car2) {
			c = car1;
		} else if (c == (car1 - 32)) {
			c = (car2 - 32);
		} else if (c == (car2 - 32)) {
			c = (car1 - 32);
		}

		//perchè con lo switch non funziona??

		fprintf(outFile, "%c", c);
	}
	fclose(outFile);
}

char inserisciCar () {
	int scelta;
	fpurge(stdin);
    scelta = scegliCarattere();
	scelta = tolower(scelta);
	return scelta;
}

char scegliCarattere () {
    char car;
    printf("        » ");
    scanf("%c", &car);
    return car;
}