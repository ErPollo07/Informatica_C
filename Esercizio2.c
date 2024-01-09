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
    
    float price, discountedPrice;
    float discount;
    int _continue;

    do {
        // Ask the input until it's > 0
        do {
            printf("inserire l'importo: ");
            scanf("%f", &price);
        } while (price < 0);


        // Calculate the discount based on the price
        if (price < 500) {
            discount = 10;
            discountedPrice = price - price * (discount / 100.0);
        }
        else if (price >= 500 && price < 1001) {
            discount = 20;
            discountedPrice = price - price * (discount / 100.0);
        }
        else if (price >= 1001) {
            discount = 30;
            discountedPrice = price - price * (discount / 100.0);
        }

        // Display amount 
        printf("Importo inseririto: %.2f\nimporto con sconto: %.2f\n", price, discountedPrice);

        printf("Vuoi inserire un altro importo: \n(1) SI\n(0) NO\n");
        scanf("%d", &_continue);
    } while (_continue);
}