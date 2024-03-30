#include <stdio.h>
#include <string.h>

/*
Scrivere un programma in C che dopo aver inserito una stringa a piacere permetta di:
   1) Eliminare 1 carattere scelto dall’utente (o più di 1 se si ripetono);
   2) Eliminare 1 carattere scelto dall’utente in  base alla sua posizione;
   3) Aggiungere 1  carattere scelto dall’utente alla fine della stringa;
*/

// delete all the character equals to c in str
void deleteCharacter(char str[], char c) {
    // Cycle throught every character of the string str 
    for (int i = 0; i < strlen(str); i++) {
        // If the character in position i is equal to c
        if (str[i] == c) {
            // move all the character a position before them
            for (int j = 0; j < bound - i; j++) {
                str[i + j] = str[i + j + 1];
            }
        }
    }
}

// Delete a character of the str in pos
void deleteCharInPos(char str[], int pos) {
    // cycle throught every character of str start from pos
    for (int i = pos; i < strlen(str); i++) {
        // assign to current character character after it
        str[i] = str[i + 1];
    }
}

// add in the last position of str the character c
void addLast(char str[], char c) {
    // Create a temp string with length of str + 1
    char temp[strlen(str) + 1];

    // copy str in temp
    strcpy(temp, str);

    // add to last positon c
    temp[strlen(temp)] = c;

    // copy temp in str
    strcpy(str, temp);
}

// Print a string to the screen
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

    // tell to the user to insert a string
    printf("Inserisci una stringa: ");
    scanf(" %s", &tempStr);

    // Create a string of the right dimension
    char str[strlen(tempStr) + 1];
    // copy the content of tempStr in str
    strcpy(str, tempStr);

    // todo create a do while for the choice of the menu

    // Print the menu
    printf("---------------------------------------------------------------------------\n");
    printf("                                MENU\n");
    printf("---------------------------------------------------------------------------\n");
    printf("\t1) Eliminare 1 carattere scelto dall'utente (o piu' di 1 se si ripetono)\n");
    printf("\t2) Eliminare 1 carattere scelto dall'utente in  base alla sua posizione\n");
    printf("\t3) Aggiungere 1  carattere scelto dall’utente alla fine della stringa\n\n");

    // Ask the user to inser a choice
    printf("Inserisci scelta: ");
    scanf("%d", &scelta);

    switch (scelta) {
        case 1:
            // Ask the user which character wants to delete in the string
            printf("\nQuale carattere vuoi togliere dalla stringa inserita: ");
            scanf(" %c", &c);

            // Call the function to delete the character
            deleteCharacter(str, c, strlen(str));

            // print the string without the character
            printf("Ecco la stringa senza %c : ", c);
            printString(str);

            break;
        case 2:
            // Ask the user the position of the character which he wants to delete
            printf("\nInsrisci la posizione in cui vuoi eliminare il carattere: ");
            scanf("%d", &pos);

            // Call the function to delete the character in the correct position
            deleteCharInPos(str, pos);

            // print the string without the character
            printf("Ecco la stringa senza il carattere in posizione %d: ", pos);
            printString(str);
            break;
        case 3:
            // Ask the user to insert which character wants to insert to the end of the string
            printf("Inserisci un carattere da inserire a fine stringa: ");
            scanf(" %c", &c);

            // Call the function to add in the last position the character
            addLast(str, c);

            // Prit the string with the chararter in the last position
            printf("Ecco la tue stringa con il carattere %c aggiunto all fine: ", c);
            printString(str);
            break;
        default:
            break;
    }


    printf("\n\n");
    return 0;
}