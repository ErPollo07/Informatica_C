/*
Una banca vuole conoscere alcune informazioni sulle proprie azioni detenute in portafoglio.
Scrivere il programma in c che dopo aver inserito da tastiera la denominazione dell’azione e il suo prezzo
determini e visualizzi in Output:
1) La somma dei prezzi delle azioni;
2) La media dei prezzi delle azioni;
3) L’azione con il prezzo massimo;
4) L’azione con il prezzo minimo;
5) La media dei prezzi delle azioni con un importo compreso tra 2,50 e 3,50 euro, estremi inclusi.
L’inserimento termina con la parola “terminato”.
Il programma deve permettere il reinserimento del prezzo se è pari a zero o inferiore.


alcune azioni utili
Apple (AAPL)
Google (GOOGL)
Amazon (AMZN)

------COSA DEVE FARE IL PROGRAMMA------

###VAR###
double array nomeAzione(es: AzioniGoogle) {prezzo, prezzo, prezzo, prezzo ...}

###MAIN###
do:
    PrintMenuAzioni() : void -> stampa le azioni con il prezzo attuale
    Chiede quale azione INSERIMENTO (.lower() se si puó)
    L'utente inserisce il nome dell'azione tra parentesi e il suo prezzo in questo momento
while (INSERIMENTO != "terminato")
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOUND 3

/*
Display the menu
*/
void PrintMenuAzioni()
{
    printf("\n\n");
    printf("|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n");
    printf("*                ~ BENVENUTI ~                  *\n");
    printf("|    1 Azioni AAPL             - Prezzo 165.98  |\n");
    printf("*    2 Azioni GOOGL            - Prezzo 124.58  *\n");
    printf("|    3 Azioni AMZN             - Prezzo 132.92  |\n");
    printf("*                                               *\n");
    printf("|*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n");
}

/*
Return the sum of the array that containts the price of actions
*/
double Sum(double prezzi[], int bound)
{
    double sum = 0;

    for (int i = 0; i < bound; i++)
    {
        sum += prezzi[i];
    }

    return sum;
}

/*
Return the avarage amount of the prices of actions
*/
double Media(double arrayAzioni[], int bound)
{
    return Sum(arrayAzioni, bound) / bound;
}

/*
Return the minimum value of the prices of actions
*/
double Min(double arrayAzioni[], int bound)
{
    double valMin = arrayAzioni[0];

    for (int i = 0; i < bound; i++)
    {
        if (arrayAzioni[i] < valMin)
            valMin = arrayAzioni[i];
    }

    return valMin;
}

/*
Return the maximum value of the prices of actions
*/
double Max(double arrayAzioni[], int bound)
{
    double valMax = arrayAzioni[0];

    for (int i = 0; i < bound; i++)
    {
        if (arrayAzioni[i] < valMax)
            valMax = arrayAzioni[i];
    }

    return valMax;
}

/*
Display the avarage of the prices of acrions with price between 2.5 and 3.5
*/
void MediaTraValori(double arrayAzioni[], int bound, double valMax, double valMin)
{
    double avarage;
    double sum = 0;
    double count = 0;

    // For each price in the array arrayAzioni 
    for (int i = 0; i < bound; i++)
    {
        // check if the price if between 2.5 and 3.5
        if (arrayAzioni[i] >= valMin && arrayAzioni[i] <= valMax) {
            sum += arrayAzioni[i]; // Update the sum
            count++; // Upgrade the counter
        }
    }

    if (count > 0)
    {
        avarage = sum / count; // Calculate the avarage of the price
        printf("La media dei valori compresi tra %f e %f e': %f\n", valMin, valMax, avarage);
    }
    else
    {
        printf("Non sono stati trovati valori tra %f e %f\n", valMin, valMax);
    }
}

void main()
{

    double actionApple[BOUND] = {1.48, 2.73, 3.24};
    double actionGoogle[BOUND] = {2.45, 3.12, 1.89};
    double actionAmazon[BOUND] = {3.76, 1.23, 2.98};

    double valMin = 2.50;
    double valMax= 3.50;
    int choice;
    char insertion[20];

    int flagTerminate = 0;

    do
    {
        PrintMenuAzioni(); // Print menu

        do {
            printf("Inserisci una scelta: ");
            scanf("%s", &insertion);

            // Check if the user digited "terminato"
            if (strcmp(insertion, "terminato") == 0)
            {
                flagTerminate = 1;
                break;
            }

            choice = atoi(insertion); // Cast insertion in int

            // Check if the choice if a valid number
            if (choice == 1 || choice == 2 || choice == 3) {
                break;
            }

        } while (1);

        // Check insertion is equal to "terminato"
        if (flagTerminate) break;


        if (choice == 1)
        {
            printf("La somma delle azioni e': %f\n", Sum(actionApple, BOUND));
            printf("La media delle azioni e': %f\n", Media(actionApple, BOUND));
            printf("Il valore minimo delle azioni e': %f\n", Min(actionApple, BOUND));
            printf("Il valore massimo delle azioni e': %f\n", Max(actionApple, BOUND));
            MediaTraValori(actionApple, BOUND, valMin, valMax);
        }
        else if (choice == 2)
        {
            printf("La somma delle azioni e': %f\n", Sum(actionGoogle, BOUND));
            printf("La media delle azioni e': %f\n", Media(actionGoogle, BOUND));
            printf("Il valore minimo delle azioni e': %f\n", Min(actionGoogle, BOUND));
            printf("Il valore massimo delle azioni e': %f\n", Max(actionGoogle, BOUND));
            MediaTraValori(actionGoogle, BOUND, valMin, valMax);
        }
        else if (choice == 3)
        {
            printf("La somma delle azioni e': %f\n", Sum(actionAmazon, BOUND));
            printf("La media delle azioni e': %f\n", Media(actionAmazon, BOUND));
            printf("Il valore minimo delle azioni e': %f\n", Min(actionAmazon, BOUND));
            printf("Il valore massimo delle azioni e': %f\n", Max(actionAmazon, BOUND));
            MediaTraValori(actionAmazon, BOUND, valMin, valMax);
        }

    } while (1);
}