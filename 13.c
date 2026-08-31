#include <stdio.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

int main() {
    int n, i;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];
    struct Student *ptr = s; // Pointing to base address of the array

    // Reading details using pointer
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &(ptr + i)->rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", (ptr + i)->name);

        printf("Enter Marks: ");
        scanf("%f", &(ptr + i)->marks);
    }

    // Displaying details using pointer traversal
    printf("\n================ ALL STUDENT RECORDS ================\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("----------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-10d %-25s %-10.2f\n", (ptr + i)->rollNo, (ptr + i)->name, (ptr + i)->marks);
    }

    return 0;
}