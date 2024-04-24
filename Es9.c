#include <stdio.h>

/*
Dopo aver letto un vettore di N elementi 
utilizzando i puntatori calcolare la media del vettore e determinare il massimo ed il minimo.
*/

float calcolaMedia(int arr[], int lenArr, float *dest) {
    int sum = 0;
    
    for (int i = 0; i < lenArr; i++) {
        sum += arr[i];
    }

    *dest = sum / lenArr;
}

int main() {

    int N;
    float media;
    int massimo, minimo;

    printf("Inserisci quanti numeri voui inserire: ");
    scanf("%d", &N);

    int numbers[N];

    for (int i = 0; i < N; i++) {
        printf("Inserisci il %d numero: ", i+1);
        scanf("%d", &numbers[i]);
    }

    calcolaMedia(numbers, N, &media);

    printf("La media e': %.2f", media);

    printf("\n\n");
    return 0;
}