/*
Dato un numero N intero positivo, 
stampare la somma dei primi N numeri primi alternati (uno sì e uno no)
*/


#include <stdio.h>


void main() {

    int numero = 0;
    int c = 2;
    int somma = 0;
    int _flagPrimo = 1;

    printf("Inserisci un numero: ");
    scanf("%d", &numero);

    for (int i = 1; i < numero; i++) {

        printf("i: %d\n", i);
        
        if (i > 1) {
            
            _flagPrimo = 1;


            for (int j = 2; j <= i / 2 && j != i; j++) {
                
                printf("j: %d\n", j);
                
                if (i % j == 0) {
                    _flagPrimo = 0;
                    break;
                }
            }
            
            if (_flagPrimo == 1) somma += i;
        }
        
        
        // printf("Count: %d\n", c);
        printf("Flag: %d\n", _flagPrimo);
        printf("somma: %d\n", somma);
    }
    
    printf("\nResult: %d\n", somma);
}
