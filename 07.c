#include <stdio.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

int main() {
    int n, i, searchRoll, found = 0;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];

    // Reading student records
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &s[i].rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", s[i].name);

        printf("Enter Marks: ");
        scanf("%f", &s[i].marks);
    }

    // Input roll number to search
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    // Searching through the array
    for (i = 0; i < n; i++) {
        if (s[i].rollNo == searchRoll) {
            printf("\n--- Student Found ---\n");
            printf("Roll No: %d\n", s[i].rollNo);
            printf("Name   : %s\n", s[i].name);
            printf("Marks  : %.2f\n", s[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", searchRoll);
    }

    return 0;
}
