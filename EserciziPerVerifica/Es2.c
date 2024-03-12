#include <stdio.h>

/*
2) Scrivere un programma in c che dopo aver inserito un vettore di N numeri interi separi il vettore
inserito in 2 ulteriori vettori il primo contenente i numeri pari ed il secondo con i numeri dispari.
*/

void separateNumberInArray(int startArr[], int arrEven[], int arrOdd[], int bound)
{
    int indexEven = 0;
    int indexOdd = 0;

    // Count how many even and idd there is in the startArr
    for (int i = 0; i < bound; i++)
    {
        if (startArr[i] % 2 == 0)
        {
            arrEven[indexEven] = startArr[i];
            indexEven++;
        }
        else
        {
            arrOdd[indexOdd] = startArr[i];
            indexOdd++;
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

int main()
{
    int howManyNumbers;

    // Ask the user how many number he wants to insert
    // If the user insert a number minor or equals to 0, tell the user that isn't a valid number
    do {
        printf("Quanti numeri vuoi inserire? ");
        scanf("%d", &howManyNumbers);

        if (howManyNumbers <= 0 )
            printf("Devi inserire un numero maggiore di 0.\n");
    } while (howManyNumbers <= 0);

    // Declare array
    int arr[howManyNumbers];
    int arrEven[howManyNumbers];
    int arrOdd[howManyNumbers];

    // take the number in input
    takeNumbers(arr, howManyNumbers);

    // call separateNumberInArray function to separate the even number from the odd ones
    separateNumberInArray(arr, arrEven, arrOdd, howManyNumbers);

    // print out the two arrays
    printf("Array di numeri pari : ");
    printArray(arrEven, howManyNumbers);
    printf("Array di numeri dispari : ");
    printArray(arrOdd, howManyNumbers);

    printf("\n\n");
    return 0;
}