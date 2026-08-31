#include <stdio.h>
#include <stdlib.h>

// Defining Student structure with dynamic marks pointer
struct Student {
    int rollNo;
    char name[30];
    int numSubjects;
    float *marks;
};

int main() {
    int n, i, j;
    struct Student *students;

    // Header with student info and separator
    printf("Name: Vishnoi Amit \t Entry No: 25BCM051\n");
    printf("----------------------------------------\n\n");

    printf("Enter number of students: ");
    scanf("%d", &n);

    // 1. Allocate dynamic array for n students
    students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Outer memory allocation failed!\n");
        return 1;
    }

    // 2. Read details and allocate inner dynamic marks array per student
    for (i = 0; i < n; i++) {
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Enter Roll Number: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter Name: ");
        scanf(" %[^\n]", students[i].name);

        printf("Enter Number of Subjects: ");
        scanf("%d", &students[i].numSubjects);

        students[i].marks = (float *)malloc(students[i].numSubjects * sizeof(float));
        if (students[i].marks == NULL) {
            printf("Inner memory allocation failed for student %d!\n", i + 1);
            return 1;
        }

        printf("Enter marks for %d subjects:\n", students[i].numSubjects);
        for (j = 0; j < students[i].numSubjects; j++) {
            printf("Subject %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
    }

    // 3. Display all student records
    printf("\n================ ALL STUDENT PERFORMANCE REPORTS ================\n");
    for (i = 0; i < n; i++) {
        float total = 0.0;
        printf("\nStudent %d:\n", i + 1);
        printf("Roll No  : %d\n", students[i].rollNo);
        printf("Name     : %s\n", students[i].name);
        printf("Marks    : ");
        for (j = 0; j < students[i].numSubjects; j++) {
            printf("%.2f ", students[i].marks[j]);
            total += students[i].marks[j];
        }
        printf("\nAverage  : %.2f\n", total / students[i].numSubjects);
    }

    // 4. Free memory in proper order (Inner then Outer)
    for (i = 0; i < n; i++) {
        free(students[i].marks);
    }
    free(students);

    return 0;
}