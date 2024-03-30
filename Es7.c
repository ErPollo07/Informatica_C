#include <stdio.h>
#include <string.h>

/*
Scrivere un programma in C che dopo aver inserito una stringa a piacere permetta di:
   1) Eliminare 1 carattere scelto dall’utente (o più di 1 se si ripetono);
   2) Eliminare 1 carattere scelto dall’utente in  base alla sua posizione;
   3) Aggiungere 1  carattere scelto dall’utente alla fine della stringa;
*/

void deleteCharacter(char str[], char c, int bound) {
    // ciclo tutti i caratteri della stringa
    for (int i = 0; i < bound; i++) {
        // se trovo il carattere nella mia stringa
        if (str[i] == c) {
            // sposto i caratteri di un posto indietro
            for (int j = 0; j < bound - i; j++) {
                str[i + j] = str[i + j + 1];
            }
        }
    }
}

void deleteCharInPos(char str[], int pos) {
    for (int i = pos; i < strlen(str); i++) {
        str[i] = str[i + 1];
    }
}

void addLast(char str[], char c) {
  char temp[strlen(str) + 1];

  strcpy(temp, str);

  temp[strlen(temp) - 1] = c;

  strcpy(str, temp);
}

void printString(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
    }
}

int main() {

    char tempStr[1000];
    char c;
    int scelta;
    int pos;

    printf("Inserisci una stringa: ");
    scanf(" %s", &tempStr);

    char str[strlen(tempStr)];

    // Menu 
    printf("----\n");
    printf("Menu\n");
    printf("----\n");
    printf("\t1) Eliminare 1 carattere scelto dall'utente (o piu' di 1 se si ripetono);\n");
    printf("\t2) Eliminare 1 carattere scelto dall'utente in  base alla sua posizione;\n");
    printf("\t3) Aggiungere 1  carattere scelto dall’utente alla fine della stringa;\n\n");

    printf("Inserisci scelta: ");
    scanf("%d", &scelta);

    switch (scelta) {
        case 1:
            printf("\nQuale carattere vuoi togliere dalla stringa inserita: ");
            scanf(" %c", &c);

            deleteCharacter(str, c, strlen(str));

            printf("Ecco la stringa senza %c : ", c);
            printString(str);

            break;
        case 2:
            printf("\nInsrisci la posizione in cui vuoi eliminare il carattere: ");
            scanf("%d", &pos);

            deleteCharInPos(str, pos);

            printString(str);
            break;
        case 3:
            printf("Inserisci un carattere da inserire a fine stringa: ");
            scanf(" %c", &c);

            addLast(str, c);

            printf("Ecco la tue stringa con il carattere %c aggiunto all fine: ", c);
            printString(str);
            break;
        default:
            break;
    }


    printf("\n\n");
    return 0;
}