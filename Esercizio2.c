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
    
    float prezzo, prezzoScontato;
    float sconto, sconto1000 = 20, scontoOltre1001 = 30;
    int continua;

    do {
        // Chiedo l'input fino a che il prezzo < 0
        do {
            printf("inserire l'importo: ");
            scanf("%f", &prezzo);
        } while (prezzo < 0);


        // Calcolo lo sconto e lo applico al prezzo
        if (prezzo < 500) {
            sconto = 10;
            prezzoScontato = prezzo - prezzo * (sconto / 100.0);
        }
        else if (prezzo >= 500 && prezzo < 1001) {
            sconto = 20;
            prezzoScontato = prezzo - prezzo * (sconto / 100.0);
        }
        else if (prezzo >= 1001) {
            sconto = 30;
            prezzoScontato = prezzo - prezzo * (sconto / 100.0);
        }

        // Stampo il prezzo inserito dall'utente e il prezzo con lo sconto applicato
        printf("Importo inseririto: %.2f\nimporto con sconto: %.2f\n", prezzo, prezzoScontato);

        printf("Vuoi inserire un altro importo: \n(1) SI\n(0) NO\n");
        scanf("%d", continua);
    } while (continua);
}