#include <stdio.h>

/*
3) Scrivere un programma in c che dopo aver inserito un vettore di N numeri controlli l’esistenza di
un numero richiesto successivamente all’utente. In caso affermativo visualizzare quante volte si
ripete il numero e che posizione/i occupa nel vettore utilizzato.
*/

int retrieveNumberOfApparitions(int arr[], int number, int bound)
{
    int counter = 0;

    for (int i = 0; i < bound; i++)
    {
        if (arr[i] == number)
            counter++;
    }

    return counter;
}

void retrievePositionOfNumber(int arr[], int bound, int number, int pos[]) {
    int indexOfPos = 0;
    
    for (int i = 0; i < bound; i++)
    {
        if (arr[i] == number) {
            pos[indexOfPos] = i+1;
            indexOfPos++;
        }
    }
}

void takeNumbers(int arr[], int bound)
{
    for (int i = 0; i < bound; i++)
    {
        printf("Inserisci il numero %d-esimo : ", i + 1);
        scanf("%d", &arr[i]);
    }
}

void printArray(int arr[], int bound)
{
    for (int i = 0; i < bound; i++)
    {
        if (arr[i] != 0)
            printf("%d ", arr[i]);
    }
    
    printf("\n");
}

int main() {

    int howManyNumbers;
    int numberToSearch;

    // Ask the user how many number he wants to insert
    do {
        printf("Quanti numeri vuoi inserire? ");
        scanf("%d", &howManyNumbers);

        if (howManyNumbers <= 0 )
            printf("Devi inserire un numero maggiore di 0.\n");
    } while (howManyNumbers <= 0);
    
    // Declare array
    int arr[howManyNumbers];
    int pos[howManyNumbers];

    // take the numbers of the array
    takeNumbers(arr, howManyNumbers);

    // Take the number which the user wants to search for
    printf("Quale numero stai cercando? ");
    scanf("%d", &numberToSearch);

    int numberOfApparitions = retrieveNumberOfApparitions(arr, numberToSearch, howManyNumbers);

    if (numberOfApparitions > 0) {
        // print how many times the searched number appeared
        printf("Il numero che stai cercando si trova %d volte nel tuo array.\n", numberOfApparitions);

        printf("le posizioni che occupa sono : ");
        
        // get the position, which the number which the user wants to search for, occupied
        retrievePositionOfNumber(arr, howManyNumbers, numberToSearch, pos);

        // print all the position which it occupied
        printArray(pos, numberOfApparitions);
    }
    else {
        printf("Il tuo numero no e' presente nell'array.");
    }

    printf("\n\n");
    return 0;
}