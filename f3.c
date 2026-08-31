#include <stdio.h>
#include <stdlib.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

int main() {
    int n, i, searchRoll, found = 0;
    struct Student *students;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamic memory allocation for n student records
    students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input records
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Input target roll number
    printf("\nEnter Roll Number to search: ");
    scanf("%d", &searchRoll);

    // Searching within the dynamic array
    for (i = 0; i < n; i++) {
        if (students[i].rollNo == searchRoll) {
            printf("\n--- Student Found ---\n");
            printf("Roll No : %d\n", students[i].rollNo);
            printf("Name    : %s\n", students[i].name);
            printf("Marks   : %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d not found.\n", searchRoll);
    }

    // Deallocate heap memory
    free(students);

    return 0;
}
