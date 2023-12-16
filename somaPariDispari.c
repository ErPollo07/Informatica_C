/*
Dopo aver letto N numeri (interi), con N scelto dall'utente e non superiore ai 30 elementi,  calcolare la somma e la media dei numeri pari, e dei numeri dispari (utilizzare %).
*/

#include <stdio.h>

void main() {

    int numero = 0;
    int lenght = 0;

    // somme
    double sommaPari = 0;
    double sommaDispari = 0;

    // lenght
    double lenghtPari = 0;
    double lenghtDispari = 0;

    // medie
    double mediaPari = 0;
    double mediaDispari = 0;

    printf("Inserisci il numero di numeri che vuoi inserire: ");
    scanf("%d", &lenght);

    if (lenght < 30) {
        while(lenght > 0) {
            printf("Inserisci un numero: ");
            scanf("%d", &numero);

            if (numero % 2 == 0) {
                sommaPari += numero;
                lenghtPari += 1;
            }
            else {
                sommaDispari += numero;
                lenghtDispari += 1;
            }

            lenght--;
        }

        mediaPari = sommaPari / lenghtPari;
        mediaDispari = sommaDispari / lenghtDispari;
        printf("La media dei numeri pari: %.2f\n", mediaPari);
        printf("La media dei numeri dispari: %.2f\n", mediaDispari);
    }
    else {
        printf("Non puoi inserire piú di 30 numeri");
    }
}