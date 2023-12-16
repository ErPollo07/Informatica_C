/*
 Scrivere un programma in C che, dopo aver letto N numeri (n scelto dall'utente) calcoli e visualizzi a video la somma dei numeri positivi, la somma dei numeri negativi in valore assoluto, il conteggio dei numeri negativi e positivi, la media dei numeri positivi e negativi.
*/

#include <stdio.h>

void main()
{

    int n;
    int numero = 0;

    double coutPositivi = 0, coutNegativi = 0;

    double sommaPositivi = 0, sommaNegativi = 0;
    double mediaPositivi = 0, mediaNegativi = 0;

    printf("Inserisci quanti numeri vuoi leggere: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {

        printf("Inserisci il numero: ");
        scanf("%d", &numero);

        if (numero > 0)
        {
            coutPositivi++;
            sommaPositivi += numero;
        }
        else
        {
            coutNegativi++;
            sommaNegativi += numero;
        }
    }

    if (coutPositivi > 0)
        mediaPositivi = sommaPositivi / coutPositivi;

    if (coutNegativi > 0)
        mediaNegativi = (sommaNegativi * -1) / coutNegativi;

    printf("La somma dei numeri positivi e': %.2f\nLa media dei numeri positivi e': %.2f\n", sommaPositivi, mediaPositivi);

    printf("La somma dei numeri negativi e': %.2f\nLa media dei numeri negativi e': %.2f\n", (sommaNegativi * -1), mediaNegativi);
}