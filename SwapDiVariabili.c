
#include <stdio.h>

int main() {

    // definisco le variabili
    int lenght = 5;
    int array[5] = {1, 4, 7, 3, 2};
    int startIndex = 0;
    int numMin = array[0];

    int t;

    for (int i = 0; i < lenght; i++) {

        // definisco qual é il numero minimo dell'array
        // {1, 4, 7, 3, 2}
        for (int j = startIndex; j < lenght; j++) {
            if (array[j] < numMin) {
                numMin = array[j];
            }
        }
        
        printf("%d", numMin);
        
        // OK
        if (array[i] == numMin) {
            t = array[startIndex];
            array[startIndex] = array[i];
            array[i] = t;
            startIndex++;
        }
        // end ok
        
        numMin++;
    }
}