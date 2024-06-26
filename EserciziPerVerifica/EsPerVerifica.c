#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/*
Scrivere un programma in C che dopo aver inserito una stringa a piacere determini e o verifichi:
  1) Il numero di consonanti e vocali contenute;
  2) Che contenga solo lettere;
  3) Il conteggio di una lettera (se presente) scelta dall’utente;
  4) Crei 2 ulteriori stringhe che contengano 1 le lettere di posizione pari; la 2° le lettere di posizione
     dispari;
  5) Verifichi se contiene doppie.
  ------
Inserita una 2° stringa determinare:
  1) Quale delle 2 è più lunga e più corta;
  2) Quale delle 2 stringhe contiene più vocali;
  3) Quale delle 2 stringhe contiene più consonanti;
  4) Quali sono le lettere contenute in ambedue le stringhe;
*/

// Print a string to the screen
void printString(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        printf("%c", str[i]);
    }
}

int countVocal(char str[]) {
    int counter = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') ++counter;
    }

    return counter;
}

int countConsonant(char str[]) {
    int counter = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') ++counter;
    }

    return counter;
}

bool containsDouble(char str[]) {
    for (int i = 0; i < strlen(str) - 1; i++) {
        if (str[i] == str[i + 1]) return true;
    }

     return false;
}

void divideChar(char str[], char evenCharacter[], char oddCharacter[]) {
    int indexEven = 0;
    int indexOdd = 0;
    
    for (int i = 0; i < strlen(str); i++) {
        if (i % 2 == 0) {
            evenCharacter[indexEven] = str[i];
            indexEven++;
        } else {
            oddCharacter[indexOdd] = str[i];
            indexOdd++;
        }
    }

    evenCharacter[indexEven] = '\0';
    oddCharacter[indexOdd] = '\0';
}

void containsTheLetter(char str[], int letter, int * counter) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == letter) ++(*counter);
    }
}

bool containsOnlyletter(char str[]) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] < 'a' || str[i] > 'z') return false;
    }

    return true;
}

void countVocalConsonant(char str[], int counters[]) {
    counters[0] = 0;
    counters[1] = 0;

    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            counters[0]++;
        else if (str[i] >= 'a' && str[i] <= 'z')
            counters[1]++;
    }
}

void retriveSameChars(char str[], char str2[], char * chars) {
    int indexChars = 0;

    for (int i = 0; i < strlen(str); i++) {
        for (int j = 0; j < strlen(str2); j++) {
            if (str[i] == str[j]) {
                chars[indexChars] = str[i];
                indexChars++;
            }
        }
    }

    chars[indexChars] = '\0';
}

int main() {
    char str[100];
    int howManyVC[2];
    char letter;
    int counter = 0;
    char str2[100];

    // take string
    printf("Inserisci una stringa: ");
    scanf("%s", str);

    // Check how many vocal and consonant
    countVocalConsonant(str, howManyVC);
    printf("Le vocali sono : %d\nLe consonanti sono : %d\n", howManyVC[0], howManyVC[1]);

    // Check if the string contains only letter
    if (containsOnlyletter(str)) {
        printf("la stringa contiene solo lettere\n");
    }
    else {
        printf("la stringa non contiene solo lettere\n");
    }

    // Count a letter
    printf("Inserisci quale lettere vuoi cercare nella stringa: ");
    scanf(" %c", &letter);

    containsTheLetter(str, letter, &counter);

    printf("La lettera %c si trova %d volte.", letter, counter);

    // Create 2 string.
    // The first contains the letters in even pos.
    // The second contains only the letters in odd pos.
    char strEven[(int)(strlen(str) / 2)];
    char strOdd[(int)(strlen(str) / 2)];

    divideChar(str, strEven, strOdd);

    printf("Le lettere in posizione pari sono ");

    for (int i = 0; i < strlen(strEven); i++) {
        printf("%c ", strEven[i]);
    }
    printf("\n");

    printf("Le lettere in posizione dispari sono ");

    for (int i = 0; i < strlen(strOdd); i++) {
        printf("%c ", strOdd[i]);
    }
    printf("\n");
    
    // Check if contiains double (doppie)
    if (containsDouble(str)) {
        printf("La stringa contiene doppie.\n");
    } else {
        printf("La stringa non contiene doppie.\n");
    }

    // tell the user to insert a second string
    printf("Inserisci una seconda stringa: ");
    scanf("%s", str2);

    // compare the first string with the second
    if (strcmp(str, str2) > 0) {
        printf("La prima stringa e' maggiore della seconda\n");
    } else if (strcmp(str, str2) < 0) {
        printf("La seconda stringa e' maggiore della prima\n");
    } else {
        printf("Le due stringhe sono uguali.\n");
    }

    // compare the number of vocal of the first string with the second
    if (countVocal(str) > countVocal(str2)) {
        printf("La prima stringa ha piu' vocali della seconda.\n");
    } else if (countVocal(str) < countVocal(str2)) {
        printf("La sconda stringa a  piu' voacali della seconda.\n");
    } else {
        printf("Le due stringhe hanno ugual numero di vocali.\n");
    }

    // compare the number of consonant of the first string with the second
    if (countConsonant(str) > countConsonant(str2)) {
        printf("La prima stringa ha piu' consonanti della seconda.\n");
    } else if (countConsonant(str) < countConsonant(str2)) {
        printf("La sconda stringa a piu' consonanti della seconda.\n");
    } else {
        printf("Le due stringhe hanno ugual numero di consonanti.\n");
    }

    // create the array of char which contains the chars which these are in the first and second string
    char charInAllString[strlen(str)];

    // cal the function to retrive the caracters
    retriveSameChars(str, str2, &charInAllString);

    // Prrint the caracters
    printf("i caratteri comuni a tutte e due le stringhe sono: ");
    for (int i = 0; i < strlen(charInAllString); i++) {
        printf("%c ", charInAllString[i]);
    }

    printf("\n\n");
    return 0;
}