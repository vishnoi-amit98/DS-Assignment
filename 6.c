#include <stdio.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

int main() {
    int n, i, maxIndex = 0;

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

    // Finding student with highest marks
    for (i = 1; i < n; i++) {
        if (s[i].marks > s[maxIndex].marks) {
            maxIndex = i;
        }
    }

    // Displaying the top student's details
    printf("\n--- Student with Highest Marks ---\n");
    printf("Roll No: %d\n", s[maxIndex].rollNo);
    printf("Name   : %s\n", s[maxIndex].name);
    printf("Marks  : %.2f\n", s[maxIndex].marks);

    return 0;
}