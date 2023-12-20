/*
Dato un numero N intero positivo, 
stampare la somma dei primi N numeri primi alternati (uno sì e uno no)
*/


#include <stdio.h>


void main() {

    int numero = 0;
    int c = 2;
    int somma = 0;
    int _flagPrimo;

    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    for (int i = 1; i <= numero; i++) {

        /* DEBUG
        printf("i: %d\n", i);
        */
        
        if (i > 1) {
            
            
            _flagPrimo = 1;
            
            /* DEBUG
            printf("sono entrato per valutare\n");
            */    

            // Valuta se primo
            for (int j = 2; j <= i / 2 && j != i; j++) {
                
                if (i % j == 0) {
                    _flagPrimo = 0;
                    break;
                }
            }
            
            printf("Count: %d\n", c);
            
            // se il numero é primo e il contatore é pari allora aggiorno la somma
            if (_flagPrimo && c % 2 == 0) somma += i;
            
            // se il numero (i) é primo allora aggiorno contatore
            if (_flagPrimo == 1) c++;

            // se il numero é primo
            if (_flagPrimo) {
                // se il count é pari allora aggiorna la somma
                if (c % 2 == 0) somma += i;
                // Aggiorno il count
                c++;
            }
        }
        
        
        /* DEBUG
        printf("Flag: %d\n", _flagPrimo);
        printf("somma: %d\n\n", somma);
        */
    }
    
    printf("\nResult: %d\n", somma);
}