/*
Dato un numero N intero positivo, 
stampare la somma dei primi N numeri primi alternati (uno sì e uno no)
*/


#include <stdio.h>


void main() {

    int number = 0;
    int count = 2;
    int sum = 0;
    int _flagPrime;

    printf("Inserisci un numero: ");
    scanf("%d", &number);

    for (int i = 1; i <= number; i++) {

        /* DEBUG
        printf("i: %d\n", i);
        */
        
        
        if (i > 1) {
            
            _flagPrime = 1;
            
            /* DEBUG
            printf("sono entrato per valutare\n");
            */    

            // Evaluate if is prime
            for (int j = 2; j <= i / 2 && j != i; j++) {
                
                if (i % j == 0) {
                    _flagPrime = 0;
                    break;
                }
            }

            /* DEBUG
            printf("Count: %d\n", c);
            */
           
            // se il numero é primo
            if (_flagPrime) {
                // If counter if even update the sum
                if (count % 2 == 0) sum += i;
                // Update the counter
                count++;
            }
        }
        
        
        /* DEBUG
        printf("Flag: %d\n", _flagPrimo);
        printf("somma: %d\n\n", somma);
        */
    }
    
    // Display the result
    printf("\nResult: %d\n", sum);
}