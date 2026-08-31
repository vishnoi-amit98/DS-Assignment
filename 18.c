#include <stdio.h>
#include <stdlib.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float *marks; // Pointer member
};

int main() {
    struct Student s;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    s.rollNo = 101;

    // INCORRECT (Original Error):
    // s.marks = 88.5; // Error: assigns float literal directly to pointer address

    // CORRECT METHOD: Allocate valid memory before assigning value
    s.marks = (float *)malloc(sizeof(float));
    if (s.marks == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *s.marks = 88.50f; // Dereferencing to store the float value

    // Displaying details
    printf("Roll No : %d\n", s.rollNo);
    printf("Marks   : %.2f\n", *s.marks);

    // Free allocated memory
    free(s.marks);

    return 0;
}