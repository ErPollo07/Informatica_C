/*
 Scrivere un programma in C che, dopo aver letto N numeri (n scelto dall'utente) calcoli e visualizzi a video la somma dei numeri positivi, la somma dei numeri negativi in valore assoluto, il conteggio dei numeri negativi e positivi, la media dei numeri positivi e negativi.
*/

#include <stdio.h>

void main()
{

    int n;
    int number = 0;

    double coutPositive = 0, coutNegative = 0;

    double sumPositive = 0, sumNegative = 0;
    double averagePositive = 0, averagenegative = 0;

    printf("Inserisci quanti numeri vuoi leggere: ");
    scanf("%d", &n);


    for (int i = 0; i < n; i++)
    {
        printf("Inserisci il numero: ");
        scanf("%d", &number);

        if (number > 0)
        {
            coutPositive++; // Increment the counter of positive number
            sumPositive += number; // Update the sun of postive number
        }
        else
        {
            coutNegative++; // Increment the counter of negative number
            sumNegative += number; // Update the sun of postive number
        }
    }

    // Calculate the avarage of positive number
    if (coutPositive > 0)
        averagePositive = sumPositive / coutPositive;

    // Calculate the avarage of negative number
    if (coutNegative > 0)
        averagenegative = (sumNegative * -1) / coutNegative;

    // Display the sum and the avarge of positive number
    printf("La somma dei numeri positivi e': %.2f\nLa media dei numeri positivi e': %.2f\n", sumPositive, averagePositive);

    // Display the sum and the avarge of negative number
    printf("La somma dei numeri negativi e': %.2f\nLa media dei numeri negativi e': %.2f\n", (sumNegative * -1), averagenegative);
}