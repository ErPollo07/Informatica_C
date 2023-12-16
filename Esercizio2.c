/*
Su una somma di denaro (relativa all'acquito di un prodotto) si vuole applicare uno sconto in base all'importo inserito seguendo il seguente schema:
    da 0 a 500€ sconto del 10%;
    da 501 a 1000 sconto del 20%;
    oltre i 1001 sconto 30%;
 Il programma dopo aver calcolato e visualizzato a video lo sconto ed il prezzo netto deve permettere di re-inserire
 ulteriori somme di denaro.
*/

#include <stdio.h>

void main() {
    
    float prezzo;

    float scontoMinore500 = 10, sconto1000 = 20, scontoOltre1001 = 30;

    float prezzoScontato;

    do {
        printf("inserire l'importo: ");
        scanf("%f", &prezzo);
    } while (prezzo < 0);

    if (prezzo < 500) {
        prezzoScontato = prezzo - prezzo * (scontoMinore500 / 100.0);
    }
    else if (prezzo >= 501 && prezzo < 1001) {
        prezzoScontato = prezzo - prezzo * (sconto1000 / 100.0);
    }
    else if (prezzo >= 1001) {
        prezzoScontato = prezzo - prezzo * (scontoOltre1001 / 100.0);
    }
    else {
        printf("inserire un valore positivo");
    }

    printf("Importo inseririto: %.2f\nimporto con sconto: %.2f\n", prezzo, prezzoScontato);
}