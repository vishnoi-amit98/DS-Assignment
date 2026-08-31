#include <stdio.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

// Function to update marks using pointer
void updateMarks(struct Student *s) {
    printf("\nEnter New Marks: ");
    scanf("%f", &s->marks);
}

int main() {
    struct Student s;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Reading initial details
    printf("Enter Roll Number: ");
    scanf("%d", &s.rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Initial Marks: ");
    scanf("%f", &s.marks);

    // Displaying details before modification
    printf("\n--- Details Before Update ---\n");
    printf("Roll No: %d\n", s.rollNo);
    printf("Name   : %s\n", s.name);
    printf("Marks  : %.2f\n", s.marks);

    // Updating marks through function
    updateMarks(&s);

    // Displaying details after modification
    printf("\n--- Details After Update ---\n");
    printf("Roll No: %d\n", s.rollNo);
    printf("Name   : %s\n", s.name);
    printf("Marks  : %.2f\n", s.marks);

    return 0;
}