#include <stdio.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

// Function to display student details using pointer
void displayStudent(struct Student *s) {
    printf("\n--- Student Details (via Function) ---\n");
    printf("Roll No: %d\n", s->rollNo);
    printf("Name   : %s\n", s->name);
    printf("Marks  : %.2f\n", s->marks);
}

int main() {
    struct Student s1;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Reading details
    printf("Enter Roll Number: ");
    scanf("%d", &s1.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s1.name);

    printf("Enter Marks: ");
    scanf("%f", &s1.marks);

    // Passing address to function
    displayStudent(&s1);

    return 0;
}