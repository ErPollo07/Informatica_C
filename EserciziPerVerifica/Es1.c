/*
1) Dopo aver caricato in memoria un 2 vettori di uguale dimensione composti da numeri interi
scrivere in output un terzo vettore dato dalla somma delle componenti fatta a una a una (Vettore
somma).
*/

#include <stdio.h>

void sumArrays(int arr1[], int arr2[], int outputArr[], int dimension) {
    for (int i = 0; i < dimension; i++) {
        outputArr[i] = arr1[i] + arr2[i];
    }
}

int main() {

    // make two integer array with equal dimension
    int arr1[5] = {1,2,3,4,5};
    int arr2[5] = {1,2,3,4,5};
    int result[5];

    // Do sum of two arrays
    sumArrays(arr1, arr2, result, BOUND);

    // Print out the result
    for (int i = 0; i < BOUND; i++) {
        printf("Il %d elemento e' : %d", i+1, result[i]);
    }

    printf("\n\n");
    return 0;
}