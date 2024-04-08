#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h> // per user malloc e free

/*
Scrivere
un programma in C che dopo aver inserito una stringa a piacere
permetta di:

1)Inserire un carattere, scelto dall’utente in una posizione sempre
  scelta dall’utente;
2) Sostituisca un carattere, scelto dall’utente, con il seguente: X.
*/

// Print a string to the screen
void printString(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
    }

    printf("\n");
}

char* insertCharacter(char str[], char c, int pos) {
    char *str2 = malloc(strlen(str) + 2); // +2 per il carattere aggiuntivo e per il terminatore di stringa
    
    for (int i = 0; i < pos; i++) {
        str2[i] = str[i]; 
    }

    str2[pos] = c;

    for (int i = pos; i < strlen(str); i++) {
        str2[i+1] = str[i];
    }

    str[strlen(str2) + 1] = '\0';

    return str2;
}

void censorshipChar(char str[], char c) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            str[i] = 'X';
        }
    }
}

int main() {

    char str[100];
    char *pStr;
    char c;
    int pos;

    printf("Inserisci una stringa: ");
    scanf("%s", str);

    printf("Che carattere vuoi inserire: ");
    scanf(" %c", &c);

    printf("Inserisci la posizione in cui vuoi inserire il carattere: ");
    scanf("%d", &pos);

    pStr = insertCharacter(str, c, pos);

    strcpy(str, pStr);

    printf("Ecco la stringa con il carattere %c in posizione %d: ", c, pos);
    printString(str);

    // libero la memoria allocata dinamicamente
    free(pStr);

    printf("Quale carattere vuoi censurare?: ");
    scanf(" %c", &c);

    censorshipChar(str, c);

    printf("Ecco la stringa con il carattere %c censurato: ", c);
    printString(str);

    printf("\n\n");
    return 0;
}