//
//  Esercizio3.c
//
//  Creato da Alberto Giunta il 28/10/13
//  Matricola: 0000691428

/*Scrivere un programma C che gestisca l’archivio dei componenti presenti in un magazzino. Il programma deve lavorare su un vettore (componenti) di strutture, dove ognuna di queste contiene le informazioni su un componente: identificativo del componente, nome del componente, quantità del componente presente in magazzino. Gestire poi un ulteriore vettore (ordini) di strutture dove ognuna di queste contiene le informazioni relative a un ordine di acquisto: identificativo ordine, identificativo componente, quantità richiesta. Il programma deve: 
 • Aggiungere un nuovo componente nell’archivio componenti (quindi nuovo identificativo, nuovo nome e nuova quantità iniziale) stampando un messaggio di errore se il componente è già presente o se l’archivio è pieno 
 • Dato l’identificativo di un componente stamparne il nome e la quantità disponibile se il componente è presente, un messaggio di errore in caso contrario 
 • Dato l’identificativo di un componente modificare la quantità disponibile stampando un messaggio di errore se il componente non è presente nell’archivio 
 • Stampare tutte le informazioni dell’archivio nell’ordine con cui sono inserite
 • Aggiungere un nuovo ordine nell’archivio ordini (quindi nuovo identificativo ordine, nuovo identificativo componente e nuova quantità richiesta) stampando un messaggio di errore se l’ordine è già presente o se l’archivio è pieno 
 • Verificare se gli ordini possono essere evasi, cioè se la quantità richiesta è inferiore a quella presente in magazzino, nel qual caso aggiornare le informazioni di magazzino e cancellare tutti gli ordini.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 //Ampiezza database


//STRUTTURA COMPONENTI
typedef struct componenti
{
	int cp_idComp;
	char cp_nome[50];
	int cp_qtaMag;
}comp;


//STRUTTURA ORDINI
typedef struct ordini
{
	int or_idOrd, or_idComp, or_qtaOrd;
}ord;


int main () {
	
	int i = 0, j = 0, esci = 0, z = 0, x = 0, v = 0, k = 0, y = 0, n = 0, m = 0, trovato = 0, idComp;
	char scelta;
	int controllo = 0, nuovaQta;
	int ricerca;
	int lett;
	
	//Inizializzo le strutture
	comp numComp[MAX] ={ {1, "Vector Magic", 15}, {2, "Asta La Vista", 32}, {3, "Heiseneberg", 12} };
	ord numOrd[MAX] = { {1, 1, 10}, {2, 2, 130}, {3, 3, 12} };
	
	do {
		fpurge(stdin);
		
		
		/*MENU*/
		puts("\n");
		puts("--------*********--------");
		puts("******** M E N U ********");
		puts("--------*********--------");
		puts("\n");
		puts("1 -> Aggiungi nuovo componente");
		puts("2 -> Report componente");
		puts("3 -> Modifica quantità presente in magazzino");
		puts("4 -> Aggiungi nuovo ordine");
		puts("5 -> Verifica evasione ordini");
		puts("6 -> Report cronologico dell'archivio");
		puts("7 -> Esci");
		
		scelta = getchar();
		
		switch (scelta) {
			case '1':
				/* 1 -> AGGIUNGI NUOVO COMPONENTE */
				
				while (i < MAX) {

					if (numComp[i].cp_idComp == 0) {
						
						printf("\nINSERISCI NUOVO COMPONENTE\n");
						
						printf("ID componente: %d\n", i+1);	/*ID = INDIRIZZO DELLA PRIMA CELLA LIBERA DEL VETTORE*/
						numComp[i].cp_idComp = i+1;
						
						/*INSERIMENTO NOME*/
						unsigned long length;
						do {
							printf("NOME componente: ");
							scanf("%s", numComp[i].cp_nome);
							length = strlen(numComp[i].cp_nome);
							if (length > 50) puts("Nome troppo lungo (MAX 50 caratteri)");
						} while (length > 50);
						
						
						/*INSERIMENTO QUANTITÀ*/
						int lett;
						do {
							lett = 0;
							printf("Q.TÀ componente: ");
							fpurge(stdin);
							if (scanf("%d", &numComp[i].cp_qtaMag) != 1) {
								puts("Non hai inserito un numero, riprova");
								lett = 1;
							}
							
						} while (lett == 1);
						break;
					}else {
						i++;
					}
				
				}
				if (i == MAX) {
					printf("\n*** Il vettore è pieno, impossibile aggiungere altri componenti. ***");
				}
					
			break;
			
			case '2':
				/* 2 -> REPORT COMPONENTE */
				
				do {
					lett = 0;
					fpurge(stdin);
					
					printf("Inserisci ID: ");
					
					//Inserimento ID di ricerca
					if (scanf("%d", &ricerca) != 1) {
						puts("Inserisci un numero");
						lett = 1;
					} else {
						for (j = 0; j < MAX; j++) {
							if (numComp[j].cp_idComp == (ricerca) && ricerca > 0 && numComp[j].cp_idComp != 0) {
								controllo = 1;
								break;
							}
						}
						//Stampa report componente
						if (controllo == 1) {
							printf("ID: %d\n", numComp[j].cp_idComp);
							printf("NOME: %s\n", numComp[j].cp_nome);
							printf("QUANTITÀ: %d\n",numComp[j].cp_qtaMag);
						} else {
							printf("Hai inserito un ID non presente nel database");
						}
					}
				} while (lett == 1);
				
				break;
			
			case '3':
				/* 3 -> MODIFICA QUANTITÀ COMPONENTE */
				
				trovato = 0;
				do {
					fpurge((stdin));
					lett = 0;
					printf("Inserisci ID: ");
					if (scanf("%d", &ricerca) == 1) {
						for (m = 0; m < MAX; m++)
							
							//Ricerca componente
							if (ricerca > 0 && numComp[m].cp_idComp != 0 && ricerca == numComp[m].cp_idComp) {
								trovato = 1;
								
								do {
									lett = 0;
									fpurge(stdin);
									printf("Nome componente: \"%s\"\n", numComp[m].cp_nome);
									printf("Modificare la quantità presente in magazzino da %d a -->  ", numComp[m].cp_qtaMag);
									if (scanf("%d", &nuovaQta) == 1) {
										numComp[m].cp_qtaMag = nuovaQta;
									} else {
										puts("Inserisci un numero");
										lett = 1;
									}
								} while (lett == 1);
							}
						if (trovato == 0) {
								puts ("Hai inserito un ID non presente nel database");
							lett = 1;
							}
					} else {
						puts("Inserisci un numero");
						lett = 1;
					}
				} while (lett == 1);
				
				break;
			
			case '4':
				/* 4 -> AGGIUNGI NUOVO ORDINE */
				
				while (k < MAX) {
					
					if (numOrd[k].or_idOrd == 0) {
						printf("\nINSERISCI NUOVO ORDINE\n");
						printf("ID ordine: %d\n", k+1);
						numOrd[k].or_idOrd = k+1;
						do {
							lett = 0;
							fpurge(stdin);
							//Inserimento ID
							printf("ID componente: ");
							if (scanf("%d", &idComp) == 1) {
								for (y = 0; y < MAX; y++) {
									if (numComp[y].cp_idComp == idComp && idComp > 0) {
										numOrd[k].or_idComp = idComp;
										trovato = 1;
									}
								}
								if (trovato == 0) {
									puts("Hai inserito un ID non presente nel database.");
									lett = 1;
								}
							} else {
								puts("Inserisci un numero");
								lett = 1;
							}
							
						} while (lett == 1);
						//Inserimento quantità
						do {
							lett = 0;
							fpurge(stdin);
							printf("Q.TÀ da ordinare: ");
							if (scanf("%d", &numOrd[k].or_qtaOrd) != 1) {
								puts("Inserisci un numero");
								lett = 1;
							}
						} while (lett == 1);
						break;
						
					} else {
						k++;
					}
				}
				if (k == MAX) {
					printf("\n*** Il vettore è pieno, impossibile aggiungere altri ordini. ***");
				}
			break;
			
			case '5':
				
				/* 5 -> VERIFICA EVASIONE ORDINE */
				
				//Evade automaticamente tutti gli ordini evadibili
				printf("Sono stati evasi gli ordini di ID:\n\n");
				for (x = 0; x < MAX; x++) {
					
					if (numComp[x].cp_idComp != 0) {
						int idComp = numComp[x].cp_idComp;
						
						for (z = 0; z < MAX; z++) {
							
							if (numOrd[z].or_idComp == idComp && numOrd[z].or_idComp != 0) {
								
								if (numOrd[z].or_qtaOrd <= numComp[x].cp_qtaMag) {
									printf("ID Ordine: %d \n", numOrd[z].or_idOrd);
									printf("ID componenente correlato: %d \n", numComp[x].cp_idComp);
									numComp[x].cp_qtaMag -= numOrd[x].or_qtaOrd;
									printf("Quantità rimenente del componente: %d\n\n", numComp[x].cp_qtaMag);
									numOrd[z].or_idOrd = 0;
									numOrd[z].or_idComp = 0;
									numOrd[z].or_qtaOrd= 0;
									break;
								}
							}
						}
					}
					
				}
				printf("\n\n");
				break;
			
			case '6':
				/* STAMPA ARCHIVI MAGAZZINI */
				
				do {
					fpurge(stdin);
					lett = 0;
					puts("Di quale archivio si vuole stampare il report?");
					puts("1 -> Magazzino");
					puts("2 -> Ordini");
					lett = 0;
					scelta = getchar();

					switch (scelta) {
						case '1':
							puts("*** STAMPA DELL'ARCHIVIO COMPONENTI ***");
							for (v = 0; v < MAX; v++) {
								if (numComp[v].cp_idComp != 0) {
									printf("ID COMPONENENTE: %d\n", numComp[v].cp_idComp);
									printf("NOME COMPONENTE: %s\n", numComp[v].cp_nome);
									printf("QUANTITÀ IN MAGAZZINO: %d\n",numComp[v].cp_qtaMag);
									puts("\n");
								}
							}
							break;
					
						case '2':
							puts("*** STAMPA DELL'ARCHIVIO ORDINI ***");
							for (n = 0; n < MAX; n++) {
								if (numOrd[n].or_idOrd != 0) {
									printf("ID ORDINE: %d\n", numOrd[n].or_idOrd);
									printf("ID COMPONENTE: %d\n", numOrd[n].or_idComp);
									printf("QUANTITÀ IN MAGAZZINO: %d\n",numOrd[n].or_qtaOrd);
									puts("\n");
								}
							}
							break;
							
						default:
							lett = 1;
							break;
					}
				} while (lett == 1);
				
				break;
			
			case '7':
				/* 7 -> ESCI */
				esci = 1;
				break;
			default:
				puts("Inserisci un numero corretto");
				break;
				
		}
	
	} while (esci == 0);

	
	printf("\n\n");
	return 0;
}