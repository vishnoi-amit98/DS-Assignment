#include <stdio.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

int main() {
    struct Student s;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Reading student details
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name); // Handles spaces in full names

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    // Displaying stored details
    printf("\nRoll No: %d\n", s.rollNo);
    printf("Name: %s\n", s.name);
    printf("Marks: %.2f\n", s.marks);

    return 0;
}
