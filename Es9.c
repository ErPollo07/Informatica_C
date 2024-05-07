#include <stdio.h>

/*
Dopo aver letto un vettore di N elementi 
utilizzando i puntatori calcolare la media del vettore e determinare il massimo ed il minimo.
*/

void calcolaMediaMinMax(int arr[], int lenArr, float *media, int *min, int *max) {
    float sum = 0;

    *min = arr[0];
    *max = arr[0];
    
    for (int i = 0; i < lenArr; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        } else if (arr[i] > *max) {
            *max = arr[i];
        }

        sum += arr[i];
    }

    *media = sum / lenArr;
}

int main() {

    int N;
    float media;
    int massimo, minimo;

    do {
        printf("Inserisci quanti numeri voui inserire: ");
        scanf("%d", &N);

        if (N < 0) printf("You have to insert a number grader then 0\n");
    } while (N < 0);

    int numbers[N];

    for (int i = 0; i < N; i++) {
        printf("Inserisci il %d numero: ", i+1);
        scanf("%d", &numbers[i]);
    }

    calcolaMediaMinMax(numbers, N, &media, &minimo, &massimo);

    printf("La media e': %.2f\n", media);
    printf("Il minimo dell'array e': %d\n", minimo);
    printf("Il massimo dell'array e': %d\n", massimo);

    printf("\n\n");
    return 0;
}
