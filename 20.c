#include <stdio.h>
#include <stdlib.h>

// Defining the Student structure with dynamic member
struct Student {
    int rollNo;
    float *marks;
};

int main() {
    struct Student s;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    s.rollNo = 101;

    // Dynamically allocating memory on the heap
    s.marks = (float *)malloc(sizeof(float));

    if (s.marks == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    *s.marks = 91.5f;

    printf("Roll No: %d\n", s.rollNo);
    printf("Marks  : %.2f\n", *s.marks);

    // Deallocating heap memory to prevent memory leak
    free(s.marks);
    s.marks = NULL; // Good practice to avoid dangling pointer

    printf("\nMemory successfully released using free().\n");

    return 0;
}