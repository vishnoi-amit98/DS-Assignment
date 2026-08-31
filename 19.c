#include <stdio.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

int main() {
    struct Student s;
    struct Student *p;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Initial assignment
    s.rollNo = 101;
    s.marks = 75.0f;

    printf("Initial value of s.marks : %.2f\n", s.marks);

    // Pointer assignment
    p = &s;

    // Modifying value through pointer
    p->marks = 95.5f;

    // Outputting to verify prediction
    printf("Predicted final s.marks  : 95.50\n");
    printf("Actual final s.marks     : %.2f\n", s.marks);

    return 0;
}