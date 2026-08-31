#include <stdio.h>
#include <stdlib.h>

// Defining the Student structure
struct Student {
    int rollNo;
    char name[30];
    float marks;
};

int main() {
    int n, i;
    struct Student *students;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamically allocating memory for array of n Student structures
    students = (struct Student *)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Reading details of all students
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Displaying all records
    printf("\n================ ALL STUDENT RECORDS ================\n");
    printf("%-10s %-25s %-10s\n", "Roll No", "Name", "Marks");
    printf("----------------------------------------------------\n");
    for (i = 0; i < n; i++) {
        printf("%-10d %-25s %-10.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }

    // Free dynamically allocated memory
    free(students);

    return 0;
}