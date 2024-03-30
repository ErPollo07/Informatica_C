#include <stdio.h>

int main() {

    // Pointer = a variable that hold an address
    // To declarate a pointer we need to write
    // <type> * <name> = <adrress>

    int x = 4; // create a int variable with value 4
    int * pX = &x; // Create a pointer named pX and assign the value of the address of the variable x

    // to access the value of the pointer we simply put * and the name of the pointer
    // Example: we want to copy the value of x in a new variable y using the pointer
    int y = *pX;

    // Print a pointer
    // address
    printf("Value of the pointer = %d\n", pX);
    // Value which is pointing on
    printf("Value of the pointed address = %d\n", *pX); // I put %d because the pointer points to an int

    /* RASPA */
    int alfa = 4;
    int beta = 7;
    int *pointer;

    pointer = &alfa; // Assign to pointer the address of alfa
    printf("alfa -> %d, beta -> %d, pointer -> %d\n", alfa, beta, pointer);

    beta = *pointer; // assign to beta the value of the pointer (not the address), which is the value of alfa
    printf("alfa -> %d, beta -> %d, pointer -> %d\n", alfa, beta, pointer);

    alfa = pointer; // assign to alfa the value of its address
    printf("alfa -> %d, beta -> %d, pointer -> %d\n", alfa, beta, pointer);

    *pointer = 5; // chage the value at the address that the pointer points to, so alfa is now 5
    printf("alfa -> %d, beta -> %d, pointer -> %d\n", alfa, beta, pointer);
    /* END RASPA */

    printf("\n\n");
    return 0;
}