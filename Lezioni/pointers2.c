#include <stdio.h>

void inc(int *n) {
    ++(*n);
}

int main() {

    /* POINTER TO POINTER */
    // To declare a pointer to a pointer we need to put 2 * before the variable name
    int **ponterToPointer;

    /* POINTERS AS FUNCTION ARGUMENTS */
    int a = 5;
    printf("a = %d\n", a); // 5
    inc(&a);
    printf("a = %d\n", a); // 6

    /* POINTERS AND ARRAYS */
    int arr[5];
    int *pArr;
    // To declare a pointer that points to the first element of the array we have 2 methods
    // 1) pointer = &arr[0];
    pArr = &arr[0];
    printf("Value of pArr = %d\n", pArr); // Address of the first element of the arr
    // 2) pointer = arr;
    pArr = arr;
    printf("Value of pArr = %d\n", pArr); // Address of the first element of the arr


    printf("\n\n");
    return 0;
}