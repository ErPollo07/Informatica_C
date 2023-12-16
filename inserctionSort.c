
#include <stdio.h>

int main() {

    int l = 7;
    int arr[] = {4,2,7,3,8,9,1};
    int numMin = arr[0];

    int startIndex = 0;

    int t = 0;
    for (int j = 0; j < l; j++) {
        for (int i = startIndex; i < l; i++) {

            if (arr[i] < numMin) {
                numMin = arr[i];
            }

            // printf("%d ", numMin);

            t = arr[startIndex];
            arr[startIndex] = numMin;
            arr[i] = t;

            startIndex++;

            // printf("%d", arr[startIndex]);
        }
    }
    

    for (int m = 0; m < l; m++) {
        printf("%d", arr[m]);
    }

    


    return 0;
}