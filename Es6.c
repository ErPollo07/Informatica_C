#include <stdio.h>


// Return the avarage mark of the mark array
float getAvarage(float marks[], int lenght) {
    float avarage = 0;
    float sum = 0;

    for (int i = 0; i < lenght; i++) {
        sum += (int)marks[i];
    }

    if (sum != 0)
        avarage = sum / lenght;

    return avarage;
}

// Assign to minMarkAndStudent[0] the maximum mark
// Assign to minMarkAndStudent[1] the index of the surname of the student with the maximum mark
void getMax(float marks[], int length, float maxMarkAndStudent[]) {
    maxMarkAndStudent[0] = marks[0];
    maxMarkAndStudent[1] = 0;

    for (int i = 1; i < length; i++) {
        if (marks[i] > maxMarkAndStudent[0]) {
            maxMarkAndStudent[0] = marks[i];
            maxMarkAndStudent[1] = i;
        }
    }
}

// Assign to minMarkAndStudent[0] the minimum mark
// Assign to minMarkAndStudent[1] the index of the surname of the student with the minimum mark
void getMin(float marks[], int length, float minMarkAndStudent[]) {
    minMarkAndStudent[0] = marks[0];
    minMarkAndStudent[1] = 0;

    for (int i = 1; i < length; i++) {
        if (marks[i] < minMarkAndStudent[0]) {
            minMarkAndStudent[0] = marks[i];
            minMarkAndStudent[1] = i;
        }
    }
}

// Returns how many students have a mark above 6
int getSufficent(float array[], int lenght) {
    int counter = 0;

    for (int i = 0; i < lenght; i++) {
        if (array[i] >= 6) 
            counter++;
    }

    return counter;
}

// Returns how many students have a mark below 6
int getInssuficent(float array[], int lenght) {
    int counter = 0;

    for (int i = 0; i < lenght; i++) {
        if (array[i] < 6) 
            counter++;
    }

    return counter;
}

// Return how many students have a mark from 7.5 and 10
int getGoodStudents(float array[], int length) {
    int counter = 0;

    for (int i = 0; i < length; i++) {
        if (array[i] >= 7.5 && array[i] <= 10) 
            counter++;
        
    }

    return counter;
}

void main() {
    // how many student the user want to insert
    int howManyStudent;
    // in the index 0: max mark
    // int the index 1: index of the name of the student that has the max mark
    float maxMarkAndStudent[2];
    // in the index 0: minimum  mark
    // int the index 1: index of the name of the student that has the minimum mark
    float minMarkAndStudent[2];

    // variable to ask the user if he want to continue
    int interruptGame;

    // Cycle while the user insert 1 to the final questio on the cycle
    do {
        // Cycle until the user insert a valid number
        do {
            // ask to the user how many marks he want to insert
            printf("Quanti studenti vuoi inserire: ");
            scanf("%d", &howManyStudent);

            // If the user insert an invalid number,
            // tell him what number are allowed
            if (howManyStudent < 0)
                printf("Devi inserire un numero maggiore o uguale a 0");
        } while (howManyStudent < 0);

        // declare an array to store marks
        char studentsSurname[howManyStudent][30];
        float studentsMarks[howManyStudent];

        // Loop through both arrays, studentsSurname and studentsMarks,
        // prompting the user to enter the student's last name first and then their respective grade.
        for (int i = 0; i < howManyStudent; i++) {
            // Prompt the user to enter the last name of the i-th student.
            printf("Inserire il %d cognome: ", i+1);
            scanf("%s", studentsSurname[i]);

            // The cycle continue until the user inser a mark above 0
            do {
                // Prompt the user to enter the grade of the i-th student.
                printf("Inserire il voto di %s: ", studentsSurname[i]);
                scanf("%f", &studentsMarks[i]);
                
                // If the user insert an invalid number,
                // tell him what numbers are allowed
                if (studentsMarks[i] < 0) 
                    printf("Devi inserire un numero maggiore o uguale a 0\n");
            } while (studentsMarks[i] < 0);
        }

        // call the function to get the maximum and minimum mark
        getMax(studentsMarks, howManyStudent, maxMarkAndStudent);
        getMin(studentsMarks, howManyStudent, minMarkAndStudent);

        // Print the result
        printf("la media dei voti degli studenti e': %.2f\n", getAvarage(studentsMarks, howManyStudent));
        printf("Il voto massimo fra tutti gli studenti e': %.2f Questo voto appartiente a %s\n", (float)maxMarkAndStudent[0], studentsSurname[(int)maxMarkAndStudent[1]]);
        printf("Il voto minimo fra tutti gli studenti e': %.2f Questo voto appartiente a %s\n", (float)minMarkAndStudent[0], studentsSurname[(int)minMarkAndStudent[1]]);
        printf("Il numero degli studenti che hanno preso un voto tra 7.5 e 10 e': %d\n", getGoodStudents(studentsMarks, howManyStudent));
        printf("Il numero degli studenti inssufficenti e': %d\n", getInssuficent(studentsMarks, howManyStudent));
        printf("Il numero degli studenti sufficenti e': %d\n\n", getSufficent(studentsMarks, howManyStudent));

        printf("\n");

        // Prompt the user if he want to play again
        printf("Vuoi continuare:\n[1] - SI\n[0] - NO\nInesrire scelta: ");
        scanf("%d", &interruptGame);
    } while (interruptGame);
}