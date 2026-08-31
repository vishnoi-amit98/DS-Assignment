#include <stdio.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

int main() {
    struct Student s;
    struct Student *ptr = &s;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    // Reading details using pointer (-> operator)
    printf("Enter Roll Number: ");
    scanf("%d", &ptr->rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]", ptr->name);

    printf("Enter Marks: ");
    scanf("%f", &ptr->marks);

    // Displaying details using (*ptr).member notation
    printf("\n--- Accessing using (*ptr).member ---\n");
    printf("Roll No: %d\n", (*ptr).rollNo);
    printf("Name   : %s\n", (*ptr).name);
    printf("Marks  : %.2f\n", (*ptr).marks);

    // Displaying details using ptr->member notation
    printf("\n--- Accessing using ptr->member ---\n");
    printf("Roll No: %d\n", ptr->rollNo);
    printf("Name   : %s\n", ptr->name);
    printf("Marks  : %.2f\n", ptr->marks);

    return 0;
}